/*
2019年9月7日14:10:16 看题
想法是直接找出所有长度大于t的串，然后去比较
不对，这个用样例2看起来很蠢...
所以我觉得应该是自己跑自动机，跑出最长的

- 前面的部分先跑大于t的
- 跑完大于t的地方后，开始随意跑

2019年9月7日14:38:13 感觉不太好写..自闭..先去喝个水

2019年9月7日15:39:16 傻逼了，cout没有注释就交了...
然后用计蒜客的测试说我超内存了！

这比TLE还难受...


傻逼...是subsequence，不是substring！
*/


#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N],t[N];
int ans,n,m;
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
        init();ans=0;
        scanf("%d%d",&n,&m);
        scanf("%s",s);scanf("%s",t);
        for(int i=0;i<n;i++)extend(s[i]-'a');
        // dfs一发
        // for(int p=1,i=0;i<n;i++){
        //     int x = i<m ? t[i] - 'a' : 0;
        //     for(int j=x;j<26;j++){
        //         if(a[p][j]) dp[a[p][j]]=dp[p]+1;
        //     }
        // }
        dfs(1,0,0);
        if(ans==0) ans = -1;
        printf("%d\n",ans );
    }
    // depth表示转移的深度
    void dfs(int p,int depth,bool ok){
        ans = max(ans,depth);
        if(!p) return ;
        int x = 0;
        if(!ok) x = depth<m ? t[depth] - 'a' : 0;
        for(int j=x;j<26;j++){
            if(a[p][j]){

               // cout<<char(j+'a')<<" "<<l[a[p][j]]<<endl;
               dfs(a[p][j],depth+1,ok||j>x);

            }

        }
    }

} sam;

int main(){
    sam.solve();
    return 0;
}