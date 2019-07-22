/*最短路+网络流*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 1e18;
const int maxn = 10000 + 5;

struct qnode{
    int v;
    ll c;
    bool operator < (const qnode& r) const { return c > r.c; }
};

struct Edges {
    int v;
    ll cost;
    int cnt;
};
vector<Edges> E[maxn];
bool vis[maxn];
ll dist[maxn];

void dijkstra(int n) {
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) dist[i] = inf;
    priority_queue<qnode> q;
    dist[n] = 0;
    q.push(qnode{n, 0});
    qnode tp;
    while(!q.empty()) {
        tp = q.top(); q.pop();
        int u = tp.v;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < E[u].size(); i++) {
            int v = E[tp.v][i].v;
            ll cost = E[u][i].cost;
            if(!vis[v] && dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                q.push(qnode{v, dist[v]});
            }
        }
    }
}

void addEdge(int u, int v, ll w) {
    E[u].push_back(Edges{v, w, 0});
}

const int M = 2e4 + 10;
const int N = 1e4 + 10;

struct edge{
    int to, nxt;
    ll flow, cap;
}es[M];
int tot;
int head[N];
void init(){
    tot = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w){
    es[tot].to = v; es[tot].cap = w; es[tot].flow = 0; es[tot].nxt = head[u]; head[u] = tot++;
    es[tot].to = u; es[tot].cap = 0; es[tot].flow = 0; es[tot].nxt = head[v]; head[v] = tot++;
}
int dep[N], cur[N], Q[N];
bool bfs(int s, int t, int n){
    int front = 0, tail = 0;
    memset(dep, -1, sizeof(dep[0])*(n+1));
    dep[s] = 0;
    Q[tail++] = s;
    while(front < tail){
        int u = Q[front++];
        for(int i = head[u]; i != -1; i = es[i].nxt){
            int v = es[i].to;
            if(es[i].cap > es[i].flow && dep[v] == -1){
                dep[v] = dep[u]+1;
                if(v == t) return true;
                Q[tail++] = v;
            }
        }
    }
    return false;
}
ll dfs(int x, int t, ll a){
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int &i = cur[x]; i != -1; i = es[i].nxt){
        int v = es[i].to;
        if(dep[x]+1 == dep[v] && (f = dfs(v, t, min(a, es[i].cap-es[i].flow))) > 0){
            es[i].flow += f;
            es[i^1].flow -= f;
            flow += f;
            a -= f;
            if(a == 0) break;
        }
    }
    return flow;
}

ll dinic(int s, int t, int n){
    int flow = 0;
    while(bfs(s, t, n)){
        for(int i = 0; i <= n; i++) cur[i] = head[i];
        flow += dfs(s, t, inf);
    }
    return flow;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) E[i].clear();
        for(int i = 0; i < m; i++) {
            int u, v; ll w;
            scanf("%d%d%lld", &u, &v, &w);
            addEdge(v, u, w);
        }
        dijkstra(n);
        init();
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < E[i].size(); j++) {
                int u = i, v = E[i][j].v;
                if(dist[v] == dist[u] + E[i][j].cost) {
                    addedge(u, v, E[i][j].cost);
                }
            }
        }
        ll ans = dinic(n, 1, n+5);
        printf("%lld\n", ans);
    }

    return 0;
}