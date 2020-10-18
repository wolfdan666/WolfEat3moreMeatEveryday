// 自己一开始没有想出来，然后看了官方题解，感觉这题挺好的
// 感觉自己比较喜欢国外的评测，有题解，有测试错误的样例查看，国内的好像只有洛谷提供这样的服务

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};