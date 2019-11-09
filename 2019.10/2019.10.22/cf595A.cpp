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
        // int pre = a[1]; ans = 1;
        set<int> s[110];
        int cnt = 0;
        s[++cnt].insert(a[1]);
        rep(i,2,n){
            // 大的想要和小的组队,然后如果和当下最大的冲突,
            // 那么让那个冲突的去新开一个队
            // 后面再冲突的时候就会想考虑这个新开的队伍了
            // 想复杂了吧？
            // 对的，可以暴力贪心的！
            rep(j,1,cnt){
                bool f = 1;
                for(auto k : s[j]){
                    if(a[i]<=k+1) f = 0;
                }
                // 万一放某个集合造成了很不好的影响咋办？
                // 傻逼，a[i]是1到100,直接贪心分配就行了!
                // 而且最多只有两队!沙雕了，2019年10月22日23:00:35 才想到最简单思路，尴尬不认真看样例
                if(f)
            }
        }
    }

    return 0;
}