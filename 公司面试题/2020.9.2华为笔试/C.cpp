/*
2020年9月2日20:31:25 开始看题

2020年9月2日20:31:56 经典背包问题啊！
现有容量下最大价值问题

2020年9月2日20:37:15 感觉华为笔试挺符合大众水平的，贪心，dfs，背包

但是这个dp背包我有点忘了...

2020年9月2日20:45:11 WC(看资料)之后继续
dp[i][j] 前 i 个物品 ，j 容量最大价值

2020年9月2日20:58:14 wa了！

2020年9月2日21:01:59 交了，没看到最后一题的结果，就交卷了...

2020年9月2日21:06:11 不过应该wa了，或者mle...(本地能过应该是偶然)
因为二维的时候应该是
f_{i,j} = max(f_{i-1,j}, f_{i-1,j-v_i} + w_i)
而不是 同 i , 后面是 i - 1
(要前面的状态转移)

*/

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
int K,N;
int dp[1024][1024];
// v容量，w价值
int v[1024],w[1024];

int main(){
    K = rd();
    N = rd();
    rep(i,1,N) v[i] = rd();
    rep(i,1,N) w[i] = rd();

    rep(i,1,N){
        //
        // rep(l,v[i],K){
        //     dp[i][l] = max(dp[i][l], dp[i][l-v[i]]+w[i]);
        // }

        // (要前面的i-1状态转移)
        rep(l,0,K-v[i]){
            dp[i][l+v[i]] = max(dp[i][l]+w[i], dp[i][l+v[i]]);
        }

        // 不管是"人人为我"还是"我为人人",这里都反复拿了w[i],是物品无限拿的解法
        rep(l,0,K-v[i]){
            f[l+v[i]] = max(f[l] + w[i], f[l+v[i]]);
        }

        // 应该是这样的
        per(l,K,v[i]){
            f[l] = max(f[l], f[l-v[i]] + w[i])
        }
    }


    cout<< dp[N][K] <<endl;

    return 0;
}