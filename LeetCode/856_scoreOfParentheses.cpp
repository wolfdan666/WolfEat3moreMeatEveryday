/* 
[wolfdan@cloud cpp]$ g++ A.cpp -o A.o -g
[wolfdan@cloud cpp]$ gdb A.o

这里的思路是最朴素的模拟栈，题解2中有优化操作，但是较难想到，所以可以参考借鉴，其他2中方法也可以借鉴一下
https://leetcode.cn/problems/score-of-parentheses/solution/gua-hao-de-fen-shu-by-leetcode-solution-we6b/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 感觉是一个栈模拟的题目，然后需要用特殊字符#代表一下中间态的分数
    // 这里相信input为合法值，参数校验在外层做
    int scoreOfParentheses(string s) {
        vector<int> tmp_sum;
        int ans = 0;
        stack<char> chs;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                chs.push(s[i]);
            } else {
                if (chs.top() == '(') {
                    chs.pop();
                    tmp_sum.push_back(1);
                    // 在插入#前检测前面是否为#，最多连续一个#，因为之前有#都会被下面逻辑先吃点
                    // 但是用while没有关系
                    while (!chs.empty() && chs.top() == '#') {
                        int len = tmp_sum.size();
                        tmp_sum[len - 2] += tmp_sum[len - 1];
                        chs.pop();
                        tmp_sum.pop_back();
                    }
                    chs.push('#');
                } else if (chs.top() == '#') {
                    chs.pop();
                    // assert(chs.top() == '(');
                    chs.pop();
                    int len = tmp_sum.size();
                    tmp_sum[len - 1] *= 2;
                    while (!chs.empty() && chs.top() == '#') {
                        int len = tmp_sum.size();
                        tmp_sum[len - 2] += tmp_sum[len - 1];
                        chs.pop();
                        tmp_sum.pop_back();
                    }
                    chs.push('#');
                }
            }
        }
        return tmp_sum[0];
    }
};

int main() {
    Solution sol;
    printf("Ans: %d \n", sol.scoreOfParentheses(string("()")));
    cout << sol.scoreOfParentheses("(())") << endl;
    cout << sol.scoreOfParentheses("(())") << endl;
    cout << sol.scoreOfParentheses("(()(()))") << endl;

    return 0;
}