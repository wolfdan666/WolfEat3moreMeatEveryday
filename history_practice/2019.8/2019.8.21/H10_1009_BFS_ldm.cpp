/*
只把下一次要drop丢进去才能不被卡时间
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
int cnt[M][M][2];

int main(){
    scanf("%d", &T);
    while(T--){
        memset(cnt, 0, sizeof(cnt));
        memset(drop,0,sizeof(drop));
        scanf("%d%d%d", &n, &m, &query);
        while(query--){
            ans = 0;
            scanf("%d%d", &x, &y);
            if(drop[x][y]){ printf("%d\n", ans); continue;}
            ans++; drop[x][y]=true;
            q.push({x,y});
            while(!q.empty()) {
                int tx=q.front().first,ty=q.front().second; q.pop();
                for(int i=0;i<4;i++){
                    int ttx=tx+a[i],tty=ty+b[i];
                    if(ttx<1||n<ttx||tty<1||m<tty) continue;
                    cnt[ttx][tty][i/2]++;
                    /*自己曾经没有掉落过，然后别人给它贡献过横竖方向的掉落，那么它就会掉落*/
                    if(!drop[ttx][tty] && cnt[ttx][tty][0] && cnt[ttx][tty][1]) {
                        drop[ttx][tty] = 1; ans++;
                        q.push({ttx,tty});
                    }
                }
                //if(cnt[tx][ty][0] && cnt[tx][ty][1] && !drop[tx][ty]) { drop[tx][ty] = 1; ans++; }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}