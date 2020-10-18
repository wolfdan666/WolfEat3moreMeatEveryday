/*
2019年10月23日20:06:55开始看题

暴力模拟

2019年10月23日20:19:06 AC
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
int q,n,p[220],a[220];

int main(){
    q = rd();
    while(q--){
        n = rd();
        mem(a,0);
        rep(i,1,n) p[i]=rd();
        rep(i,1,n){
            int tp = i;
            while(p[tp] != i) tp = p[tp],a[i]++;
        }
        rep(i,1,n) printf("%d%c", a[i]+1," \n"[i==n]);
    }

    return 0;
}