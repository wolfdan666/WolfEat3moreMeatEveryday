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
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int ans = 0;

        return sol(pRoot,&ans);
    }

    bool sol(TreeNode* pRoot,int *depth){
        if(pRoot == nullptr){
            *depth = 0;
            return true;
        }

        int l,r;
        if(sol(pRoot->left,&l) && sol(pRoot->right,&r)){
            int diff = l - r;
            if(abs(diff) <= 1){
                *depth = 1 + (l > r? l : r);
                return true;
            }
        }

        return false;
    }
};

int main(){


    return 0;
}