// 2019年5月5日20:33:42开始看题
// 思路：最长递增公共子序列题目，要输出最长子序列
// 2019年5月5日21:19:32 才发现这个最长子序列竟然要相同两串相同，可以跨字符

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,a[505],b[505],dp[505],mark[505][505],ans[505];

int LICS(){
    int MAX,k;

    for(int i = 1; i <= n; i ++){
        k = 0;
        memcpy(mark[i],mark[i - 1],sizeof(mark[0]));
        for(int j = 1; j <= m; j ++){
            if(a[i - 1] > b[j - 1] && dp[k] < dp[j]) // 这种情况下，可能是循环到了后面，a[i-1]本身比较大，但是dp[k]<dp[j],所以更新k
                k = j;
            if(a[i - 1] == b[j - 1] && dp[k] + 1 > dp[j]){
                dp[j] = dp[k] + 1;
                mark[i][j] = i * (m + 1) + k;
            }
        }
    }
    MAX = 0;
    for(int i = 1; i <= m; i ++)
        if(dp[i] > dp[MAX])
            MAX = i;
    int i = (m + 1) * n + MAX;

    for(int j = dp[MAX]; j > 0; j --){
        ans[j - 1] = b[i % (m + 1) - 1]; // 记录路径
        i = mark[i/(m + 1)][i%(m + 1)];
    }
    return dp[MAX];// dp记录长度
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i = 0; i < m; i ++)
        scanf("%d",&b[i]);

    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    int k = LICS();
    printf("%d\n",k);

    for(int i = 0; i < k; i ++){
        if(i)
            printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}