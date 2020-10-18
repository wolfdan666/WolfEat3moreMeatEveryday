#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2010,M=4100;
int Case,n,m,i,j,k,cb,b[N],pos[N];ll pre[M],suf[M],s[M],v[M],ans;
struct E{int x,y,z;}e[N];
inline bool cmp(const E&a,const E&b){return a.x<b.x;}

/*用纵坐标建的线段树，大佬对于线段树的理解以及如同我对1+1的理解一样了！*/
void build(int x,int a,int b){
  pre[x]=suf[x]=s[x]=v[x]=0;
  if(a==b){
    pos[a]=x;
    return;
  }
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
inline void change(int x,int p){
  x=pos[x];
  s[x]+=p;
  if(s[x]>0)pre[x]=suf[x]=v[x]=s[x];else pre[x]=suf[x]=v[x]=0;
  /*上传的操作精辟,orz*/
  for(x>>=1;x;x>>=1){
    /*根的左边的 = max(左子树之前的,左子树+右子树之前的)*/
    pre[x]=max(pre[x<<1],s[x<<1]+pre[x<<1|1]);
    /*根的右边的 = max(右子树右边的,右子树+左子树右边的)*/
    suf[x]=max(suf[x<<1|1],s[x<<1|1]+suf[x<<1]);
    /*s是直接叠加的*/
    s[x]=s[x<<1]+s[x<<1|1];
    /*区间最大值 = max(左子树最大,右子树最大,左子树后面的+左子树前面的)*/
    v[x]=max(max(v[x<<1],v[x<<1|1]),suf[x<<1]+pre[x<<1|1]);
  }
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(cb=0,i=1;i<=n;i++){
      scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
      b[++cb]=e[i].y;
    }
    /*离散化纵坐标*/
    sort(b+1,b+cb+1);
    for(m=0,i=1;i<=cb;i++)if(i==1||b[i]!=b[m])b[++m]=b[i];
    /*给横坐标排序*/
    sort(e+1,e+n+1,cmp);
    ans=0;
    /*用离散化后的纵坐标覆盖掉原来的纵坐标*/
    for(i=1;i<=n;i++)e[i].y=lower_bound(b+1,b+m+1,e[i].y)-b;
    /*枚举上边界，x是行号，是上边界*/
    for(i=1;i<=n;i++)if(i==1||e[i].x!=e[i-1].x){
      build(1,1,m);
      /*加入点确定好下边界，这样上下边界都确定好了*/
      for(j=i;j<=n;j=k){
        /*又是逐步插入空树维护区间最大值的操作*/
        for(k=j;k<=n&&e[j].x==e[k].x;k++)change(e[k].y,e[k].z);
        if(ans<v[1])ans=v[1];
      }
    }
    printf("%lld\n",ans);
  }
}