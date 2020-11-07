/*
2020年11月07日14:19:32 开始看题

直观做法，前缀和+双层遍历直接被否定了

线段树来快速计算区间和会怎么样呢？ --- 区间和计算不是复杂度卡住的关键

卡住复杂度的是双层遍历，所以应该是使用dp来优化

子区间如果可以，但是如何合并状态呢---递归记忆区间搜索

子区间用相同的处理方式

区间记忆有点忘了怎么写，借鉴一下答案
边浪边看完答案后，2020年11月07日15:36:20 发现自己的方法要一开始一层O(n)之后O(logn)的遍历中也有遍历方法的O(n)
所以其实是O(n^2logn),反而更差了...

-------
发现了官方题解一的归并排序中的ret只计算了每次两个数组之间的count，原因是两个数组内的计算在之前的子区间已经计算过了
感觉方法二三的线段树和主席树都不错，真香，自己却没想到，太不熟悉了

方法五的平衡二叉树，那个给定val知道多少个0到val值其实就是数据结构保证了
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


//     int countRangeSum(vector<int>& nums, int lower, int upper) {
//         int ans = 0;
//         ans += dfs(nums, lower, upper);
//         return ans;
//     }

//     bool check(vector<int>& nums, int lower, int upper) {
//         int tmp = 0;
//         for (auto x : nums) {
//             tmp += x;
//         }
//         if (lower <= tmp && tmp <= upper) {
//             return true;
//         }
//         return false;
//     }

//     int dfs(vector<int>& nums, int lower, int upper) {
//         int sz = nums.size();
//         if (1 == sz) {
//             if (check() )
//         }
//     }
// };

struct SegNode {
    int lo, hi, add;
    SegNode* lchild, *rchild;
    SegNode(int left, int right): lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
};

class Solution {
public:
    SegNode* build(int left, int right) {
        SegNode* node = new SegNode(left, right);
        if (left == right) {
            return node;
        }
        int mid = (left + right) / 2;
        node->lchild = build(left, mid);
        node->rchild = build(mid + 1, right);
        return node;
    }

    void insert(SegNode* root, int val) {
        root->add++;
        if (root->lo == root->hi) {
            return;
        }
        int mid = (root->lo + root->hi) / 2;
        if (val <= mid) {
            insert(root->lchild, val);
        }
        else {
            insert(root->rchild, val);
        }
    }

    int count(SegNode* root, int left, int right) const {
        if (left > root->hi || right < root->lo) {
            return 0;
        }
        if (left <= root->lo && root->hi <= right) {
            return root->add;
        }
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        vector<long long> preSum = {0};
        for (int v: nums) {
            sum += v;
            preSum.push_back(sum);
        }

        set<long long> allNumbers;
        for (long long x: preSum) {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }
        // 利用哈希表进行离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x: allNumbers) {
            values[x] = idx;
            idx++;
        }

        SegNode* root = build(0, values.size() - 1);
        int ret = 0;
        for (long long x: preSum) {
            int left = values[x - upper], right = values[x - lower];
            ret += count(root, left, right);
            insert(root, values[x]);
        }
        return ret;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/count-of-range-sum/solution/qu-jian-he-de-ge-shu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){


    return 0;
}