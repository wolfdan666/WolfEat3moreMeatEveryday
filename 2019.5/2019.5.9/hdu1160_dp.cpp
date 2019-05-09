// 2019年5月9日14:04:21开始看题
// 不会就是一个排序吧，然后再遍历一遍使得严格就完事了？试试2019年5月9日14:14:05
// 中途退出30mins处理一些杂事
// 今天莫名其妙地心情不好，心态炸裂，好烦躁，算了，每个月总有那么几天心情焦躁...炼心就好...热闹确实是他们的,我确实什么都没有
// 而且当我拥有的时候还不能高声呼喊，因为会让人嫉妒，只能表现地自己很菜,好吧
// 欲戴王冠，必承其重，没事，谁让你选择了不同的路，那就去享受追梦路上所有的不同，然后享受获得与众不同的收获

// 一定要看书啊，因为看别人的书能少走弯路！！！进步速度更快，才能效率更高，才能真正拿金牌，好的
// 2019年5月9日16:22:08 今天效率好低，心情有点沉重，所以先刷一下LeetCode爽一下吧，然后多看点书学习算法提高刷题效率

/*
shiyicode:
按体重递增排序，再求最长递增(此递增表示体重递增速度递减)子序列。
dp[i] = max(dp[j]+1) 0<=j<=i-1


自己:
只想到了第一波排序，并没有想清楚其实那种排序只是按照主线排序了，并没有真正 速度 递减
*/
// #include<bits/stdc++.h>
// using namespace std;
// #define x first
// #define y second
// typedef pair<int,pair<int,int>> P;
// const int M = 1010;
// vector<P> a;
// int t[M];

// bool cop(P m,P n){
//     return m.y.x==n.y.x? (m.y.y<n.y.y) : (m.y.x>n.y.x);
// }

// int main(int argc, char const *argv[])
// {
//     int i = 0;int b,c;
//     while(~scanf("%d,%d",&b,&c)){
//         a.push_back(make_pair(++i,make_pair(b,c)));
//     };
//     sort(a.begin()+1,a.begin()+i+1,cop);
//     int prew=a[1].y.x,pres=a[1].y.y;
//     t[1]=a[1].x;
//     int ans = 1;
//     for(int j=2;j<=i;j++){
//         if(a[j].y.x==prew||a[j].y.y==pres) ;
//         else{
//             t[++ans]=a[j].x;
//         }
//         prew=a[j].y.x;
//         pres=a[j].y.y;
//     }
//     cout<<ans<<endl;
//     for(int j=1;j<=ans;j++){
//         cout<<t[i]<<endl;
//     }
//     return 0;
// }


#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

const int N = 1006;
struct Node
{
    int a, b, i;
    bool operator <(const Node &t) const
    {
        return a < t.a;
    }
}p[N];

int dp[N], fa[N], ans[N];

int main()
{
    int pos = 0;
    while(~scanf("%d%d", &p[pos].a, &p[pos].b))
    {
        p[pos].i = pos+1;
        pos++;
    }
    sort(p, p+pos);
    memset(fa, -1, sizeof(fa));
    int ians = 0, amax = 0;
    for(int i=0; i<pos; i++)
    {
        int mmax = 0;
        for(int j=0; j<i; j++)
        {
            if(p[j].a < p[i].a && p[j].b > p[i].b && mmax < dp[j])
            {
                mmax = dp[j];
                fa[i] = j;
            }
        }
        dp[i] = mmax+1;  // 最长上升子序列的长度
        if(amax < dp[i])
        {
            amax = dp[i];
            ians = i;
        }
    }
    printf("%d\n", amax);
    int i = 0;
    while(i < amax)
    {
        ans[i++] = p[ians].i;
        ians = fa[ians];
    }
    while(i--)
        printf("%d\n", ans[i]);
    return 0;
}