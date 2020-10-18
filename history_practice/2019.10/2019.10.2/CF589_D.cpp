/* 
2019年10月02日19:38:47 开始看题
2019年10月02日19:54:37 没有想出怎么暴力,图论自己太弱,所以看tutorial去

2019年10月02日20:21:15 直接理解玩tutorial直接交了tutorial...没有重写,下不为例!

https://codeforces.com/blog/entry/70162
 */
// Standard libraries
#include <stdio.h>
#include <vector>
#include <set>
 
// Main
int main(int argc, char **argv){
 
#ifdef __McDic__ // Local testing I/O
    freopen("VScode/IO/input.txt", "r", stdin);
    freopen("VScode/IO/output.txt", "w", stdout);
#endif
 
    // Get input
    int v, e; scanf("%d %d", &v, &e);
    std::vector<std::set<int>> edges(v+1);
    for(int i=0; i<e; i++){
        int e[2]; scanf("%d %d", e, e+1);
        edges[e[0]].insert(e[1]);
        edges[e[1]].insert(e[0]);
    }
 
    // Assign groups
    std::vector<int> group(v+1, -1);
    // 找出三组值
    for(int g = 0; g < 3; g++){
        
        // Find first point of group
        int first;
        for(first=1; first<=v; first++) if(group[first] == -1) break;
        if(first == v+1){ printf("-1\n"); return 0;} // All are in some group
 
        // Group settings
        group[first] = g;
        // 不直接相连的就可以加到自己的团集之中
        for(int second = 1; second <= v; second++) if(first != second && group[second] == -1 
        && edges[first].find(second) == edges[first].end()) group[second] = g;
    }
 
    // All vertices should be in some group
    std::vector<std::vector<int>> groups(3);
    for(int now=1; now<=v; now++){
        if(group[now] == -1){ printf("-1\n"); return 0;} // Non grouped vertex exist
        else groups[group[now]].push_back(now);
    }
 
    // Edge counting
    int found_edges = 0;
    for(int g1=0; g1<3; g1++){
        for(int g2=g1+1; g2<3; g2++){
            for(int v1: groups[g1]) for(int v2: groups[g2]){
                if(edges[v1].find(v2) == edges[v1].end()){ printf("-1\n"); return 0;} // Non complete bipartite
                else found_edges++;
            }
        }
    }
 
    // Edge validation
    if(found_edges != e){ printf("-1\n"); return 0;} // Remaining edges detected
    for(int now=1; now<=v; now++) printf("%d ", group[now] + 1); // OK!!
    return 0;
}