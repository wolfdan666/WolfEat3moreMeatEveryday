/// 2019年6月30日14:48:57  一开始半天没有理解题意....emmm 果然好久没刷题，题感下降了许多

// 我一开始也想的使用前缀树，结果直接看题解，感觉这题不必要用前缀树，emmm，佛了

// 找到最短字符串，以它的长度为基准，从所有字符串的第一个字符开始对比，若都一样，ans加上该字符，若不一样，返回答案；

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = "";
        if (strs.empty())
            return ans; //输入为空，输出空ans
        int arr = strs.size();
        string min = strs[0];
        for (int i = 1; i < arr; ++i) { //找到最短字符串
            if (strs[i].size() < min.size())
                min = strs[i];
        }
        for (int j = 0; j < min.size(); ++j) { //从第一个字符开始对比，若都一样，ans加上该字符，若不一样，返回答案；
            for (int m = 0; m < arr; ++m) {
                if (min[j] != strs[m][j])
                    return ans;
            }
            ans = ans + min[j];
        }
        return ans;
    }
};
