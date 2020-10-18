// 感觉自己Dp比较菜，所以还是先写写简单的题目先
// 2019年5月5日21:35:39开始看题

// 发现这题过于简单了...看手速了2019年5月5日21:40:34
// 2019年5月5日21:59:57 TLE！！！我惊了
/*
看大佬：懂了
我ac的思路是直接排序，然后一次循环进行对出现次数最大值的判断。
还有一种方法是排序后找第n/2大的数，因为特殊数出现次数超过一半，所以排序后中位数一定是特殊数。
看了大牛博客才发现还有更妙的一种方法，上面两种方法都基本是O(nlogn)，而这个方法是O(n)
设置一标志量num，按照原顺序依次迭代，随便假定一个解，如果a[i]==ans，num++，否则num–，当num为0时将当前a[i]作为新解。因为n为奇数，且特殊值出现次数大于一半，所以任何情况下，特殊值做为解时代num不会小于1，所以最终的解一定就是特殊值。
---------------------
作者：shiyicode
来源：CSDN
原文：https://blog.csdn.net/to_be_better/article/details/50557796
版权声明：本文为博主原创文章，转载请附上博文链接！

我觉得大佬好像没有看清楚解法2 是log(n)
然后他没写的解法二，我用他解法一来改了一手
解法三也粘一下
*/
/*
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int M = 1e6+10;
int a[M];
std::map<int, int> num;
set<int> s;

int main(int argc, char const *argv[])
{
    int n;
    int ans=0;
    while(cin>>n) {
        ans=0;
        int level = (n+1)/2;
        s.clear();
        num.clear();
        int si = 0;
        for (int i = 0; i < n; ++i){
            cin>>a[i];
            if(ans==0){
                s.insert(a[i]);
                if((int)s.size()==si){
                    num[a[i]]++;// 原来已经初始化成1了
                    if(num[a[i]]>=level) ans=a[i];
                }
                else{
                    si++;
                    num[a[i]]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/
// 解法一和二(主二)
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

const int N = 1000009;
int a[N];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        int ans = a[n/2];
        // int num = 1;
        // int mmax = 0;
        // for(int i=1; i<n; i++)
        // {
        //     if(a[i] == a[i-1])
        //         num++;
        //     else
        //     {
        //         if(mmax <= num)
        //         {
        //             mmax = num;
        //             ans = a[i-1];
        //         }
        //         num = 1;
        //     }
        // }
        // if(mmax <= num)
        //     ans = a[n-1];
        printf("%d\n", ans);
    }
    return 0;
}


// 解法三
// #include<iostream>
// #include<cstring>
// #include<cmath>
// #include<cstdio>
// #include<algorithm>
// #include<stack>
// #include<queue>
// using namespace std;

// const int N = 1000009;
// int a[N];

// int main()
// {
//     int n;
//     while(~scanf("%d", &n))
//     {
//         int num = 0;
//         int ans = -1;
//         for(int i=0; i<n; i++)
//         {
//             scanf("%d", &a[i]);
//             if(num == 0)
//             {
//                 ++num;
//                 ans = a[i];
//             }
//             else
//             {
//                 if(ans != a[i])
//                     num--;
//                 else
//                     num++;
//             }
//         }
//         printf("%d\n", ans);
//     }
//     return 0;
// }