#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 110;
int n,m;
int c[M],topo[M],t,G[M][M];

bool dfs(int u){
    c[u] = -1;
    for(int v=0;v<n;v++) if(G[u][v]){
        if(c[v]<0) return false;
        else if(!c[v]&&!dfs(v)) return false;
    }
    c[u] = 1;topo[--t]=u+1;
    return true;
}

/*题目保证了只有一种拓扑线路
其实这样子写可以处理多种拓扑路线*/
bool toposort(){
    t = n;
    memset(c,0,sizeof(c));
    for(int u=0;u<n;u++) if(!c[u])
        if(!dfs(u)) return false;
    return true;
}

int main(){
    // ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n>>m){
        if(n==0) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                G[i][j] = 0;
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            G[u-1][v-1]++;
        }
        if(toposort())
            for(int i=0;i<n;i++){
                cout<<topo[i]<<" \n"[i==n-1];
            }
    }


    return 0;
}