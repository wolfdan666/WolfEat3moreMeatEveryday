/*
发现自己总是为了代码效率牺牲了提交的时间,这很傻,因为目标是AC...所以以后看目的做事


2019年10月13日18:55:15 交了,发现比赛交也不能lld啊,那看别人的提交代码怎么lld的? ---> 好像无视警告再交一次就行

wa on test 5...应该做C,D的...
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
ll n,a[M],ans;
ll k,tp,ttp,res;
bool f;

int main(){
	n = rd(); scanf("%lld",&k);
	rep(i,1,n) a[i] = rd();
	sort(a+1,a+n+1);
	ll lw = 1,rw = 1,mi = a[1],mm = a[n];
	ll l = 1,r = n;
	while(l<r){
		// 改善层数
		ll tl = a[l+1] - a[l];
		ll tr = a[r] - a[r-1];
		// 花费
		ll cl = tl*lw, cr = tr*rw;
		double tpl = 1.0*tl/cl,tpr = 1.0*tr/cr;
		// 发现一开始就要这样子比较权重啊!所以前面的情况判断错了...再改
		// res = (a[r] - k/rw) - a[l];
		// ttp = a[r] - (a[l] + k/lw);
		// 2019年10月13日18:37:50 感觉不对,自己这里写错了...傻逼了,我日...这里就是简单的比较rw,lw了,再认真理理思路

		// 应该是这样的,我贪心 改善层数/花费 , 够花都好说,主要处理不够花的情况
		if(tpl<tpr){
			if(k >= cr){
				k -= cr;
			} else {
				// 右边不够花,左边可能够花啊!
				if(lw < rw){
					if(k > cl){
						k -= cl;
						l++,lw++;
						continue;
					}
					else ans = a[r] - (a[l] + k/lw);
				}
				else{
					ans = (a[r] - k/rw) - a[l];
				}
				k = 0;
				break;
			}
			r--;rw++;
		} else {
			if(k >= cl){
				k -= cl;
			} else {
				if(lw < rw) ans = a[r] - (a[l] + k/lw);
				else{
					if(k > cr){
						k -= cr;
						r--;rw++;
						continue;
					}
					else ans = (a[r] - k/rw) - a[l];
				}
				k = 0;
				break;
			}
			l++,lw++;
		}
	}
	if(k){
		if(k&1) ans = 1; else ans = 0;
	}
	printf("%lld\n", abs(ans));

    return 0;
}