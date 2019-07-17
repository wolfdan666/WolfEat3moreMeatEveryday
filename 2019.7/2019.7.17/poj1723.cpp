/*
2019年7月17日21:42:39 开始看题
最小的步数,这个最终的y肯定是中位数，因为上移或者下移一点的话就都会变成是对多数人来说要移动，会导致值变得更加大了
然后x左右同理

所以直接sort左右，然后左右直接填入.中途碰撞可以看作后面的人先走，但是好像还是有点风险,不会，因为中位已经确定好了的原因

解法:直接sort后算？
2019年7月17日21:55:00 开始试写

2019年7月17日22:19:13 现实很惨地wa了

2019年7月17日22:45:07 想找个大佬的代码交一下看看是不是系统出问题了..结果大佬的空格自带bug... 改了我好久...


2019年7月17日22:50:18 发现自己mdzz 了，x方向根本不同理好吗！   如果你2个数分散在左边，3个数在右边一条线，你用中位数，然后右边的3个点中还有两个点要移动，是不是很傻！
所以只要左右两点向中间靠拢就行，可以以 {a[0]->a[n]-(n-1)} 这里面的任意一条线做左边的基准线！  所以采用大佬的写法

啊，这么垃圾的签到题也写了1小时13mins，多多训练吧
*/

// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// const int M = 1e4 + 10;
// typedef pair<int, int> P;
// vector<P> a;
// int b[M], n, ans, x;
// bool cmp(P a, P b) { return a.first < b.first; }

// int main(int argc, char const* argv[])
// {
//     ios::sync_with_stdio(false);
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> x >> b[i];
//         a.push_back({ x, b[i] });
//     }
//     sort(b, b + n);
//     int tmpy = b[n / 2];
//     sort(a.begin(), a.end(), cmp);

//     // for(int i=0;i<n;i++) cout<<a[i].first<<endl;

//     int tmpx = a[n / 2].first;
//     int ttmpx = tmpx - n / 2;
//     for (int i = 0; i < n; i++) {
//         ans += abs(a[i].first - (ttmpx + i)) + abs(a[i].second - tmpy);
//         cout << abs(a[i].first - (ttmpx + i)) << endl;
//     }
//     cout << ans << endl;
//     return 0;
// }

/*
x方向和y方向分开讨论。

1  y方向：

要使士兵最后位于同一水平线，则最终所有士兵的y坐标相同。

将所有坐标的y值从小到大排序，对于首尾两个y值，移动到它们之间的任何y值所需要的步数是相同的，所以 最终的y值取中位数。

y方向的步数y_steps=|y[0]-y_mid|+|y[1]-y_mid|+...+|y[n-1]-y_mid|，y_mid=y[n/2]。

2  x方向：

x方向稍微复杂点，先对所有x坐标从小到大排序，由于要移动步数最少，所以最终的x坐标相对位置与排序后的x坐标相对位置相同。

----------------AC-------------------------
作者：_Greenday_
原文：https://blog.csdn.net/zzucsliang/article/details/20923113
*/
#include <algorithm>
#include <cstdio>

int main()
{
    int n, x[10001], y[10001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);
    std::sort(x, x + n);
    std::sort(y, y + n);
    for (int i = 0; i < n; i++)
        x[i] -= i;
    std::sort(x, x + n);
    int s = 0;
    for (int i = 0; i < n / 2; i++)
        s += x[n - 1 - i] - x[i] + y[n - 1 - i] - y[i];
    printf("%d\n", s);
    return 0;
}
