#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=4010;
int _,n,m;
ll fac[N],fnv[N];

ll comb(int x,int y) {
    if (y>x||y<0) return 0;
    return fac[x]*fnv[y]%mod*fnv[x-y]%mod;
}
int main() {
    fac[0]=fnv[0]=1;
    rep(i,1,4001) fac[i]=fac[i-1]*i%mod,fnv[i]=powmod(fac[i],mod-2);
    while (scanf("%d%d",&n,&m)!=EOF) {
        ll ans=comb(2*n+2*m,n+m)-comb(2*n+2*m,n-1)-comb(2*n+2*m,m-1);
        ans%=mod;
        if (ans<0) ans+=mod;
        printf("%lld\n",ans);
    }
}