// CF541D  2019年3月12日20:48:07 开始看题
// 2019年3月12日21:05:01 感觉自己想的思路不对，所以看了tutorial来写
// 先连起来，然后在vis的辅助下判断是否可行
// 2019年3月12日22:29:19 本地运行出现怪异错误，emmm，状态不佳，看看别人的code
// 2019年3月12日22:54:44看懂了别人写的code，但应该还是不会用！！！所有要多看，自己的算法应该不对，
// 而且还出现了好多异常，GG，不管了，状态不佳写的，Debug反而浪费时间,回去吧2019年3月12日22:57:46

#include<bits/stdc++.h>
using namespace std;
// int id[2010];// 一个从0开始，一个从1000开始
int id[2][1005];
char a[1005][1005];// a[1000010] 这种一般用在动态中
bool vis[2][1005];// changable,就是如果有等于的话就不能再伸缩了,true表示不能再伸缩了

int main(int argc, char const *argv[])
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%c",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    id[0][0]=0; vis[0][0]=1;
    int ma=-10000;int mi=10000;
    for(int i=0;i<m;i++){
        if(a[0][i]=='='){
            id[1][i]=0;
            vis[1][i]=true;
        }
        else if(a[0][i]=='>'){
            id[1][i]=-1;

            cout<<id[1][i]<<" do down what  ";

            mi = min(mi,-1);
        }
        else{
            id[1][i]=1;
            ma = max(ma,1);
        }

    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='='){
                if(vis[0][i]&&a[0][i]!=a[1][j]){printf("No\n");return 0;}
                id[0][i]=id[1][j];
                vis[0][i]=true;
            }
            else if(a[i][j]=='<'){
                if(vis[0][i]&&a[0][i]>=a[1][j]){printf("No\n");return 0;}
                id[0][i]=id[1][j]-1;
                mi = min(mi,id[0][i]);
            }
            else{
                if(vis[0][i]&&a[0][i]<=a[1][j]){printf("No\n");return 0;}
                id[0][i]=id[1][j]+1;
                ma = max(ma,id[0][i]);

                cout<<id[0][i]<<" <-up down->"<<id[1][i]<<" end    ";

            }
        }
        cout<<endl;
    }
    int d=ma-mi+1;
    for(int i=0;i<n;i++){
        printf("%d%c", id[0][i]+d,i==n-1?'\n':' ');
    }
    for(int i=0;i<m;i++){
        printf("%d%c", id[1][i]+d,i==m-1?'\n':' ');
    }
    return 0;
}


// By Changyu, contest: Codeforces Round #541 (Div. 2), problem: (D) Gourmet choice, Accepted, #
 #include<cstdio>
const int N=1002;//边从小往大连   // 从注释看出是中国同胞
int n,m,p[N+N],g[N+N][N+N],d[N+N],q[N+N],l,r=-1,f[N+N];char a[N][N];
int Find(int k){return k==p[k]?k:p[k]=Find(p[k]);}

int main(){
    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",a[i]+1);  // cin
    for(u=1;u<=n+m;u++)p[u]=u; // 初始化自点
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='=')p[Find(i)]=Find(j+n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          if(a[i][j]!='='){
            u=Find(i),v=Find(j+n);
            if(u==v)return 0*puts("No");
            else{
              if(a[i][j]=='>'&&!g[v][u])g[v][u]=1,d[u]++;// v->u 也就是小往大
              if(a[i][j]=='<'&&!g[u][v])g[u][v]=1,d[v]++;
            }
          }
    for(u=1;u<=n+m;u++)
        if(!d[u]) // 所有未定值去bfs   // 这里是找到最小的，没有弟弟的人
            f[u]=1,q[++r]=u;
    for(;l<=r;){
      u=q[l++];
      for(v=1;v<=n+m;v++)
        if(g[u][v]&&!--d[v])q[++r]=v,f[v]=f[u]+1;// d[v]必须为1,也就是只有u指向v的时候，否则不添加v，而是减掉v的一条邻边
    } // 小的指向大的，而且逐渐加1
    for(u=1;u<=n+m;u++)
        if(d[u]) return 0*puts("No");
    puts("Yes");
    for(u=1;u<=n;u++)
        printf("%d ",f[Find(u)]);
    puts("");
    for(u=n+1;u<=n+m;u++)
        printf("%d ",f[Find(u)]);
    return 0;
}