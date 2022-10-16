#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
看题意应该是个并查集.
好久没有写了，有点忘了并查集怎么写了...看下题解吧.
看了一下题解，是并查集忘了用递归了...以及并查集一套的连接操作也忘了...汗颜...还是孰能生巧

然后还有染色的BFS，DFS两种做法，都可以看看

链接：https://leetcode.cn/problems/possible-bipartition/solutions/1893341/ke-neng-de-er-fen-fa-by-leetcode-solutio-guo7/
*/
class Solution {
    unordered_map<int, int> fa_map;
public:
    // int findFa(int node) {
    //     if (fa_map.find(node) == fa_map.end()) {
    //         return fa_map[node] = node;
    //     }
    //     fa_map[node] = fa
    //     return 
    // }
    int findFa(int x, vector<int>& fa) {
        return fa[x] < 0 ? x : fa[x] = findFa(fa[x], fa);
    }

    void unit(int x, int y, vector<int>& fa) {
        x = findFa(x, fa);
        y = findFa(y, fa);
        if (x == y) {
            return ;
        }
        if (fa[x] < fa[y]) {
            swap(x, y);
        }
        fa[x] += fa[y];
        fa[y] = x;
    }

    bool isconnect(int x, int y, vector<int>& fa) {
        x = findFa(x, fa);
        y = findFa(y, fa);
        return x == y;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> fa(n + 1, -1);
        vector<vector<int>> g(n + 1);
        for (auto& p : dislikes) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                unit(g[i][0], g[i][j], fa);
                if (isconnect(i, g[i][j], fa)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    
    
    return 0;
}