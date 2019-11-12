/*
2019年11月12日20:22:44 开始看题

肚子痛，去一下WC

2019年11月12日20:31:35 回来了

序列个数1e4,所有的序列中数字个数加起来是1e6

加上len不总是相同，可以直接跑n^2的暴力比较

样例竟然是从0开始计数的... 不过我也sb,因为我vector竟然没有从0开始用...

2019年11月12日20:53:17 交暴力...只过了20%
2019年11月12日21:00:11 突然想到我的i值多次pb了...
2019年11月12日21:02:24 交第二发---还是wa on 20%...

2019年11月12日21:06:19 突然发现自己读错题目了...因为一列重复的读完之后就不能再访问了！那更简单一点！

2019年11月12日21:14:14 交第三发,wa on test 80%...
```
对应输出应该为:

no

你的输出为:
空.请检查一下你的代码，有没有循环输入处理多个case
```

出题人没说要输出no...

2019年11月12日21:17:14 终于AC..只剩下10mins...还有前4题看一遍觉得不太会写...去看看(因为一开始没状态)
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
const int M = 1e4+10;
int n;
struct nd{
    int len;
    vector<int> S;
} a[M];
vector<int> anstp;
vector< vector<int> > ans;
// 被插入了的可以直接剔除掉
bool inserted[M];

int main(){
    n = rd();
    rep(i,0,n-1){
        int len = rd();
        a[i].len = len;
        rep(j,0,len-1){ int tp = rd(); a[i].S.pb(tp);}
    }

    rep(i,0,n-2){
        anstp.clear();
        if(inserted[i]) continue;
        rep(j,i+1,n-1){
            if(inserted[j]) continue;
            if(a[i].len == a[j].len){
                bool ok = 1;
                rep(k,0,a[i].len-1){
                    if(a[i].S[k] != a[j].S[k]) { ok = 0;break; }
                }
                if(ok){
                    if(!inserted[i]) anstp.pb(i),inserted[i]=1;
                    if(!inserted[j]) anstp.pb(j),inserted[j]=1;
                }
            }
        }
        if(!anstp.empty()) ans.pb(anstp);
    }
    bool no = 1;
    for(auto x:ans){
        for(auto y:x) no=0,printf("%d ", y);
        puts("");
    }
    if(no) puts("no");

    return 0;
}