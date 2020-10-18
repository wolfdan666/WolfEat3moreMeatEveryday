// 思路:一个int w[26]来记录位置，然后第二次出现就可以直接获取下一个长度 i-j
// 后面我想着想着，想到了要对原位置前面的东西清空，否则会影响到后面判断(因为我的判断是直接判断非0)
// 后面感觉不对劲,于是看了题解,发现题解比我牛逼的地方在于它直接不清理前面,
// 而是设置一个max(current position,w[]),这样就巧妙的完成了设计与清理,真好,算法真美
// 2019年5月2日19:30:19 还有,题解考虑的是128个字符
#include<bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = int(s.length()),ans = 0;
//         int index[128];
//         if(n==1) return 1;
//         if(n==2){
//             return s[0]==s[1]?2:1;
//         }
//         memset(index,0,sizeof(index));
//         for(int i=0,j=0;i<n;i++){
//             j = max(index[s[i]],j);
//             ans = max(ans,i - j);
//             index[s[i]]= i;
//         }
//         return ans;
//     }
// };// 没有处理好aux的例子情况，就是本身就无重复会使得答案少1
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
int main(int argc, char const *argv[])
{
    Solution a;
    string s;
    while(cin>>s) {
        cout<<a.lengthOfLongestSubstring(s)<<endl;
    }
    return 0;
}