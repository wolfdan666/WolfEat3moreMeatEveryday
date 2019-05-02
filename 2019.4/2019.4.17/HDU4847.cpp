// 2019年4月17日17:15:59开始看题  算了先吃饭2019年4月17日17:20:36
// 2019年4月17日19:29:18 开始继续看题   emmmm,发呆了,专注起来！2019年4月17日19:38:28
// 2019年4月17日19:44:25 我服了，这个题目这么长，让人失去耐心，最后发下前面写的都没啥用

// 思路:先把DOGE的所有4个字符转为了小写，其他变成#(包括换行符),然后再直接使用kmp，64K=65536B，不是很大，用getline分开操作吧，因为
// 会换行，所以不用直接kmp了，直接find吧
// 想看下别人是不是这个思路，不行， 先写
// 2019年4月17日20:15:32 emm，难受，很陌生的读取，还是先借鉴学习吧


/*
2019年4月17日20:18:02 我惊了，别人直接这样暴力判断就完事了,我还是太菜，没想到这么简单的方法，因为这里doge的f[i]全为0,反而会多此一举

//当然 while(~scanf("%s",str)) 也行
---------------------
作者：AC_Dreameng
原文：https://blog.csdn.net/hurmishine/article/details/51356569
*/

// #include<bits/stdc++.h>
// using namespace std;
// string s;

// int main(int argc, char const *argv[])
// {
//     ios::sync_with_stdio(false);
//     while(getline(cin,s)!="eofbit"){

//     }
//     return 0;
// }


#include <iostream>
#include <cstring>
using namespace std;
char a[1000];
int main()
{
    int sum=0;
    // while(~scanf("%s",str))
    while(cin>>a)
    {
        int len=strlen(a);
        for(int i=0;i<len-3;i++)
        {
            //doge
            if((a[i]=='D'||a[i]=='d')&&(a[i+1]=='O'||a[i+1]=='o')&&(a[i+2]=='G'||a[i+2]=='g')&&(a[i+3]=='E'||a[i+3]=='e'))
            {
                sum++;
            }
        }
    }
    cout<<sum<<endl;
}
