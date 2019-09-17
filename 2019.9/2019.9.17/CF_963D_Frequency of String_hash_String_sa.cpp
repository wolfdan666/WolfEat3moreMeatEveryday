/*
2019年9月17日19:57:04 开始看题


题意理解:
给一个串S，然后对每次询问求最短串t，使得 t中有出现$k_i$次的$m_i$

# 大佬题解
一开始看到这题就想SAM然后fail树上乱搞
然后就搞不出来。。

事实上可以暴力
令M=∑|m|M=∑|m|
令M=$\sigma$|m|
首先询问串的长度种类数最多只有M−−√M种
最坏就是1,2,3,4,....x1,2,3,4,....x，x\*(x+1)/2=Mx(x+1)2=M,x是根号M级别的

每个长度的所有串在|S|中出现次数之和是|S|级别的
因此所有询问串在|S|中出现次数之和是|S|M−−√|S|M的

这样就可以暴力了
用AC自动机先把所有出现的位置弄出来
Fail树上乱搞一波，直接扫一扫就好了
————————————————
版权声明：本文为CSDN博主「BAJim_H」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/hzj1054689699/article/details/80316430
*/


// https://www.cnblogs.com/hehe54321/p/8994810.html
// SAM版本
// 但是好像不够套路,价值不高,所以还是学暴力的那种===>这种也看看
#pragma GCC diagnostic error "-std=c++11"
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;
char s[100010],ss[100100];
int ll,x[100100],l2;
int pp[100100];
vector<int> vv[200100];
set<int> sss[200100];
int n,ans[100100];
int lll[100100];
int teststet;
int ssss;

namespace SAM
{
    int mem,np,root;
    int len[200100],par[200100];
    int trans[200100][26];
    void append(int ch)
    {
        int p=np;np=++mem;len[np]=len[p]+1;
        for(;p&&!trans[p][ch];p=par[p])    trans[p][ch]=np;
        if(!p)    par[np]=root;
        else
        {
            int q=trans[p][ch];
            if(len[q]==len[p]+1)    par[np]=q;
            else
            {
                int nq=++mem;par[nq]=par[q];par[q]=par[np]=nq;
                memcpy(trans[nq],trans[q],sizeof(trans[nq]));len[nq]=len[p]+1;
                for(;p&&trans[p][ch]==q;p=par[p])    trans[p][ch]=nq;
            }
        }
    }
    void build()
    {
        np=root=++mem;
        int i;
        for(i=1;i<=ll;i++)
        {
            append(s[i]-'a'),sss[np].insert(i);
        }
    }
}
void work(int tt)
{
    using SAM::trans;
    int i,now=SAM::root;
    for(i=1;i<=l2;i++)
    {
        now=trans[now][ss[i]-'a'];
    }
    vv[now].push_back(tt);
}
queue<int> q;int in[200100];
void work2()
{
    using SAM::mem;using SAM::par;
    int i,j,t;vector<int> tmp;
    for(i=1;i<=mem;i++)    if(par[i])    in[par[i]]++;
    for(i=1;i<=mem;i++)    if(!in[i])    q.push(i);
    while(!q.empty())
    {
        t=q.front();q.pop();
        if(vv[t].size())
        {
            tmp.clear();
            for(auto k:sss[t])    tmp.push_back(k);
        }
        for(auto p:vv[t])
        {
            for(i=0,j=x[p]-1;j<tmp.size();i++,j++)
            {
                ans[p]=min(ans[p],tmp[j]-tmp[i]+lll[p]);
            }
        }
        if(par[t])
        {
            if(sss[par[t]].size()<sss[t].size())    swap(sss[par[t]],sss[t]);
            for(auto k:sss[t])    sss[par[t]].insert(k);
            sss[t].clear();
            in[par[t]]--;
            if(!in[par[t]])    q.push(par[t]);
        }
    }
}
int main()
{
    int i;
    scanf("%s",s+1);ll=strlen(s+1);
    SAM::build();
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%s",&x[i],ss+1);l2=lll[i]=strlen(ss+1);
        work(i);
    }
    int aefsaf;
    memset(ans,0x3f,sizeof(ans));
    work2();
    for(i=1;i<=n;i++)
        printf("%d\n",ans[i]==0x3f3f3f3f?-1:ans[i]);
    return 0;
}