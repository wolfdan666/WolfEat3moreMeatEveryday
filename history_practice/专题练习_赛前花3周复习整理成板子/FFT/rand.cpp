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
#define random(a,b) ((a)+rand()%((b)-(a)+1))
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
int a[] = {12,3};

int main(){
    freopen("ramd.txt","r",stdin);
    freopen("inrand.txt","w",stdout);
    int n = 4096;int tp;
    // cout<<"{";

    // // 时间种子一样！
    // while(n--){
    //     tp = rand()%100;

    //     printf("%d%c",tp,n!=0?',':'}' );
    // }
    //     cout<<";";
    char tmp;
    cin>>tmp;
    rep(i,0,n-1){
        cin>>tp;
        printf("%d 0\n", tp);
    }
    cin>>tmp;


    return 0;
}