/**
 * 2021年02月07日20:38:43 就是简单的判断两次大于后者返回false
 * 
 * 2021年02月07日20:44:41 翻车在：[3,4,2,3]
 * 
 * 所以后面的值必须大于前面的pre_max，可以4和2比较的时候，只能把2变成4
 * 对，其实不用pre_max，我就是少了变化这一步
 * 
 * 2021年02月07日20:51:42 又错在：[4,2,3]
 * 其实可以把前面的值变小！对，所以还是维护pre_max,4和2比较，然后2>pre_max(1e-5),所以把4变成2
 * 
 * 2021年02月07日21:02:25 其实pre_max是pre_pre.比如i=1的时候，pre是nums[0],pre_pre=MIN
 * 每次都是pre和cur(nums[i])比较，要参考pre_pre的值
 * 
 * 发现这就是最优解，2021年02月07日21:13:45 AC,不能小看简单题啊(35mins)
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
    bool checkPossibility(vector<int>& nums) {
        const int MIN = 1e-5;
        int cnt = 0;
        int sz = nums.size();
        if (sz <= 2) {
            return true;
        }

        int pre = nums[0];
        int pre_pre = MIN;
        for (int i = 1; i < sz; i++) {
            if (pre > nums[i]) {
                if (++cnt > 1) {
                    return false;
                }
                if (nums[i] >= pre_pre) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = pre;
                }
            }
            pre = nums[i];
            pre_pre = nums[i - 1];
        }

        return true;
    }
};

int main(){
    
    
    return 0;
}