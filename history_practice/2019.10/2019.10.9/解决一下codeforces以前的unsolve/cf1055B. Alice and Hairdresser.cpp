/*
2019年10月09日15:06:15 开始看题
2019年10月09日15:15:08 发现就是一个简单的dsu,并查集,   自己平时写dsu比较少,所以尝试写一下先
2019年10月09日15:20:19 发现自己好像不会怎么快速得到并查集的总个数,去看一下tutorial...或者看书吧
2019年10月09日15:23:05突然想到可以在getfa中嵌入cnt变量就行,算了,先学习一波并查集
2019年10月09日15:33:01 学习完毕,开始搞

2019年10月09日16:15:52 总算写完了这个mlog(n) `log(n)的dsu`的算法,发现自己以前写的是m*n--> 1e10的BF算法,笑死
2019年10月09日16:17:23 WA了...

2019年10月09日16:22:35 感觉今天的评测机真的跑得好慢呀...佛了,昨天被ddos打慢了?  AC了,真好
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
const int M = 1e5+10;
int n,m,l,t,p,d,a[M];
set<int> s;

// 因为这是自己的dsu(Disjoint-Set)的入门题,所以把板子放在一起写了,以后就可以写得自由一点
int fa[M];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}

int get(int x){
	if(x == fa[x]) return x;
	return fa[x] = get(fa[x]); // 路径压缩,递归访问直到根节点
}

void merge(int x,int y){
	fa[get(x)] = get(y);
}

// 以下才是本题要用的
int myget(int x){
	if(fa[x] == 0) return 0;
	if(x==fa[x]){ s.insert(x); return x; }
	return fa[x] = get(fa[x]);
}

void mymerge(int x,int y){
	int tp = get(x);
	s.erase(tp);
	fa[tp] = get(y);
}

int main(){
	scanf("%d%d%d",&n,&m,&l);
	rep(i,1,n){
		a[i] = rd();
		// if(a[i]>=l){
		if(a[i]>l){
			if(myget(i-1)) fa[i] = myget(i-1);
			// else fa[i] = i;
			else fa[i] = i,s.insert(i);
		}
	}
	while(m--){
		t = rd();
		if(t){
			scanf("%d%d",&p,&d);
			a[p]+=d;
			if(myget(p)) continue;
			// else{ WA了
			else if(a[p]>l){
				// if(myget(p-1)) fa[p] = myget(p-1);
				if(myget(p-1)){
					fa[p] = myget(p-1);
					if(myget(p+1)) mymerge(p+1,p-1);
				}
				else if(myget(p+1)) fa[p] = myget(p+1);
				// else fa[p] = p;
				else fa[p] = p,s.insert(p);
			}
		} else {
			printf("%d\n",s.size());
		}

	}

    return 0;
}
