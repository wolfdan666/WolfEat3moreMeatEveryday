// 看了郭炜老师的解题思路
// 写出来的关键,用高度排序,但是要记住他们之间的位置关系,直接搞一个复刻的关系组
// 就是一个strut{x,y,h},用高度排序后再对h[x][y]进行分析,用dp[x][y]来推断
// 写了一个小时，交了一发，居然wa了！   应该是忘了判断边界  ... 还是wa了，什么鬼

// 2019年5月11日20:20:13 写加debug   80 mins,自己还是太菜了呀！所以今天最后一题先做个简单题

// 我在网上找到有个人写的  “人人为我类型的”  和我的构造方式完全一样，那我为啥错了！
#include<iostream>
#include<algorithm>
using namespace std;
int h[110][110];
int dp[110][110];
struct node{
    int x,y,z;
} n[10010];
int ns[4]={0,-1,0,1};
int ew[4]={1,0,-1,0};

bool cop(node a,node b){
    return a.z < b.z;
}

int main(int argc, char const *argv[])
{
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>h[i][j];
            // n[i*r+j].x=i;  // 下标是temporary的，所以可以sort掉
            // n[i*r+j].y=j;
            // n[i*r+j].z=h[i][j];

// 2019年5月11日20:14:33发现每一行不是r个，而是c个！！！
// 还不如用最简单的num++的形象来积累，不然可能一不下心，显摆行列，结果出错！
            n[i*c+j].x=i;  // 下标是temporary的，所以可以sort掉
            n[i*c+j].y=j;
            n[i*c+j].z=h[i][j];

            dp[i][j]=1;
        }
    }
    sort(n,n+r*c,cop);
    for(int i=0;i<r*c;i++){
        int ro = n[i].x, co = n[i].y, hi = n[i].z;
        for(int j=0;j<4;j++){
            if( ( ro+ns[j]>=0&& ro+ns[j]<r ) || ( co+ew[j]>=0 && co+ew[j]<c ) )
                if(h[ro+ns[j]][co+ew[j]]>hi){
                    dp[ro+ns[j]][co+ew[j]]=max(dp[ro+ns[j]][co+ew[j]],dp[ro][co]+1);
                }
        }
    }
    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}


// 别人的人人为我型
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// const int maxn = 105;
// int a[maxn][maxn];
// int dp[maxn][maxn];

// struct node
// {
//     int x,y,h;
// }A[maxn*maxn];

// bool cmp(node a,node b)
// {
//     return a.h<b.h;
// }

// int main()
// {
//     int n,c;
//     while(scanf("%d%d",&n,&c)==2)
//     {

//         memset(dp,0,sizeof(dp));
//         memset(a,0,sizeof(a));
//         int num = 0;
//         for(int i = 1 ; i <= n ; i++)
//         {
//             for(int j = 1 ; j <= c ; j++)
//             {
//                 scanf("%d",&a[i][j]);
//                 A[num].x=i;
//                 A[num].y=j;
//                 A[num++].h = a[i][j];
//                 dp[i][j] = 1 ;   //初始条件
//             }
//         }
//         sort(A,A+num,cmp);//排序
//         //这样处理了之后就不用考虑边界的问题了，边界的点都比边界外的高，但是边界外面的dp初始值为0
//         //加上1之后还是不变

//         for(int k = 0 ; k < num ; k++)
//         {
//             int i = A[k].x;
//             int j = A[k].y;
//             if(a[i][j]>a[i-1][j]) dp[i][j] = max(dp[i][j],dp[i-1][j]+1);
//             if(a[i][j]>a[i][j-1]) dp[i][j] = max(dp[i][j],dp[i][j-1]+1);
//             if(a[i][j]>a[i+1][j]) dp[i][j] = max(dp[i][j],dp[i+1][j]+1);
//             if(a[i][j]>a[i][j+1]) dp[i][j] = max(dp[i][j],dp[i][j+1]+1);
//         }
//         int ans = 0 ;
//         for(int i = 1 ; i <= n ; i++)
//         {
//             for(int j = 1 ; j <= c ; j++)
//             {
//                 //cout<<dp[i][j]<<" ";
//                 ans = max(ans,dp[i][j]);
//             }
//             //cout<<endl;
//         }
//         printf("%d\n",ans);
//     }
//     return 0;
// }


/*
Auther:LIUYAN
2015.12.14
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/