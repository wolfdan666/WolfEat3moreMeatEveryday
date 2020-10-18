/*
2019年10月06日13:29:51 开始看题
2019年10月06日13:37:46 觉得是一个见世面的题,所以猜它是利用位运算的一个巧妙的性质,因为我不太会,所以直接看tutorial

2019年10月06日14:06:38 自己看了tutorial,感觉好像它的高低位是不是操作反了,懵逼了老半天,直到自己去google了一下,发现大佬的说法才懂,加速啊
看了下面大佬的解读,发现原来自己一直过分关注了错误的东西...

借鉴自: https://blog.csdn.net/sdz20172133/article/details/100567411
因为题目最多给你14位，0异或x=x，
- 我们可以先异或高7位为0的数，得到ans的高七位。
- 异或低7位为0的数，得到ans的低七位。

2019年10月06日14:18:28 AC(50mins,龟速...加油啊)
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
int ans,ansh,ansl;

int main(){
	cout<<"?";
	rep(i,1,100) cout<<" "<<i; cout<<endl;
	fflush(stdout);
	cin>>ansh;

	cout<<"?";
	rep(i,1,100) cout<<" "<<(i<<7); cout<<endl;
	fflush(stdout);
	cin>>ansl;

	ans |= ansh & (((1<<7)-1)<<7);
	ans |= ansl & (1<<7)-1;

	printf("! %d\n",ans);

    return 0;
}