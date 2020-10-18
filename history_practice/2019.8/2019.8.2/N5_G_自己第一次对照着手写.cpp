/*
因为还是不太熟悉，所以2019年8月2日14:46:12 第一次是看着std写的
然后只过了10%...原来自己手残把t写成了s
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int M = 3005;
int T,n,m;
char s[M],t[M];
ll C[M][M],dp[M][M];

void add(ll &a,ll v){
    a += v;
    if(a >= mod) a-=mod;
}

void pre(){
    for(int i=0;i<M;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=mod) C[i][j]-=mod;
        }
    }
}

void solve(){
    ll ans = 0;
    /*枚举非0前导*/
    for(int i=n-1;i>=0;i--){
        if(s[i]!='0'){
            /*后缀(长度<=n-1-i)加前导总长度大于m+1的组合数都要加入*/
            for(int j=m;j<=n-i-1;j++){
                add(ans,C[n-1-i][j]);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }
    /*以t为主导.枚举t的位置,m-1-i就是t的后缀长度
    然后j是s的位置*/
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            /*这里累加前面的东西*/
            add(dp[j][i],dp[j+1][i]);
            if(s[j]>t[i]){
                /*如果当前位置大于的话,就是加上组合数*/
                add(dp[j][i],C[n-1-j][m-1-i]);
            }
            else if(s[j]==t[i]){
                /*如果相等的话，后面后缀长度-1(也即这里长度+1)的部分也可以叠加起来*/
                add(dp[j][i],dp[j+1][i+1]);
            }
        }
    }
    add(ans,dp[0][0]);
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    pre();
    cin>>T;
    while(T--){
        cin>>n>>m;
        cin>>s>>t;
        solve();
    }

    return 0;
}