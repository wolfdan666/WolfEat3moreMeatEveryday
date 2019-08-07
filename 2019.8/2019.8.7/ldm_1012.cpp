/*赛时514ms，赛后TLE，佛了评测机，签到暂时不重写先
赛后无限T...
傻逼了，交到了1001去了，竟然不是wa，因为数据问题，然后题目名还相似...
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

struct node {
    int id;
    ll v;
    bool operator < (const node& r) const { return v < r.v; }
};

priority_queue<node> q;
ll a[maxn];
vector<int> G[maxn];
int d[maxn];
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            G[i].clear();
            d[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            if(2*i > n) break;
            if(2*i <= n) { G[2*i].push_back(i); d[i]++; }
            if(2*i+1 <= n) { G[2*i+1].push_back(i); d[i]++; }
        }
        /*先把所有的叶子节点都丢进去优先队列*/
        for(int i = n/2+1; i <= n; i++) q.push({i, a[i]});
        ll ans[2] = {0}; int cur = 0;
        /*然后这里把所有父亲丢进大根堆,优先队列*/
        while(!q.empty()) {
            node tp = q.top(); q.pop();
            //cout<<tp.v<<" "<<tp.id<<endl;
            ans[cur] += tp.v;
            cur ^= 1;
            int u = tp.id;
            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                d[v]--;
                if(d[v] == 0) q.push({v, a[v]});
            }
        }
        printf("%lld %lld\n", ans[0], ans[1]);
    }

    return 0;
}