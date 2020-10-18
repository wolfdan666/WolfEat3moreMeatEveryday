// 2019年5月11日18:32:40开始看题
// 2019年5月11日18:58:34 酝酿了半天，还是不知道具体怎么写...
// F[i][j] = max(F[i-1][j],F[i-1][j-w[i]]+d[i])   (j-w[i]>=0)
// 求d[N][M]
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 3450;  // 最大的N值
// const int M = 12900; // 最大质量
// int W[N],D[N];

// int main(int argc, char const *argv[])
// {
//     int n,m;
//     cin>>n>>m;
//     int minw = 0x3f3f3f3f;
//     for(int i = 0;i < n;i++){
//         cin>>W[i]>>D[i];
//         minw = min(minw,W[i]);
//     }
//     for(i=minw;i<=m;i++){
//         for(int j=)
//     }
//     return 0;
// }


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=12880+5;
int v[maxn];
int w[maxn];
int dp[maxn];
int main(){
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("data/3624.txt","r",stdin);
    while(cin>>n>>m){
        for(int i=0; i<n; i++)
            cin>>w[i]>>v[i];
        memset(dp,0,sizeof(dp));

        for(int i=0; i<n; i++){
            // for(int j=w[i]; j<=m; j--){// 测试一下,直接RE了
            for(int j=m; j>=w[i]; j--){// 这里好像确实是必须先更新右边的值，
                // 因为如果先更新左边的值的话，那么右边的值就不是用的上一行的左边来更新了，而是用的本行的左边来更新了
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}