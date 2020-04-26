/*
2020年4月26日20:52:06 这里感觉是找规律！

- 第n层最后一个的编号是 2^n-1
- 第n层的个数是 2^(n-1)
- 所以第n层的第一个的编号是
    2^n - 1 - 2^(n-1) + 1 = 2^n - 2^(n-1)

- 然后祖先是 x >> 1

- 2^64 = 16 * 10^16 ---> 64次还可以

2020年4月26日21:15:23 竟然只过了50%...

2020年4月26日21:19:32 发现自己傻逼了，rd()的返回值是int

2020年4月26日21:20:49 AC
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
int Q;
ll x,l,r,xi;
int k;

int main(){
    Q = rd();
    while(Q--){
        // x = rd();
        cin>> x;
        k = rd();
        xi = x;
        r = pow(2,k)-1;
        l = r+1 - pow(2,k-1);

        // cout<< "l: "<< l << " r: "<<r <<endl;

        while( x > r ) x >>= 1;
        if(l <= x && x <= r && x!=xi) cout << x <<endl;
        else puts("-1");
    }

    return 0;
}