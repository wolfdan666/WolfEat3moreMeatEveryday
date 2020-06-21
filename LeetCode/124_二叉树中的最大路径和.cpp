/*
2020年6月21日19:14:42 开始看题

DFS

2020年6月21日19:17:52 准备写

2020年6月21日19:22:17 感觉自己的写法没有记录过程，导致了大量重复遍历，不行
2020年6月21日19:26:02 想清楚了，不会重复遍历，因为我只用一次dfs

2020年6月21日19:28:55 WA在了cornor case , 单独一个-3的二叉树
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 会导致不联通，见124_错点
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // int ans = 0;
        int ans = -inf;
        int lv = root->left == nullptr ? -inf : maxPathSum(root->left);
        // int lv = root->left == nullptr ? 0 : maxPathSum(root->left);
        int rv = root->right == nullptr ? -inf : maxPathSum(root->right);
        // int rv = root->right == nullptr ? 0 : maxPathSum(root->right);
        ans = max(ans,root->val);
        ans = max(ans,lv);
        ans = max(ans,rv);
        ans = max(ans,root->val+lv);
        ans = max(ans,root->val+rv);
        ans = max(ans,root->val+lv+rv);

        return ans;
    }
private:
    const int inf = 0x3f3f3f3f;
};

class Solution {
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-leetcode-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){


    return 0;
}