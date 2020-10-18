/*
2019年10月17日22:26:02 开始看题
n种礼物,每种无限个
然后m个朋友对应m个盒子
- 每个盒子中的每种礼物最多一个
- 每种礼物都应该被放置出去至少一个

2019年10月17日22:45:59 :
考虑每个盒子的种类数tp = C(n 0)+C(n 1)+...+C(n n),然后盒子组合就行了
ans = tp^m (mod mod)

用ll保平安,防止万一写丑了wa

发现一个尴尬的事情是n是10^9！傻逼，这个组合表达式可以写成2^n(对的,秒推)
因为之前做过的一个题中理解到的东西-->就是blog中写的20中颜色的那个题(今天还复习了)
可以从n中选0到n个,则相当于一个n长的2进制数，然后选与不选两种

测试发现一个事情就是我错了一个地方，没有遵循第二条规则
就是说每个东西都要必须给出去

所以还是要考虑成为添空格的排列组合

emm.室友在寝室开黑，自己思绪断了，算了，明天打吧...
现在2019年10月17日23:20:19 复习吧

2019年10月18日00:02:50 看大佬cout<<P(P(2,m)-1,n);


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
// ll
ll n,m,tp,ans;

int main(){
    scanf("%lld%lld",&n,&m);
    tp = qpow(2,n);
    ans = qpow(tp,m);
    printf("%lld\n", ans);

    return 0;
}