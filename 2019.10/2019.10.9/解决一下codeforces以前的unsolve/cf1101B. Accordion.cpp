/*
2019年10月09日14:20:09 开始看题
2019年10月09日14:25:08 感觉应该是个傻逼Brute Force题啊!

2019年10月09日14:43:45 暴力你也现在才写完...23mins,还是太菜了...

2019年10月09日14:47:22 还在等结果...发现有几百发测试样例!---惊了!
GNU C++11	Running on test 383	0 ms	0 KB 

2019年10月09日14:48:22 看了一下以前自己写的这题的代码,发现以前自己好傻,只判断了一重Accordion

2019年10月09日14:50:33 发现判到505发了...真佛了,这是多少test?
2019年10月09日14:51:06 533
2019年10月09日14:51:33 571... 感觉要判10mins.......
2019年10月09日14:52:09 AC了,588发,判了9mins...惊了
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
const int M = 5e5+10;
char s[M];
int ans = -1;

int main(){
	scanf("%s",s);
	int state = 0,precnt = 0,cnt = 0;
	rep(i,0,strlen(s)-1){
		switch(state){
			case 0 : if(s[i]==char(91)) state = 1;
				break;
			case 1 : if(s[i]==char(58)) state = 2;
				break;
			case 2 :
				if(s[i] == char(124)) cnt++;
				else if(s[i] == char(58)){
					precnt = cnt;
					state = 3;
				}
				break;
			case 3 :
				if(s[i] == char(124)) cnt++;
				else if(s[i] == char(58)){
					precnt = cnt;
					state = 3;
				} else if(s[i] == char(93)){
					ans = precnt + 4;
				}
				break;
		}
	}
	printf("%d\n",ans);

    return 0;
}
