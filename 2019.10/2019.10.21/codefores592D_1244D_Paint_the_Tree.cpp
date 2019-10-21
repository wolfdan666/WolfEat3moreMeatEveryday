/*
2019年10月21日10:16:27 开始看题

中途看手机5mins


感觉就是dfs每一种颜色,看完tutorial确认思路后就写

感觉 不怎么会写 为了高效率，前几次先学别人的代码写
先看几份代码，然后自己写

2019年10月21日11:24:37 看懂一个luogu大佬的代码

充分利用形成是一条链的性质

2019年10月21日12:32:52... 中途有吃饭什么的，树和图自己还是太菜了，多补补
为了高效率上分，所以先不断刷2000分一下的先
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
const int N = 1e5+10;
int n,c[3][N],p[N],u,v,id[N],col[N],ansid[3];ll ans;
vector<int> E[N];

int main(){
    n = rd();
    rep(i,0,2) rep(j,1,n) c[i][j] = rd();
    rep(i,1,n-1){u = rd(),v = rd();E[u].pb(v);E[v].pb(u);}
    rep(i,1,n){
        if(E[i].size()>2) return puts("-1"),0;
        if(E[i].size() == 1) p[1] = i;
    }
    rep(i,2,n) for(int v:E[p[i-1]]) if(v!=p[i-2]) p[i]=v;
    rep(i,0,2) id[i]=i;
    ans = 2e15;
    while(1){
        ll s = 0;
        // 充分利用了一条链的性质，然后这里和题意是紧密相关的
        rep(i,1,n) s+=c[id[i%3]][p[i]];
        if(s < ans) ans = s,memcpy(ansid,id,sizeof ansid);
        if(!next_permutation(id,id+3)) break;
    }
    // 从有序的映射链接到之前的节点值,让有序输出
    rep(i,1,n) col[p[i]] = ansid[i%3]+1;
    printf("%lld\n", ans);
    rep(i,1,n) printf("%d%c", col[i]," \n"[i==n]);
    return 0;
}