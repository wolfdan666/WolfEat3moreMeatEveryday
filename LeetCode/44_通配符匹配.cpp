/*
2020年7月5日12:14:59 感觉以前做过

可以用递归来写，这样好写一点

2020年7月5日16:26:14 出问题了，看题解看看先

2020年7月5日16:39:45 TLE
"abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab"
"*aabb***aa**a******aa*"
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

// 自己TLE了，因为在*过多的时候，有太多的调用
class Solution {
public:
    bool sol(string s, string p){
        int sl = s.length();
        int pl = p.length();

        if( sl == 0 && pl == 0) return ans = true;
        // if( (sl == 0 && pl != 0) || (sl != 0 && pl == 0) ) return false;
        if( (sl != 0 && pl == 0) ) return false;

        /*
""
"*"
        */
        if(sl == 0 && pl != 0){
            for(int i=0;i<pl;i++) if(p[i]!='*') return false;
            return ans = true;
        }

        // if(p[0] == '?' || p[0] == s[0] ) sol(s.substr(1,sl-1), p.substr(1,sl-1));
        if(p[0] == '?' || p[0] == s[0] ) sol(s.substr(1,sl-1), p.substr(1,pl-1));
        else if(p[0] == '*' ){
            // sol(s.substr(1,sl-1), p.substr(1,sl-1));
            // 匹配一个
            sol(s.substr(1,sl-1), p.substr(1,pl-1));
            // sol(s.substr(1,sl-1), p.substr(1,sl));
            // sol(s.substr(1,sl-1), p.substr(1,pl));
            // 匹配多个
            sol(s.substr(1,sl-1), p);

            /*
"adceb"
"*a*b"
            */
            // 匹配0个
            sol(s,p.substr(1,pl-1));
        }
        return false;
    }

    bool isMatch(string s, string p) {
        ans = false;
        sol(s,p);
        return ans;
    }
private:
    bool ans = false;
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
/* Dp ， 可以滚动数组优化
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/


class Solution {
public:
    bool isMatch(string s, string p) {
        auto allStars = [](const string& str, int left, int right) {
            for (int i = left; i < right; ++i) {
                if (str[i] != '*') {
                    return false;
                }
            }
            return true;
        };
        auto charMatch = [](char u, char v) {
            return u == v || v == '?';
        };

        while (s.size() && p.size() && p.back() != '*') {
            if (charMatch(s.back(), p.back())) {
                s.pop_back();
                p.pop_back();
            }
            else {
                return false;
            }
        }
        if (p.empty()) {
            return s.empty();
        }

        int sIndex = 0, pIndex = 0;
        int sRecord = -1, pRecord = -1;
        while (sIndex < s.size() && pIndex < p.size()) {
            if (p[pIndex] == '*') {
                ++pIndex;
                sRecord = sIndex;
                pRecord = pIndex;
            }
            else if (charMatch(s[sIndex], p[pIndex])) {
                ++sIndex;
                ++pIndex;
            }
            else if (sRecord != -1 && sRecord + 1 < s.size()) {
                ++sRecord;
                sIndex = sRecord;
                pIndex = pRecord;
            }
            else {
                return false;
            }
        }
        return allStars(p, pIndex, p.size());
    }
};
/* 巧妙方法
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

int main(){
    string s = "test";
    cout<< "s.substr(0,4)" << s.substr(0,4) << endl;
    cout<< "s.substr(1,3)" << s.substr(1,3) << endl;
    cout<< "s.substr(4,0)" << s.substr(4,0) << endl;


    return 0;
}