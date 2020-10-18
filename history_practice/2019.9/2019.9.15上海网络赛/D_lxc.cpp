#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



const int N = 3010;
//dp[i][j][k]=用i个数,和为j,积为k,的方案数

int dp[2][2*N][2*N];
int ans[N];
void add(int &a, int b) {
    a=(a+b)%P;
}
int main() {
    dp[0][0][1] = 1;
    int cur = 0;
    const int S=3000;
    REP(i,1,S) {
        cur ^= 1;
        memset(dp[cur],0,sizeof dp[cur]);
        REP(j,0,2*S) REP(k,1,2*S) {
            int &r = dp[!cur][j][k];
            if (!r) continue;
            REP(d,1,S) {
                if (j+d<2*N&&k*d<2*N) add(dp[cur][j+d][k*d],r);
                else break;
            }
        }
        REP(j,1,2*S) if (dp[cur][j][j]) {
            add(ans[i],dp[cur][j][j]);
        }
        if (i%100==0) printf("i=%d\n",i);
    }
    REP(i,1,S) cout<<ans[i]<<',';hr;
}