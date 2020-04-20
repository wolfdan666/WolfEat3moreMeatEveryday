/*
2020年3月8日10:41:25 看到这个题目显然是无限背包问题，需要动态规划
无限背包有点忘...

从暴力枚举递归到DFS记忆搜索到DP： https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/

2020年3月8日11:19:36.... 龟速

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
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// 2020年4月19日17:44:40 感觉好像也可以贪心
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 2020年4月19日18:02:15 wa在了 [1] 0...我-1，ans=0
        if(amount==0) return 0;
/*
2020年4月19日18:07:31 又wa了
输入：
[186,419,83,408]
6249
输出：
-1
预期：
20

贪心果然会漏情况，还是动规遍历了所有的情况！！

*/

        int n = coins.size();
        // sort(coins,coins+n);
        sort(coins.begin(), coins.end());
        int ans = 0,left = amount;
        // for(int i=n-1;i>=0;i++){
        for(int i=n-1;i>=0;i--){
            ans += left/coins[i];
            left %= coins[i];
        }
        if(left || ans==0) return -1;
        return ans;
    }
};

int main(){
    Solution2 s;
    int a[] = {1,2,5};
    int target = 11;
    cout<<"sizeof a:" << sizeof a << endl;
    cout<<"sizeof(a):" << sizeof(a) << endl;
    vector<int> coins(a,a+sizeof(a)/sizeof(int));

    for(auto i:coins) cout<<i<<" "; cout<<endl;

    cout<< s.coinChange(coins,target) <<endl;

    int b[] = {2};
    vector<int> coins2(b,b+sizeof(b)/sizeof(int));
    target = 3;
    cout<< s.coinChange(coins2,target) <<endl;

    return 0;
}