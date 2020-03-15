/*
2020年3月15日15:07:02 理解题意5分钟，发现是一个简单的bfs的题目

2020年3月15日15:29:17 AC了，一开始用LeetCode的console跑测试样例全是0，还人肉找了会bug
结果花了8分钟后觉得没问题就交了，odk
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

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        if(r == 0) return 0;

        int c = grid[0].size();
        memset(vis,0,sizeof(vis));
        int ans = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j]) ans = max(ans,bfs(i,j,r,c,grid));
            }
        }

        return ans;
    }

    int bfs(int x,int y,int r,int c,vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= r || y >= c ||
            vis[x][y] || grid[x][y] == 0) return 0;

        vis[x][y] = 1;
        int tp = 1;
        for(int i = 0; i < 4; i++){
            tp += bfs(x+a[i],y+b[i],r,c,grid);
        }

        return tp;
    }

private:
    bool vis[51][51];
    int a[4] = {0,0,1,-1};
    int b[4] = {1,-1,0,0};
};

int main(){


    return 0;
}