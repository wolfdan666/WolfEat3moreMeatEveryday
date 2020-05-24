#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int maxn=2e3;
const int maxm=2e6+5;
const int INF=0x3f3f3f3f;
struct Edge{
    int v,flow,w,nxt;
    Edge(){}
    Edge(int v,int flow,int w,int nxt):v(v),flow(flow),w(w),nxt(nxt){}
}edge[maxm];
int cnt;
int head[maxn];
int pre[maxn],dis[maxn];
bool vis[maxn];
void add(int u,int v,int flow,int w){
    edge[cnt]=Edge(v,flow,w,head[u]);
    head[u]=cnt++;
    edge[cnt]=Edge(u,0,-w,head[v]);
    head[v]=cnt++;
}
queue<int> q;
bool spfa(int s,int e){
    for(int i=s;i<=e;i++) dis[i]=INF,pre[i]=-1,vis[i]=false;
    vis[s]=true;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];~i;i=edge[i].nxt){
            if(!edge[i].flow) continue;
            int v=edge[i].v,w=edge[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return ~pre[e];
}
int mcmf(int s,int e){
    int flow,cost;
    flow=cost=0;
    while(spfa(s,e)){
        int k=INF;
        for(int i=pre[e];~i;i=pre[edge[i^1].v]){
            k=min(k,edge[i].flow);
        }
        for(int i=pre[e];~i;i=pre[edge[i^1].v]){
            edge[i].flow-=k;
            edge[i^1].flow+=k;
            cost+=k*edge[i].w;
        }
        flow+=k;
        // cost+=k*dis[e];
    }
    return cost;
}

int G[maxn][maxn];
int main(){
    int T,n,m,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&G[i][j]);
            }
        }
        int s=0,t=n+m+1;
        cnt=0;
        for(int i=s;i<=t;i++) head[i]=-1;
        for(int i=1;i<=n;i++) add(0,i,1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                add(i,n+j,1,-G[i][j]);
            }
        }
        for(int i=1;i<=m;i++) add(n+i,t,k,0);
        int ans=mcmf(s,t);
        printf("%d\n",-ans);
    }
}