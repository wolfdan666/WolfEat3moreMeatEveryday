/*
2019年9月5日14:37:34 开始看题
2019年9月5日14:53:28 真滴没有看懂这个题目的意思...所以每天必须开始复习单词！加入日事清--看下大佬们怎么理解这题吧..

最小表示法：https://blog.csdn.net/remember_your_dream/article/details/70669867
题意：给一个字符串，求循环同构串中 最小同构的起点。

关于字符串的循环同构 ：例如 s = ‘aabaa’，则其所有的循环同构串为 abaaa，baaaa，aaaab，aaaba，即把这个串视为循环的，
取遍所有可能的起点。 最小表示法求得是所有同构串中字典序最小的起点位置。


SAM: http://forever97.is-programmer.com/2016/9/1/uva719.205609.html
【题目大意】

    给出一个字符串，求出与其循环同构的字符串中，字典序最小的一个。



【题解】

    以原字符串的两倍建立自动机，按字典序在parent树上搜索，得到的第一个长度为n的字符串就是答案。
*/

/*SAM做法  要开2倍串长！所以整体节点就是4倍！RE一发...*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=10005;
char s[N];
struct sam{
    // 注意N是题目给的n的两倍,因为节点数最多有2*n-1个
      int p,q,np,nq,cnt,last,a[N<<2][26],l[N<<2],f[N<<2];
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
          scanf("%s",s);
          int n=strlen(s),len=n;
          for(int k=0;k<2;k++)for(int i=0;i<n;i++)extend(s[i]-'a');
          int p=1;
          while(n--){
              for(int i=0;i<26;i++)if(a[p][i]){
                  p=a[p][i];break;
              }
          }printf("%d\n",l[p]-len+1);
      }
}sam;
int T;
int main(){
    scanf("%d",&T);
    while(T--)sam.solve();
    return 0;
}


// 最小表示法也能AC
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10005;

int main()
{
    int n;
    scanf("%d",&n);
    char s[maxn];
    while(n--)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        int len = strlen(s);
        int p = 0, q = 1;
        while(p < len && q < len){
            int i;
            for(i = 0; i < len; i++)
                if(s[(p+i)%len] != s[(q+i)%len]) break;
            if(i == len) break;

            if(s[(p+i)%len] > s[(q+i)%len]) p += i+1;
            else q += i+1;
            if(p == q) q++;
        }
        printf("%d\n",min(q,p)+1);
    }
    return 0;
}