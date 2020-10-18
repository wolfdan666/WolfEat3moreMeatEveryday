/*
q的值比较小，所以解题应该从q入手
用并查集模拟实现一个链表
用map模拟并查集，初始时每个点的父亲指向后面第一个可用的点。
当删除一个点i时，令x的父亲等于x+1的父亲
查询时直接输出 x 的父亲
*/

/*
被删除过就直接找他们的父亲
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 100;
unordered_map<int, int> fa;

int findfa(int x) {
    if (!fa.count(x)) return x;
    return fa[x] = findfa(fa[x]);
}


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    int op, x;
    while (q--) {
        scanf("%d %d", &op, &x);
        if (op == 1) {
            fa[x] = findfa(x + 1);
        } else {
            int ans = findfa(x);
            if (ans > n) ans = -1;
            printf("%d\n", ans);
        }
    }
    return 0;
}