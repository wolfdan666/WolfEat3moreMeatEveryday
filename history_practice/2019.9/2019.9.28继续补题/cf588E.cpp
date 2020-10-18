/* 
2019年09月27日08:55:23 开始看题

# 题意
- 自己可以是自己的祖先
- v节点美丽值 $x_v$(\nolarge $10^12$)
- 一条路径(u,v)的美丽值是f(u,v)最短路的所有节点的__gcd(u,...,v);
- 我们要求的的$\sigma$ f(u,v)  u 是 v的祖先(mod 1e9+7)   (**具体含义见题目中的note**)

# 思路
- 难道直接暴力求解? 我对这题想到的唯一方法是暴力求解 2019年09月27日09:22:36 
- tag 是 数论, 所以直接看tutorial学习一下吧,直接通过刷题学算法
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 10, mod = 1e9 + 7;
int n;
long long a[N], ans;
vector<int> gr[N];
void dfs(int v = 0, int par = -1, map<long long, int> bcnt = {}) {
	map<long long, int> cnt;
	cnt[a[v]]++;
	// 这里都是和父辈累积下来的gcd进行gcd,所以就是一整条链的gcd或者从链中某点开始的链一直下沿的某条链,所以是没有毛病的!
	for (auto p : bcnt)
		cnt[__gcd(p.first, a[v])] += p.second;
	for (auto p : cnt){
		ans = (ans + p.first * p.second) % mod;
        // cout<<"test: "<<p.first<<" "<<p.second<<endl;
    }
    // cout<<endl;
	for (auto u : gr[v])
		if (u != par) 
			dfs(u, v, cnt);
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		gr[x].push_back(y); gr[y].push_back(x);
	}
	dfs();
	cout << ans;
	return 0;
}