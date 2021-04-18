/* 
2021年04月18日19:29:08 感觉就是倒序找到一个
降序pair，然后swap就行了

233 -- 323 ，而不是 332，所以相等的时候，要把big_index前移
但是如果像下面那样小于

不对，完全错了，我自己只搞了两个位置的互换

链接：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/
看答案，差了许多---详见答案

输入：
[1,3,2]
输出：
[3,1,2]
预期结果：
[2,1,3]
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
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int sz = nums.size();
//         int big_index = sz - 1;
//         int low_index = -1;
//         for (int i = sz - 2; i > -1; i--) {
//             if (nums[big_index] > nums[i]) {
//                 low_index = i;
//                 break;
//             } else {
//                 big_index = i;
//             }
//         }
//         if (-1 != low_index) {
//             swap(nums[big_index], nums[low_index]);
//         } else {
//             sort(nums.begin(), nums.end());
//         }
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};



int main(){
    
    
    return 0;
}