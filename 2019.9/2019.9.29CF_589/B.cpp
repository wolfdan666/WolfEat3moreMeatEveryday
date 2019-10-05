/*
2019年09月29日21:11:54 开始看题
r[i] 标识 第i行的从左最大连续块
c[j] 则是从上开始连续块数

求满足给定的r[i],c[j]的形状总数
也就是说那些可以变动的块是t个,ans = 2^t

先暴力填充,cnt++,然后没有cnt过的地方就是的了,当然要注意cnt多右边一个

2019年09月29日21:31:52 交了B---> wa on test 2!!!
傻逼了,只测了test3就交了......

真傻比,样例给的cornor case都没测,你是故意wa 1 发吧....然后再交,wa on test 4
2019年09月29日21:41:28 先下一题看看吧


2019年09月29日22:28:35 看了cd的B才发现自己没有判断有矛盾的项目...就是列填了行不准填的位置!

改了改,然后又wa在test 11了 --->  2^0 次方是可以的!然后AC了

lxc大佬让我直接使用2^n^2 的暴力对拍,果然大佬
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
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
const int M = 1e3+10;
int h,w;
int r[M],c[M];
int cnt[M][M];


int main(){
	h=rd();w=rd();
	for(int i=0;i<h;i++){
		r[i] = rd();
		// for(int j=0;j<=r[i];j++) cnt[i][j]++;
		for(int j=0;j<=r[i];j++) cnt[i][j]++; cnt[i][r[i]]++;
	}
	for(int i=0;i<w;i++){
		c[i] = rd();
		// for(int j=0;j<=c[i];j++) cnt[j][i]++;
		for(int j=0;j<=c[i];j++) cnt[j][i]++; cnt[c[i]][i]++;
	}
	int q = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			if(!cnt[i][j]) q++;
			// 4不算!
			// else if(cnt[i][j]>=3){
			else if(cnt[i][j]==3){
				printf("%d\n",0 );		
				return 0;
			}
	}
	// 其实q=0也在之前没考虑,后面考虑了
	// 不对.只要前面都满足,这里是可以算一种的!
	// int ans = q ? qpow(2,q) : 0; 
	int ans = qpow(2,q); 

	printf("%d\n", ans);


    return 0;
}