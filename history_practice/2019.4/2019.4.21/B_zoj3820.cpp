// 2019年4月21日20:06:37看题
// 2019年4月21日20:16:22发现是bfs  二分，直接借鉴大佬的来补题
/*
大佬 ： http://www.voidcn.com/article/p-ojlfyuje-bh.html

以前搞过图，后面换了一个组队后就没有搞过图了，因为有个老哥图玩的很溜了，所以我去开发新的地方，就玩字符串去了，不过这里还是
可以玩一下的

解题思路：
二分长度，判断是否可行。
判断长度L过程中，任选一个点作为根节点，利用bfs找出最远的点，
然后选择相隔L的节点作为第一个消防站，
然后再以这个节点为根结点进行遍历，同样也是找出最远的点，
然后再取相隔L的结点建立第二个消防站，再次进行距离的更新。
最后判断一下是否所有节点的距离都是小于等于L的。
从最远的点进行选择是为了使得最远的点到达消防站能够满足要求。
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
vector<int> e[maxn];
int p[maxn], dist[maxn];
int N, U, V;
queue<int> q;

int bfs (int u) {
    int len;
    dist[u] = 0;
    p[u] = 0;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();
        len = e[u].size();
// printf ("len:%d\n", len);
        for (int i = 0; i < len; i++) {
            if (dist[e[u][i]] > dist[u] + 1) {  // 这里应该是Floyd的最短路算法  // no ,就是简单的更新距离
// printf ("u:%d\n", e[u][i]);
                dist[e[u][i]] = dist[u] + 1;
                p[e[u][i]] = u;
                q.push(e[u][i]);
            }
        }
    }

    return u;
}

bool judge(int L) {
    if (!L) {
        if (N <= 2)
            return true;
        return false;
    }

    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    U = bfs(1);
    for (int i = 0; i < L; i++) {
        if (p[U] == 0) {
            V = U % N + 1;
            return true;
        }
        U = p[U];
    }
    //printf ("%d\n", U);

    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    V = bfs(U);
    for (int i = 0; i < L; i++) {
        if (p[V] == 0) {
            if (U == V)
                V = U % N + 1;
            return true;
        }
        V = p[V];
    }

    if (U == V)
        V = U % N + 1;
// printf ("%d %d\n", U, V);
    bfs(V);
    for (int i = 1; i <= N; i++)
        if (dist[i] > L)
            return false;
    return true;
}

void solve() {
    int l = 0;
    int r = N;
    int m;
    while (l < r) {
        m = (l + r)>>1;
        if (judge(m))
            r = m;
        else
            l = m + 1;
    }
    judge(l);
    printf ("%d %d %d\n", l, U, V);
}

int main () {

    int T;
    int u, v;
    scanf ("%d", &T);
    while (T--) {

        for (int i = 1; i <= N; i++)
            e[i].clear();
        scanf ("%d", &N);
        for (int i = 1; i < N; i++) {
            scanf ("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        solve();
    }
    return 0;
}