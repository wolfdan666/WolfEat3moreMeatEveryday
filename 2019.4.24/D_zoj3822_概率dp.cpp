// 2019年4月24日16:20:52再次看题，希望20mins后就完成
// 2019年4月24日16:59:44 由于没有学这部分，所以只看懂了第二种解法，然后就用第二种解法
// 2019年4月24日17:02:36 发现ZOJ只是单独地不能交B题...

// 概率dp(暂时还没有补这部分)
// 首先求出 放置到前i行 前j列时刻，棋盘中 放置 k棋子个数的 概率。
// 然后递推。
// 我们发现，总共四种状态。
// 1 当前行当前列有，我们可以在之前已经合法的地方在加一个。
// 2当前列没有 n-j+1 *i
// 3 当前行没有
// 4 当前行 当前列都没有
/*#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
double dp[55][55][3005];
int main(){
     int t;
     int m,n;
     scanf("%d",&t);
     while(t--)
     {  scanf("%d%d",&m,&n);
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
           for(int k=1;k<=m*n;k++)
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j][k]+=dp[i-1][j-1][k-1]*1.0*(m-i+1)*(n-j+1)/(1.0*(m*n-k+1));// 此行此列的左上角部分，所以就是m-(i-1)=m-i+1,其他同理
                    dp[i][j][k]+=dp[i-1][j][k-1]*1.0*(m-i+1)*j/(1.0*(m*n-k+1));
                    dp[i][j][k]+=dp[i][j-1][k-1]*1.0*i*(n-j+1)/(1.0*(m*n-k+1));
                    if(i==m&&j==n) continue;
                    dp[i][j][k]+=dp[i][j][k-1]*1.0*(i*j-k+1)/(1.0*(m*n-k+1));
                }
            }
        double ans=0;
        for(int i=0;i<=n*m;i++)
            ans+=dp[m][n][i]*i;
           printf("%.8f\n",ans);
     }
    return 0;
}*/
// 大佬：http://www.voidcn.com/article/p-hrvhlcgl-bqp.html

/*
题目大意：有一个n行n列的棋盘，每次可以放一个棋子，问把每行每列都至少有一个棋子的期望。

题目思路：概率dp，dp[i][j][k]。i表示放了i行，j表示放了j列,k代表用了k个棋子。
dp[i][j][k] = 原始状态的概率 * 选到当前这样状态的概率。
我们可以知道，每放一个棋子会出现4种情况，

一、没有增加一行一列，dp[i][j][k] += dp[i][j][k - 1] * (i * j - k + 1) / (sum - k + 1);
二、增加了一行，dp[i][j][k] += dp[i - 1][j][k - 1] * (n- i + 1) * j / (sum - k + 1);
三、增加了一列，dp[i][j][k] += dp[i][j - 1][k - 1] * (m - j + 1) * i / (sum - k + 1);
四、增加了一行一列 dp[i][j][k] += dp[i - 1][j - 1][k - 1] * (n - i + 1) * (m - j + 1) / (sum - k + 1);

例外需要注意，由于题目要求第k个棋子刚好填满n行m列，故概率为dp[n][m][k] - dp[n][m][k - 1]；

// 自己理解:所以到了后面的时候，d[n][m][n*m量级的时候],两个相减几乎就是0.因为两者的值都接近于1吧

---------------------
作者：宣之于口
原文：https://blog.csdn.net/loy_184548/article/details/46849367
*/
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
double dp[60][60][3600] = {0};
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int sum = n * m;
        for (int k = 0; k <= sum; k++)
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= m; j++)    dp[i][j][k] = 0;
        dp[0][0][0] = 1;
        for (int k = 1; k <= sum; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    double ret = sum - k + 1;
                    dp[i][j][k] += dp[i][j][k - 1] * (i * j - k + 1) / ret;
                    dp[i][j][k] += dp[i][j - 1][k - 1] * (m - j + 1) * i / ret;
                    dp[i][j][k] += dp[i - 1][j][k - 1] * (n- i + 1) * j / ret;
                    dp[i][j][k] += dp[i - 1][j - 1][k - 1] * (n - i + 1) * (m - j + 1) / ret;
                }
            }
        }
        double ans = 0;
        for (int k = 1; k <= sum; k++)
            ans += (dp[n][m][k] - dp[n][m][k - 1]) * k;
        printf("%.10f\n",ans);
    }
    return 0;
}


