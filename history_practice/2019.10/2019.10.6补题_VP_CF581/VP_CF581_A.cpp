/*
2019年10月06日19:15:44 开始
2019年10月06日19:26:36 AC,主要卡题意...
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
string s;
int ans;

int main(){
	cin>>s;
	int len = s.length();
	if(len%2==0) cout<<len/2<<endl;
	else{
		rep(i,1,len-1){
			if(s[i]=='1') ans = 1;
		}
		cout<<ans+len/2<<endl;
	}

    return 0;
}