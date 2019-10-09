/*
2019年10月09日13:51:06 开始看题
2019年10月09日14:18:19 才交...,27mins...太菜了吧...AC了...原来以前自己这么菜,看来还是有点进步,不过自己现在每天很难感到进步,所以还是要多多练习
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
int t,n,x,y,d,ans;

int main(){
	t = rd();
	while(t--){
		n = rd(); x = rd(); y = rd(); d = rd();
		ans	= inf;
		int tp = abs(x - y);
		if(tp % d){
			// if((y-1)%d==0) ans = min(ans,int(ceil(x-1)/d+(y-1)/d));
			// if((y-1)%d==0) ans = min(ans,int(ceil((x-1)/d)+(y-1)/d));
			if((y-1)%d==0) ans = min(ans,int(ceil(1.0*(x-1)/d)+(y-1)/d));
			if((n-y)%d==0) ans = min(ans,int(ceil(1.0*(n-x)/d)+(n-y)/d));
			if(ans == inf) ans = -1;
			// cout<<ceil((x-1)/d)<<" fi "<<(y-1)/d<<endl;
		} else ans = tp / d;
		printf("%d\n",ans);
	}

    return 0;
}