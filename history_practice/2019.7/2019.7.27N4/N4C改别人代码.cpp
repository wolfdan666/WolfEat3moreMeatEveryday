#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=3e6+7;
typedef long long LL;

int aa[maxn];

struct node{
    int l,r;
    LL sum,lsum,rsum;  //sum为区间和，lsum最小前缀，rsum最小后缀
}tr[maxn<<2];
//L[i]~R[i]为满足a[i]为最小的最大区间
int n,p,a[maxn],L[maxn],R[maxn],stk[maxn];
LL ans;

node gets(node a,node b){
    node t;
    t.l=a.l,t.r=b.r;
    t.sum=a.sum+b.sum;
    t.lsum=min(a.lsum,a.sum+b.lsum);
    t.rsum=min(b.rsum,b.sum+a.rsum);
    return t;
}

void build(int v,int l,int r){
    tr[v].l=l,tr[v].r=r;
    if(l==r){
        tr[v].sum=a[r];
        tr[v].lsum=min(a[r]*1LL,0LL);
        tr[v].rsum=min(a[r]*1LL,0LL);
        return;
    }
    int mid=(l+r)>>1;
    build(v<<1,l,mid);
    build(v<<1|1,mid+1,r);
    tr[v]=gets(tr[v<<1],tr[v<<1|1]);
}

void query(node &x,int v,int l,int r){
    if(l<=tr[v].l&&r>=tr[v].r){
        x=gets(x,tr[v]);
        return;
    }
    int mid=(tr[v].l+tr[v].r)>>1;
    if(l<=mid) query(x,v<<1,l,r);
    if(r>mid) query(x,v<<1|1,l,r);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&aa[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    a[0]=a[n+1]=0xcfcfcfcf;
    stk[p=0]=0;   //利用单调栈求L[i],R[i]
    for(int i=1;i<=n;++i){
        while(a[stk[p]]>=a[i]) --p;
        L[i]=stk[p]+1;
        stk[++p]=i;
    }
    stk[p=0]=n+1;
    for(int i=n;i>=1;--i){
        while(a[stk[p]]>=a[i]) --p;
        R[i]=stk[p]-1;
        stk[++p]=i;
    }
    build(1,1,n);
    for(int i=1;i<=n;++i){
        if(a[i]>0){
            node t;
            t.sum=t.lsum=t.rsum=0;
            query(t,1,L[i],R[i]);
            if(a[i]*t.sum>ans) ans=a[i]*t.sum;
        }
        else if(a[i]<0){
            LL tmp=0;
            node t;
            t.sum=t.lsum=t.rsum=0;
            query(t,1,L[i],i);
            tmp+=t.rsum;
            t.sum=t.lsum=t.rsum=0;
            query(t,1,i,R[i]);
            tmp+=t.lsum;
            tmp-=a[i];
            if(tmp*a[i]>ans) ans=tmp*a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}