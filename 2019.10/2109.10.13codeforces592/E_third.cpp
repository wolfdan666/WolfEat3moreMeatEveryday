/*
发现自己总是为了代码效率牺牲了提交的时间,这很傻,因为目标是AC...所以以后看目的做事

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
ll k,tp,ttp;
bool f;

int main(){
	n = rd(); scanf("%lld",&k);
	rep(i,1,n) a[i] = rd();
	sort(a+1,a+n+1);
	int lw = 1,rw = 1,mi = a[1],mm = a[n];
	int l = 1,r = n;
	while(l<r){
		int tl = a[l+1] - a[l];
		int tr = a[r] - a[r-1];
		// tp = tl > tr ? tl*lw : tr*rw;
		if(tl > tr) tp = tl*lw, f = 0;
		else tp = tr*rw, f = 1;
		if(k > tp){
			k -= tp;
			if(f) rw++,r--; else lw++,l++;
		} else {
			int res = 0;
			if(f){
				// 发现一开始就要这样子比较权重啊!所以前面的情况判断错了...再改
				res = a[r] - (k/rw) - a[l];
				ttp = a[r] - (a[l] + k/lw); 
			}
		}

	}

    return 0;
}