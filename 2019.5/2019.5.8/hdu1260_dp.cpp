// 2019年5月8日13:48:24 开始看题

// 怎么感觉这题思路很简单？就是疯狂卖两张票不就行了？哦，不对，和组合方式有关

// 想到递推思路了，做了这么多题，总算从递归思维转化到了递推
// dp[i]代表到当前的最小值   dp[i] = min(dp[i-2]+couple,d[i-1]+cost[i])

// 2019年5月8日14:32:07第一发，wa了... 看了大佬的，发现我对题意有些误解
// 其实就是我菜，The master has failed more times than the beginner has tired
// 完了，番茄时间浪了，focus！

/*
1. ios::同步关掉就不能混用了cout和printf了，所以开着

2. 关于输出前面的0
假设你知道最大的数是五位的（如果不知道可以循环找到）
如果是C语言那么用
printf("%05d", a);
如果是C++
#include <iostream>
#include <iomanip> //包括这个头文件
using namespace std;
void main()
{
    int a = 33;
    cout<<setw(5)<<setfill('0')<<a; 用这两个函数
}

下面是大佬的
解题思路：

一个人可以单独买票花费一定的时间，也可以两个人一起买票，也给定一个时间，给出K个人的单独买票时间和K-1个相邻的两个人一起买票的时间，问一共花费的最小时间。

用sin[i]为每个人单独买票的时间，dou[ i+1]为两个人一起买票的时间。

状态转移方程为： dp[i] = min(dp[i-1]+single[i] , dp[i-2] + dou[i] )。当前第i个人分为两种情况，一是单独买，而是和前面的一块买。
---------------------
作者：同学少年
原文：https://blog.csdn.net/sr_19930829/article/details/24915887
*/
// #include<bits/stdc++.h>
// using namespace std;
// const int M = 2010;
// int dp[M],cost[M];
// int N,K,cp;

// int main(int argc, char const *argv[])
// {
//     // ios::sync_with_stdio(false);
//     cin>>N;
//     while(N--) {
//         cin>>K;
//         for(int i=1;i<=K;i++){
//             // cin>>cost[M];  //手贱
//             cin>>cost[i];
//         }
//         if(K==1){
//             printf("08:00:%02d am\n",cost[1] );  continue;
//         }
//         cin>>cp;
//         dp[1]=cost[1];
//         for(int i=2;i<=K;i++){
//             dp[i]=min(dp[i-2]+cp,dp[i-1]+cost[i]);
//         }
//         int ss=dp[K]%60;
//         int MM=(dp[K]/60)%60;
//         int HH=(dp[K]/3600)+8;
//         if(HH>12) printf("%02d:%02d:%02d pm\n",HH-12,MM,ss );
//         else printf("%02d:%02d:%02d am\n",HH,MM,ss );
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
const int maxn=2005;
int dp[maxn];
int single[maxn];//每个人单独买票时间
int dou[maxn];//相邻两个人一块买票时间
int n,k;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
            scanf("%d",&single[i]);
        for(int i=2;i<=k;i++)
            scanf("%d",&dou[i]);
        dp[0]=0;
        dp[1]=single[1];
        for(int i=2;i<=k;i++)
            dp[i]=min(dp[i-1]+single[i],dp[i-2]+dou[i]);
        int h=dp[k]/3600+8;
        int m=dp[k]/60%60;
        int s=dp[k]%60;
        if(h>12)
            cout<<setiosflags(ios::fixed)<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<" pm"<<endl;
        else
            cout<<setiosflags(ios::fixed)<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<" am"<<endl;
    }
    return 0;
}