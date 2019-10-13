/*
2019年10月13日17:41:00 不小心看了E题,觉得好短,题意明朗,于是先写了

2019年10月13日17:55:30 发现想简单了,赶快回去写C,D
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
const int M = 2e5+10;
int n,a[M],ans;
ll k;

int main(){
	n = rd(); scanf("%lld",&k);
	rep(i,1,n) a[i] = rd();
	sort(a+1,a+n+1);
	int mx = a[n];
	rep(i,1,n){
		int tp = mx - a[i];
		if(tp && k > tp){
			k -= tp;
		}
		else{
			if(tp==0){
				if(k&1) ans = 1;
			}
			else{
				// k<tp的时候,这种情况自己想简单了...果然这题没这么简单...
			}
		}
	}

    return 0;
}