/*
2019年10月21日13:32:32 开始看题
2019年10月21日13:37:02 处理完A继续看

后面的x会变大，所以让权值最大的先用掉，让权值小的最后用

2019年10月21日13:55:04 RE on test 6？？？
(中途老妈发消息来了)
靠...2019年10月21日14:24:50 RE什么鬼...pass先

2019年10月21日14:35:16 我靠！我把cmp的>=改成 > 就AC了...玄学...,SPJ写的有点问题吧
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
const int M = 1e3+10;
struct node{
    int id,v;
} a[M];
int n;
bool cmp(node a,node b){ return a.v > b.v;}
ll ans;

int main(){
    n = rd();
    rep(i,1,n){
        a[i].id = i;
        a[i].v = rd();
    }
    sort(a+1,a+1+n,cmp);
    rep(i,0,n-1) ans+= a[i+1].v*i+1;
    printf("%lld\n", ans);
    rep(i,1,n) printf("%d%c", a[i].id," \n"[i==n]);

    return 0;
}