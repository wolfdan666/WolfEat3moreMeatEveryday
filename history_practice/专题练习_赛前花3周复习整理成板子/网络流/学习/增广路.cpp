#define maxn 250
#define INF 0x3f3f3f3f

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct EK {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int a[maxn], p[maxn];

  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    // 去向边的id 更小
    G[from].push_back(m - 2);
    // 反向边的id 更大
    G[to].push_back(m - 1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    for (;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          // 没有访问过，并且还有剩余
          // 用e.cap > e.flow来控制不访问原来的路径(这里要联系整体的意义来理解)
          if (!a[e.to] && e.cap > e.flow) {
            // 标记 e.to 的来边id
            p[e.to] = G[x][i];
            // 标记 e.to 的来边上贯穿着的最大流(贯穿着的最大流是经历的边中的最小剩余量)
            a[e.to] = min(a[x], e.cap - e.flow);
            Q.push(e.to);
          }
        }

        // bfs只要访问过a[t]就跳出吗？ 这里有点点疑问----因为每找到一条路来一次增广

        if (a[t]) break;
      }
      // dst到不了,直接break,flow等于0了
      if (!a[t]) break;

      // 从dst 到 src 倒转都加上a[t]的流？？？ ---
      // 对的，初始流为0，然后没找到一条路增广一次，之后用e.cap > e.flow来控制不访问原来的路径

      for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};