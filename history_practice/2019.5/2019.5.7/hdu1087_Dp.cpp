// 2019年5月7日21:29:35开始看题，两题，全力以赴
// 用递归的话很简单，但是这种题目应该又是要递推的，所以必须转化过去
// 2019年5月7日21:36:03，尴尬了，没时间了，有点想不出，先看答案吧
// 好吧，看了大佬的思路，发现和我的完全一样，自己没有分析复杂度的具体数值，我只是觉得这类题可能O(n^2)一般会TLE，所以我就没敢写..所以多刷题积累exp

/*

​ 只要能找到递增的序列就可以将该序列各元素值相加，这样的序列可能有多个，简单来说，就是求一个最大递增子数组和。
​
 设dp[i]为以第i个元素结尾的递增子数组的最大子数组和，则状态方程可写作：dp[i] = max(dp[i], dp[j] + arr[i])，
其中方程的约束条件为0 <= j <= i && arr[j] < arr[i]，约束条件的理解应该是，在i位置之前，寻找使得arr[j] < arr[i]成立的位置，
并将其对于dp值与dp[i]做比较，取较大的值，但不应该仅找一个位置就结束，应该寻找到i-1的位置。具体代码如下：
---------------------
作者：Morrisss_
原文：https://blog.csdn.net/tobebetterprogrammer/article/details/53765750
*/

#include<bits/stdc++.h>
using namespace std;

const int g_kMaxSize = 1001;

int main(int argc, const char *argv[]){
    int n;
    int arr[g_kMaxSize] = { 0 };
    int dp[g_kMaxSize] = { 0 };

    int i, j;
    int res;
    while (~scanf("%d", &n)&&n) {
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        dp[0] = arr[0];
        for (i = 1; i < n; ++i) {
            dp[i] = arr[i];
            for (j = 0; j < i; ++j) {  //在i位置之前寻找符合条件的j
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        //在dp数组中寻找最后需要求解的最大递增子数组和
        res = -1;
        for (i = 0; i < n; ++i) {
            res = max(res, dp[i]);
        }

        printf("%d\n", res);
    }
    return 0;
}
