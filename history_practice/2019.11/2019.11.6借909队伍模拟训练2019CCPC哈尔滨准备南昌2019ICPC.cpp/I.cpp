/*
还是不太靠谱,看cd的

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
int T,n,h[100010],cnt[100010],k;
int A[100010];

void pre_init(){
    A[0] = 1;
    rep(i,1,100005){
        A[i] = (A[i]*A[i-1]) % mod;
    }
}

int main(){
    cin>>T;
    pre_init();
    while(T--){
        ll ans = 1;
        k = 0;
        n = rd();
        rep(i,1,n){
            h[i] = rd();
            if(i==1||h[i]!=h[i-1]) cnt[++k]=i;
        }
        int pre = h[cnt[k]];
        per(i,k-1,1){
            int tp = h[cnt[i]];
            int a = i==1? 2 : pre - tp + 1;
            int b = tp>1 ? A[tp-1] : 1;
            ans = ans*a*b%mod;
            pre = tp;
            cout<<
        }
        printf("%lld\n", ans);
    }

    return 0;
}