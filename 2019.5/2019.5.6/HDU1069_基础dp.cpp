// 2019年5月6日19:59:26 开始看题
// 2019年5月6日20:13:44 好困,中午喝了点小酒,没看懂题意,为啥样例一不是60?看看大佬先把

// 2019年5月6日20:42:44 发现自己没有仔细看题  both！！！
// as long as the two base dimensions of the upper block were both strictly smaller than the corresponding base dimensions
// 2019年5月6日20:49:31 我的天，看别人的code，写最简单的题目都花了50mins!!!现在还困得要死，
// 状态极差，所以今天不能写代码了，这周的今天就好好休息吧，
// 从明天开始养状态然后好好准备省赛，争取队伍ak，所以自己必须较快的辅助队友完成所有签到题，然后一起讨论专题

/*
大佬：shiyicode    一个CSDN玩家，应该把kuangbin刷完了，所以我经常看到他的blog，因为我在刷kuangbin专题
每种箱子有三种放置方式且数量无限，故可将每个箱子按三个箱子看待。
对所有箱子按主长副宽进行先大后小排序，那么问题就成了求最大递增子串。
因为n的范围特别小，只有30，所以直接两重循环dp即可
*/

#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

const int N = 39;
struct Node
{
    int a, b, c;
    bool operator < (const Node &t) const
    {
        if(a == t.a)
            return b > t.b;
        return a > t.a;
    }
}node[N*3];
int dp[N*3];

void add(int i, int a, int b, int c)
{
    node[i].a = a;
    node[i].b = b;
    node[i].c = c;
}

int main()
{
    int n, T = 1;
    while(~scanf("%d", &n) && n)
    {
        for(int i=0; i<n; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(i*3, max(a, b), min(a, b), c);
            add(i*3+1, max(a, c), min(a, c), b);
            add(i*3+2, max(c, b), min(c, b), a);
        }
        sort(node, node+n*3);    // 不排序的话，for 循环的时候，可能会有大块的区别在for 未遍历的地方，这样就会导致出错
        dp[0] = node[0].c;
        int ans = dp[0];
        for(int i=1; i<3*n; i++){
            int temp = 0;
            dp[i] = node[i].c;
            for(int j=0; j<i; j++)
            {
                if(node[i].a<node[j].a && node[i].b<node[j].b)   // both
                    temp = max(temp, dp[j]);
            }
            dp[i] += temp;   // 就是第i块为最上面的时候的最大值
            ans = max(ans, dp[i]);
        }
        printf("Case %d: maximum height = %d\n", T++, ans);
    }
    return 0;
}