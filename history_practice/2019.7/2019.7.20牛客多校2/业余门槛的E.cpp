#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
const int MOD=1E9+7;
int n,m,q,b[50010][11];
char s[20];
struct Matrix
{
    int a[11][11];
    friend Matrix operator*(const Matrix&a,const Matrix&b)
    {
        Matrix c;memset(c.a,0,sizeof(c.a));
        rep(i,m)rep(k,m)rep(j,m)c.a[i][j]=(c.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%MOD;
        return c;
    }
}tree[200010];
void work(int b[11],Matrix&ans)
{
    memset(ans.a,0,sizeof(ans.a));
    rep(i,m)
    {
        int j=i;
        for(;j>=1&&!b[j];ans.a[i][j]=1,j--);
        j=i;
        for(;j<=m&&!b[j];ans.a[i][j]=1,j++);
    }
}
void build(int p,int le,int ri)
{
    if(le==ri){work(b[le],tree[p]);return;}
    int mid=(le+ri)>>1;
    build(p<<1,le,mid);
    build(p<<1|1,mid+1,ri);
    tree[p]=tree[p<<1]*tree[p<<1|1];
}
void modify(int p,int le,int ri,int x)
{
    if(le==ri){work(b[le],tree[p]);return;}
    int mid=(le+ri)>>1;
    if(x<=mid)modify(p<<1,le,mid,x);
    else modify(p<<1|1,mid+1,ri,x);
    tree[p]=tree[p<<1]*tree[p<<1|1];
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    rep(i,n){scanf("%s",s+1);rep(j,m)b[i][j]=s[j]-'0';}
    build(1,1,n);
    rep(i,q)
    {
        int opt,x,y;
        scanf("%d%d%d",&opt,&x,&y);
        if(opt==1)
        {
            b[x][y]^=1;
            modify(1,1,n,x);
        }
        else printf("%d\n",tree[1].a[x][y]);
    }
    return 0;
}