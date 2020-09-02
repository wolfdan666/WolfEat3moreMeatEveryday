/*
室友7点40回来打电话打游戏....

2020年9月2日20:02:04 开始看题

2020年9月2日20:02:58 感觉就是不连通的s的个数
2020年9月2日20:05:05 可以速写
2020年9月2日20:30:58 AC
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
const int M = 1024;

char maze[M][M];
bool vis[M][M];
int n,m;
int a[4] = {1,-1,0,0};
int b[4] = {0,0,1,-1};

void dfs(int i,int j) {
    if (vis[i][j] || maze[i][j] != 'S') return;
    vis[i][j] = true;
    rep(k,0,3){
        if(i+a[k] > 0 && i+a[k] <= n &&
            j+b[k] > 0 && j+b[k] <= m) {
            dfs(i+a[k], j+b[k]);
        }
    }
}

int main(){
    // n = rd(); m = rd();
    scanf("%d,%d",&n,&m);
    rep(i,1,n) scanf("%s", maze[i]+1);
    int ans = 0;


    // rep(i,1,n){
    //     rep(j,1,m){
    //         cout<< maze[i][j];
    //     }
    //     cout<<endl;
    // }

    // rep(i,1,n){
    //     rep(j,1,m){
    //         if(vis[i][j]) cout<< 1;
    //         else cout<<0;
    //     }
    //     cout<<endl;
    // }

    rep(i,1,n){
        rep(j,1,m){
            if(vis[i][j] || maze[i][j] != 'S') continue;
            dfs(i,j);
            ans++;

            // printf("i = %d, j = %d : \n", i, j );
            // rep(q,1,n){
            //     rep(p,1,m){
            //         if(vis[q][p]) cout<< 1;
            //         else cout<<0;
            //     }
            //     cout<<endl;
            // }
        }
    }
    printf("%d\n", ans);

    return 0;
}