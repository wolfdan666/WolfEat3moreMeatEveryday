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
        scanf("%lld",&v);
        LL k=(l^r^v)+1;
        /*获取有第k排名的不同字符的起始位置(sum见process函数)*/
        int pos=lower_bound(sum+1,sum+1+n,k)-sum;
        /*因为每个串都是  后缀 所以sum[pos]-(k-1)就能得到第k个起始的后缀长度！
        然后用n减去,就是k起始的位置！
        (字符串下标从0开始,可以用k=1,来模拟理解一遍) */
        LL tl=sa[pos],tr=n-(sum[pos]-k+1);
        l=tl,r=tr;
        int len=tr-tl+1;
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