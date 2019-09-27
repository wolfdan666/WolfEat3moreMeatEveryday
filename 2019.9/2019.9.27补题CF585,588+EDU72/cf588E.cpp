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

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}


int main(){
	// cout<<__gcd(8,0)<<endl;  // 8

    return 0;
}