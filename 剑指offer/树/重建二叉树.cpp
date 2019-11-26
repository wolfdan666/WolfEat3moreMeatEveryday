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

Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 竟然爆栈了...

// 2019年11月26日20:01:53 看了别人的code，发现果然不能用copy方法
// class Solution {
// public:
//     TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
//         if(pre.empty() || vin.empty()) return nullptr;

//         return ConstructCore(pre,vin);
//     }

//     TreeNode* ConstructCore(vector<int> pre,vector<int> vin){
//         // 获取先序遍历的第一个数字 --- 根节点值
//         int rootVal = pre[0];
//         TreeNode* root = new TreeNode(rootVal);
//         // root->val = rootVal;
//         root->left = root->right = nullptr;

//         int presz = pre.size();
//         int vinsz = vin.size();
//         if(presz == 1){
//             if(vinsz ==1 && pre[0] == vin[0]) return root;
//             // else throw std::exception("Invalid input");
//         }

//         // 在中序遍历中找到根节点
//         int i = 0;
//         vector<int>::iterator it;
//         while(i<vinsz && vin[i] != rootVal) i++,it++;

//         // if(i == vinsz-1 && vinsz[i] != rootVal) throw std::exception("Invalid input");

//         // 突然发现自己用题目中给的默认的vector<int> 不利于递归...(强行用vector可能导致臃肿(复制vector)...)
//         // 注意it的操作，还是有点巧妙
//         vector<int>::iterator it1;
//         if(i>0){
//             // 构建左子树
//             vector<int> svin; svin.assign(it1,it);
//             it1++; it++;
//             vector<int> spre; spre.assign(it1,it);

//             root->left = ConstructCore(spre,svin);
//         }
//         if(i<vinsz-1){
//             // 构建右子树
//             vector<int> spre; spre.assign(it,pre.end());
//             vector<int> svin; svin.assign(it,vin.end());

//             root->right = ConstructCore(spre,svin);
//         }

//         return root;
//     }
// };

class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        struct TreeNode *head;
        if (pre.size() <= 0)
            head = NULL;

        else
            PreInOrder(pre, in , 0, pre.size() - 1, 0, in.size() - 1, &head);
        return head;
    }

    void PreInOrder(vector<int> pre, vector<int> in, int i, int j, int k, int h , struct TreeNode **p){
      //先序序列中从i到j，中序序列中从k到h，建立一棵二叉树存放在p中

        int m;
        (*p) = (TreeNode*)malloc(sizeof(TreeNode));
        (*p)->val = pre.at(i);

        m = k;

        //在中序序列中找到根节点
        while(in.at(m) != pre.at(i))
            m++;

        //递归调用建立左子树
        if(m == k) (*p)->left = NULL;  //左子树为空
        else PreInOrder(pre, in, i + 1, m - k + i, k, m - 1 , &((*p)->left));

        //递归调用建立又子树
        if(m == h) (*p)->right = NULL;
        else PreInOrder(pre, in, m - k + i + 1, j, m + 1, h , &((*p)->right));
    }
};

int main(){


    return 0;
}