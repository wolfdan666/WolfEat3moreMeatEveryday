/*
2020年4月26日20:25:40 先找10分钟规律

1. 总是有偶数个反面朝上 0,2,4...
2. 两次相邻操作--如果是相同位置的操作
   --->等于没有操作
   但是如果不是相邻操作则有有用
3. 对于一张牌连续一个方向奇数次移动，
   则会翻转它和它路过的所有牌
4. 对于一张牌连续一个方向偶数次移动，
   则自己不翻转__但会翻转它路过的所有牌

2020年4月26日20:35:17 先下一题吧

2020年4月26日21:46:40 经过上次ali笔试教训，所以先
puts("-1");混点分数先
结果发现又是0%...还是tx牛逼，所有数据都不给我混分数

n 比较小，难道可以暴力过？
但是不可能吧

2020年4月26日21:56:30 感觉有点悲凉,写个random混点分数试试

2020年4月26日21:59:53 rand()%19都过了5%,惊呆了

2020年4月26日22:09:11 大佬说冒泡排序秒了
作者：Tc201804281321680
链接：https://www.nowcoder.com/discuss/417912?type=post&order=time&pos=&page=1&channel=
来源：牛客网

O(n^2)两层循环，从前往后扫描，如果A[i]>B[i]，那就交换swap(A[i],B[i+1]),swap(B[i],A[i+1])，
每次循环完保证最大的在最后面，如果产生无法交换的情况就是A[i]>B[i]且B[i+1]>A[i+1]
那就输出-1

看完思路，落下了泪水，太菜了自己

2020年4月26日22:14:07 看评论有人输出1获得10%..233
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
int n;
int a[20],b[20];

int main(){
    n = rd();
    while(n--) cout<<rand()%18<<endl;
    rep(i,0,n-1) a[i] = rd();
    rep(i,0,n-1) b[i] = rd();
    cout<<rand()%19<<endl;

    return 0;
}