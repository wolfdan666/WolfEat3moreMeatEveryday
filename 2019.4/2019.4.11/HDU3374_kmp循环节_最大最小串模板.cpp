// 2019年4月11日20:14:37开始看题
// 第一个想法是暴力模拟，然后sort，之后遍历数出来，但是一想到生成string[]是N*N=1e12bytes=1e9k>>32768K!!
// 2019年4月11日20:27:53 去给老妈回个电话   2019年4月11日20:38:58 帮老妈找完qq开始继续coding
// 看大佬怎么写吧
// 大佬说
/*
题意：输出所给字符串的最大最小表示的起始位置和数量！
PS:
数量我们可以利用KMP里的求next数组来求的循环节！然后再套用一下最大最小表示法的模板就OK了！
---------------------
作者：田益铭
原文：https://blog.csdn.net/u012860063/article/details/48812061


我的欠缺：没有想到用next数组求循环节(因为好久没有刷了，有点忘了...)，不懂最大最小表示法的模板

2019年4月11日21:24:30 完成今天第一题,GG 60mins，所以后两题只剩下30mins了，加油
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 1000017
int Next[MAXN];
char str[MAXN];
int k;
void getNext( char T[],int len)
{
    int i = 0, j = -1;
    Next[0] = -1;
    while(i < len)
    {
        if(j == -1 || T[i] == T[j])
        {
            i++,j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}
// 有点不习惯别人的通用kmp,因为自己一直写刘佳汝的kmp... 不过还是能看懂

//最小表示法
int get_minstring(char *s)
{
    int len = strlen(s);
    int i = 0, j = 1, k = 0;
    while(i<len && j<len && k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)
            k++;
        else
        {
            if(t > 0)
                i+=k+1; // 保持i找到最小位置
            else
                j+=k+1;
            if(i==j) j++;
            k=0;
        }
    }
    return min(i,j); // 感觉直接就是i 是最小的，j是最大的//  测试发现不是的，前后是不同的j，i+=k+1,而且这里是rank！不是求位置
// 后面答案输出有+1 下标变序号
    // 再看题目发现是先默认了rank-- 1 -- N 然后找到最小的那个的rank
}

//最大表示法
int get_maxstring(char *s)
{
    int len = strlen(s);
    int i = 0, j = 1, k = 0;
    while(i<len && j<len && k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)
            k++;
        else
        {
            if(t > 0)
                j+=k+1;
            else
                i+=k+1; // 保证i找到最大位置
            if(i==j) j++; //// 保证i找到最大位置的第一个，j是辅助变量
            k=0;
        }
    }
    return min(i,j);
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        getNext(str,len);
        int tt = len - Next[len];   // 这里是一顿操作求出循环节
        int num = 1;
        if(len%tt == 0)
        {
            num = len/tt;
        }
        int posmin = get_minstring(str);
        int posmax = get_maxstring(str);
        printf("%d %d %d %d\n",posmin+1,num,posmax+1,num);
    }
    return 0;
}

