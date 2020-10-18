/*
2019年11月06日20:29:52 开始看

奇数 = 3 + 大于2的偶数(必定是合数)
偶数 = 2 + 大于2的偶数
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
int T,n,a,b;

int main(){
    T = rd();
    while(T--){
        n = rd();
        if(n<=5) printf("%d\n", -1);
        else if(n&1) printf("%d %d\n",3,n-3);
        else printf("%d %d\n", 2, n-2);
    }

    return 0;
}