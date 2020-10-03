/*
2020年10月03日11:02:39 今天的每日一题竟然是LeetCode第一题，真简单啊

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

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int> res;
		unordered_map<int, int> mymap;
		for (int i = 0; i < nums.size(); i++) {
			mymap[nums[i]] = i;
		}

		int temp = 0, i = 0, j = 0;
		for (; i < nums.size(); i++) {
			temp = target - nums[i];
			unordered_map<int, int>::const_iterator got = mymap.find(temp);
			if (got == mymap.end()) { // not found
				continue;
			}
			else{
				j = got->second;
				if (j == i){ continue; }
				else{ break; }
			}
		}

		if (i < j) {
			res.push_back(i);
			res.push_back(j);
		}
		else {
			res.push_back(j);
			res.push_back(i);
		}
		return res;
	}
};

int main(){


    return 0;
}