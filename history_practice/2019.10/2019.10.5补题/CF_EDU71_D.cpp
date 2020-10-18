/*
2019年10月05日20:25:16 开始看题
p1,p2,---,pn就是对pair进行排序

2019年10月05日20:44:40 感觉肯定不会暴力枚举吧(中途浪了10mins...)

看了tutorial,用的是反面法,正难则反,从反面求解,太精妙了
2019年10月05日21:09:54 先理解后,开始仿写
2019年10月05日21:35:35 才AC...真的太慢了!!!

Let's suppose that all n! permutation are good. We counted the permutations giving the sequences 
where the first elements are sorted (we denote the number of such permutations as cnt1) and the permutations
giving the sequences where the second elements are sorted (we denote the number of such permutations as cnt2).
Then the answer is n!−cnt1−cnt2, right? No, because we subtracted the number of sequences where first and 
second elements are sorted simultaneously (we denote this number as cnt12) twice. So, the answer is n!−cnt1−cnt2+cnt12.

How can we calculate the value of cnt1? It's easy to understand that the elements having equal ai can be arranged in any order. 
So, cnt1=c1! c2! … cn!, where cx is the number of elements equal to x among ai. cnt2 can be calculated the same way.

How can we calculate the value of cnt12? First of all, there is a case where it is impossible to arrange the elements of the sequence 
so that the first elements and the second elements are sorted. To check that, we may sort the given sequence comparing two elements by ai, 
and if ai are equal — by bi. If the sequence of second elements in the resulting sequence is not sorted, then cnt12=0. Otherwise, 
equal elements of the given sequence can be arranged in any order. So cnt12=cs1! cs2! csk!, where s1, s2, ..., sk are the elements that 
appear in the given sequence of pairs at least once.
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
const ll mod=998244353;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
const int M = 3e5+11;
int n;
pair<int,int> a[M];
int f[M];

int mul(int a,int b){return 1ll*a*b%mod;}
int sum(int a,int b){return (a+b)%mod;}

int main(){
	n = rd();
	rep(i,0,n-1){
		a[i].fi = rd(); a[i].se = rd();
	}
	f[0] = 1;
	rep(i,1,M) f[i] = mul(i,f[i-1]);

	int ans = f[n];
	rep(c,0,1){
		int d = 1;
		sort(a,a+n);
		int l = 0;
		while(l<n){
			int r = l+1;
			while(r<n && a[l].fi == a[r].fi) ++r;
			d = mul(d,f[r-l]);
			l = r;
		}
		ans = sum(ans,mod - d);
		rep(i,0,n-1) swap(a[i].fi,a[i].se);
	}

	sort(a,a+n);
	int l = 0;
	int d = 1;
	while(l<n){
		int r = l+1;
		while(r<n && a[l].fi == a[r].fi) ++r;
		map<int,int> m;
		rep(i,l,r-1) ++m[a[i].se];
		for(auto p:m) d = mul(d,f[p.se]);
		l = r;
	}
	rep(i,1,n-1) if(a[i-1].se > a[i].se) d = 0;

	ans = sum(ans,d);
	printf("%d\n", ans);

    return 0;
}