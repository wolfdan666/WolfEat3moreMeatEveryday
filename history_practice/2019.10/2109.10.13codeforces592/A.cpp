/*
2019年10月13日17:05 开始看题
2019年10月13日17:14:37 交...读题有点慢-->AC

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
int t,a,b,c,d,k;
int ans;

int main(){
	t = rd();
	while(t--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int ans1 = ceil(1.0*a/c);
		int ans2 = ceil(1.0*b/d);
		ans = ans1+ans2;
		if(ans > k){
			ans = -1;
			printf("%d\n", ans);
		}
		else{
			printf("%d %d\n", ans1,ans2);
		}
	}

    return 0;
}