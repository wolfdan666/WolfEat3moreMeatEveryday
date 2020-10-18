/*
2019年9月5日16:14:42 开始看题
求两个串的最长公共字串，可以把他们连起来，然后看sa-link跳转
遍历后面串开始字符的所有节点,然后看跳转前后节点的共同的后缀长度最长是多少，
现在需要解决的问题是，如何找到后面串的第一个节点...在添加的时候就标记一下cnt值就可以了

2019年9月5日16:51:41 发现不对啊,这里fa[p]也必须是前面的啊！那这样答案不对啊---> 去看大佬怎么做

大佬:
对A建后缀自动机，然后用B去匹配，若能匹配上就转移到儿子，否则沿着parent树向上跳

我的补充:
先看当下B串中新加的字符x是否能通过上次匹配的后缀来转移，如果能转移就直接加，
否则就要跳到fa树上去匹配更短endpos为p的后缀(为了找到新加入的字符x的转移)，
然后在匹配到之后就是匹配到的长度+1(要加上刚进入的x字符的一个长度)

(果然大佬没有把B也加到自动机)

2019年9月5日17:26:54 AC
*/

#include<bits/stdc++.h>
using namespace std;
const int N=250010;
char s1[N],s2[N];
int ans;
struct sam{
    // 注意N是题目给的n的两倍,因为节点数最多有2*n-1个
      int p,q,np,nq,cnt,last,a[N<<1][26],l[N<<1],f[N<<1];
      sam(){cnt=0;last=++cnt;}
      void init(){
          cnt=0;last=++cnt;
          memset(a,0,sizeof(a));
          memset(l,0,sizeof(l));
          memset(f,0,sizeof(f));
      }
      void extend(int c){
            p=last;np=last=++cnt;l[np]=l[p]+1;
            while(!a[p][c]&&p)a[p][c]=np,p=f[p];
            if(!p)f[np]=1;
            else{
                  q=a[p][c];
                  if(l[p]+1==l[q])f[np]=q;
                  else{
                        nq=++cnt;l[nq]=l[p]+1;
                        memcpy(a[nq],a[q],sizeof(a[q]));
                        f[nq]=f[q]; f[np]=f[q]=nq;
                        while(a[p][c]==q)a[p][c]=nq,p=f[p];
                  }
            }
      }
      void solve(){
          init();
          scanf("%s",s1);scanf("%s",s2);
          int n=strlen(s1);
          for(int i=0;i<n;i++)extend(s1[i]-'a');
          ans = 0;n=strlen(s2);
          for(int i=0,p=1,tp=0;i<n;i++){
            int x = s2[i] - 'a';
            if(a[p][x]) tp++,p = a[p][x];
            else{
                for(;p&&!a[p][x];p=f[p]);
                if(!p) tp=0,p=1;
                else tp = l[p] + 1,p = a[p][x];
            }
            ans = max(ans,tp);
          }
          printf("%d\n",ans );
      }
}sam;
int T;
int main(){
    sam.solve();
    return 0;
}