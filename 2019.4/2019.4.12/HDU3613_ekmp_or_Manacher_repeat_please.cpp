// 2019年4月12日14:46:45开始看题
// 2019年4月12日14:52:29感觉读懂了题意，但是还是不太理解样例
// 2019年4月12日14:53:54 原来是两个子回文之和，或者是一个最大子回文+非回文
// 感觉这个要深度理解Manacher算法才能快速写完，否则要花超久时间，自己现在还是先借鉴

// 看大佬说的，发现这题还有关于extend Kmp
/*
解法一快，空间用得比解法二多

解法思路一(扩展kmp):
求出字符串S的反串T，以T为模板跑一遍S的exkmp就能得到S的后缀是否为回文串的信息，
同理以S为模板跑一遍T就可以得到S的前缀是否是回文串的信息，枚举每个断点，取最大值即可。
link: http://forever97.is-programmer.com/2016/9/20/hdu3613.206021.html
(含图的详析): https://blog.csdn.net/u013480600/article/details/23041391
```cpp
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=500000+1000;
char S[MAXN],T[MAXN];
int n;//串S与串T的长都为n
int next[MAXN],extend1[MAXN],extend2[MAXN];
int val[30],sum[MAXN];
void EKMP(char *S,char *T,int *next,int *extend)
{
    int j=0;
    int k=1;
    while(j+1<n && T[0+j]==T[1+j])
        j++;
    next[1]=j;
    for(int i=2;i<n;i++)
    {
        int len=k+next[k]-1,L=next[i-k];
        if(L<len-i+1)
            next[i]=L;
        else
        {
            j=max(0,len-i+1);
            while(i+j<n && T[i+j] == T[0+j])
                j++;
            next[i]=j;
            k=i;
        }
    }
    j=0;
    while(j<n && S[0+j]==T[0+j])
        j++;
    extend[0]=j;
    k=1;
    for(int i=1;i<n;i++)
    {
        int len=k+extend[k]-1,L=next[i-k];
        if(L<len-i+1)
            extend[i]=L;
        else
        {
            j=max(0,len-i+1);
            while(i+j<n && j<n && S[i+j]==T[j])
                j++;
            extend[i]=j;
            k=i;
        }
    }
}
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        for(int i=0;i<26;i++)
            scanf("%d",&val[i]);
        scanf("%s",S);
        n=strlen(S);
        for(int i=0;i<n;i++)
        {
            T[i]=S[n-1-i];
            if(i==0)sum[i]=val[S[i]-'a'];
            else sum[i]=sum[i-1]+val[S[i]-'a'];
        }
        T[n]=0;
        EKMP(T,S,next,extend1);
        EKMP(S,T,next,extend2);
        int max_s=-1e8;
        for(int i=1;i<n;i++)//i表示前半段的长度
        {
            int sc=0;//分数
            //求前缀[0,i-1]分数
            if(extend1[n-i]+n-i==n)
            {
                sc+= sum[i-1];
            }
            //求后缀[i,n-1]的分数
            if(extend2[i]+i==n)
            {
                sc+= sum[n-1]-sum[i-1];
            }
            max_s=max(max_s,sc);
        }
        printf("%d\n",max_s);
    }
    return 0;
}
```

解题思路2(Manacher)(我的自然想法也是这个，但是我不会写):
先用Manacher算法求出以每个字母为中心的回文串的长度，并计算该字符串的前缀价值和。
然后枚举切割点，得到两份子串。这样就可以知道每个子串的中心点，
然后检查以该子串的中心点作为中心点的回文串的长度，
如果长度等于该子串的长度，那么就加上该子串的价值。然后和最优价值比较就行了。

其实如果熟悉了Manacher算法的应用，这道题是很简单的。
---------------------
作者：84970000
原文：https://blog.csdn.net/u014088857/article/details/47804593

*/

// 解法二(Manacher)
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

const int maxn=500005;
char str[maxn],s[maxn<<1];
int p[maxn<<1],newlen;
int val[26];
int presum[maxn];

void init(int n)
{
    newlen=n<<1;
    for(int i=0;i<=newlen+1;i++) s[i]='#';
    for(int i=1;i<=n;i++) s[i<<1]=str[i];
    s[newlen+2]=0;
}

void manacher()
{
    int mx=0,id=0;
    for(int i=1;i<=newlen;i++)
    {
        if(mx>i) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;

        // while(i-p[i]>=0&&s[i-p[i]]==s[i+p[i]]) p[i]++;// 感觉这个人的i-p[i]没什么用，去掉提交一次试试
        while(s[i-p[i]]==s[i+p[i]]) p[i]++; // 果然没用，去掉后速度提升20ms
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<26;i++) scanf("%d",&val[i]);
        scanf("%s",str+1);
        int len=strlen(str+1);
        presum[0]=0;   // 求出一开始的前缀价值和
        for(int i=1;i<=len;i++) presum[i]=presum[i-1]+val[str[i]-'a'];

        init(len);
        manacher();
        int ans=-(INT_MAX-1);

        for(int cutpnt=1;cutpnt<len;cutpnt++)
        {
            int temp=0;
            int len1=cutpnt,len2=len-len1;
            //看子串的长度的奇偶性
            if(len1%2==1)
            {
                int midpnt=len1/2+1;
                int palen=p[midpnt*2]-1;
                if(midpnt-palen/2==1) temp+=presum[len1];
            }
            else
            {
                int midpnt=len/2;
                int palen=p[midpnt*2+1]-1;
                if(midpnt-palen/2+1==1) temp+=presum[len1];
            }

            if(len2%2==1)
            {
                int midpnt=len1+len2/2+1;
                int palen=p[midpnt*2]-1;
                if(midpnt+palen/2==len) temp+=presum[len]-presum[len1];
            }
            else
            {
                int midpnt=len1+len2/2;
                int palen=p[midpnt*2+1];
                if(midpnt+palen/2==len) temp+=presum[len]-presum[len1];
            }
            if(temp>ans) ans=temp;
        }
        printf("%d\n",ans);
    }
}