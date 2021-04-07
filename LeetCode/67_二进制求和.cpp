/* 
这里题解可以看到更简单的做法
https://leetcode-cn.com/problems/add-binary/solution/er-jin-zhi-qiu-he-by-leetcode-solution/
 */
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string ls, string rs) {
        int l_sz = ls.length();
        int r_sz = rs.length();
        string ans = "";
        int tmp = 0;
        int added = 0;
        int big_sz = l_sz > r_sz ? l_sz : r_sz;
        for (int i = 0; i < big_sz || added; i++) {
            tmp = added;
            if (i < l_sz) {
                tmp += ls[l_sz - 1 - i] == '1' ? 1 : 0;
            }
            if (i < r_sz) {
                tmp += rs[r_sz - 1 - i] == '1' ? 1 : 0;
            }
            // 小心漏了1111，1111这种导致的tmp = 3
            if (tmp >= 2) {
                added = 1;
            } else {
                added = 0;
            }

            // 错在tmp = 2 的时候也有是 0 ，这一点没注意
            if (tmp & 1) {
                ans = '1' + ans;
            } else {
                ans = '0' + ans;
            }
            printf("i=[%d] tmp=%d added=%d ans=%s\n", i, tmp, added, ans.c_str());
        }
        return ans;
    }
};

int main() {
    string str_a, str_b;
    cin >> str_a;
    cin >> str_b;
    Solution a; 
    cout << a.addBinary(str_a, str_b) << endl;

    return 0;
}