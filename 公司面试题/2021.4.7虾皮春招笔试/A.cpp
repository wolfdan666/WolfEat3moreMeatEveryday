#include <string>
#include <cstring>
#include <iostream>
using namespace std;

bool is_zore(string str) {
    int sz = str.length();
    for (int i = 0; i < sz; i++) {
        if (str[i] == '1') {
            return false;
        }
    }
    return true;
}

// https://leetcode-cn.com/problems/add-binary/ ，2021年04月07日17:43:41 搜了一下，可以用这题检测一下
// 发现wa了
/* 
输入：
"1111"
"1111"
输出：
"1010"
预期结果：
"11110"
 */
string add_bin_str(string ls, string rs) {
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

        // if (tmp == 0) {
        // 错在tmp = 2 的时候也有是 0 ，这一点没注意
        // 2021年04月07日17:34:18 人没了
        if (tmp & 1) {
            ans = '1' + ans;
        } else {
            ans = '0' + ans;
        }
    }
    return ans;
}

int main(){
    string str, ls, rs;
    cin >> str;
    int pos = str.find_first_of(';');
    if (pos == string::npos) {
        printf("invalid input\n");
        return -1;
    }

    ls = str.substr(0, pos);
    rs = str.substr(pos + 1, str.length() - pos - 1);

    int sz = ls.length();
    // 0 判断
    if (is_zore(ls) || is_zore(rs)) {
        puts("0");
        return 0;
    }

    string ans = "";
    for (int i = sz - 1, j = 0; i > -1; i--, j++) {
        if (ls[i] == '1') {
            // printf("before add in j = [%d], ans is %s\n", j , ans.c_str());
            ans = add_bin_str(ans, rs + string(j, '0'));
            // printf("after add in j = [%d], ans is %s\n", j , ans.c_str());
        }
    }
    cout << ans << endl;
    return 0;    
}