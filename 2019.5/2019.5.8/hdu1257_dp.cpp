// 2019年5月8日14:50:16 开始看题
// 因为前面浪了，所以这个longrest要写完这题
// 突然发现这题不就是遍历一下解决掉吗？
// 居然wa了...看大佬怎么写

// 原来这题有坑点...

// 还有大佬说的LIS我不懂是啥，所以今晚啃点书吧

// #include<bits/stdc++.h>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int n;
//     while(cin>>n){
//         int ans = 1;
//         if(n==1) {cin>>ans;/*借用一下来*/ cout<<1<<endl;continue;}
//         int pre=0x3f3f3f3f; // 32位就是int
//         int cur=0;
//         for(int i=0;i<n;i++){
//             cin>>cur;
//             if(cur>pre){
//                 ans++;
//             }
//             pre=cur;
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }

/*

虽然题目是中文的，但是不是一般的号理解（或许是我理解能力差）。题目中n的数量也没说！！！

题目给的样例：

第一套拦截系统：383,207，155,

第二套拦截系统：300，299,170,158,65



再给一组坑爹的样例吧：

8

7,6,5,6,3,2,4,1

答案是3吗？恭喜你WA！其实对于这组数据，只要两套就够了


第一套拦截系统：7,6,5

第二套拦截系统：6,3,2

这是毫无疑问的，对于剩下的两个数据，继续用第一套系统就可以了？不是吗？

理解题目后就可以贪心了，

注意：

第一份代码中数组a保存的每套系统目前发射的最大高度。

还有人说用LIS可以A，确实可以。
---------------------
作者：AC_Dreameng
原文：https://blog.csdn.net/hurmishine/article/details/52926957
*/


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[105];
int main()
{
    int n;
    while(cin>>n)
    {
        int x;
        int cnt=1;
        bool flag=false;
        cin>>a[0];
        for(int i=1;i<n;i++)
        {
            flag=false;
            cin>>x;
            for(int j=0;j<cnt;j++)
            {
                if(a[j]>x)
                {
                    a[j]=x;
                    //a[j]以后能发射的最大高度
                    flag=true;
                    break;
                }
            }
            if(!flag)//没有找到，选新系统
                a[cnt++]=x;
        }
        cout<<cnt<<endl;
    }
    return 0;
}