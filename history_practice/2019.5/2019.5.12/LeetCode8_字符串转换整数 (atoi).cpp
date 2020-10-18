// 2019年5月12日22:27:15开始看题
// 2019年5月12日22:35:34今天比较忙，所以直接看的题解
class Solution {
public:
    int myAtoi(string str) {
        int i = 0, n = str.size(),sign = 1,ans = 0;
        //把i移动非空格位
        for(;i < n && isspace(str[i]);i++);
        //判断符号
        if(str[i] == '+' || str[i] == '-'){
            sign *= (str[i++] == '+' ? 1:-1);
        }

        while(str[i] >= '0' && str[i] <= '9'){
            //std::cout << ans;
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && str[i]-'0'>7)){
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            ans = ans * 10 + (str[i++]-'0');
        }
        return ans * sign;
    }
};