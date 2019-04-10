/*
自己的思路是没有使用dp的，只用了比较简单的前缀和


题目大意：输入一个m，n分别表示成m组，一共有n个数即将n个数分成m组，m组的和加起来得到最大值并输出。
解题思路：状态dp[i][j]表示前j个数分成i组的最大值。
动态转移方程：dp[i][j]=max(dp[i][j-1]+a[j],max(dp[i-1][k])+a[j]) (0<k<j)
dp[i][j-1]+a[j]表示的是前j-1分成i组，第j个必须放在前一组里面。
max( dp[i-1][k] ) + a[j] )表示的前（0<k<j）分成i-1组，第j个单独分成一组。
但是题目的数据量比较到，时间复杂度为n^3，n<=1000000，显然会超时，继续优化。
max( dp[i-1][k] ) 就是上一组 0....j-1 的最大值。我们可以在每次计算dp[i][j]的时候记录下前j个
的最大值 用数组保存下来 ，这样时间复杂度为 n^2。
---------------------
作者：qiqi_starsky
原文：https://blog.csdn.net/qiqi_skystar/article/details/50599816
*/

#include<bits/stdc++.h>
using namespace std;
#define N 1000000
#define INF 0x7fffffff
int a[N+10];
int dp[N+10],Max[N+10];//max( dp[i-1][k] ) 就是上一组 0....j-1 的最大值。

int main(){
    int n,m,mmax;
    while (~scanf("%d%d",&m,&n)){
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        memset(Max,0,sizeof(Max));
        for (int i=1;i<=m;i++)//分成几组
        {
            mmax=-INF;
            for (int j=i;j<=n;j++)//j个数分成i组，至少要有i个数
            {
                dp[j]=max(dp[j-1]+a[j],Max[j-1]+a[j]);
                Max[j-1]=mmax;// 上一组0...j-1的最大值，所以放在下面一行的前面
                mmax=max(mmax,dp[j]);
            }
        }
        printf ("%d\n",mmax);
    }
    return 0;
}