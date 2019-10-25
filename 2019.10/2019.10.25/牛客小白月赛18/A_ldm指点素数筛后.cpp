/*
原来题目指定线性筛,自闭,原来自己现在就是基础不扎实的下场...之前学习没有好好刷书本知识!--->所以只能通过题海来弥补了...不过还是要刷书!所以以后还是要刷一刷书!补齐基础

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
const int N = 3e7+1;
int prime[N] = {0},num_prime = 0;
bool isNotPrime[N] = {1, 1};
int f[N];
ll ans;
int n;

int main(){
    for(int i=2;i<N;i++){
        // 确定素数
        if(!isNotPrime[i]) prime[num_prime++]=i,f[i]=i;
        for(int j=0;j<num_prime && i*prime[j]<N;j++){
            int tp = i*prime[j];
            isNotPrime[tp] = 1;
            f[tp]=prime[j];
            if(!(i%prime[j])) break;//关键处2
        }
    }
    n = rd();
    rep(i,1,n) ans+=f[i];
    printf("%lld\n", ans);
    return 0;
}