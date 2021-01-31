/**
 * 2021年01月31日14:28:59 开始看题
 * 
 * 判断相似：
 * 1. 最多只有2个位置的字符不同
 * 2. 这两个位置的字符是交差相同的（即这两个位置交换后，两个字符串相同）== 交差异或都为0
 * 第二点其实题目同位异形词已经保证
 * 
 * n = strs.size(), m = max(strs[i].length()) ，k = sum(strs[i].length)
 * 要归到一个相似组的话，如果遍历这个组所有的元素，那么就是O(n^2 * m )的复杂度 大概 10^7
 * 但还是感觉暴力肯定超时
 * 
 * 这个应该有点像搜索引擎里面的字符串算法，但是暂时没有想到怎么搞
 * 2021年01月31日14:52:39 看答案吧  
 * 
 * 结果发现答案还真是我想的这样，尴尬
 * 作者：LeetCode-Solution
 * 链接：https://leetcode-cn.com/problems/similar-string-groups/solution/xiang-si-zi-fu-chuan-zu-by-leetcode-solu-8jt9/
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
public:
    vector<int> f;

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool check(const string &a, const string &b, int len) {
        int num = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                num++;
                if (num > 2) {
                    return false;
                }
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string> &strs) {
        int n = strs.size();
        int m = strs[0].length();
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int fi = find(i), fj = find(j);
                if (fi == fj) {
                    continue;
                }
                if (check(strs[i], strs[j], m)) {
                    f[fi] = fj;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] == i) {
                ret++;
            }
        }
        return ret;
    }
};


int main(){
    
    
    return 0;
}