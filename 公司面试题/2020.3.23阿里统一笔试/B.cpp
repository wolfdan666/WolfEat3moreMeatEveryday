/*
bfs以及使用飞行器5次


2020年3月23日20:30:31 才发现想错了...要bfs...dfs的话vis会起反作用
哭了
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
const int N = 510;
char maze[N][N];
bool vis[N][N];
int n,m;
pair<int,int> s,t;
int ans = inf;
int a[5] = {0,0,1,-1};
int b[5] = {1,-1,0,0};


// int dfs(int t,int x,int y,int count){
void dfs(int t,int x,int y,int count){
    // if(maze[x][y] == 'E') return 0;
    if(maze[x][y] == 'E') {
        ans = min(ans,t+5-count);
        return ;
    }
    if(vis[x][y] || (maze[x][y] == '#')) return ;
    vis[x][y] = 1;

    // int tp = inf;
    // int tp = t;
    rep(i,0,3){
        if(x+a[i] < 0 || x+a[i] > n-1 || y+b[i] < 0 || y+b[i] > m-1) continue;
        // tp = min(tp,dfs(++t,x+a[i],y+b[i],count));
        dfs(++t,x+a[i],y+b[i],count);
        t--;
    }
    int tx = n-1-x,ty = m-1-y;
    if(!(tx<0 || tx>n-1 || ty < 0 || ty > m-1) && count != 0){
       // tp = min(tp,dfs(++t,tx,ty,--count));
        dfs(++t,tx,ty,--count);
        t--;
    }
    // return t + tp;
    return ;
}

int main(){
    n = rd(); m = rd();
    rep(i,0,n-1){
        scanf("%s",maze[i]);
        // 要从0开始
        rep(j,0,m-1){
            if(maze[i][j] == 'S'){
                s.fi = i; s.se = j;
                // cout<< s.fi << " " << s.se <<endl;
            }
            if(maze[i][j] == 'E'){
                t.fi = i; t.se = j;
                // cout<< t.fi << " " << t.se <<endl;
            }

        }
        // rep(j,0,m-1) cout<< maze[i][j];
    }
    // 后面要用n - 1,m-1去飞行器

    dfs(0,s.fi,s.se,5);

    cout<< ans <<endl;

    return 0;
}

/*
4 4
#S..
E#..
#...
....

4
*/
