/*
2019年10月13日18:04:05 想到了比类似单调栈,但更简单的思路

2019年10月13日18:11:11 发现自己想到的第二种逐层法竟然被样例1血喷...我智障了,没有好好看题

2019年10月13日18:13:14 所以就改善成两端法...早点认真看样例就没有那么多B事了
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
	int w = 1,mm = a[n];
	rep(i,1,n-1){
		ll　tp = 1ll*w*(a[i+1] - a[i]);
		if(k > tp){
			k -= tp;
			w++;
			a[i] = a[i+1];
		} else {
			ans = mm - (a[i] + k/w);
		}
	}

    return 0;
}