/*
2019年10月06日19:27:27 开始

简单贪心2019年10月06日19:31:05 开始写

2019年10月06日19:40:29 AC
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
int n,l,r;
int al,ar;

int main(){
	cin>>n>>l>>r;
	al = n-(l-1);		
	rep(i,1,l-1) al+=1<<i;

	rep(i,0,r-2) ar+=1<<i;
	ar+= (n-(r-1))*(1<<(r-1));

	printf("%d %d\n",al,ar );
    return 0;
}