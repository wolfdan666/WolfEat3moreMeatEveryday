// 2019年10月22日23:04:47 才交，寝室没人喧哗都这菜，太垃圾了

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

int q,n,ans,a[110];

int main(){
    q = rd();
    while(q--){
        n = rd();
        rep(i,1,n) a[i] = rd();
        sort(a+1,a+1+n);
        bool f = 0;
        rep(i,1,n-1){
            if(a[i]+1>=a[i+1]){f=1;break;}
        }
        if(f) cout<<2<<endl;
        else cout<<1<<endl;
    }

    return 0;
}