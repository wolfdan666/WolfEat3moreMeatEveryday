// #include<bits/stdc++.h>
// using namespace std;
// 2019年3月1日20:16:39 想了20mins，看答案去
// 心情总算平复下来了2019年3月1日21:22:44，发现原来是找一棵树写出来反驳算法！另一个树是刚好符合算法的！绝了，现在才读懂题目，GG

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n<=5) puts("-1");
    else{
        for (int i=2;i<=4;i++)
        printf("1 %d\n",i);
        for (int i=5;i<=n;i++)
        printf("2 %d\n",i);
    }
    for (int i=2;i<=n;i++) printf("1 %d\n",i);
    return 0;
}