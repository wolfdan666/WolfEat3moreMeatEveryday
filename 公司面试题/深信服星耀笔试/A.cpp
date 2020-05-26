/*
2020年5月26日19:00:16 等待发卷好久...

不相邻，不岩石

主要是这里种1 - max颗树都是要算的
2020年5月26日19:06:34 先读一下第二题题目

2020年5月26日19:41:40 发现不种树也是一种！
3棵树是在两颗数基础上找的，感觉是像set套set
0 棵树 1
1 棵树 set< pair<int,int> > --> 1的个数
2 棵树 set< vector<pair<int,int>> >
3 棵树 set< vector<pair<int,int>> >
少于51 棵树 set< vector<pair<int,int>> >

2020年5月26日19:48:38 感觉可以写一手
2020年5月26日20:13:24 保持全力以赴

2020年5月26日20:20:33 发现是套set

2020年5月26日20:27:04 TLE过了10% ???
样例都没过，我居然这样过了10%...奇怪

群里说dp...我居然不会...服了

2020年5月26日20:46:27 突然想到自己连取模mod都没写


2020年5月26日22:44:27 补了别人的类似8皇后的dp,心情有点难过
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
const ll mod=1e8;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
int N,M;
int maze[11][11];
bool vis[11][11];
set< set<pair<int,int>> > tr[51];
int ans;
int a[]={1,-1,0,0};
int b[]={0,0,1,-1};

// 在外面就处理好vis,这样可以让dfs通用化
void dfs(set<pair<int,int>> x){
    // 在set的一个vector里面，但是不是岩石,锁住，然后去找空闲块
    int nxt = x.size()+1;
    memset(vis,false,sizeof vis);
    for(auto i : x){
        int p = i.fi,q = i.se;
        vis[p][q] = true;
        rep(j,0,3){
            vis[p+a[j]][q+b[j]]=true;
        }
    }
    rep(i,1,N){
        rep(j,1,M){
            if(!vis[i][j] && maze[i][j]){
                ans++;
                set<pair<int,int>> tp_x = x;
                tp_x.insert({i,j});
                tr[nxt].insert(tp_x);
            }
        }
    }
}

int main(){
    N = rd(); M = rd();
    // 0,1 棵树情况
    ans = 1;
    memset(vis,false,sizeof vis);
    rep(i,1,N){
        rep(j,1,M){
            maze[i][j]=rd();
            if(maze[i][j]){
                ans++;
                set<pair<int,int>> tp;
                tp.insert({i,j});
                tr[1].insert(tp);
            } else vis[i][j] = true;
        }
    }

    int sz = N*M/2;
    rep(i,1,sz){
        for(auto x:tr[i]){
            dfs(x);
        }
    }
    printf("%d\n", ans);

    return 0;
}