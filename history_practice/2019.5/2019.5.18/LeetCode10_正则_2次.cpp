/*
# 2019年5月18日21:23:17看想题

2019年5月18日22:27:01 自闭了，又在这题卡了一个小时，下次状态好再来写
'''
2019年5月18日21:36:08依然懵逼，所以还是看题解
1. p[j] == s[i]:dp[i][j] = dp[i-1][j-1]
2. p[j] == ".":dp[i][j] = dp[i-1][j-1]
3. p[j] =="*":
    3.1 p[j-1] != s[i]:dp[i][j] = dp[i][j-2]
    3.2 p[i-1] == s[i] or p[i-1] == ".":
        dp[i][j] = dp[i-1][j] // 多个a的情况
        or dp[i][j] = dp[i][j-1] // 单个a的情况
        or dp[i][j] = dp[i][j-2] // 没有a的情况
'''


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        #if not s or not p:
            #return False
        s_len = len(s)
        p_len = len(p)
        dp = [[False] * (p_len + 1) for _ in range(s_len + 1)] # 行对应的是s
        #print(dp)
        dp[0][0] = True
        for i in range(p_len):
            if p[i] == "*" and dp[0][i - 1]:  #当前为*号，前一个是实体，那么下一个为true
                dp[0][i + 1] = True
        #print(dp)
        for i in range(s_len):
            for j in range(p_len):
                if p[j] == s[i] or p[j] == ".":
                    dp[i + 1][j + 1] = dp[i][j]
                elif p[j] == "*":
                    if p[j - 1] != s[i]:
                        dp[i + 1][j + 1] = dp[i + 1][j - 1]
                    if p[j-1] == s[i] or p[j-1] == ".":
                        dp[i+1][j+1] = (dp[i][j+1] or dp[i+1][j]   or  dp[i+1][j-1])
        #print(dp)
        return dp[-1][-1]
有很多人所这个人写的有些地方不对，但是我真的不懂他每个状态分别表示什么，浪费我时间和精力，抛弃.... 2019年5月18日22:08:14
        */

// 容易理解的版本 200ms
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        } else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};


// 优化后的版本 20ms
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p) {
        if(*p == 0) return *s == 0;

        auto first_match = *s && (*s == *p || *p == '.');

        if(*(p+1) == '*'){
            return isMatch(s, p+2) || (first_match && isMatch(++s, p));
        }
        else{
            return first_match && isMatch(++s, ++p);
        }
    }
};