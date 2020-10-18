#include<bits/stdc++.h>
using namespace std;
const int maxn=4005;
const int E=2000;
typedef long long ll;
const ll M=1000000007;
ll f[maxn],nf[maxn],inv[maxn],dp[2][maxn];
int n,m;
ll C(ll x,ll y){
    return f[x]*nf[y]%M*nf[x-y]%M;
}
ll K(ll x){
    return C(x*2,x)*inv[x+1]%M;
}
void add(ll &x,ll y){
    x+=y; if (x>=M) x-=M;
}
int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=f[i-1]*i%M,nf[i]=nf[i-1]*inv[i]%M;
    while (scanf("%d%d",&n,&m)==2){
        memset(dp,0,sizeof(dp));
        dp[0][E]=1;
        for (int i=0;i<(n+m)*2;i++){
            int o=i&1;
            for (int j=E-n;j<=E+m;j++){
                if (j>E-n) add(dp[o^1][j-1],dp[o][j]);
                if (j<E+m) add(dp[o^1][j+1],dp[o][j]);
                dp[o][j]=0;
            }
        }
        cout << dp[0][E] << endl;
    }
    return 0;
}