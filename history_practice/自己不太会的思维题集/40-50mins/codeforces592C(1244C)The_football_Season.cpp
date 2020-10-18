/*
2019年10月21日09:22:14 开始看题
exgcd不太会啊，看tutorial学习吧

the number of points awarded for a draw, respectively. Note that w>d,
so the number of points awarded for winning is strictly greater than
the number of points awarded for draw.


xw+yd=p
if y>w : (x+d)w+(y-w)d = p

2019年10月21日09:49:35 理解了半天才发现是因为最大的匹配一定可以
通过不断地进行 -w 操作来达到0 到 w-1之内，所以可以直接迭代0到w-1

2019年10月21日10:12:59 这题真牛逼
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
ll n,p,d,w,ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>p>>w>>d;
    rep(i,0,w-1){
        ll y = i;
        ll xw = p - y*d;
        if(xw>=0 && xw%w==0 && xw/w+y <= n){
            ll x = xw/w;
            cout<<x<<" "<<y<<" "<<n - x - y<<endl;
            return 0;
        }
    }
    printf("%d\n", -1);

    return 0;
}