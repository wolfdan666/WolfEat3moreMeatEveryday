/*
忘了q.pop()卡了一会..
我T--后的新结果会出错...drop初始化写成了vis...复制...
然后mem TLE 改成 for TLE...
O(qnm)不行... cd说对了..

要去掉vis数组的所有操作,因为太卡时间了...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 2010;
int T,query,n,m,x,y,ans;bool vis[M][M],drop[M][M];
typedef pair<int,int> P;
queue<P> q;
int a[4] = {0,0,1,-1};
int b[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        /*每个样例只掉一次*/
        // memset(drop,0,sizeof(drop));

        cin>>n>>m>>query;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) drop[i][j]=0;
        while(query--){
            ans = 0;
            cin>>x>>y;
            /*每次敲vis都要更新*/
            // memset(vis,0,sizeof(vis));
            for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) vis[i][j]=0;

            if(drop[x][y]){cout<<ans<<endl;continue;}
            /*敲的第一下,自己会掉落*/
            vis[x][y]=true; ans++; drop[x][y]=true;
            q.push({x,y});
            while(!q.empty()){
                int tx=q.front().first,ty=q.front().second; q.pop();
                int cnt[2]={0,0};
                for(int i=0;i<4;i++){
                    int ttx=tx+a[i],tty=ty+b[i];
                    if(ttx<1||n<ttx||tty<1||m<tty) continue;
                    if(drop[ttx][tty]){ cnt[i/2]++;continue;}
                    if(vis[ttx][tty]){ continue;}
                    else{
                        q.push({ttx,tty});
                        vis[ttx][tty]=true;
                    }
                }
                if(!drop[tx][ty]&&cnt[0]&&cnt[1]) ans++,drop[tx][ty]=true;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}