/*
2019年09月28日20:15:32 开始看题

2019年09月28日20:49:51 对自己ACM生涯大发尴尬一番...
然后决定直接看tutorial吧


1. 最多两种颜色
2. 自环就是两种颜色去涂
3. 否则直接一种颜色走个遍


看了tutorial感觉好简单啊,但是之前就是没有想到...
*/

#include<bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 55;

int n, m;
vector <pair<int, int> > g[N];
int col[N];
bool cyc;
int res[N];

void dfs(int v){
	col[v] = 1;
	for(auto p : g[v]){
		int to = p.first, id = p.second;
		if(col[to] == 0){
			dfs(to);
			res[id] = 1;
		}
		// dfs通过多条有向路径走到这里,但是还是没事的,不是环
		else if(col[to] == 2)
			res[id] = 1;
		// 这里是其他点又来到了已经访问的点col[to]=1!所以自环了
		else{
			res[id] = 2;
			cyc = true;
		}
	}
	col[v] = 2;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(make_pair(v, i));
	}
	
	for(int i = 0; i < n; ++i)
			if(col[i] == 0)
				dfs(i);

	cout << (cyc? 2 : 1) << endl;
	for(int i = 0; i < m; ++i) cout << res[i] << ' ';
	cout << endl;
	return 0;
}