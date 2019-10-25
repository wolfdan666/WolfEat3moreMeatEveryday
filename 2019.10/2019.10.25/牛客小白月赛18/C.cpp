/*
2019年10月25日19:24:09 T了A题看C

极值,k个队的极值和最大

2019年10月25日19:29:47 交了,AC
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
const int M = 1e5+10;
int n,k;
int a[M];
ll ans;

int main(){
    n = rd();k = rd();
    rep(i,1,n) a[i] = rd();
    // 就是sort后取前后各k个,一正一负
    sort(a+1,a+1+n);
    rep(i,1,k){
        ans+=a[n+1-i] - a[i];
    }
    printf("%lld\n", ans);

    return 0;
}