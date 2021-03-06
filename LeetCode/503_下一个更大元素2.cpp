/* 
2021年03月06日14:55:20 开始看题
2021年03月06日14:57:36 直觉告诉我O(n^2)会超时
因为这里数组长度就算不过10000，也有1e8.还是太大，而且这个题中等难度
应该有其他方法

想到应该是倒序查找，如果a[i - 1] 比 a[i] 小，那么直接是a[i]
如果a[i - 1] 大于等于 a[i].那么就是和greater[a[i]] 依次比较，这样就可以了
递推，那么终止条件就是找到其中的max，然后再直接倒退
2021年03月06日15:02:10 开干

2021年03月06日15:54:18发现自己的本地g++编译能跑能过，但是LeetCode Runtime error了
2021年03月06日16:23:42 还没找出LeetCode的编译问题，不管了，pass，搞了一个半小时，佛了
2021年03月06日16:34:21 又找了10分钟，也没办法gdb进去看堆栈信息，算了，不搞了，编译选项不同吧
暴力O(n^2)都能过，那么我这个方法肯定也是可以过的

发现答案的是单调栈，确实很好，但是自己这个思路的编译错误怎么搞呢
 */

// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans(sz, 0);
        if (!sz) {
            return ans;
        }
        if (sz == 1) {
            ans[0] = -1;
            return ans;
        }

        int max_value = nums[0];
        // for (auto x : nums) {
        for (int i = 0; i < sz; i++) {
            max_value = max(nums[i], max_value);
        }

        int random_max_index = -1;
        for (int i = 0; i < sz; i++) {
            if (max_value == nums[i]) {
                ans[i] = -1;
                random_max_index = i;
            }
        }

        int j = random_max_index;
        for (int i = 0; i < sz; i++) {
            int pre_j = (j - 1 + sz) % sz;
            // 最大值已经不用处理
            if (ans[pre_j] == -1) {
                j = pre_j;
                continue;
            }
            int tmp = nums[j];
            // 不小于，则找当前的更大值,eg: 3 2 3 4
            while (nums[pre_j] >= tmp) {
                // tmp = ans[tmp];
                int tmp_new = ans[tmp];
                tmp = tmp_new;
            }
            ans[pre_j] = tmp;
            j = pre_j;
        }

        return ans;
    }
};

class Solution_ans {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }
};


int main(){
    vector<int> test(3);
    test[0] = 1;
    test[1] = 2;
    test[2] = 1;
    Solution sol;
    vector<int> ans = sol.nextGreaterElements(test);

    for (auto x : ans) {
        printf("%d ", x);
    }
    puts("");
    
    return 0;
}