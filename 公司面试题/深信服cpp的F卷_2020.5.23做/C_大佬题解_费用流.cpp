/*
2020年5月23日21:59:33 3个小时之前我在 深信服 群里问了这个题
然后同为ACM的同一届的杭电大佬就去写了一发，然后发出了题解，太强了
感谢

主要是一般都是ldm写图论，所以自己好就没写过了...

链接：https://www.nowcoder.com/questionTerminal/22db959eb35946a78b8888d681fb9c2a?toCommentId=6197825
来源：牛客网


链接：https://www.nowcoder.com/questionTerminal/22db959eb35946a78b8888d681fb9c2a?toCommentId=6197825
来源：牛客网

比较明显的费用流题，建图，超级源点向n个人的点连边，每条边费用为0，流量为1,n个人点向m个岗位点的点连边，流量为1，费用为-A[i][j]，
最后，每个岗位点向超级汇点连边，费用为0，流量为k.跑最小费用最大流，然后费用流答案取负就是最后答案。

---

每一段都是要达到最大流k,所以是最大流,否则可以不取k个

2020年5月24日21:12:13 学完最大流的基本概念之后，就懂了题解的意思了，所以还是继续学一下mcmf的板子吧
*/
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

// u -> v的边 , 这是把边和点一起添加
// 它这个head[*] = -1的操作是和模板中的 for(*;~i;*)绑定在一起的

// 但是我实在是没看懂哪有体现了 u -> v 的边
// 好像是因为nxt是反向边的节点，就是表示一条边的from
// 想了好久，终于有点眉目了，0,1是一组边，head[u]表示u的来边-1
// 在main中，head[0] 有 -1,0,2,4,6 ... 等等值
// 这个模板的这个边结构让人晕头转向，2020年5月24日22:15:23 看了60分钟还是晕，所以还是先歇会吧
// 2020年5月24日22:20:11 决定描绘一遍正向边的形成
/*
for(int i=s;i<=t;i++) head[i]=-1;
for(int i=1;i<=n;i++) add(0,i,1,0);
v  head[u]
1  head[0]=-1  之后 head[0]=0 cnt=2   --- edge[0] 是一条边
2  head[0]=0   之后 head[0]=2 cnt=4   --- edge[2] 是一条边
3  head[0]=2   之后 head[0]=4 cnt=6   --- edge[4] 是一条边
4  head[0]=4   之后 head[0]=6 cnt=8

**其实是先有edge[cnt] 然后 把 head[u] 指向 edge[cnt], 之后再cnt++**

然后 2020年5月24日22:28:11 去看spfa中的用法
for(int i=head[u];~i;i=edge[i].nxt)

2020年5月24日22:30:28 突然懂了，其实head[i]的变动，固化成为一个链在edge的nxt中，这样就可以溯源
然后发现了跳转之后可以获得来边的队列！father树--- ---
所以多点~~汇聚~~发散一点时，head构建了一个~~来~~出边队列

所以就是 head[u] 指向 u的~~来~~出 边id ,然后这个边id中的v是 边id的~~起~~终点端,  边id的nxt是 u的上一个~~来~~出边，如果上一个~~来~~出边没有则为-1 ！
精妙的结构，让我看了90分钟( 由于没有注释，没有去找好的教程，直接自己头铁理解 )

2020年5月24日22:57:01 发现我一开始脑子有点糊，其实不是汇聚，是发散，不是来边，是出边
*/

void add(int u,int v,int flow,int w){
    edge[cnt]=Edge(v,flow,w,head[u]);
    head[u]=cnt++;
    edge[cnt]=Edge(u,0,-w,head[v]);
    head[v]=cnt++;
}

// 这是从~~终~~起点到~~起~~终点的最短路，其实都是一样的，和 迪杰特斯拉 和 Bellman-fold 算法有相同的灵魂
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
    // 前一条边不为-1则为true
    return ~pre[e];
}
int mcmf(int s,int e){
    int flow,cost;
    flow=cost=0;
    while(spfa(s,e)){
        int k=INF;
        // 反向边的终点 == 原来边的起点
        // 其实这一题到起点，k 最小流 肯定是 1
        for(int i=pre[e];~i;i=pre[edge[i^1].v]){
            k=min(k,edge[i].flow);
        }
        for(int i=pre[e];~i;i=pre[edge[i^1].v]){
            edge[i].flow-=k;
            edge[i^1].flow+=k;
            // 这里是因为题目特性把 cost移到外面加和了，其实也可以这里加，外面不加
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
