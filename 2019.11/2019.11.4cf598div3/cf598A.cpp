/*
2019年11月04日21:15:36 看到题目开始

2019年11月04日21:27:11 才交...
TLE on test 4!!!

sb 了一发
2019年11月04日21:32:54 AC
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
ll q,a,b,n,S;
bool f;

int main(){
    q = rd();
    while(q--){
        f = 0;
        a = rd();
        b = rd();
        n = rd();
        S = rd();
        // a*n+b>=S
        if(a*n+b<S){ printf("%s\n", "NO"); continue ;}
        // 0_b, n_n+b, ... , a*n_a*n+b
        // rep(i,0,a){
        //     ll tp = 1ll*i*n;
        //     if(tp <= S && S <= tp+b){
        //         printf("%s\n", "YES");
        //         f = 1;
        //         break;
        //     }
        // }
        else{
            ll tp = S%n;
            if(tp <= b){
                printf("%s\n", "YES");
                f = 1;
            }
        }
        if(f==0) printf("%s\n", "NO");
    }

    return 0;
}