/*
2019年10月27日15:53:00 写了50mins了还是写不对...

2019年10月27日16:03:48 和tutorial的代码检查了好多遍了,为什么答案不对呢?

2019年10月27日16:12:38 傻逼弟弟行为,debug 70mins...没有及时使用cout...查看...愚蠢!
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
int n,k;
// vector<pair<int,int> > edge[220];
// vector<pair<int,int> > edge(220);
int cnt[234]/*,ans[220]*/;

int main(){
    n = rd(); k = rd();
    // vector<pair<int,int> > edge(n);
    vector<pair<int,int> > edge(n+1);
    rep(i,1,n){
        edge[i].fi = rd(); edge[i].se = rd();
        cnt[edge[i].fi]++,cnt[edge[i].se+1]--;
    }
    // rep(i,1,n-1) cnt[i+1]+=cnt[i]; 傻逼!!!!!这里卡了70mins,点和边的序号没有分清楚!
    rep(i,1,233) cnt[i+1]+=cnt[i];

    vector<int> ans(n+1);
    // rep(i,1,n){       傻逼!!!!!这里卡了70mins,点和边的序号没有分清楚!
    rep(i,1,220){
        while(cnt[i]>k){
            int pos = -1;
            rep(e,1,n)
                if(!ans[e] && (edge[e].fi<=i&&edge[e].se>=i) && (pos==-1||edge[pos].se<edge[e].se))
                    pos = e;
            // assert(pos==-1);
            assert(pos!=-1);
            rep(j,edge[pos].fi,edge[pos].se){
                cnt[j]--;
            }
            ans[pos]=1;
        }
    }

    // printf("%d\n", accumulate(ans,ans+210,0));
    printf("%d\n", accumulate(ans.begin(),ans.end(),0));
    rep(i,1,n){
        if(ans[i]) printf("%d ", i);
    }
    puts("");

    return 0;
}