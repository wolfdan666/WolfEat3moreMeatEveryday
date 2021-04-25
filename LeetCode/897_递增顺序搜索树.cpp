/* 

2021年04月25日19:02:49 搞了45分钟，还是这样，看答案吧，菜了
输入
[5,3,6,2,4,null,8,1,null,null,null,7,9]
输出
[1,null,2]
预期结果
[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]


2021年04月25日19:05:49 发现答案写的极其简洁
原来是自己之前见过的非递归的写法 + 自己又看过递归的写法，导致自己写出了混合态的错误写法
但是要找到错在哪里

2021年04月25日19:08:23 知道了，自己遍历father的时候，已经father自己找不到自己的father了！

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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class ERROR_Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* virtual_head = new TreeNode;
        inorder_2_increasing_get(root, virtual_head);

        TreeNode* ret = virtual_head->right;
        delete virtual_head;
        return ret;
    }

    TreeNode* inorder_2_increasing_get(TreeNode* src_root, TreeNode* increasing_root) {
        if (!src_root) {
            return increasing_root;
        }
        TreeNode* father = nullptr;
        TreeNode* change_node = src_root;
        while (change_node->left) {
            father = change_node;
            change_node = change_node->left;
        }

        increasing_root->right = change_node;
        increasing_root = increasing_root->right;
        // 右树进行递归，而且right会在increasing_root中改变
        // 所以所有father都是left的father
        // 右树and父亲直接递归
        if (change_node->right) {
            increasing_root = inorder_2_increasing_get(change_node->right, increasing_root);
        }
        if (father) {
            father->left = nullptr;
            inorder_2_increasing_get(father, increasing_root);
        }
        return increasing_root;
    }
};


class Solution {
private:
    TreeNode *resNode;

public:
    void inorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);

        // 在中序遍历的过程中修改节点指向
        resNode->right = node;
        node->left = nullptr;
        resNode = node;

        inorder(node->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        inorder(root);
        return dummyNode->right;
    }
};



int main(){
    
    
    return 0;
}