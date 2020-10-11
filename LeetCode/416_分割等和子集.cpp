/*
2020年10月11日19:20:25 开始
nlog(n)
先排序，再双指针

2020年10月11日19:30:44 发现
1 2 8 9
不能这样搞...

2020年10月11日19:32:55 看题解吧
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/fen-ge-deng-he-zi-ji-by-leetcode-solution/

还是 0 - 1 背包
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
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 2) return false;
//         sort(nums.begin(), nums.end());
//         long long l = nums[0];
//         long long r = nums[n - 1];

//         long long sum = 0;
//         for (auto num : nums) {
//             sum += num;
//         }
//         if (sum & 1) return false;

//         long long half = sum / 2;
//         long long tmp = 0;
//         for (auto num : nums) {
//             tmp +=
//         }
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0, maxNum = 0;
        for (auto& num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<int> dp(target + 1, 0);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
};

int main(){


    return 0;
}