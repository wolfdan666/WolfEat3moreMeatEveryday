/*
2019年10月26日20:07:46 开始看题

x非负


k为减去p的一个二进制数
用多个不同的k表示n

ldm来晚了之后看题助攻

if(i > tp) break;
tp = 24(已经考虑了p值的影响),然后我i个二进制,最少为1,所以如果还不行,必须退出,一般是行的

2019年10月26日20:26:40交了ldm的 ldm牛逼


2019年10月27日21:04:40 还看了tutorial,理解得更多了点,牛逼!
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
ll p, n, ans = -1;

int main() {
    cin>>n>>p;
    for(int i = 1; ; i++) {
        ll tp = n-p*i;
        if(__builtin_popcount(tp) <= i && i <= tp) { ans = i; break; }
        if(i > tp) break;
    }
    cout << ans;

    return 0;
}