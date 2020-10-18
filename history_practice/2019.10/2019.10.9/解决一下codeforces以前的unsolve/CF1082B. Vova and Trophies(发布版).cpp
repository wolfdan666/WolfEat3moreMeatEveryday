#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
const int M = 1e5+10;
int n,s1,s2,s3,ans,state;
char s[M];

int main(){
	n = rd();
	scanf("%s",s); 
	rep(i,0,n-1){
		switch(state){
			case 0 : 
				if(s[i]=='G') state = 1,s1=1,ans = max(ans,s1+s3);
				break;
			case 1 : 
				if(s[i]=='G') s1++,ans = max(ans,s1+s3);
				else if(s[i]=='S') state = 2;
				break;
			case 2 : 
				if(s[i]=='G') state=3,s2=1,ans = max(ans,s1+s2+s3);
				else{
					ans = max(ans,s1+s3);
					state = 6;
				}
				
				break;
			case 3 : 
				if(s[i]=='G') s2++,ans = max(ans,s1+s2+s3);
				else{
					ans=max(ans,s1+s2+s3);
					state = 4;
				}
				break;
			case 4 : 
				if(s[i]=='G'){
					ans=max(ans,s1+s2+1);
					s3=1,s1=s2,s2=1;
					state = 3;
				} else {
					// 之前状态三遇到银之前的遇到金都有维护,所以这里可以不维护
					state = 5;
				}
				break;
			case 5 : 
				if(s[i]=='G'){
					s3=1;
					ans=max(ans,s1+s2+s3);

					s1=1,s2=0;

					state = 1;
				}
				break;
			case 6 : 
				if(s[i] == 'G'){
					ans = max(ans,s1+1);
					s1=1,s3=1;
					state = 1;
				}
				break;
		}

	}
	printf("%d\n", ans);

    return 0;
}