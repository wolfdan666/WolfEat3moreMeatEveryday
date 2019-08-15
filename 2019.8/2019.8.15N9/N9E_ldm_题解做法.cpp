#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

ll C[maxn][5];
int p[maxn], sz[maxn], cnt[maxn];
int n, m;
ll ans;
set<int> st;

void init() {
    for(int i = 0; i < maxn; i++) C[i][0] = 1;
    for(int i = 1; i < maxn; i++) {
        for(int j = 1; j < 5; j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
}

int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if(fx != fy) {
        if(fx > fy) swap(fx, fy);
        p[fx] = fy;
        ll tp = C[n-sz[fx]-sz[fy]][2];
        for(auto i : st) {
            tp -= C[i][2]*cnt[i];
        }
        tp += C[sz[fx]][2]+C[sz[fy]][2];
        if(tp > 0) ans -= 1LL*sz[fx]*sz[fy]*tp;
        cnt[sz[fx]]--;
        cnt[sz[fy]]--;
        if(cnt[sz[fx]] == 0) st.erase(sz[fx]);
        if(cnt[sz[fy]] == 0) st.erase(sz[fy]);
        sz[fy] += sz[fx];
        cnt[sz[fy]]++;
        st.insert(sz[fy]);
    }
}


int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    cnt[1] = n; st.insert(1);
    ans = C[n][4];
    printf("%lld\n", ans);
    while(m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        Union(u, v);
        printf("%lld\n", ans);
    }

    return 0;
}