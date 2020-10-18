/* 
2019年10月03日18:55 开始看题  VP begin

2019年10月03日19:07:23 才交... 写的还是慢 ,12mins
结果wa on test 2!!?

不科学啊!！！？

2019年10月03日19:24:34 随便改了改 AC了...等下比完赛再看自己哪里写龊了...
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
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
int t,b,p,f,h,c;

int main(){
    t = rd();
    while(t--){
        int ans = 0;
        cin>>b>>p>>f;
        cin>>h>>c;
        // if(h>=c){
        if(h>c){
            if(b/2>=p){
                b-=2*p,ans+=p*h;
                if(b/2>=f) ans+=f*c;
                else ans+=b/2*c;
            }
            else ans+=b/2*h;
        } 
        else if(h==c){
            if(b/2>=p+f) ans = (p+f)*h;
            else ans = b/2*h;
        } else {
            if(b/2>=f){
                b-=2*f,ans+=f*c;
                if(b/2 >= p) ans+=p*h;
                else ans+=b/2*h;
            }
            else ans+=b/2*c;
        }
        cout<<ans<<endl;

    }
    
    return 0;
}