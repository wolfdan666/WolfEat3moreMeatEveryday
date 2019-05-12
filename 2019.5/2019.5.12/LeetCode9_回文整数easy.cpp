// 比较简单，所以就自己写了
/*
执行用时 : 68 ms, 在Palindrome Number的C++提交中击败了76.25% 的用户
内存消耗 : 8.1 MB, 在Palindrome Number的C++提交中击败了86.53% 的用户

然后这个结果感觉自己有点菜

看看别人的算法

原来我自己的算法就是  itoa()  int转string
然后官方的解是耗时最短的解
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int k = 1,temx=x;
        string t;
        t += char((temx%10)+'0');  // 因为是判断回文，所以后位放前面也无所谓
        while(temx/=10){
            k++;
            t += char((temx%10)+'0');
        }
        for(int i=0;i<=k/2+1;i++){
            if(t[i]!=t[k-i-1]) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    int s;
    Solution solve;
    while(cin>>s){
        cout<<solve.isPalindrome(s)<<endl;
    }
    return 0;
}





// 官方的C#
public class Solution {
    public bool IsPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber/10;
    }
}

