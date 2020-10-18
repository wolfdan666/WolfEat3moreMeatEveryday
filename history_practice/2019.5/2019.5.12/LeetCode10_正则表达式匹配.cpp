/*
动态规划
直接上动态方程：
1.p[j] == s[i]:dp[i][j] = dp[i-1][j-1]
2.p[j] == ".":dp[i][j] = dp[i-1][j-1]
3.p[j] =="*":
3.1 p[j-1] != s[i]:dp[i][j] = dp[i][j-2]
3.2 p[i-1] == s[i] or p[i-1] == ".":
dp[i][j] = dp[i-1][j] // 多个a的情况
or dp[i][j] = dp[i][j-1] // 单个a的情况
or dp[i][j] = dp[i][j-2] // 没有a的情况
*/
// 2019年5月12日23:37:18有点想不清了，现在这个状态不适合想了，所以明天go on    室友还一直在放歌

//py版
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        #if not s or not p:
            #return False
        s_len = len(s)
        p_len = len(p)
        dp = [[False] * (p_len + 1) for _ in range(s_len + 1)]
        #print(dp)
        dp[0][0] = True
        for i in range(p_len):
            if p[i] == "*" and dp[0][i - 1]:
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


class Solution {
public:
    bool isMatch(char* s, char* p) {
        int ls=strlen(s);
        int lp=strlen(p);
        bool match[ls+1][lp+1];
        memset(match,false,sizeof(bool )*(ls+1)*(lp+1));
        match[ls][lp]=true;
        for(int i=ls;i>=0;--i){
            for(int j=lp-1;j>=0;--j){
                bool curmatch=(s[i]==p[j])||(p[j]=='.');
                if(p[j+1]=='*'){
                    if(i==ls)
                        match[i][j]=match[i][j+2];
                    else
                        match[i][j]=match[i][j+2]||(match[i+1][j]&&curmatch);
                }
                else{
                    if(i==ls)
                        match[i][j]=false;
                    else
                        match[i][j]=curmatch&&match[i+1][j+1];
                }
            }
        }
        return match[0][0];
    }
};