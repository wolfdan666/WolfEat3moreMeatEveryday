/*
2019年10月10日15:38:30 再次认真看题目
2019年10月10日16:17:28 懂了此题(中途情绪不太稳定,所以效率有点低...),花了40mins,菜啊

Define the sequence v1,v2,…,vk of k vertexes as good, if v is a subsequence of p, v1=p1, vk=pm,
and p is one of the shortest paths passing through the vertexes v1, …, vk in that order.

这里v是p的子串,他们首尾相同,然后p是v的最短路---> 我们最终要找到最短的v

tutorial : 
Firstly, find the matrix of the shortest paths using Floyd-Warshall algortihm or running dfs from all vertexes;
then a greedy approach works here: 
add p1 to the answer and then go along the path;
if the distance from the last vertex in the answer to the current vertex pi is shorter than in given path,
add the vertex pi−1 to the answer and continue traversing the path. Don't forget to add pm in the end!


*/

#include <bits/stdc++.h>
using namespace std;
int n,m,v[1000001],g[101][101];
vector<int> an;
char cc;
int main(){
	cin>>n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf(" %c", &cc);
			g[i][j]=cc-'0';
			if(!g[i][j])g[i][j]=1e9;
		}
		g[i][i]=0;
	}
	cin>>m;
	for(int i=0; i<m; ++i){
		scanf("%d",&v[i]);
		--v[i];
	}
	for(int k=0; k<n; ++k)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
	an.push_back(v[0]);
	int ls=0;
	for(int i=1; i<m; ++i){
		if(g[an.back()][v[i]] < i-ls){
			ls=i-1;
			an.push_back(v[i-1]);
		}
	}
	an.push_back(v[m-1]);
	cout<<an.size()<<endl;
	for(int x:an)
		printf("%d ", x+1);
	return 0;
}