/* 
2021年05月23日11:57:47 
暴力就是直接O(n*m) 有 1e10,不行的

应该是预处理nums数组，得出比特位Trie
感觉是可以用LeetCode421 题的一些思路,多一个mi的限制
那么就是O(n*log(m))

看了答案，果然如此
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/solution/yu-shu-zu-zhong-yuan-su-de-zui-da-yi-huo-7erc/
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


class Trie {
public:
    const int L = 30;

    Trie* children[2] = {};
    int min = INT_MAX;

    void insert(int val) {
        Trie* node = this;
        node->min = std::min(node->min, val);
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
            node->min = std::min(node->min, val);
        }
    }

    int getMaxXorWithLimit(int val, int limit) {
        Trie* node = this;
        if (node->min > limit) {
            return -1;
        }
        int ans = 0;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr && node->children[bit ^ 1]->min <= limit) {
                ans |= 1 << i;
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        Trie* t = new Trie();
        for (int val : nums) {
            t->insert(val);
        }
        int numQ = queries.size();
        vector<int> ans(numQ);
        for (int i = 0; i < numQ; ++i) {
            ans[i] = t->getMaxXorWithLimit(queries[i][0], queries[i][1]);
        }
        return ans;
    }
};


int main(){
    
    
    return 0;
}