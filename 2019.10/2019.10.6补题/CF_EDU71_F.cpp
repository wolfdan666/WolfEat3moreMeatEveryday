/* 
2019年10月06日14:18:38 开始看题
乍一看,发现这个好像是线段树的板子裸题...
2019年10月06日14:31:07 仔细一看发现并不是线段树题...

2019年10月06日15:06:08 中途看到休息了10mins...继续加油

sum[i][x % i] 中的x  表示的是 x 是 [模i][余数为x%i] 的集合 中的一个


2019年10月06日15:27:52 为啥我写的测样例最后一个是8???什么鬼?  冷静,淡定
2019年10月06日15:41:22 测试发现原来我使用的lxc大佬的快读是没有判断正负号的快读!所以赶紧改,还好是在训练的时候就发现了

2019年10月06日15:48:55 5e5+10,被自己写成沙雕的1e5... 傻逼,发现codeforces的报错简直良心到你妈都不认识你!直接在错误的地方标红!还给数据,最好的oj平台!没有之一!
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
// inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
// const int M = 1e5+10;
const int M = 5e5+10;
const int K = 750;
int q,t,x,y,a[M],sum[K][K];

inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}


int main(){
	q = rd();
	while(q--){
		t = rd(); x = rd(); y = rd();
		// cout<<t<<"  "<<x<<"  "<<y<<endl;
		// 把这一行改成scanf之后,样例输出的最后一个就不是8了,就变成0了
		// scanf("%d %d %d", &t, &x, &y);
		if(t==1){
			a[x] += y;
			rep(i,1,K-1){
				sum[i][x%i] += y;
			}
		} else {
			if(x >= K){
				int ans = 0;
				for(int i=y;i<=500000;i+=x) ans+=a[i];
				printf("%d\n", ans);
			} else {
				printf("%d\n", sum[x][y]);
			}
		}
	}

    return 0;
}