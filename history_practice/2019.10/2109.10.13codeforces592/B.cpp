/*
2019年10月13日17:15:06 开始读题
2019年10月13日17:21:06 应该是Z型走位,特判U型走位(首尾有1)
2019年10月13日17:22:52 就是贪心Z型和U型

2019年10月13日17:37:35 AC,写的时候犯傻了一下下
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
int t,n;
string s;

int main(){
	t = rd();
	while(t--){
		int ans = 0,cnt = 0;
		n = rd();
		cin>>s;
		int len = s.length();
		rep(i,0,len-1){
			if(s[i]=='1'){
				int tp = max(i+1,len-i) << 1;
				cnt++;
				// ans = max(tp,len+cnt);
				ans = max(ans,tp);

				// cout<<tp<<" "<<len+cnt<<" "<<cnt<<endl;
			}
			ans = max(ans,len+cnt);
		}
		printf("%d\n", ans);
	}



    return 0;
}