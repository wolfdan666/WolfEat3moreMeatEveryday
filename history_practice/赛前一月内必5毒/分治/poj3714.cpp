/*
2019年7月15日20:46:50 开始看题
2019年7月15日20:52:09 n个站点，n个兵，求任意一个兵离任意一个站点的最小距离！

我的思路是 O(n^2) 暴力枚举.. min( abs(x-a)+abs(y-b) ).然后就可以 long double 勾股定理

2019年7月15日20:57:59 决定看看为什么分治，如何分治

大佬说数据强一点，O(n^2)会挂

所以借鉴了大佬的讲解和代码
https://blog.csdn.net/C20190102/article/details/75174569
https://blog.csdn.net/C20190102/article/details/75174797

 */

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define MAXN 100000
#define INF 0x7fffffff
struct point {
    double x, y;
    int f; //点的“阵营”
} a[MAXN * 2 + 5]; //注意是两倍
int N;
int t[MAXN * 2 + 5];
/*以下是“求平面最小点对”的模板*/
bool cmp1(point x, point y) { return x.x < y.x; }
bool cmp2(int x, int y) { return a[x].y < a[y].y; }

double dis(point x, point y)
{
    if (x.f == y.f)
        return INF; //f一样则返回极大值
    return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}

double F(int l, int r)
{
    if (r - l == 0)
        return INF;
    if (r - l == 1)
        return dis(a[l], a[r]);
    int mid = (l + r) >> 1;
    double ans = min(F(l, mid), F(mid + 1, r));
    int cnt = 0;
    for (int i = l; i <= r; i++)
        if (a[i].x >= a[mid].x - ans && a[i].x <= a[mid].x + ans)
            t[++cnt] = i;
    sort(t + 1, t + cnt + 1, cmp2);
    for (int i = 1; i <= cnt; i++)
        for (int j = i + 1; j <= cnt; j++) {
            if (a[t[j]].y >= a[t[i]].y + ans)
                break;
            ans = min(ans, dis(a[t[i]], a[t[j]]));
        }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
            a[i].f = 0; //电厂
        }
        for (int i = 1; i <= N; i++) {
            scanf("%lf%lf", &a[N + i].x, &a[N + i].y);
            a[N + i].f = 1; //特工
        }
        N *= 2;
        sort(a + 1, a + N + 1, cmp1);
        printf("%.3lf\n", F(1, N));
    }
}