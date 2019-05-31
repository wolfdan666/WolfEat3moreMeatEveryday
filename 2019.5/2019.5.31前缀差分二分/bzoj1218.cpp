// 2019年5月31日12:52:00开始看题
// 2019年5月31日13:10:48 肚子痛，先wc一波  ---> 2019年5月31日13:23:36 好困，睡吧，等下再高效编码
// 2019年5月31日16:23:08 真读题开始
// 2019年5月31日16:41:29 中途改文件名丢失了一次代码,没事,再默写一次
// 2019年5月31日16:51:20 第一发，wa了.2019年5月31日16:59:16 休息完再看

// 2019年5月31日17:01:13 看了别人的代码，发现果然智障了，原来可以不让输入有序化!
// 发现暴力枚举要O(n^2*R^2),前缀和O(2*n^2)


// #include<iostream>
// #include<algorithm>
// #include<cstdio>
// using namespace std;
// const int M = 5010;
// int s[M][M];

// int main(int argc, char const *argv[])
// {
//     int n,R;
//     cin>>n>>R;
//     int xm=0,ym=0;
//     while(n--) {
//         int x,y,v;
//         scanf("%d%d%d",&x,&y,&v);
//         x++;y++;
//         xm = max(xm,x); ym= max(ym,y);
//         s[x][y]=s[x-1][y]+s[x][y-1]-s[x-1][y-1]+v;
//     }
//     int ans = 0;
//     for(int i=R;i<=xm;i++){
//         for(int j=R;j<=ym;j++){
//             ans = max(ans,s[i][j]-s[i-R][j]-s[i][j-R]+s[i-R][j-R]);
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int a[5002][5002];
int main() {

    int n, r;
    while (~scanf ("%d %d", &n, &r)) {
        int x, y, w;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i) {
            scanf ("%d %d %d", &x, &y, &w);
            a[x+1][y+1] = w;
        }
        for (int i = 1; i <= 5001; ++i) {
            for (int j = 1; j <= 5001; ++j) {
                a[i][j] += (a[i-1][j] + a[i][j-1] - a[i-1][j-1]);
            }
        }
        int ans = 0;
        for (int i = r; i <= 5001; ++i) {
            for (int j = r; j <= 5001; ++j) {
                ans = max(ans, (a[i][j] - a[i-r][j] - a[i][j-r] + a[i-r][j-r]));
            }
        }
        printf ("%d\n", ans);
    }

    return 0;
}