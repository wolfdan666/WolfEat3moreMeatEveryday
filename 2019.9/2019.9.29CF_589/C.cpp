/*
看看C吧

我的思路肯定会T,自闭...

继续看一下B吧...

然后求助队友才AC B 的,之后因为收作业的那些事情,我由于卡题然后发了无语的`....`,被xj在群里喷了...哎,后面2019年09月29日23:00:59 也不会做C,D
先这样吧,多多练习吧,加油,失败和挫折是常态---> 我仍会心怀感恩,满怀敬畏,加油
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
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
ll x,n,ans=1;

ll f(ll p){
    ll m=n,sum=0;
    while(m) m/=p,sum+=m;
    return qpow(p,sum);
}

int main(){
    scanf("%lld%lld",&x,&n);
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            ans=ans*f(i)%mod;
            while(x%i==0) x/=i;
        }
    }
    if(x!=1) ans=ans*f(x)%mod;
    printf("%I64d\n",ans);

    return 0;
}