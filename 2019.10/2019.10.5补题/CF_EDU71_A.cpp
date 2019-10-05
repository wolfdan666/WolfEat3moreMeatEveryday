/* 
2019年10月05日19:36:36 分析那天第一发错误的原因

把错误代码搞下来,分析.发现自己真傻逼,犯了初学者级别的错误...
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
        if(h>=c){
            if(b/2 > p){
                b-=2*p,ans+=p*h;
                if(b/2>f){
                    ans+=f*c;
                }
                else{
                    ans+=b/2*c;
                }
            }
            else{
                // 那天主要错在这里!先把b=0.然后再对b运算,就很傻逼
                // b = 0;
                ans+=b/2*h;
            }
        } else {
            if(b/2>f){
                b-=2*f,ans+=f*c;
                if(b/2 > p){
                    ans+=p*h;
                }
                else{
                    ans+=b/2*h;
                }
            }
            else{
                // b=0;
                ans+=b/2*c;
            }
        }
        cout<<ans<<endl;
 
    }
    
    return 0;
}