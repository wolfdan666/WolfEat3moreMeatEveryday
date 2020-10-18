/* 
2019年10月03日20:42:22 开始看题

2019年10月03日20:53:50 想法,因为只有固定的几种结构,所以可以从左到右简单的min--dp!
主要是自己傻逼B题 没有看清题目条件,然后疯狂讨论最优解...傻逼


2019年10月05日19:43:16 再看来补题
直接看了tutorial...
然后借鉴tutorial的代码写的...可以的,加油
2019年10月05日20:23:55 才AC...看tutorial还花了40mins.太菜了啊!

This task was designed as a simple dynamic programming problem, but it also can be solved greedily.

The dp solution is following: when we have already built some prefix of the pipeline all we need to
know is the length of the prefix the height of the pipeline's endpoint (1 or 2).
 So we can calculate the following dynamic programming: 
 d[pos][add] is the minimal answer for prefix of length pos with pipeline at height 1+add.
 Transitions are quite straightforward: if s[pos]=0 then 
we can either leave the pipeline on the same level, or change it.
 If s[pos]=1 then we have to stay on the height 
2. Look at the source code for the formal transitions. The answer is d[n][0].

The greedy solution is based on the following fact: let's look at some subsegment consisting of 0's.
 It's always optimal either to leave this subsegment on height 1 or raise it to height 2.
  We can calculate the amount we have to pay in both cases and choose the optimal one.
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
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
const int M = 2e5+10;
int T;
int n,a,b;
char s[M];
// 傻逼定义数组,段错误...
// ll d[M][M];
ll d[M][2];

int main(){
    T = rd();
    while(T--){
        scanf("%d%d%d",&n,&a,&b);
        scanf("%s",s);
        memset(d,0x3f,sizeof d);
        d[0][0] = b;
        rep(i,0,n-1){
            if(s[i]=='0'){
                // keep the same height. 保持高度
                d[i+1][0] = min(d[i+1][0],d[i][0]+a+b);
                d[i+1][1] = min(d[i+1][1],d[i][1]+a+2*b);
                // change. 做改变
                d[i+1][0] = min(d[i+1][0],d[i][1]+2*a+b);
                d[i+1][1] = min(d[i+1][1],d[i][0]+2*(a+b));
            } else {
                // 是1的话,整个高度都要在高度2
                d[i+1][1] = min(d[i+1][1],d[i][1]+a+2*b);
            }
        }
        printf("%lld\n",d[n][0]);
    }
    
    return 0;
}