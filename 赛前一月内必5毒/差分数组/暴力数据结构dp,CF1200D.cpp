/*
2019年8月31日13:17:09 开始看题
2019年8月31日13:28:58 正方形 有 黑白,让一块k边长的正方形变白,求最大的行列白线数

n 2000 所以n^2 == 4e6枚举..然后再2*n检测？ ===》 真暴力啊

有点烦,银川的网络赛导致自己没有什么心情了...

2019年8月31日14:24:49 看题解发现自己这样根本不对,因为每次更改要重新计算的就是n^3 = 8e9 会TLE

2019年8月31日14:29:46 发现题解思路确实也是这样,不过做了预处理,这样就能够让n^3变成n^2(用k做的预处理...)

令白色为0，黑色为1，求前缀和，再预处理每个slide k的区间的和值是否达到了前缀和，然后就可以得出了变白行数，也就相当于要O(n^2)的预处理出
[1,n-k+1] 的 ok表(扫到这个点的时候变了几行)，后面直接调用就行，第一次预处理求出前缀和，第二次求出ok表

看看题解怎么写的把，因为现在都2019年8月31日14:41:34 ！一个小时了！

2019年8月31日16:19:46 交了大佬的题解 ---> 3小时，坑!
发现VJ上和队友之间的代码直接是共享的
*/

/*
发现一个神仙  62 ms   48 KB
写法太骚，加上自己太浪(主)==>以至于理解了大概90mins！  ===>珍惜自己的时间啊！生命啊!!!
*/
#include <bits/stdc++.h>
#define LL long long
#define db double
#define l first
#define r second
#define mk(a, b) make_pair(a, b)
#define Hzy(o) freopen(o".in", "r", stdin), freopen(o".out", "w", stdout)
using namespace std;
const int N = 2010;
int read() {
    int w = 0, f = 0; char c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') f = 1, c = getchar();
    while(c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
    return f ? -w : w;
}

int x_min[N], x_max[N], y_max[N], y_min[N], res[N], ans, base = 0;
int n, k;
char s[N];

int main() {
    n = read(), k = read();
    memset(x_min, -1, sizeof x_min);
    memset(x_max, -1, sizeof x_max);
    memset(y_max, -1, sizeof y_max);
    memset(y_min, -1, sizeof y_min);
    for(int i = 0; i < n; ++i) {
        scanf("%s", s);
        for(int j = 0; j < n; ++j)
            if(s[j] == 'B') {
                /*x_max,x_min表示B出现的左右位置！y同理是表示上下位置*/
                x_max[i] = max(x_max[i], j);
                x_min[i] = x_min[i] == -1 ? j : min(x_min[i], j);
                y_max[j] = max(y_max[j], i);
                y_min[j] = y_min[j] == -1 ? i : min(y_min[j], i);
            }
    }
    /*记录从未有B的行列*/
    for(int i = 0; i < n; ++i) {
        if(x_min[i] < 0)
            base++;
        if(y_min[i] < 0)
            base++;
    }
    for(int i = 0; i + k - 1 < n; ++i) {
        memset(res, 0, sizeof res);
        for(int j = 0; j < k; ++j) {
            /*存在这种并且B被全覆盖.所以是[最大位置-k+1起始的块,和最小位置]的这一段区间内都是可以的
            所以利用差分数组的性质，然后 让 res[最大位置-k+1起始的块]++,让 res[最小位置**+1**]--*/
            /*这里是行是满足的*/
            if(x_max[i + j] >= 0 && x_max[i + j] - x_min[i + j] < k)
                res[max(0, x_max[i + j] - k + 1)]++, res[x_min[i + j] + 1]--;
        }
        int now = res[0];
        for(int j = 0; j < k; ++j)
            /*上下是满足条件的.===>列是满足的*/
            if(y_min[j] >= i && y_max[j] <= i + k - 1)
                now++;
        ans = max(ans, now);
        for(int j = 1; j + k - 1 < n; ++j) {
            /*这里的  +=  利用的就是差分数组前缀和得到真实的值*/
            now += res[j];
            /*之前有没有消除的列，那么就要减去*/
            if(y_min[j - 1] >= i && y_max[j - 1] <= i + k - 1)
                now--;
            /*现在有新来的消除列又加回来*/
            if(y_min[j + k - 1] >= i && y_max[j + k - 1] <= i + k - 1)
                now++;
            /*每个橡皮檫的状态都要维护一次*/
            ans = max(ans, now);
        }
    }
    ans += base;
    cout << ans << endl;
    return 0;
}