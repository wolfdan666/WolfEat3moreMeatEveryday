/*
2019年10月23日21:12:15 开始看题

easy版的应该也就是暴力枚举

想法是这样的:
首先有n条线段,然后我对n覆盖的每个点计数,然后记录所有的超过k次的点,优先去除warning最多的线段...

但是有个问题是,warning数随着去除的线段在变化...所以还是不行的
2019年10月23日21:26:30 再冷静地想想,不要着急,猥琐发育

2019年10月23日21:29:54 觉得应该就是线性化,从最左边的被覆盖的点一直遍历的最右边,优先去除头顶上向右延展最长的线段,因为我们已经假定了左边是满足的(dp思想)

2019年10月23日22:00:51 写搓了,功力还不够...太菜了
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
int n,k,ans;
struct line{
    int id,l,r;
} li[220];
vector<int> a[220];
vector<int> ans;

bool cmp(int a,int b){ return li[a].r > li[b].r; }

int main(){
    n = rd(); k = rd();
    int lt=210,rt=0;
    rep(i,1,n){
        li[i].id=i; li[i].l = rd(); li[i].r = rd();
        lt = min(lt,li[i].l);
        rt = max(rt,li[i].r);
        // size值就是点对应的被覆盖的边数
        rep(j,li[i].l,li[i].r){
            a[j].pb(i);
        }
    }
    rep(i,lt,rt){
        if(a[i]<=k) continue;
        int tp = a[i] - k;
        sort(a[i].begin(), a[i].end(),cmp);
        rep(i,0,tp-1){
            ans.pb(a[i]);
            rep(j,a[i].l,a[i].r){
                a[j].erase(a[j].find(i));
            }
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    rep(i,0,sz-1) printf("%d\n", ans[i]);

    return 0;
}

