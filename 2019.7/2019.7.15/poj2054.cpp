/*
2019年7月15日16:13:32 感觉虽然 算法书 上讲了思路，但是自己并不会实现，所以还是得借鉴一下大佬的
大佬一的代码有点晕，所以用大佬2的：

犀利的贪心，开始完全没有正确贪心的思路。

还是看了网上的题解。

根据这种题目，肯定我们首先考虑最大的c，可是由于有父节点的限制，但是对于某个最大的c，它必定是紧随父节点之后，这样便可以把这两个节点合并成一个节点，c表示集合的权值，num表示节点的个数，我们利用c/num进行权衡。

pre表示父节点

next,start采用前向星存储
---------------------
作者：acm_cxlove
原文：https://blog.csdn.net/ACM_cxlove/article/details/7720218

2019年7月15日17:35:27 还是有点迷糊，决定先去吃饭...
 */

// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
// using namespace std;
// #define ll long long
// int N,R;

// int main(){
//     ios::sync_with_stdio(false);
//     while(cin>>N>>R && !(N==0&&R==0)){

//     }
//     return 0;
// }

// 此代码有点迷
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #define clr(a, b) memset(a, b, sizeof(a))
// #define maxn 1000
// using namespace std;
// int da[maxn + 10], fa[maxn + 10];
// int suf[maxn + 10], ta[maxn + 10], s[maxn + 10], c[maxn + 10];
// /*suf[i]表示选i之后选的点；ta[i]表示第一个选的点为i的点集中最后一个被选的点，s[i]为点权之和，c[i]为点的个数，i含义同前。*/
// int main()
// {
//     for (;;) {
//         int n, ro;
//         scanf("%d%d", &n, &ro);
//         if (!n)
//             break;
//         for (int i = 1; i <= n; i++) {
//             c[i] = 1;
//             ta[i] = i;
//             scanf("%d", &da[i]);
//             s[i] = da[i];
//         }
//         for (int i = 1; i < n; i++) {
//             int a, b;
//             scanf("%d%d", &a, &b);
//             fa[b] = a;
//         }
//         clr(suf, 0);
//         for (int i = 1; i < n; i++) {
//             double m = 0;
//             int k;
//             //找点权算术平均数最大的点集，注意要转成double
//             for (int j = 1; j <= n; j++)
//                 if (j != ro) {
//                     if ((double)s[j] / c[j] > m) {
//                         m = (double)s[j] / c[j];
//                         k = j;
//                     }
//                 }
//             //合并
//             s[fa[k]] += s[k];
//             c[fa[k]] += c[k];
//             //合并之后以后便不再考虑k这个点，因此清零防止重复选择
//             s[k] = 0;
//             //k的儿子也要处理
//             for (int j = 1; j <= n; j++)
//                 if (fa[j] == k)
//                     fa[j] = fa[k];
//             suf[ta[fa[k]]] = k;
//             ta[fa[k]] = ta[k];
//         }
//         int ans = 0;
//         for (int i = ro, cnt = 1; i; cnt++, i = suf[i])
//             ans += cnt * da[i];
//         printf("%d\n", ans);
//     }
//     return 0;
// }

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-6
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1 << 30
using namespace std;
struct Node {
    int idx, next;
} a[1005];
int cnt, n, root, c[1005], num[1005], pre[1005], start[1005];
bool visit[1005];
int addedge(int u, int v)
{
    a[cnt].idx = v;
    a[cnt].next = start[u];
    return cnt++;
}
int find_root()
{
    /* 找到当下等价权值最大的点 */
    double mmax = 0;
    int k;
    for (int i = 1; i <= n; i++)
        // 第一次的num值都没有变化过！所以就是比较的c[i]的值
        if (!visit[i] && (double)c[i] / num[i] > mmax && i != root) {
            mmax = (double)c[i] / num[i];
            k = i;
        }
    return k;
}
void Union(int k, int p)
{
    num[p] += num[k];
    c[p] += c[k];
    // k已经被计算，所以必须把所有以k起始的下标的地方的子节点都要标明其 爷爷 为 其 父亲---这样子它父亲就的num为2！
    for (int i = start[k]; i; i = a[i].next)
        pre[a[i].idx] = p;
}
int slove()
{
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int k = find_root();
        visit[k] = true;
        int p = pre[k];
        while (visit[p])
            p = pre[p];
        ans += num[p] * c[k];
        Union(k, p);
    }
    return ans + c[root];
}
int main()
{
    while (scanf("%d%d", &n, &root) != EOF && n + root) {
        memset(start, 0, sizeof(start));
        memset(visit, false, sizeof(visit));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
            num[i] = 1;
        }
        cnt = 1;
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            // start[u]表示u的前一个，最开始是0，所以第一个点在addedge函数中赋值其前一个为 0，之后赋值为前一个u的下标(即同u出发的下标)
            start[u] = addedge(u, v);
            pre[v] = u;
        }
        printf("%d\n", slove());
    }
    return 0;
}