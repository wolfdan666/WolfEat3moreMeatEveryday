/*
ldm用比较法也wa，后面改成这种遍历dp转移就AC了

所以我的比较法肯定没有考虑到所有特例...
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
const int N = 1e3 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

struct node {
    int cost, val;
}a[N];
LL dp[10010];
int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        rep(i, 1, n) scanf("%d%d", &a[i].cost, &a[i].val);
        int mx = 10000;
        rep(i, 1, mx) dp[i] = INF;
        dp[0] = 0;
        rep(i, 1, n) {
            rep(v, a[i].val, mx) {
                dp[v] = min(dp[v], dp[v-a[i].val] + a[i].cost);
            }
        }
        LL ans = INF; int vol;
        per(v, mx, m) {
            if(dp[v] != INF && dp[v] < ans) {
                ans = dp[v];
                vol = v;
            }
        }
        printf("%lld %d\n", ans, vol);
    }

    return 0;
}