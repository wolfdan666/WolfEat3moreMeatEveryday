#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int n,m,ans;
int id[8];
int vis[8][8];
vector<int> G[8];

int solve(){
    int tp = 0;
    for(int u=1;u<=n;u++){
        for(auto v:G[u]){
            if(!vis[id[u]][id[v]] && id[u] <= id[v]){
                vis[id[u]][id[v]] = 1;
                tp ++;
            }
        }
    }
    return tp;
}

void iddfs(int now){
    if(now == n+1){
        memset(vis,0,sizeof vis);
        ans = max(ans,solve());
        return ;
    }
    for(int i=1;i<=6;i++){
        id[now] = i;
        iddfs(now+1);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++) if(!G[i].empty()) G[i].clear();
        ans = 0;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            // G[u].push_back(v); G[v].push_back(v);
            G[u].push_back(v); G[v].push_back(u);
        }
        iddfs(1);
        cout<<ans<<endl;
    }

    return 0;
}