/*
2020年09月26日14:07:29 开始看题

感觉就是简单的dfs
确实简单，但是自己的实现好像有点不太行

执行用时：24 ms, 在所有 C++ 提交中击败了24.44%的用户
内存消耗：29.6 MB, 在所有 C++ 提交中击败了25.70%的用户

然后看了官方的，比我的优美一些
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

class Solution {
public:
    void dfs(vector<int> tmp, TreeNode* root, int sum) {
        if (root->left == NULL && root->right == NULL) {
            if (sum == 0) ans.push_back(tmp);
            return ;
        } else {
            if (root->left) {
                int tmp_val = root->left->val;
                tmp.push_back(tmp_val);
                dfs(tmp, root->left, sum - tmp_val);
                tmp.pop_back();
            }
            if (root->right) {
                int tmp_val = root->right->val;
                tmp.push_back(tmp_val);
                dfs(tmp, root->right, sum - tmp_val);
                tmp.pop_back();
            }
        }

    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear();
        if (!root) return ans;

        vector<int> tmp;
        tmp.push_back(root->val);
        dfs(tmp, root, sum - root->val);

        return ans;
    }
private:
    vector<vector<int>> ans;
};

class _Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            ret.emplace_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ret;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/path-sum-ii/solution/lu-jing-zong-he-ii-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){


    return 0;
}