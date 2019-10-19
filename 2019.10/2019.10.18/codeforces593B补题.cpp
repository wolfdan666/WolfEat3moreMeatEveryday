/*
题解：
- 考虑每种礼物(共有n种)的放置方式，有m个盒子，tp = C(n 1)+C(n 2)+...+C(n n) = 2^n - 1
- 然后总共有n种，所以选择n次，也就是tp^n

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
int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    cout<<qpow(qpow(2,m)-1,n)<<endl;

    return 0;
}