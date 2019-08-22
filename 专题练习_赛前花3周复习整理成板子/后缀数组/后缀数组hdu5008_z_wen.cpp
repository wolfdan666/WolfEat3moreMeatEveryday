/*
2019年8月6日12:44:24 开始看题

求出所有字串中第k小的，但是我还是不会怎么巧妙地求出所有本质不同的字符串...
后缀数组忘了...zkq问我的...既然说看看，那就认真看看

后缀数组忘光了，于是粗略地补一下后缀数组补到了2019年8月6日14:23:58 ...
在怀疑只用后缀数组真的能做？我找到的答案好像都用了LCP(最长公共前缀)
中途发呆了25mins，2019年8月6日15:05:11 现在继续...

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
    /*所以这里是从排名大到小(字典序小到大)的字串累加贡献的字串数目(因为自己字典序最小,所以其字串就更小!)*/

    /*综合来说: sum[i]就是i后缀中的字串个数,也是i后缀字符串的长度*/
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
        int pos=lower_bound(sum+1,sum+1+n,k)-sum;
        /*减掉前k-1小的,就是第k小的长度,然后再用n减去第k小的长度,即为第k小的位置*/
        LL tl=sa[pos],tr=n-(sum[pos]-k+1);
        l=tl,r=tr;
        int len=tr-tl+1;
        /*看另一个大佬的blog说这是数据弱了才能这样暴力过
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