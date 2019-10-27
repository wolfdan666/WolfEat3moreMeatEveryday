/*
2019年10月27日10:40:14 开始看题

2019年10月27日10:46:00 感觉就是使用电梯或者走楼梯的一种简单dp吧

2019年10月27日10:52:26 想到还要考虑连续坐电梯的优惠
如果相等的话,优先做电梯?对的,这样就不用下次花费

2019年10月27日11:01:55 交 --- wa on test 11
2019年10月27日11:17:06 感觉没有问题...看一下tutorial
感觉自己和tutorial的写法就一点点偏差啊,思路完全一样啊'


2019年10月27日12:03:09 想清楚了自己错在哪里了,这里的dp只能dp状态
两种情况不能一起贪心! --->

- 因为假设乘坐电梯的代价c很大,然后b每次只是略微小于a
- 那么就基本上每步最优都是选a
- 但是当层数很多的时候,b积累的优势就出来了,这样子就可以坐电梯了!(算法功底是长期发展的电梯!)
- 因此不能只贪每一小步,要两者兼顾,备份
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
const int M = 2e5+10;
int n,c,a[M],b[M];
// int dp[M];
int dp[M][2];

int main(){
    n = rd();c = rd();
    rep(i,2,n) a[i]=rd();
    rep(i,2,n) b[i]=rd();
    // bool ok = 0;
    // rep(i,2,n){
    //     if(!ok){
    //         if(dp[i-1]+b[i]+c<=dp[i-1]+a[i]){
    //             dp[i] = dp[i-1]+b[i]+c;
    //             ok = 1;
    //         } else {
    //             dp[i] = dp[i-1]+a[i];
    //             ok = 0;
    //         }
    //     } else {
    //         if(dp[i-1]+b[i]<=dp[i-1]+a[i]){
    //             dp[i] = dp[i-1]+b[i];
    //             ok = 1;
    //         } else {
    //             dp[i] = dp[i-1] + a[i];
    //             ok = 0;
    //         }
    //     }
    // }
    // rep(i,1,n) printf("%d%c",dp[i]," \n"[i==n]);
    mem(dp,inf);
    dp[1][0]=0,dp[1][1]=c;
    rep(i,2,n){
        dp[i][0] = min(dp[i][0],dp[i-1][1]+a[i]);
        dp[i][0] = min(dp[i][0],dp[i-1][0]+a[i]);
        dp[i][1] = min(dp[i][1],dp[i-1][1]+b[i]);
        dp[i][1] = min(dp[i][1],dp[i-1][0]+b[i]+c);
    }
    rep(i,1,n) printf("%d%c",min(dp[i][0],dp[i][1])," \n"[i==n]);

    return 0;
}