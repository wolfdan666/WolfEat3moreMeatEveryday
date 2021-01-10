/**
 * 2021年01月10日13:33:35 感觉就是一个简单的字符串添加的题目
 * 
 * 2021年01月10日13:57:56 在size == 1那里忘了判断，wa一发
 * 
 * 2021年01月10日13:59:49 [-2147483648,-2147483647,2147483647] 爆int,wa一发
 * 
 * 2021年01月10日14:05:35 发现上面这个不仅仅是爆int,因为改成ll也不行
 * 
 * 2021年01月10日14:16:24 发现是buf开24，当时没有考虑双负号，所以开25就AC了
 * 
 * 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗：7 MB, 在所有 C++ 提交中击败了81.01%的用户
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int nums_size = nums.size();
        if (nums_size == 0)
            return ans;
        
        // int BUFF_MAX_LEN = 24;
        int BUFF_MAX_LEN = 25;
        char buf[BUFF_MAX_LEN];
        // 因为数组有序无重复，所以可以不用下标做begin和end
        long long begin = nums[0];

        if (nums_size == 1) {
            sprintf(buf, "%lld", begin);
            ans.push_back(buf);
            return ans;
        }

        long long end = nums[nums_size - 1];
        for (int i = 1; i < nums_size; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                end = nums[i - 1];
                if (begin != end)
                    sprintf(buf, "%lld->%lld", begin, end);
                else 
                    sprintf(buf, "%lld", begin);
                ans.push_back(string(buf));
                
                begin = nums[i];
            }
            if (i == nums_size - 1) {
                end = nums[i];
                if (begin != end)
                    sprintf(buf, "%lld->%lld", begin, end);
                else 
                    sprintf(buf, "%lld", begin);
                ans.push_back(string(buf));
            }
        }

        return ans;
    }
};

int main(){
    
    
    return 0;
}