/*
2019年8月22日10:19:11 第二遍看这题的时候，感觉又不怎么明白了...--->然后还花了1小时把之前的理解推翻了
后面又花了30mins证明，之前的理解是对的...刚刚一小时的理解是有问题的...

*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
typedef long long LL;
int sa[maxn],height[maxn],rank[maxn],t[maxn],t2[maxn],c[maxn];
int n;
char str[maxn];
int q;
LL sum[maxn];

void build_sa(int m,int n){
    int *x=t,*y=t2;
    for(int i=0;i<m;i++)c[i]=0;
    for(int i=0;i<n;i++)c[x[i]=str[i]]++;
    for(int i=1;i<m;i++)c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
        for(int i=0;i<m;i++)c[i]=0;
        for(int i=0;i<n;i++)c[x[y[i]]]++;
        for(int i=1;i<m;i++)c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        x[sa[0]]=0;p=1;
        for(int i=1;i<n;i++)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++);
        if(p>=n)break;
        m=p;
    }
}

void getheight(int n){
    int k=0;
    for(int i=1;i<=n;i++)::rank[sa[i]]=i;
    for(int i=0;i<n;i++){
        if(k)k--;
        int j=sa[::rank[i]-1];
        while(str[i+k]==str[j+k])k++;
        height[::rank[i]]=k;
    }
}

void process(){
    memset(sum,0,sizeof(sum));
    /*sa[i]表示排名为i的后缀的起始位置的下标
    所以n-sa[i]是后缀长度...
    height[i]是sa[i-1]和sa[i]的最长公共前缀*/
    /*jujuz:height数组有个性质，len-sa[i]-height[i]是每个后缀字符串所能贡献的不同子串数目--->这里要综合起来看*/
    /*所以这里是从排名大到小(字典序小到大)的字串累加贡献的字串数目
    (因为自己字典序最小,所以其字串就更小!-->相同前面，串短一点更小)*/

    /*综合来说: sum[i]就是到i排名后缀时总的不同字串个数*/
    sum[1]=n-sa[1];
    for(int i=2;i<=n;i++)
        sum[i]=sum[i-1]+n-sa[i]-height[i];
}

void solve(){
    scanf("%d",&q);
    LL l=0,r=0;
    process();
    while(q--){
        LL v;
        // scanf("%I64d",&v);
        scanf("%lld",&v);
        LL k=(l^r^v)+1;
        /*获取有第k排名的不同字符的起始位置(sum见process函数)*/
        int pos=lower_bound(sum+1,sum+1+n,k)-sum;
        /*减掉前k-1小的,就是第k小的长度,然后再用n减去第k小的长度,即为第k小的位置*/
        /*2019年8月22日12:37:06 tr没看懂，睡觉..*/
        /*看到有其他blog主用tl+一些值来求这个tr,但是自己就是不甘心这里竟然没有看懂，所以一直想总算灵光乍现
        因为每个串都是  后缀 所以sum[pos]-(k-1)就能得到第k个起始的后缀长度！然后用n减去,就是k起始的位置！(字符串下标从0开始,可以用k=1,来模拟理解一遍) */
        LL tl=sa[pos],tr=n-(sum[pos]-k+1);
        l=tl,r=tr;
        int len=tr-tl+1;
        /*看另一个大佬的blog说这是数据弱了才能这样暴力过
        确实10w个1,1e5次k=1,则为1e10的复杂度..如果有这样的的case,必然会TLE
        其实应该用RMQ的...*/
        while(pos+1<=n&&height[pos+1]>=len){
            pos++;
            tl=sa[pos],tr=tl+len-1;
            l=min(l,tl),r=min(r,tr);
        }
        l++,r++;
        if(pos>=n+1)l=r=0;
        cout<<l<<" "<<r<<endl;
    }
}

int main(){
    while(scanf("%s",str)!=EOF){
        n=strlen(str);
        build_sa(123,n+1);
        getheight(n);
        solve();
    }
    return 0;
}