#include <bits/stdc++.h>
#define scll(x) scanf("%lld", &x)
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", &x)
#define ptf(x) printf("%d", x)
#define ptfs(x) printf("%s", x)
#define ptfb printf(" ");
#define ptfll(x) printf("%lld", x)
#define pts puts("")
#define rep(i, x, n) for(int i = x; i <= n; i++)
#define per(i, x, n) for(int i = n; i >= x; i--)
#define met(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double eps = 1e-8;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 6;
ll qpow(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % MOD;a = a * a % MOD;b >>= 1;}return ans;}
ll inv(ll a) {return qpow(a, MOD - 2);}
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
int t, n;
ll h[MAXN], dp[MAXN];

int main() {
    sc(t);
    while(t--) {
        sc(n);
        rep(i, 1, n) sc(h[i]);
        bool flag = 1;
        if(h[1] != 0) flag = 0;
        rep(i, 2, n) {
            if(h[i] == 0 || h[i - 1] > h[i] || h[i] >= n) {
                flag = 0;
                break;
            }
        }
        if(!flag) {
            puts("0");
            continue;
        }
        dp[1] = 1;
        rep(i, 2, n) {
            if(h[i] == h[i - 1]) {
                // 如果相等,则从选择域中(h[i]+1)个数剔除掉之前选过的(i-1)个,得到可能选择的
                dp[i] = (dp[i - 1] % MOD * ((h[i] + 1) - (i - 1))) % MOD;
            }
            else if(h[i] > h[i - 1]) {
                // 如果不相等,则必然是加入了新的最小或者最大这两种可能
                dp[i] = dp[i - 1] * 2 % MOD;
            }
        }
        ptf(dp[n]%MOD), pts;
    }
    return 0;
}
/*
5
3
0 2 2
3
0 1 2
3
0 2 3
*/
