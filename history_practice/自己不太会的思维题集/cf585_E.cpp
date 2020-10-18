/* 
2019年09月28日11:04:15 开始看题
2019年09月28日13:20:57 再次开始,之前只是看了个题目
2019年09月28日13:27:42 想不出来... 只想到了暴力交换位置-->这个计算出来很可能是错的-->去看tutorial
2019年09月28日13:30:56 发现tutorial是从小数据范围的变量开始分析的,也就是说,题目数据范围有点异常的时候都要给予特殊关注
2019年09月28日15:40:09 中途给xjy维修了100mins的网络服务,还是没有搞好...尽力了,所以改天再搞吧,所以就回来继续写题目了

2019年09月28日16:53:56 菜鸡历经坎坷,总算看懂了tutorial!太精妙了!太美了!写一发题解

# 题意
- 有一排有色石头,然后把相同颜色排在一起
- 能做的操作是交换相邻的石头
- 求最少的操作次数

n $\in$ [2,4⋅$10^5$]
$a_i$ $\in$ [1,20] 

# 题解
## 总体思路
通过cnt[i][j]计算出把所有的i颜色的放到j颜色前面需要做的交换次数
然后用子集dp来递推出最后的答案,就是说一开始是0种颜色之间的关系,然后慢慢得加入各种颜色进去,
每次加入一种颜色的时候就是把新的颜色放到最后面,然后这样子一直求出所有颜色放入后的最优决策,而且不重不漏!

## 为什么这样可以不重不漏?
因为我们for(1<<20-1) for(20) 的双重循环,就是已经枚举了所有的已经存在的颜色状态,然后把新的颜色放到最后的方案!
比如红黄蓝,在 红黄 状态时会有 加入蓝 (蓝在最后),同理也有 红蓝 + 黄,黄蓝 + 红! 这样就达到了不重不漏 


# 单词学习
exponential 指数的
 */
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000 * 1000 + 13;
const int M = 20 + 1;
const long long INF = 1000 * 1000 * 1000 * 1ll * 1000 * 1000 * 1000;

int n;
long long d[(1 << M)];
long long cnt[M][M];
vector<int> col[M];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        col[x].push_back(i);
    }
    // 题解前面的操作有点繁杂,所以推荐看不懂的可以看简单版AC代码
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == j) {
                continue;
            }
            if ((int)col[i].size() == 0 || (int)col[j].size() == 0) {
                continue;
            }
            int pos2 = 0;
            for (int pos1 = 0; pos1 < (int)col[i].size(); pos1++) {
                // 找到 j 在 i 的每个位置之前的位置.然后计算移动所需要的值(注意这里只要考虑两者之间的交换)
                while (true) {
                    if (pos2 == (int)col[j].size() - 1 || col[j][pos2 + 1] > col[i][pos1]) {
                        break;
                    }
                    pos2++;
                }
                if (col[i][pos1] > col[j][pos2]) {
                    cnt[i][j] += pos2 + 1;
                }
            }
        }
    }

    for (int mask = 0; mask < (1 << 20); mask++) {
        d[mask] = INF;
    }
    d[0] = 0;
    for (int mask = 0; mask < (1 << 20); mask++) {
        vector<int> was;
        for (int i = 0; i < 20; i++) {
            if (mask & (1 << i)) {
                was.push_back(i);
            }
        }
        for (int i = 0; i < 20; i++) {
            if (mask & (1 << i)) {
                continue;
            }
            long long sum = 0;
            for (int j = 0; j < (int)was.size(); j++) {
                sum += cnt[was[j]][i];
            }
            int nmask = mask | (1 << i);
            d[nmask] = min(d[nmask], d[mask] + sum);
        }
    }
    cout << d[(1 << 20) - 1] << endl;
}