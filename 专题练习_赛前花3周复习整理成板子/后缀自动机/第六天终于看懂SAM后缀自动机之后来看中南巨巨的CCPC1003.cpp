/*
2019年9月3日20:44:23 开始看

题意:
T组,N次询问,  l,r这个子串的第k次出现
*/


#include<iostream>
#include<complex>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<string.h>
using  namespace std;
char s[100010];
int T[200010][30],fa[200010],len[200010],cnt,last,n;

/*这里是建立SAM.大佬的板子真滴简洁..*/
void build(int v){
    int i,p=last,np,q,nq;
    last=np=++cnt;
    len[np]=len[p]+1;
    for(;p&&T[p][v]==0;p=fa[p]) T[p][v]=np;
    if(p==0) fa[np]=1;
    else{
        q=T[p][v];
        if(len[q]==len[p]+1) fa[np]=q;
        else{
            nq=++cnt;
            len[nq]=len[p]+1;
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            for(i=0;i<27;i++) T[nq][i]=T[q][i];
            for(;T[p][v]==q;p=fa[p]) T[p][v]=nq;
        }
    }
}

int root[200010],num;
/*开了40倍的这里是主席树,若只考虑最大的大小和n次修改,每次log(n)的话,那么其实只要2n-1+nlog(n)就行
也就是只要19e5===>也可以直接n << 5 ,即(2^5)*n    */
struct Q{
    int L,R,sum;
}A[8000000];

void update(int &x,int l,int r,int k,int v){
    A[++num]=A[x];
    x=num;
    A[x].sum++;
    if(l==r) return;
    int mid=(l+r)/2;
    if(k<=mid) update(A[x].L,l,mid,k,v);
    else update(A[x].R,mid+1,r,k,v);
}
int mer(int a,int b,int l,int r){
    if(a==0||b==0) return a+b;
    int z=++num,mid=(l+r)/2;
    if(l==r){
         A[z].sum=A[a].sum|A[b].sum;
         return z;
    }
    A[z].L=mer(A[a].L,A[b].L,l,mid);
    A[z].R=mer(A[a].R,A[b].R,mid+1,r);
    A[z].sum=A[A[z].L].sum+A[A[z].R].sum;
    return z;
}
int qkth(int x,int l,int r,int k){
    if(l==r) return l;
    int mid=(l+r)/2;
    if(k<=A[A[x].L].sum) return qkth(A[x].L,l,mid,k);
    else return qkth(A[x].R,mid+1,r,k-A[A[x].L].sum);
}

vector<int>g[200010];
int Fa[200010][25],pos[200010];
void dfs(int u){
    int i,v;
    for(i=1;i<=19;i++) Fa[u][i]=Fa[Fa[u][i-1]][i-1];
    for(i=0;i<g[u].size();i++){
        v=g[u][i];
        Fa[v][0]=u;
        dfs(v);
        root[u]=mer(root[u],root[v],1,n);
    }
}


int main(){
    int i,m,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        cnt=last=1;
        memset(T,0,sizeof(T));
        for(i=0;i<=200000;i++) g[i].clear();

        /*构建SAM*/
        for(i=1;s[i];i++) build(s[i]-'a');
        /*i的后缀link放入i,也就是g表示源点到终止节点的方向,fa数组的反hash*/
        for(i=1;i<=cnt;i++) g[fa[i]].push_back(i);
        int p=1,v;

        memset(root,0,sizeof(root));
        A[0].L=A[0].R=A[0].sum=num=0;
        /*插入构建主席树*/
        for(i=1;s[i];i++){
            v=s[i]-'a';
            p=T[p][v];
            pos[i]=p;
            update(root[p],1,n,i,1);
        }
        dfs(1);


        int l,r,k,u,a;
        while(m--){
            scanf("%d%d%d",&l,&r,&a);
            p=pos[r];
            k=r-l+1;
            for(i=19;i>=0;i--) if(len[Fa[p][i]]>=k) p=Fa[p][i];
            if(a>A[root[p]].sum) printf("-1\n");
            else{
                u=qkth(root[p],1,n,a);
                printf("%d\n",u-k+1);
            }
        }
    }
    return 0;
}