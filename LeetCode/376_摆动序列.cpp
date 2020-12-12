/*
2020年12月12日23:44:36 感觉这个题目是个模拟题
就是找出一条尽量长，尽量起伏大的波浪数字线

一小段里面的最大直接取最大就好了

比较两条线：
1. 先递增
2. 先递减

2020年12月13日00:31:54 自己竞技状态全无，wa在一些很小的点
尴尬，不行，我要肝出来
2020年12月13日00:37:11 AC

2020年12月13日00:38:32 发现答案还有2个动态规划的做法，
个人感觉动态规划和这题的主要思路偏离太多，所以就不看了，直接用贪心最好
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
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return size;
        int ans = 1;
        // int cur_i = 0;
        int rise_flag = -1;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[0]) {
                rise_flag = 1;
                ans++;
                break;
            } else if (nums[i] < nums[0]) {
                rise_flag = 0;
                ans++;
                break;
            }
        }
        if (rise_flag == -1)
            return 1;

        for (int i = 1; i < size; i++) {
            if (rise_flag) {
                if (nums[i] < nums[i - 1]) {
                    ans++;
                    rise_flag = 0;
                    // cur_i = i;
                }
            } else {
                if (nums[i] > nums[i - 1]) {
                    ans++;
                    rise_flag = 1;
                    // cur_i = i;
                }
            }
        }
        // if (cur_i != size - 1)
        //     ans++;

        return ans;
    }
};

int main(){


    return 0;
}