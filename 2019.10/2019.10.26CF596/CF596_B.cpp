/*
2019年10月26日19:15:40  开始看题

看不太懂题意...谷歌翻译

n 天,k 种节目,你想看d集
到底什么意思...

2019年10月26日19:32:54 懂了
就是你想要买最少的集数,但是这些集数会在连续的d天播放
就是扫描所有的d天,然后看最少size数,用个set?easy可以

2019年10月26日19:47:39 交--AC
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
int t,n,k,d,ans;
set<int> s;
int a[120];

int main(){
    t = rd();
    while(t--){
        n = rd(), k = rd(), d = rd();
        rep(i,1,n) a[i] = rd();
        ans=inf;
        rep(i,1,n-d+1){
            s.clear();
            // rep(j,i,d){
            rep(j,i,i+d-1){
                s.insert(a[j]);
            }
            ans = min(ans,(int)s.size());
        }
        cout<<ans<<endl;
    }

    return 0;
}