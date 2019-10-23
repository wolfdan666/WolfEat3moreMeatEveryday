/*
2019年10月23日20:30:14 开始看题

这里n是1e4,而且是多个q,所以我觉得可以直接打表,列出3个各个次方的排列组合得到的值
3^11>1e4
O(2^11 = 2048的排列)

2019年10月23日20:41:35 看了一下hard版的n在1e18的量级,所以应该有更好的做法.所以暂时先不写打表,可以直接想一下最好的做法

哦哦,其实就是直接的凑数模拟去做减法,但是这个减法不一定可以做到不重不漏...而且1e18...等下,1e18也没有多少位啊===39位...很多位了...2^40次方,1e12次方的排列.两秒也会TLE!
要不先写easy版?2019年10月23日20:47:51 先去喝个水
我知道了,可能到达某一个值之后就一直都是那一个值最小,然后就不用变了,所以这里就是一个巨大的剪枝
不对,我之前写过一篇blog,就是写的排列中的dp的,那样可以把循环的次数直接降下来吧? 那个涂颜色的题目

害,还是差点什么,不会写,先写第一个暴力的吧

2019年10月23日21:10:32 过了简单版的也有点小开心,果然自己现在还是一个div3的选手,菜哭
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
int q,n,m,p[12];
vector<int> ans;

void pre(){
    p[0] = 1;
    rep(i,1,11){
        p[i] = 3*p[i-1];
    }
    rep(i,1,(1<<11)-1){
        int tp = 0;
        rep(j,1,11){
            if(i&(1<<(j-1))) tp += p[j-1];
        }
        ans.pb(tp);
    }
    sort(ans.begin(), ans.end());
}

int main(){
    // cout<<log(40010)/log(3)+1<<endl;
    // cout<<log(1e18+10)/log(3)+1<<endl;
    pre();
    q = rd();
    while(q--){
        n = rd();
        int i = lower_bound(ans.begin(), ans.end(),n) - ans.begin();
        printf("%d\n", ans[i]);
    }

    return 0;
}