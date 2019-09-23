/*
枚举 $6^n$ ,然后check

我不会实现，这是ldm的

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int n, m, ans;
int id[10];
int cnt[10][10], use[10][10];
vector<int> G[10];

int chk() {
    int res = 0;
    rep(u, 1, n) {
        for(auto v : G[u]) {
            if(id[u] <= id[v] && !use[id[u]][id[v]]) {
                use[id[u]][id[v]] = 1;
                res++;
            }
        }
    }
    return res;
}

// 1向2dfs，然后2向3dfs，id表示点数
// 第一点发散出6种情况，然后第二点在第一点的基础上再每点发散6个点,
// 就相当于1->2环状6点，然后每个2再发散出6个3……
// 这里只是为了枚举出每个点被朝向的对应点的数值而已,与连接是无关的
void dfs(int cur) {
    if(cur == n+1) {
        memset(use, 0, sizeof(use));
        ans = max(ans, chk());
        return;
    }
    // 枚举朝向cur的点数值
    rep(i, 1, 6) {
        id[cur] = i;
        dfs(cur+1);
    }
}


int main() {
    while(cin >> n >> m) {
        rep(i, 1, n) G[i].clear();
        rep(i, 1, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v); G[v].pb(u);
        }
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }

    return 0;
}
