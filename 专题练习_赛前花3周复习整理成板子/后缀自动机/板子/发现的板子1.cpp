#include<bits/stdc++.h>
using namespace std;
const int N=250010;
char s1[N];
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
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<n;i++)extend(s[i]-'a');



        printf("%d\n",ans );
    }
} sam;
int T;
int main(){
    sam.solve();
    return 0;
}