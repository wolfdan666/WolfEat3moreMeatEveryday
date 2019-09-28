// 60633745 Sep/15/2019 20:34UTC+8 alocytus	E - Marbles	GNU C++11	Accepted	93 ms
// 15700 KB 2019年09月28日15:56:57 奇怪啊,我复制他的交了一发,竟然wa on test
// 92,结果相差2! 发现比赛的时候只有90发样例,可能是赛后被人hack了!
// 发现文件名过长的话在VScode还是无法编译的...还是sublime直接调用bash无敌
/*
分析第一种算法错误原因,因为每一个都是只考虑了自己和其他19种颜色的最优前后关系,但是并没有确定这样前后关系是否一定可以实现!所以test 92牛逼!
所以 : 出好题真难

*/

/*#include<bits/stdc++.h>
using namespace std;
int cnt[25],a[4000010];
long long s[25][25];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        for(int j=1;j<=20;j++)if(a[i]!=j)s[a[i]][j]+=cnt[j];
        // 这句话不管放到for之前还是for之后都是wa!
        cnt[a[i]]++;
    }
    long long ans=0;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=20;j++){
            if(i==j)continue;
            ans+=min(s[i][j],s[j][i]);
        }
    }
    printf("%I64d\n",ans/2);
	return 0;
}*/

// By ez_zh, contest: Codeforces Round #585 (Div. 2), problem: (E) Marbles,
// Accepted, #
 #include <bits/stdc++.h>
using namespace std;

#define MAXN 400010

int n, a[MAXN], cnt[21];
long long inv[21][21], f[(1 << 21) + 1];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        for (int j = 1; j <= 20; ++j) inv[a[i]][j] += cnt[j];
        ++cnt[a[i]];
    }
    for (int i = 1; i < (1 << 20); ++i) f[i] = 1ll << 62;
    // 20种排列要全面枚举出来
    for (int i = 0; i < (1 << 20); ++i) {
        vector<int> x;
        for (int j = 1; j <= 20; ++j)
            if (i & (1 << (j - 1))) x.push_back(j);
        // 这是"我为人人"的子集DP
        for (int j = 1; j <= 20; ++j) {
            if (i & (1 << (j - 1))) continue;
            long long res = 0;
            for (auto k : x) res += inv[k][j];
            long long next_state = i | (1 << (j - 1));
            f[next_state] = min(f[next_state], f[i] + res);
        }
    }
    // 别人交可以用lld,为啥我交就不行?...也许是比赛的时候用的,然后系统默认转化了
    // printf("%lld\n", f[(1 << 20) - 1]);
    printf("%I64d\n", f[(1 << 20) - 1]);
} 