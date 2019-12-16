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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k){
        if(pRoot == nullptr || k == 0) return nullptr;

        return SolKth(pRoot,k);
    }

    // 第二发WA,原来忘了引用...
    // 内存超限:您的程序使用了超过限制的内存
    TreeNode* SolKth(TreeNode* pRoot,int& k){
        TreeNode* ans = nullptr;

        if(pRoot->left != nullptr)
            // 手残了
            // ans = SolKth(pRoot,k);
            ans = SolKth(pRoot->left,k);

        if(ans == nullptr){
            if(k == 1) ans = pRoot;
            k--;
        }

        if(ans == nullptr && pRoot->right != nullptr){
            ans = SolKth(pRoot->right,k);
        }

        return ans;
    }

};

int main(){


    return 0;
}