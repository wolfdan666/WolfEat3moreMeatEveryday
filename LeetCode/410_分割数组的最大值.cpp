/*
2020年7月25日13:18:23 开始看题

2020年7月25日13:25:32 想到一开始都是独立的，然后合并n-m次
保证每次合并最小的两个，只要用一个multiset或者优先队列就行了

2020年7月25日13:56:36 交
2020年7月25日13:57:23 wa了，因为不能动数组的位置....才发现审题错了...

(n-m)次扫描最小相邻位置？不太好操作

2020年7月25日14:02:31 看答案吧

看到这一句  「将数组分割为 mm 段，求……」是动态规划题目常见的问法。 感觉自己真丢人

方法二：二分查找 + 贪心
思路及算法

「使……最大值尽可能小」是二分搜索题目常见的问法。
牛逼的LeetCode题解


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


class ，my_error_Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(!s.empty()) s.clear();

        int n = nums.size();
        if(m > n) return -1;

        s = std::move(std::multiset<int>(nums.begin(), nums.end()));

        int cnt = n - m;
        while(cnt--){
            std::multiset<int>::iterator it = s.begin();
            int tp1 = *it;
            int tp2 = *(++it);
            s.erase(it);
            s.erase(s.find(tp1));
            s.insert(tp1+tp2);
        }

        return *s.rbegin();
    }

private:
    multiset<int> s;
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/split-array-largest-sum/solution/fen-ge-shu-zu-de-zui-da-zhi-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    bool check(vector<int>& nums, int x, int m) {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > x) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++) {
            right += nums[i];
            if (left < nums[i]) {
                left = nums[i];
            }
        }
        while (left < right) {
            long long mid = (left + right) >> 1;
            if (check(nums, mid, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/split-array-largest-sum/solution/fen-ge-shu-zu-de-zui-da-zhi-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){
    int tmp_nums[5] = {7,2,5,10,8};
    int m = 2;
    vector<int> nums(tmp_nums,tmp_nums+5);

    for(auto x : nums) cout<< x << " "; cout<< endl;

    Solution a;
    cout << a.splitArray(nums, m) <<endl;

    return 0;
}