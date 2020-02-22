/*
2020年2月22日18:48:23 二次刷，发现自己看了半天才看懂自己第一次写的代码
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = int(s.length()),ans = 0;
        int index[128];
        memset(index,0,sizeof(index));
        for(int i=0,j=0;i<n;i++){
            j = max(index[s[i]],j);
            ans = max(ans,i + 1 - j);
 // 出现过，就是aba  (3-1)  没出现过 就是 an (2-0)   假设abca(4-1)  a到z再a(27-1),acdad(index[d]和j都是3)
// 也就是把未出现过的都放在刚出现的那个前面一位，这就是巧妙的清0，牛逼！
            index[s[i]]= i + 1;
        }
        return ans;
    }
};