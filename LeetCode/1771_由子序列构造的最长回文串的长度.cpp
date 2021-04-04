/* 
2021年04月04日13:46:36感觉这里需要反向 匹配前缀，但是又可以去掉字符，所以有点难搞

看题解发现很惭愧，想复杂了，别人直接通过一个拼接+最长回文字串的dp搞定了

作者：chen-qi-xian
链接：https://leetcode-cn.com/problems/maximize-palindrome-length-from-subsequences/solution/dong-tai-gui-hua-jie-jue-hui-wen-chuan-w-yfvc/

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
    int longestPalindrome(string w1, string w2) {
        int l1 = w1.size(), l2 = w2.size(), len = l1 + l2;
        // 拼接w1 w2得到一个完整的字符串w
        string w = w1 + w2;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        // 特殊判断word1的最后一个字符是否与word2第一个字符相等，若相等则res初始化为2.
        int res = (w[l1-1] == w[l1]) ? 2: 0;
        // 以下与计算最长回文子串解法一致
        for(int i = 0 ; i < len ; i ++) {
            dp[i][i] = 1;
        }
        for(int i = 0 ; i < len - 1 ; i ++) {
            dp[i][i+1] = (w[i] == w[i+1])? 2: 1;
        }
        
        for(int l = 2 ; l < len ; l ++) {
            for(int i = 0 ; i + l < len ; i ++) {
                int j = i + l;
                if(w[i] == w[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                    // 唯一的区别就在于当两端字符相等更新最长回文子串时
                    // 若 i j 分别属于两个字符串，才更新最终结果值
                    if(i < l1 && j >= l1){
                        res = max(res, dp[i][j]);
                    }
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return res;
    }
};

int main(){
    
    
    return 0;
}