/*
2019年10月26日19:49:30 开始想hard版

t*n = 2e9了... 2s..难道cf机器现在1秒2e9?

O(n) 的检测是滑动窗口吧

试试吧

2019年10月26日20:06:58 AC
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
const int M = 2e5+10;
int t,n,k,d,ans;
unordered_map<int,int> s;
int a[M];

int main(){
    t = rd();
    while(t--){
        n = rd(), k = rd(), d = rd();
        rep(i,1,n) a[i] = rd();
        ans=inf;
        s.clear();
        rep(i,1,d){
            s[a[i]]++;
            // cout<<"size: "<<(int)s.size()<<endl;
            // ans = min(ans,(int)s.size());
        }
        ans = min(ans,(int)s.size());

        rep(i,d+1,n){
            s[a[i-d]]--;
            if(s[a[i-d]]==0) s.erase(a[i-d]);
            s[a[i]]++;
            // cout<<"size: "<<(int)s.size()<<endl;
            ans = min(ans,(int)s.size());
        }
        cout<<ans<<endl;
    }

    return 0;
}