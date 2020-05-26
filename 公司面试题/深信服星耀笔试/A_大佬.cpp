#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}

int mat[15][15];
int line[15];
int dp[15][2200];
int res;
const int MOD = 1e8;
int N,M;

int main(){
    N = rd(); M = rd();
    rep(i,0,N-1){
        rep(j,0,M-1){
            mat[i][j]=rd();
            // 用bit位压缩状态
            line[i] = line[i]*2 + (mat[i][j]==0 ? 1:0);
        }
    }
    // 处理第一行的
    rep(j,0,(1<<M)-1){
        // line[0]是第1行的所有列状态 line[0]的最左边的那一位( line[0]<<(M-1) ) 表示第一行第一列的状态
        // 所以这里的意思是没有石头也没有相邻
        if( (j & line[0]) == 0 && (j & (j<<1)) == 0 ){
            dp[0][j] = 1;
        }
    }

    // 处理后面的行，因为这个要考虑上面一行
    rep(i,1,N-1){
        // 各层遍历状态
        rep(j,0,(1<<M)-1){
            // 此层 有相邻 or 有石头就跳过
            if( (j & (j<<1)) != 0 || (j & line[i]) != 0 ) continue;
            // 与上层不相邻则叠加
            rep(k,0,(1<<M)-1){
                if((j&k) == 0) dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
            if(i == N-1) res = (res+dp[i][j])%MOD;
        }
    }
    printf("%d\n", res);

    return 0;
}

/*
2 3
0 1 1
1 1 0

8
*/