/* 与线段树解题的思想是相同，但这样操作简单有趣，快准狠
线段树更通用，不过要标准化线段树板子，不然写得千奇百怪，debug困难，维护困难 */

#include<iostream>
#include<set>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
multiset<int> ss;

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        ss.clear();
        long long int n, m;
        scanf("%lld%lld", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        long long int sum = 0;
        int tem = 0;
        for (int i = 0; i < n; i++) {
            long long int suma = sum;
            int jishu = 0;
            if (suma + a[i] > m) {
                auto j = ss.end();
                /* 这里用计数jishu记下软删除的数量，由于priority_queue
                只能访问第一个值，所以不支持软硬删除操作...所以会用真实删除再
                恢复的操作会TLE...因为这样会从O(nlog(n))魔化到O(n^2) */
                /* 由题意a[i]<=m，满足下面条件时一定不会出现ss为空 */
                while (suma + a[i] > m) {
                    j--;
                    suma -= *j;
                    jishu++;
                }
            }
            /* 第一个铁定是0的 */
            printf("%d ", jishu + tem);
            ss.insert(a[i]);
            auto j = ss.end();
            sum += a[i];
            /* 用tem记录下硬删除的数量 */
            while (sum > m) {
                j--;
                sum -= *j;
                /* 这里由于find返回的是指针，所以就会只删除一个值
                而不是删除数值那样把所有数值都删除掉 */
                ss.erase(ss.find(*j));
                tem++;
            }
        }
        printf("\n");
    }
}
