/*
2021年05月16日13:54:05 开始看题 (今天用sublime来写代码，回味一下当年没有被vscode统治的年代)

暴力解法肯定是O(n^2)可以解决，但是题目要求O(n),就需要考虑一些异或的特性
暂时没有想到，看题解吧

震惊，果然又是32bit为直接从前向后选数

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/solution/shu-zu-zhong-liang-ge-shu-de-zui-da-yi-h-n9m9/

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
private:
    // 最高位的二进制位编号为 30
    static constexpr int HIGH_BIT = 30;

public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            unordered_set<int> seen;
            // 将所有的 pre^k(a_j) 放入哈希表中
            for (int num: nums) {
                // 如果只想保留从最高位开始到第 k 个二进制位为止的部分
                // 只需将其右移 k 位
                seen.insert(num >> k);
            }

            // 目前 x 包含从最高位开始到第 k+1 个二进制位为止的部分
            // 我们将 x 的第 k 个二进制位置为 1，即为 x = x*2+1  也就是`(x << 1) + 1`
            int x_next = x * 2 + 1;
            bool found = false;

            // 枚举 i
            for (int num: nums) {
                // ans = x1 ^ x2 , 那么 x1 = ans ^ x2
                if (seen.count(x_next ^ (num >> k))) {
                    found = true;
                    break;
                }
            }

            if (found) {
                x = x_next;
            }
            else {
                // 如果没有找到满足等式的 a_i 和 a_j，那么 x 的第 k 个二进制位只能为 0
                // 即为 x = x*2
                x = x_next - 1;
            }
        }
        return x;
    }
};


struct Trie {
    // 左子树指向表示 0 的子节点
    Trie* left = nullptr;
    // 右子树指向表示 1 的子节点
    Trie* right = nullptr;

    Trie() {}
};

class Solution_2 {
private:
    // 字典树的根节点
    Trie* root = new Trie();
    // 最高位的二进制位编号为 30
    static constexpr int HIGH_BIT = 30;

public:
    void add(int num) {
        Trie* cur = root;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur->left) {
                    cur->left = new Trie();
                }
                cur = cur->left;
            }
            else {
                if (!cur->right) {
                    cur->right = new Trie();
                }
                cur = cur->right;
            }
        }
    }

    int check(int num) {
        Trie* cur = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                // a_i 的第 k 个二进制位为 0，应当往表示 1 的子节点 right 走
                if (cur->right) {
                    cur = cur->right;
                    x = x * 2 + 1;
                }
                else {
                    cur = cur->left;
                    x = x * 2;
                }
            }
            else {
                // a_i 的第 k 个二进制位为 1，应当往表示 0 的子节点 left 走
                if (cur->left) {
                    cur = cur->left;
                    x = x * 2 + 1;
                }
                else {
                    cur = cur->right;
                    x = x * 2;
                }
            }
        }
        return x;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 1; i < n; ++i) {
            // 将 nums[i-1] 放入字典树，此时 nums[0 .. i-1] 都在字典树中
            add(nums[i - 1]);
            // 将 nums[i] 看作 ai，找出最大的 x 更新答案
            x = max(x, check(nums[i]));
        }
        return x;
    }
};


int main(){


    return 0;
}