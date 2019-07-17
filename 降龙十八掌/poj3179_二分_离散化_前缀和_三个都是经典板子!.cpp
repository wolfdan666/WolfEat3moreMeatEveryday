/*
2019年7月17日13:41:33 开始看题
2019年7月17日13:48:16 还有迷题意 --- 先翻译一下题目..

李煜东老师给的建议是  二分，离散化，前缀和... 2019年7月17日13:53:51
想到了离散化和前缀和，但是想不到怎么二分，把问题缩小.. 2019年7月17日13:57:02 （16mins了，看大佬怎么想）

【算法】

           首先，我们发现答案是具有单调性的，也就是说，如果边长为C的正方形可以，那么比边长C大的正方形也可以，因此，可以二分答案

           那么，我们怎么检验呢？

           每个点的坐标最大时达到10000，因此，直接二维前缀和显然是会超时的

           考虑将坐标离散化，然后求二维前缀和，由于N<=500，所以离散化后最多也只有1000个点

           检验时，我们枚举正方形的左上角，用二分求出它的右下角，然后，判断正方形内是否有大于C的草量

大佬：evenbao
链接：https://www.cnblogs.com/evenbao/p/9243183.html

其实感觉自己这种从大一才开始学习，然后一直被放羊式的自我看情况训练的菜鸡，只有不断地努力才能在某一天达到那些信息学竞赛专业化训练的人的水平，不管怎么说，这40天必须全力以赴，把所以其他事情都扔掉吧
别感慨了，这半年都要全力以赴疯狂训练，什么分享平台什么绩点啥的，等我退役赛打完再说...
心无杂念的35天，每天训练至少8小时以上，然后暑假必须刷完20场比赛和补完题，看完小蓝书，形成算法和数据结构体系

看了好久大佬一的代码，写得很规范，很好，然后看到卡住去看了大佬二的代码，发现大佬二写得很亲切...因为有了大佬一的思路，所以大佬二的代码一下就看懂了

2019年7月17日16:16:44 整理完，这个题目真的综合
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define ll long long

using namespace std;
#define MAXN 510

int C, N, i, j, l, r, mid, ans, tx, ty, len;
int tmp[MAXN << 1], s[MAXN << 1][MAXN << 1], x[MAXN], y[MAXN];

inline int getsum(int xa, int ya, int xb, int yb)
{
    return s[xb][yb] - s[xa - 1][yb] - s[xb][ya - 1] + s[xa - 1][ya - 1];
}
inline bool check(int x)
{
    int i, j, tx, ty, pos;
    /* x的值一开始是5000.而tmp[len]一直是10001，所以这个循环好像没有意义 */
    /* 不对，有可能x一直变大到大于10000，但是还是没有用 ，然后去看了大佬二的代码，发现这一步果然是没有来过的 */
    if (x > tmp[len]) {
        if (s[len][len] >= C)
            return true;
        else
            return false;
    }
    /* 这里使用整块长度去切出x长度，防止右下角的访问溢出边界 */
    /* 我做了点改进，就改了一点点，延迟降低31ms！ */
    pos = upper_bound(tmp + 1, tmp + len + 1, tmp[len] - x) - tmp - 1;
    // pos = upper_bound(tmp + 1, tmp + len + 1, tmp[len] - x + 1 - 1) - tmp - 1;
    /* 枚举左上方，求出右下方 */
    for (i = 1; i <= pos; i++) {
        for (j = 1; j <= pos; j++) {
            /*想着像大佬二一样得优化upper——bound,结果忘了这里是x,y公用一个tmp来映射，所以不能像大佬二那样玩 */
            // tx = upper_bound(tmp + i, tmp + pos + 1, tmp[i] + x - 1) - tmp - 1;
            // ty = upper_bound(tmp + j, tmp + pos + 1, tmp[j] + x - 1) - tmp - 1;
            tx = upper_bound(tmp + 1, tmp + len + 1, tmp[i] + x - 1) - tmp - 1;
            ty = upper_bound(tmp + 1, tmp + len + 1, tmp[j] + x - 1) - tmp - 1;
            if (getsum(i, j, tx, ty) >= C)
                return true;
        }
    }
    return false;
}

int main()
{

    scanf("%d%d", &C, &N);
    /* x,y 混合在一起离散化是可以的！只是要统计需要离散化的点 */
    for (i = 1; i <= N; i++) {
        scanf("%d%d", &x[i], &y[i]);
        tmp[++len] = x[i];
        tmp[++len] = y[i];
    }
    sort(tmp + 1, tmp + len + 1);
    len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
    for (i = 1; i <= N; i++) {
        /*查询x,y映射为1-len中哪个整数
        example ： 1 2 3
                 tem+1 tem+2 tem+3 tem+4
            x[i] = 1
            则 (tem+2) - (tem) = 2
            lower_bound 获取 `>` x[i]的下标值
            思考： 为什么不用upper_bound() - tem - 1?  ---> 因为`>=` 可能对浮点数不稳定，所以还是使用 lower_bound鲁棒性更好
         */
        tx = lower_bound(tmp + 1, tmp + len + 1, x[i]) - tmp;
        ty = lower_bound(tmp + 1, tmp + len + 1, y[i]) - tmp;
        s[tx][ty]++;
    }
    tmp[++len] = 10001;
    /* 获取前缀和 */
    for (i = 1; i <= len; i++) {
        for (j = 1; j <= len; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
        }
    }
    l = 1;
    r = 10000;
    /* 二分标准左右最终相遇相离板子 */
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }
    printf("%d\n", ans);

    return 0;
}

// 大佬二
///https://www.cnblogs.com/huyufeifei/p/9031815.html
/// poj3179
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 510;

int a[N], b[N], x[N], y[N], g[N][N], sum[N][N], n, C, tx, ty;

inline bool check(int k) {
    //printf("check:%d\n", k);
    int ans = 0;
    for(int i = 1; i <= tx; i++) {
        for(int j = 1; j <= ty; j++) {
            /* x[i]+k就是找到右下角的坐标 */
            int ii = upper_bound(x + i, x + tx + 1, x[i] + k) - x - 1;
            int jj = upper_bound(y + j, y + ty + 1, y[j] + k) - y - 1;
            /// 就是这里！
            //printf("%d %d %d %d ", i, j, ii, jj);
            ans = max(ans, sum[ii][jj] - sum[ii][j - 1] - sum[i - 1][jj] + sum[i - 1][j - 1]);
            if(ans >= C) return 1;
            //printf("ans=%d\n", ans);
            //ii = i; jj = j;
            //while(ii >= 0 && x[ii] - x[i] )
        }
    }
    //printf("%d\n", ans);
    return ans >= C;
}

int main() {
    int m = -1;
    scanf("%d%d", &C, &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        x[i] = a[i];
        y[i] = b[i];
        m = max(m, x[i]);
        m = max(m, y[i]);
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for(int i = 1; i <= n; i++) {
        if(x[i] != x[i - 1]) {
            x[++tx] = x[i];
        }
        if(y[i] != y[i - 1]) {
            y[++ty] = y[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        /* x 可以看作去重量， a可以看作原量 ， 然后 px 可以看作是序列量 */
        int px = lower_bound(x + 1, x + tx + 1, a[i]) - x;
        int py = lower_bound(y + 1, y + ty + 1, b[i]) - y;
        g[px][py]++;
    }
    for(int i = 1; i <= tx; i++) {
        for(int j = 1; j <= ty; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i][j];
        }
    }
    int l = 0, r = m, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            r = mid;
        }
        else l = mid + 1;
    }
    printf("%d", r + 1);
    return 0;
}

/*
小细节：1 * 1的方框边长是0，n * n的方框边长是n - 1
所以我最后输出时 + 1
*/