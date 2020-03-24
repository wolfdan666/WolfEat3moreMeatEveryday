/*
19点开始读题目

2020年3月23日20:24:16 看群里有人说
C（n,1）*1 + C(n,2)*2 ... + C(n,n)*1 = n*2^(n-1)

2020年3月23日20:32:00 早知道第二题有坑就应该先第一题打表找规律的
现在爆零自闭了

明显不是组合数预处理...



作者：卖报人
链接：https://www.nowcoder.com/discuss/389640?type=post&order=time&pos=&page=1
来源：牛客网

第一题：N个人，任意选k个，再从k个里任选1个当队长，求总组合数

代码没记，大概是这样：
总数S = 0*C(N,0) + ... + i*C(N,i) + N*C(N,N)
倒着加：S +S  = N*(C(N,0) + ... + C(N,N) = N*2^(N)
所以 S = N*2^(N-1)
接下来只需要考虑计算2^(N-1)的快速计算方法就好了（简单2分递归即可）
时间复杂度O(logN)，可以AC

————————
2020年3月23日20:39:23 看巨佬代码，自己自闭了
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
// const int  M = 1e4;
// int C[M][M];
// void add(ll &a,ll v){
//     a += v;
//     if(a >= mod) a-=mod;
// }


// void pre(){
//     for(int i=0;i<M;i++) C[i][0]=1;
//     for(int i=1;i<M;i++){
//         for(int j=1;j<=i;j++){
//             C[i][j]=C[i-1][j-1]+C[i-1][j];
//             if(C[i][j]>=mod) C[i][j]-=mod;
//         }
//     }
// }

int n;

int main(){
    n = rd();
    // pre();
    ll ans = n*qpow(2,n-1)%mod;
    // rep(i,1,n) ans += i*C[n][i];

    cout<<ans<<endl;
    return 0;
}