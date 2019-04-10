// 夜深了，那写点简单的题目吧12:10开始看题
// HDU1024 每一个区块都是从正到正(包含长度为1的自己到自己)
// 思路：计算连续的正数块数k：1.k<=m就是直接ans=正数块的和  2.m>k,那么选择m-k块较小的负数块来填充(例如example2)

#include<bits/stdc++.h>
using namespace std;
const int M = 1e6+5;
const int N = 5e5+10;
int m,q;
int a[M],p[N],n[N];

bool cop(int a,int b){return a>b;}

// int mian(){  // 昨天晚上居然错在这里，我服了
int main(){
    ios::sync_with_stdio(false);
    while(cin>>m>>q){
        int pk=0,nk=0;
        n[0]=-32768;
        int f=1;//f 0表示前一块是负，1表示前一块是正，假定最开始的前一块是正，那么巧妙地使得第一块负为0(如果a[0]为正)
        // a[0]的 0表示第一块是负数,1表示第一块是正数(决定了舍不舍弃第一个负数块)(比不记录一个负数块更易实现)
        for(int i=0;i<q;i++){
            cin>>a[i];
            if(f){
                if(a[i]>=0){
                    p[pk]+=a[i];
                }
                else{
                    n[++nk]+=a[i];
                    f=0;// 居然忘了翻转...昨晚真是智障巅峰啊
                }
            }
            else{
                if(a[i]<0){
                    n[nk]+=a[i];
                }
                else{
                    a[++pk]+=a[i];
                    f=1;
                }
            }
        }
        long long ans=0;
        // sort(p,p+nk,cop);
        sort(p,p+pk,cop);
        sort(n,n+nk,cop);
        if(nk<=m){
            for(int i = 0; i < nk; i++){
                ans+=p[i];
            }
        }
        else{
            int t = m-pk;
            for(int i=0;i<m;i++){
                if(i<t) ans+=n[i];//t次
                ans+=p[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}