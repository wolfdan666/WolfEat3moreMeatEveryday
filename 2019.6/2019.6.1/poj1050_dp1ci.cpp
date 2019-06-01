// 2019年6月1日21:52:07 先刷一下水题
// 1. 暴力法: O(n^3)  --->  发现好像O(n^3)还做不到
/*
  n*n个单一矩阵，n*n个整行交列---->dp(任何一个算法比赛都会用到)自己还是太菜，2019年6月1日22:13:28 想了20mins看答案吧
*/
// 2.
/*
题目要求：求出最大子矩阵。
题目分析：
首先，如果遍历，找到所有的子矩阵，解出这道题是没问题的，只是在POJ上，必然会超时。
所以我考虑用动态规划来解决。即把这问题划分为更小的问题。
现在考虑把这个二维数组拆分，每行每行的先计算。
就把问题化解成求一维数组中子段和最大。  类似求最长字符串的问题。
然后累加比较总和。即可。
详细说明如下：
1、首先考虑一维的最大子段和问题，给出一个序列a[0]，a[1]，a[2]...a[n]，求出连续的一段，使其总和最大。

a[i]表示第i个元素
dp[i]表示以a[i]结尾的最大子段和

dp[i] = max{a[i], dp[i-1] + a[i]}

解释一下方程:

如果dp[i-1] > 0，则 dp[i] = dp[i-1] + a[i]
如果dp[i-1] < 0，则 dp[i] = a[i]

因为不用记录位置信息，所以dp[]可以用一个变量dp代替:

如果dp > 0，则dp += a[i]
如果dp < 0，则dp = a[i]

2、考虑二维的最大子矩阵问题

我们可以利用矩阵压缩把二维的问题转化为一维的最大子段和问题。因为是矩阵和，所以我们可以把这个矩形的高压缩成1，用加法就行了。

恩，其实这个需要自己画图理解，我的注释里写得很详细了，自己看吧。

 枚举求的结果矩阵的行号范围，从(1,1), (1,2), ...到(1,n),然后再求(2,2),(2,3),...(2,n)的最大值，直至到(m,n)。
---------------------
作者：Colin丶
来源：CSDN
原文：https://blog.csdn.net/hitwhylz/article/details/11848439
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#include <stdio.h>
#define MAXSIZE 101

//求出一行中最大的子段和
int MaxArray(int n, int arr_[])
{
    int i, sum_ = 0, max_ = 0;
    for (i = 1; i <= n; i++) {
        if (sum_ > 0) {
            sum_ += arr_[i];
        } else {
            sum_ = arr_[i];
        }
        if (sum_ > max_) {
            max_ = sum_;
        }
    }
    return max_;
}

//求出最大子矩阵和。
int MaxMatrix(int n, int arr_[][MAXSIZE])
{
    int max_ = arr_[1][1];
    int sum_;
    int i, j, k;
    int temp_arr[MAXSIZE];
    for (i = 1; i <= n; i++) //从第一行开始，直到第n行
    {
        for (j = 1; j <= n; j++) //只有起始行改变，temp_arr数组才初始化
        {
            temp_arr[j] = 0;
        }

        for (j = i; j <= n; j++) //从i行到第n行
        {
            for (k = 1; k <= n; k++) {
                temp_arr[k] += arr_[j][k]; //temp_arr[k] 表示从第i行到第n行中第k列的总和。
            }

            sum_ = MaxArray(n, temp_arr); //求出该行中最大的子段和

            if (sum_ > max_) {
                max_ = sum_;
            }
        }
    }

    return max_;
}

int main()
{
    int n;
    int i, j;
    int arr_[MAXSIZE][MAXSIZE];
    int max_;
    while (~scanf("%d", &n)) //多组测试。 相当于 scanf("%d", &n) != EOF
    {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%d", &arr_[i][j]);
            }
        }
        max_ = MaxMatrix(n, arr_);
        printf("%d\n", max_);
    }

    return 0;
}