// 2019年6月14日11:13:17 再次认真看题,感觉这个题意还是不是很理解

// 2019年6月14日11:51:39 总算读懂了,就是root到每两个距离相同的点---> 那两个点周围的边数都是一样的就行了
// 2019年6月14日14:43:53 中途休息了两个小时后又开始看，发现看D题真复杂
// 2019年6月14日14:55:45 决定花30mins认真看完(先找个短码看一下先)
// 这里是McDic的方法
// 2019年6月14日17:50:27 总算看完了,17:50-13:50===4个多小时，而且还仅仅是理解！我太菜了啊！
#include<stdio.h>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;

// Graph attributes
typedef vector<set<int>> EDGE;
int v;
vector<bool> isInner;
EDGE edges, inneredges;

// Validation
bool validate(int root){
    //printf("Validating for %d\n", root);
    vector<bool> visited(v+1, false);
    vector<int> nowlook = {root};
    while(!nowlook.empty()){
        set<int> degrees;
        vector<int> nextlook;
        for(auto now: nowlook) visited[now] = true;
        for(auto now: nowlook){
            for(auto next: edges[now]){
                if(!visited[next]){
                    nextlook.push_back(next);
                    degrees.insert(edges[next].size());
                    if(degrees.size() >= 2) return false;
                }
            }
        } nowlook = nextlook;
    } return true;
}

// Calculate distances for directly reachable nodes. -1 for not set.
void directDistanceCalculation(int now, vector<int> &distance){
    for(auto next: edges[now]){
        if(distance[next] == -1 && edges[next].size() <= 2){
            distance[next] = distance[now]+1;
            directDistanceCalculation(next, distance);
        }
    }
}

int main(void){
    // Get input and construct tree
    scanf("%d", &v);
    edges.resize(v+1); // v个点，v+1个边
    isInner.resize(v+1, true);
    for(int i=1; i<v; i++){
        int u1, u2; scanf("%d %d", &u1, &u2);
        edges[u1].insert(u2);
        edges[u2].insert(u1);
    } inneredges = edges;

    // Construct inner tree
    //printf("Constructing inner tree:\n");
    for(int start=1; start<=v; start++){
        if(edges[start].size() == 1 && inneredges[start].size() == 1){ // 集合数组,每一个元素都是一个集合
            int now = start; // 每一个点都进行了滚动删除
            while(edges[now].size() <= 2 && inneredges[now].size() == 1){// inneredge为1,而外界为直连，可以直接减掉
                //printf("Removing %d\n", now);
                int next = *(inneredges[now].begin());// begin是个迭代器，然后*是解引用，所以得到的是now的邻接点
                inneredges[now].clear();// 清理掉外围的
                inneredges[next].erase(now);  // 邻接点也擦去自己
                isInner[now] = false;
                now = next;// 每一个点都进行了滚动删除
            }
        }
    }

    // Corner case: No inner tree => See leaf
    //printf("Let's see if this is corner case\n");
    int innervertices = 0;
    vector<int> leaves;
    for(int u=1; u<=v; u++){
        if(isInner[u]) innervertices++;
        if(edges[u].size() == 1) leaves.push_back(u);
    }
    if(innervertices == 0){// 因为上面的每一个点都进行了滚动删除
        //printf("ok no inner\n");
        for(auto leaf: leaves){
            if(validate(leaf)){
                printf("%d\n", leaf);
                return 0;
            }
        }
        throw "???";
    }

    // Collapse inner tree
    //printf("Let's collapse inner tree\n");
    vector<bool> collapseVisited(v+1, false);
    vector<int> nowlook;
    for(int u=1; u<=v; u++) if(isInner[u] && inneredges[u].size() <= 1) nowlook.push_back(u);
    while(nowlook.size() >= 2){
        set<int> nextlook;
        for(auto now: nowlook) collapseVisited[now] = true;
        for(auto now: nowlook) for(auto next: inneredges[now]) if(!collapseVisited[next]) nextlook.insert(next);
        nowlook.clear();
        for(auto next: nextlook) nowlook.push_back(next);
    }

    // Corner case 2: No semitop
    if(nowlook.empty()){
        printf("-1\n");
        return 0;
    }

    // Semitop validation
    int semitop = nowlook[0];
    //printf("Ok semitop is %d\n", semitop);
    if(validate(semitop)){
        printf("%d\n", semitop);
        return 0;
    }

    // Calculate distances for directly reachable leaves
    vector<int> dirDist(v+1, -1);
    dirDist[semitop] = 0;
    directDistanceCalculation(semitop, dirDist);
    vector<pair<int, int>> directLeaves;
    for(int u=1; u<=v; u++){
        if(edges[u].size() == 1 && dirDist[u] != -1) // 就是可以当做semiroot根节点的点
            directLeaves.push_back({dirDist[u], u});
    } sort(directLeaves.begin(), directLeaves.end());

    // Validate for the furthest leaf and the closest leaf
    if(!directLeaves.empty()){
        int closestLeaf = directLeaves.front().second;
        int furthestLeaf = directLeaves.back().second;
        if(validate(closestLeaf)){
            printf("%d\n", closestLeaf);
            return 0;
        }
        else if(validate(furthestLeaf)){
            printf("%d\n", furthestLeaf);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}




// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+50;
// int n,x,y,ver[N*2],nxt[N*2],head[N],tot,zh,s[N],p[N],now=1e9,du[N],mp[N];
// void add(int x,int y){
//     ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;du[y]++;
// }
// void dfs(int x,int fa){
//     s[x]=1;int maxn=0;
//     for(int i=head[x];i;i=nxt[i]){
//         int y=ver[i];
//         if(y==fa)continue;
//         dfs(y,x);
//         s[x]+=s[y];maxn=max(maxn,s[y]);
//     }
//     int dat=max(maxn,n-s[x]);
//     if(dat<now)zh=x,now=dat;
// }
// bool check(int x,int fa,int dis){
//     if(!fa)memset(p,0,sizeof(p));
//     if(!p[dis])p[dis]=du[x];
//     else if(du[x]!=p[dis])return 0;
//     for(int i=head[x];i;i=nxt[i]){
//         int y=ver[i];
//         if(y==fa)continue;
//         if(!check(y,x,dis+1))return 0;
//     }
//     return 1;
// }
// void find(int x){printf("%d\n",x);exit(0);}
// void dfs2(int x,int fa,int dis){
//     if(du[x]==1)mp[dis]=x;
//     for(int i=head[x];i;i=nxt[i]){
//         int y=ver[i];
//         if(du[y]>2||y==fa)continue;
//         dfs2(y,x,dis+1);
//     }
// }
// int main(){
// //  freopen("data.txt","r",stdin);
// //  freopen("my.txt","w",stdout);
//     scanf("%d",&n);
//     for(int i=1;i<n;i++){
//         scanf("%d%d",&x,&y);
//         add(x,y);add(y,x);
//     }
//     dfs(1,0);
//     if(check(zh,0,0))find(zh);
//     dfs2(zh,0,0);
//     for(int i=n;i>=0;i--)if(mp[i]){
//         if(check(mp[i],0,0))find(mp[i]);
//         break;
//     }
//     for(int i=0;i<=n;i++)if(mp[i]){
//         if(check(mp[i],0,0))find(mp[i]);
//         break;
//     }
//     find(-1);
//     return 0;
// }