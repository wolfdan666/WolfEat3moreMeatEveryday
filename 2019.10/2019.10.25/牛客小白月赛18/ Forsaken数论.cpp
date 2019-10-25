/*
好像就是一个素数筛

用素数筛,在本地都有2s左右!

2019年10月25日19:21:35 交了 , 应该会TLE

我以为是两个nlog(n),结果跑了这么久...

2019年10月25日19:23:24 先看C题吧


2019年10月25日19:31:51 过了C之后感觉自己很智障,素数筛不就可以求出所有的f[i]吗!
2019年10月25日19:37:13 又交了一发,感觉已经到我的极限优化了...再不过就不做这题了--->结果又TLE
2019年10月25日20:01:13 尝试DB失败...换一题吧
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
const int M = 3e7+10;
bool vis[M];
int f[M];
// set<int> v;
int n;
ll ans;

// 5mins才写完...这个
void pre(){
    f[1] = 0;
    // v.insert(2);
    rep(i,2,3e7+1){
        if(vis[i]) continue;
        vis[i] = 1;
        // v.insert(i);
        f[i] = i;
        for(int j = i;j<=M;j+=i){
            vis[j] = 1;
            f[j] = i;
        }
    }
}

void pre(int n){
    f[1] = 0;
    // v.insert(2);
    rep(i,2,n){
        if(vis[i]) continue;
        vis[i] = 1;
        // v.insert(i);
        f[i] = i;
        for(int j = i;j<=n;j+=i){
            vis[j] = 1;
            f[j] = i;
        }
    }
}

int main(){
    // 防止io卡pre,所以把pre放上面试试,这个O(n*log(n))吧?
    // 傻逼了,竟然自己想去复制3e7个数字,先写到文件里面啊!
    // freopen("out.txt", "w", stdout);
    // pre();
    // cout<<"{";
    // rep(i,1,(int)3e7) cout<<f[i]<<",}"[i==(int)3e7];
    // n = rd();
    // rep(i,2,n){
    //     if(v.find(i)!=v.end()) ans+=i;
    //     else for(auto x:v){
    //             if(i%x==0){
    //                 ans+=x;break;
    //             }
    //         }
    // }
    n = rd();
    pre(n);

    rep(i,1,n) ans += f[i];
    printf("%lld\n", ans);

    return 0;
}