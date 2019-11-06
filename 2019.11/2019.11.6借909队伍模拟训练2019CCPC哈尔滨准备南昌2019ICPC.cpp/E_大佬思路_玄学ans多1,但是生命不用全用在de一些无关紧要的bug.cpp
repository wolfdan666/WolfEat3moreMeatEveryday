/*
E. Exchanging Gifts

题意：有n个操作，每个操作决定Si，op==1表示后面Si为当前给出的序列，op==2表示Si是Sx+Sy，由此得到最后的Sn，Sn随意交换得到H，问H与Sn最多有多少个不同；

分析：假设我们已经得到Sn，长度为len，出现次数最多的数是x，出现次数为num，如果num*2>len，ans=2*(len-num)，否则答案为len；那么问题就转化为如何得到num和len；

如果Sn的op==1，那么可以直接考虑，如果op==2，那么就只需要考虑对最后Sn有影响的Si；

那么就可以先找到出现次数最多的数x是什么，然后扫一遍记录x出现的真实次数；


————————————————
版权声明：本文为CSDN博主「MaJorieL」的原创文章，遵循 CC 4.0 BY-SA
版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_43813163/article/details/102883590


E_test 和 这份代码一模一样,这份代码为什么答案多1 ??? 导致wa了...
算了不管了,太浪费时间了,所以不找了
*/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn = 1e6 + 7;
typedef long long ll;
ll num[maxn];
int f[maxn][3];
vector<int> a[maxn];

ll solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i].clear();
        num[i] = 0;
        int op;
        scanf("%d", &op);
        f[i][0] = op;
        if (op == 1) {
            int k, x;
            scanf("%d", &k);
            for (int j = 0; j < k; j++) scanf("%d", &x), a[i].pb(j);
        } else
            scanf("%d%d", &f[i][1], &f[i][2]);
    }
    num[n] = 1;
    // 下面计算由拓扑拼叠生成的num个数,所以倒着推===> 我们要用的只有s[n]...傻逼了,所以num[n]=1,然后拓扑就行
    // f[n][0]为1,则直接是,但是这个没有什么意义(对于这题的骚操作)
    // 所以一般是f[n][0]=2,然后不断得拼叠
    // 所以最终f[i][0] = 1时,它的次数为num[i]
    for (int i = n; i > 0; i--)
        if (f[i][0] == 2) num[f[i][1]] += num[i], num[f[i][2]] += num[i];
    ll mx = 0, mxnum = 0, sum = 0;
    // 注意它这里的mxsum表示的是最大和第二大之间的差距!!!妙用
    for (int i = 1; i <= n; i++)
        if (f[i][0] == 1 && num[i])
            // 对串中的元素进行遍历
            for (auto j : a[i]) {
                // 还未遇到元素
                if (mx == 0) mx = j, mxnum += num[i];
                // 遇到的元素为之前最大计数的元素
                else if (mx == j) mxnum += num[i];
                // 遇到的新元素或着非最大计数的元素
                else{
                    // 可能来自新的一个i串的第一个
                    if (num[i] > mxnum) mx = j, mxnum = num[i] - mxnum;
                    else mxnum -= num[i];
                }
                // 每个元素的次数都会对这个sum进行贡献
                sum += num[i];
            }
    ll tot = 0;
    for (int i = 1; i <= n; i++)
        if (f[i][0] == 1 && num[i])
            for (auto j : a[i])
                if (j == mx) tot += num[i];
    if (tot * 2 > sum) return 2 * (sum - tot);
    else return sum;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) printf("%lld\n", solve());

    return 0;
}