/*
2019年10月08日14:02:08 开始借鉴学习安师大附中中学生大佬LittleBeetle的代码
2019年10月08日14:20:49 看完init()  有点慢,加油
2019年10月08日14:49:57 看完AC.build()
2019年10月08日15:14:40 又一次卡在了为什么要使用位运算上面...
2019年10月08日15:43:22 还是不懂...这位运算也太骚了

2019年10月08日19:50:46 再在网上找大佬写的tutorial,发现一个[大佬](https://ycdzj.xyz/ti-jie-codeforces-1207g/)如下下到

```
AC自动机+树状数组+离线询问+树上dfs序……厉害了出题人。

```
**树状数组**......我就说为啥这个位运算这么熟悉,又那么陌生...因为树状数组太菜了(只看过一次,但没有做题...),导致看晕了两天...

*/

// 59470538	Aug/25/2019 23:34UTC+8	LittleBeetle	G - Indie Album	GNU C++11	Accepted	561 ms	89100 KB
// By LittleBeetle, contest: Educational Codeforces Round 71 (Rated for Div. 2), problem: (G) Indie Album, Accepted, #
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int N=400002;
int n,q,i,j,k,opt,h[N],tt[N],v[N],ans[N];
char ch[3],s[N],ti[N];
vector<int>p[N],id[N];
void add(int a,int b){
	// tt 记录的是 trie 的fa指向节点值
	// h[a] 记录的是上一次的节点的id值 hash
	// 看AC.dfs()发现,h[a]记录的应该是最后一个a指向的节点,而tt则记录的是同一层节点的前向路径,所以不是什么trie,而是一个奇特的最右儿子兄弟树!
	// 因此可以AC.dfs()可以通过使用这样的for循环 `for(int j=H[i];j;j=to[j])` 访问整个一层的节点
	tt[++k]=h[a];
	h[a]=k;
	// 这里v[k] 就是记录的是id节点的value, 用int 记录 char 是没有关系的
	v[k]=b;
}
struct AC{
	int cnt,t[N][26],fail[N],q[N],l,r,i,j,k;
	int H[N],to[N],V[N],dfn[N],sz[N],Tim,c[N],loc[N];
	int insert(char *s){
		for(i=j=1;s[j];j++){
			if(!t[i][s[j]-97])
				t[i][s[j]-97]=++cnt;
			i=t[i][s[j]-97];
		}
		return i;
	}
	void add(int a,int b){
		to[++k]=H[a];
		H[a]=k;
		V[k]=b;
	}
	// 深度遍历右儿子以及右儿子的兄弟,统计size的值
	void dfs(int i){
		// dfn 是 各个节点被深度遍历的顺序的hash记录
		dfn[i]=++Tim;
		sz[i]=1;
		for(int j=H[i];j;j=to[j])
			dfs(V[j]),sz[i]+=sz[V[j]];
	}
	void Build(){
		// bfs的l,r的写法
		// 根节点用的是1
		l=0;r=-1;
		for(j=0;j<26;j++)
			if(t[1][j])
				fail[t[1][j]]=1,add(1,t[1][j]),q[++r]=t[1][j];
			else
				t[1][j]=1;
		while(l<=r){
			i=q[l++];
			for(j=0;j<26;j++)
				if(t[i][j])
					fail[t[i][j]]=t[fail[i]][j],add(fail[t[i][j]],t[i][j]),q[++r]=t[i][j];
				else
					t[i][j]=t[fail[i]][j];
		}
		dfs(1);
	}
	// 这是一个反向树状数组,所以序数小的节点是大节点(父节点)
	void Add(int x,int y){
		while(x)
			c[x]+=y,x-=x&-x;
	}
	int Query(int x){
		int s=0;
		while(x<=cnt)
			s+=c[x],x+=x&-x;
		return s;
	}
	void DFS(int i){
		Add(dfn[loc[i]],1);
		// 测试发现,i=0等一些没有到过的值的时候,是不会进入for的...
		for(int j=0;j<p[i].size();j++){
			ans[id[i][j]]=Query(dfn[p[i][j]])-Query(dfn[p[i][j]]+sz[p[i][j]]);

			cout<<"i: "<<i<<" j: "<<j<<" id[i][j] "<<id[i][j]<<"  Q:dfn[p[i][j]] "<<Query(dfn[p[i][j]])<<" Query(dfn[p[i][j]]+sz[p[i][j]]): "<<Query(dfn[p[i][j]]+sz[p[i][j]])<<endl;
		}
		// 卡很久一个点,注意这里的for循环也是右儿子及其兄弟的遍历方式...===> 而且这里是要查询自动机的初始串的遍历!!!!!
		for(int j=h[i];j;j=tt[j]){
			// 这里是跑AC自动机的核心,失配之后 从i跑向j,然后再DFS
			// 对的,跑自动机的时候是不用fail的,然后在这里跑下去,所以先算好了下面的,然后回溯算好了上面的
			// 每一小块都要把对应的树状数组部分清除掉

			// 2019年10月08日21:21:13 突然那么一瞬间,总算想清楚了多一点点
			// 比如你dadada,然后AC自动机上只有模式串da,所以你虽然dfs向下走dadada,但是你每次添加的位置都是loc[v[i]],所以这里是一个比较松的耦合!
			loc[v[j]]=t[loc[i]][s[v[j]]-97];
			DFS(v[j]);
		}
		Add(dfn[loc[i]],-1);
	}
	void work(){
		loc[0]=1;
		DFS(0);
	}
}T;
void init(){
	T.cnt=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++,j=0){
		scanf("%d",&opt);
		if(opt==2)
			scanf("%d",&j);
		add(j,i);
		scanf("%s",ch);
		s[i]=*ch;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%d%s",&j,ti+1);
		p[j].push_back(T.insert(ti));
		id[j].push_back(i);
	}
}
int main(){
	init();
	T.Build();
	T.work();
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}