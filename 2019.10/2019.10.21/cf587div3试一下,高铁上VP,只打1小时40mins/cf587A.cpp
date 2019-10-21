/*
2019年10月21日13:20:27 开始看题

2019年10月21日13:32:06 准备交，但卡了

2019年10月21日13:33:42 wa on 4???

傻逼了，c[]值忘了改,2019年10月21日13:36:48 AC
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
int n,c[2],ans;
string s;

int main(){
    cin>>n>>s;
    rep(i,0,n-1){
        c[s[i]-'a']++;
        if(i&1){
            if(c[0] > c[1]){
                // ans++;s[i]='b';
                ans++;s[i]='b';c[0]--,c[1]++;
            } else if(c[0] < c[1]){
                // ans++;s[i]='a';
                ans++;s[i]='a';c[0]++,c[1]--;
            }
        }
    }
    cout<<ans<<endl;
    cout<<s<<endl;

    return 0;
}