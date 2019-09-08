/*
我想出了思路，然后队友ldm快速模拟链表实现了，真爽啊！团队竞赛
走M次空格，第M+1次落下
第一个先填1
循环走
比如N = 5, M = 4;
一开始是 1 _ _ _ _
然后走4次空格，第5次落下 变成 1 2 _ _ _
之后同理得到 1 2 _ 3 _ ==> 1 2 _ 3 4 ==> 1 2 5 3 4
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 4e7 + 10;
int pos[N], nxt[N], pre[N];

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n, m, q, u, v;
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++) nxt[i] = i+1, pre[i] = i-1;
        nxt[n] = 2; pre[2] = n;
        pos[1] = 1;
        int cur = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m+1;j++) {
                cur = nxt[cur];
            }
            pos[cur] = i;
            u = pre[cur]; v = nxt[cur];
            nxt[u] = v; pre[v] = u;
        }
        scanf("%d", &q);
        while(q--) {
            scanf("%d", &u);
            printf("%d\n", pos[u]);
        }
    }
    return 0;
}