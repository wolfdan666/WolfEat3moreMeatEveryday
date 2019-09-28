/*
2019年09月28日19:07:27 开始看题
2019年09月28日19:26:27 浪学Latex一会儿...

SAM是可以处理出所有的子串和出现次数的.然后通过长度是否和i相等去判断?
但是tag给的是BF算法啊!
2019年09月28日19:31:20 决定看一下tutorial...不行,先SAM试试--->SAM要是要知道串的字符信息好像不能这样啊!感觉应该是自己想多了
2019年09月28日19:33:26 自己又想了一下,好像可以直接Dp啊,因为pair新增的都是以新增字符为最右的pair 是**真实新增**(很像前缀的后缀233)
但是这样的DP要O(n^2)啊,想想怎么优化==>对啊,可以想想怎么使用前面的数据!不然怎么叫DP!
2019年09月28日19:43:49 艹,想太久了,不行!看tutorial吧
艹,看了tutorial才发现只有大约O(18*n)的样子.因为再长一点就会不够了,要注意的是这样也要对s[i]=1的位置特殊处理下
因为相距18个1的话,那么数据太大,2<<18=262144 > 2·10^5了,更何况不会拿整个串长去比这个相差的1,因为你串长上去了,数值就飙升更快了 
挺有技巧!!!

# 条件
t $\in$ [1,1000]

给一个串 s ,|s| $\in$ [1,2·$10^5$]

$\sum_{i=1}^t |s_i|$ $\leq$  $2·10^5$

# tutorial

At first, lets precalc the array nxt1,nxt2,…,nxtn. The value of nxti if equal the maximum position j in range 1…i 
such that s_j=1.

After that lets iterate over the right boundary of substring and high 1-bit position (denote it as r and l respectively).

Note that if r−l>18 then f(l,r)>2·10^5.

So we iterate over such pair (l,r) that 1≤l≤r≤n and r−l≤18.

Lets look at value f(l,r). If f(l,r)>r−l+1, then we have to 
increase the length of substring without increasing the value of f(l,r).
 So we need to check if there exists a position nl such that f(nl,r)=f(l,r) and r−nl+1=f(nl,r).(所以可以推断是向l左边寻找0)
  This position exists if the condition f(l,r)≤r−nxtl−1 is met (nxt0 is equal to -1).
*/

// tutorial
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int t;
string s;
int nxt[N];

int main() {
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> s;
		// 找到i之前由后向前第一个s[i]=1的位置
		for(int i = 0; i < s.size(); ++i)
			if(s[i] == '1') nxt[i] = i;
			else nxt[i] = (i == 0? -1 : nxt[i - 1]);		
		int res = 0;
		for(int r = 0; r < s.size(); ++r){
			int sum = 0;
			for(int l = r; l >= 0 && r - l < 20; --l){
				if(s[l] == '0') continue;
				sum += 1 << (r - l);
				// 这个1的位置减去前一个1的位置,这样就得到了本身1和多的前导0个总长度(所以这里可以直接大于等于)
				if(sum <= r - (l == 0? -1 : nxt[l - 1]))
					++res;
			}
		}
		cout << res << endl;
	}	

	return 0;
}