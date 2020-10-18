#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct node {
    int ls, rs, sum;
} ns[MAXN * 20];

int ct;
int rt[MAXN * 20];

void cpy(int& now, int old) {
    now = ++ct;
    ns[now] = ns[old];
}

void pushUp(int& now) {
    ns[now].sum = ns[ns[now].ls].sum + ns[ns[now].rs].sum;
}

void build(int& now, int l, int r) {
    now = ++ct;
    ns[now].sum = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(ns[now].ls, l, m);
    build(ns[now].rs, m + 1, r);
}

void update(int& now, int old, int l, int r, int x) {
    cpy(now, old);
    if (l == r) {
        ns[now].sum++;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) update(ns[now].ls, ns[old].ls, l, m, x);
    else update(ns[now].rs, ns[old].rs, m + 1, r, x);
    pushUp(now);
}

int query(int s, int t, int l, int r, int k) {
    if (l == r) return l;
    int m = (l + r) >> 1;
    int cnt = ns[ns[t].ls].sum - ns[ns[s].ls].sum;
    //cout << s << " " << t << " " << cnt << endl;
    if (k <= cnt) return query(ns[s].ls, ns[t].ls, l, m, k);
    return query(ns[s].rs, ns[t].rs, m + 1, r, k - cnt);
}

void init(int n) {
    ct = 0;
    build(rt[0], 1, n);
}

int a[MAXN], b[MAXN];

int main() {
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        int sz = unique(b + 1, b + 1 + n) - b - 1;
        init(sz);
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
            update(rt[i], rt[i - 1], 1, sz, a[i]);
        }
        /*for (int i = 0; i <= 5 * n; i++) {
            printf("%d, rt = %d, ls = %d, rs = %d, sum = %d\n", i, rt[i], ns[rt[i]].ls, ns[rt[i]].rs, ns[rt[i]].sum);
        }*/
        while (m--) {
            int s, t, k;
            scanf("%d%d%d", &s, &t, &k);
            printf("%d\n", b[query(rt[s - 1], rt[t], 1, sz, k)]);
        }
    }
    return 0;
}