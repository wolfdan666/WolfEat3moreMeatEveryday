/*
2019年9月3日20:44:23 开始看
2019年9月4日11:39:03 再看
主席树+SAM都是刚刚学了一点点皮毛，然后就要接受这种魔鬼题目训练，真是毒打

感觉后缀数组用的是各种后缀的前缀，而后缀自动机则是用前缀的后缀比较多，因为endpos就相当于前缀的感觉
后缀数组的LCP(Longest Common Prefix)问题等价于后缀树的最小公共祖先LCA(Least Common Ancestor)问题
前者是后缀的共同前缀，后者是前缀endpos的共同后缀(link)---> 也即sam构成的后缀link树的lca
有一点点的融会贯通的感觉真他妈的爽啊！

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

/*root[i]数组表示的是endpos为i的节点*/
int root[200010],num;
/*开了40倍的这里是主席树,若只考虑最大的大小和n次修改,每次log(n)的话,那么其实只要2n-1+nlog(n)就行
也就是只要19e5===>也可以直接n << 5 ,即(2^5)*n    */
struct Q{
    int L,R,sum;
} A[8000000];

/*
pos[i]=p;---> pos数组就是endpos数组,不懂可以参考[oi-wiki/sam](https://oi-wiki.org/string/sam/)
update(root[p],1,n,i,1);
*/
void update(int &x,int l,int r,int k,int v){
    /*下面三句话就是1. 获取之前的节点(之前也可能是空节点)信息
    2. 让当前的root[]等于新得到的id(sum)_3.然后在这个id上进行玩耍*/
    /*总体上就是记录一条新建的边上的所有信息,最主要的是维护权值--为了求出第k大*/
    /*我们从递归的角度看进去,发现每个node左右点都是从1开始一直加的，所以这就是权值主席树*/
    A[++num]=A[x];
    x=num;
    A[x].sum++;
    if(l==r) return;
    int mid=(l+r)/2;
    if(k<=mid) update(A[x].L,l,mid,k,v);
    else update(A[x].R,mid+1,r,k,v);
}
/*root[u]=mer(root[u],root[v],1,n);*/
int mer(int a,int b,int l,int r){
    if(a==0||b==0) return a+b;
    int z=++num,mid=(l+r)/2;
    if(l==r){
        /*因为sum要么一样,要么某一个为0,所以用'或'操作*/
         A[z].sum=A[a].sum|A[b].sum;
         return z;
    }
    A[z].L=mer(A[a].L,A[b].L,l,mid);
    A[z].R=mer(A[a].R,A[b].R,mid+1,r);
    A[z].sum=A[A[z].L].sum+A[A[z].R].sum;
    return z;
}
/*
u=qkth(root[p],1,n,a);
printf("%d\n",u-k+1);
返回的是endpos值...也就是返回的是串的右端点...也就是说答案是u-k+1
*/
int qkth(int x,int l,int r,int k){
    if(l==r) return l;
    int mid=(l+r)/2;
    if(k<=A[A[x].L].sum) return qkth(A[x].L,l,mid,k);
    else return qkth(A[x].R,mid+1,r,k-A[A[x].L].sum);
}

vector<int>g[200010];
int Fa[200010][25],pos[200010];
/*dfs(1)*/
void dfs(int u){
    int i,v;
    /*这里i为什么是<=19?...--->每次插入主席树一条边需要log(n),这题就是约等18左右,开到19是为了保险
    这里的大的Fa不是sam中的fa*/
    /*最最开始这里的初始化都是0,后面就是链状的，用i来dp，真是太巧妙了！
    比如Fa[u][0]=0;Fa[v][0]=u;Fa[w][0]=v.  那么Fa[w][1]=Fa[v][0]=u
    这就是dp叠层数了===> 所以后面使用的时候就直接用Fa[p][i]就行了*/
    for(i=1;i<=19;i++) Fa[u][i]=Fa[Fa[u][i-1]][i-1];
    for(i=0;i<g[u].size();i++){
        v=g[u][i];
        /*v的直接父亲是u...*/
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
            /*p就是转移之后的节点啊，所以就是说每个节点在主席树上都是一棵新树*/
            p=T[p][v];
            /*对，pos就是endpos，转移就是转移到下一个状态*/
            pos[i]=p;
            update(root[p],1,n,i,1);
        }
        /*前面生成g[]数组的时候,fa[i]最小值就是1,所以dfs(1)就是从源点跑到各个点去,然后合并每个endpos对应的所有后缀...*/
        dfs(1);


        int l,r,k,u,a;
        while(m--){
            scanf("%d%d%d",&l,&r,&a);
            /*获取endpos为r的状态点*/
            p=pos[r];
            /*这里的k竟然是长度...*/
            k=r-l+1;
            /*为啥又是19,这个是哪来的数字！==>难道说是一个log(n)的大小！好像是！
            那么这里的意思应该就是: 找出最短的长度大于要求的字串长的后缀
            然后如果对应的节点的权值不够a(其实就是题中说的k),那么直接输出-1
            否则就去主席树中找出答案，所以dfs(1)应该就是从源点出发找到终止节点之类的操作


            可得好好研究一下Fa数组的作用! 这里从它的作用来看就是用在了自成一体的fa树！就是
            答案中说的  扒出 parent树 ，然后利用这个来操作...找到这个串位置对应于主席树的位置
            因为之前的fa[]是与主席树没有任何联系的，所以我们需要这个Fa来构建联系
            */
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