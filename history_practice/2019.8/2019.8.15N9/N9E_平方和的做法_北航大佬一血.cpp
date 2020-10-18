#include <bits/stdc++.h>

using ll = long long;
const int MAXN = 100010;

int n, m;
int f[MAXN], sz[MAXN];
ll sum;

ll sqr(int x) {
    return 1ll * x * x;
}

int getf(int x) {
    return f[x] == x ? x : (f[x] = getf(f[x]));
}

int main() {
    scanf("%d%d", &n, &m);
    ll ans = (__int128) n * (n - 1) * (n - 2) * (n - 3) / 24;
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        sz[i] = 1;
    }
    sum = n;
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        u = getf(u);
        v = getf(v);
        if (u != v) {
            sum -= sqr(sz[u]) + sqr(sz[v]);
            ll tmp = 1ll * sz[u] * sz[v] * (sqr(n - sz[u] - sz[v]) - sum) / 2;
            f[u] = v;
            sz[v] += sz[u];
            sum += sqr(sz[v]);
            ans -= tmp;
        }
        printf("%lld\n", ans);
    }
    return 0;
}