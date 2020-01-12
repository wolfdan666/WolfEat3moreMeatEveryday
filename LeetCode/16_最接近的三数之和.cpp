// 2020年1月12日13:08:07 开始看题
/*
2020年1月12日13:11:49 想到的是O(n^2)的算法，就是遍历第一个值+两个指针,然后判断最接近
[题目说了唯一答案]

所以应该就是这样的,开始写吧 2020年1月12日13:13:11

在else if比较发呆一会儿，后面用纸笔写，一下子就明白了...


2020年1月12日13:51:23 手生了，写了40mins...

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

// 2020年1月12日13:38:50 测试完交到LeetCode说我堆栈溢出，不用INT_MAX也溢出
// 所以2020年1月12日13:42:29 看题解，看别人的代码好像比别人差了一点点
// 2020年1月12日13:46:02 发现自己傻逼了，r--写成了r++... 手生了，测试案例可能没用到r--,所以本地没报错
/*
第一发：
执行用时 :
20 ms
, 在所有 C++ 提交中击败了
20.02%
的用户
内存消耗 :
8.9 MB
, 在所有 C++ 提交中击败了
71.50%
的用户

第二发加：if(dftmp == 0) return tp; 速度超过了我看到的解题，odk
执行用时 :
12 ms
, 在所有 C++ 提交中击败了
59.85%
的用户
内存消耗 :
8.9 MB
, 在所有 C++ 提交中击败了
71.50%
的用户
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // int ans = INT_MAX;
        int ans = 0;
        // int df = INT_MAX;
        int df = 0x3f3f3f3f;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i++){
            int l = i+1,r = n-1;

            while(l<r){
                int tp = nums[l] + nums[r] + nums[i];
                int dftmp = abs(tp - target);
                if(dftmp == 0) return tp;

                if(dftmp < df) ans = tp,df = dftmp;

                if(tp < target) l++;
                // else r++;
                else r--;
            }
        }

        return ans;
    }
};

// 作者：varyshare
// 链接：https://leetcode-cn.com/problems/3sum-closest/solution/yi-dong-gao-xiao-cti-jie-ji-bai-99yong-hu-by-varys/
/*
2020年1月12日13:50:54 测
执行用时 :
16 ms
, 在所有 C++ 提交中击败了
32.31%
的用户
内存消耗 :
9.1 MB
, 在所有 C++ 提交中击败了
71.14%
的用户
*/
class Solution {
public:

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closestSumValue = nums[0]+ nums[1]+ nums[2];
    int digit1_index, digit2_index, digit3_index;// 所选定的要求和的三个数的下标
    int max_digit1_index = nums.size() - 2;
    // 从左到遍历一遍数组，遍历到第i个元素时则认为该元素为第一个选定元素
    // 另外两个元素是从该元素的右边选择（即从第i+1到end之间选另外两个元素）。
    for (int i = 0; i < max_digit1_index; i++)
    {
        digit1_index = i;
        digit2_index = i + 1;
        digit3_index = nums.size() - 1;
        int tmp_sum = nums[digit1_index] + nums[digit2_index] + nums[digit3_index];
        // 第一个数是在当前时刻是指定不变了
        // 下面这个循环要做的事情就是确定在第一个数是nums[i]的情况下
        // 剩下两个数怎么选最合适
        while (digit2_index < digit3_index)
        {
            if (abs(tmp_sum - target) < abs(closestSumValue - target))
                closestSumValue = tmp_sum;
            int difference = target - tmp_sum;
            if (difference == 0)
                return target;
            if (difference > 0)
            {
                // target比tmp_sum大，所以为了缩小差距那就应该增大tmp_sum
                // 但是第3个数已经是最大了那就增大第2个数
                digit2_index++;
            }
            else {
                // target比tmp_sum小，所以为了缩小差距那就应该减小tmp_sum
                // 但是第2个数已经是最小了那就减小第3个数
                digit3_index--;
            }
            tmp_sum = nums[digit1_index] + nums[digit2_index] + nums[digit3_index];
        }
    }
        return closestSumValue;
}
};


int main(){
    int T;
    vector<int> tmp;
    cin>>T;
    int t;
    while(T--){
        cin>>t;
        tmp.pb(t);
    }
    int target;
    cin >> target;

    Solution a;
    cout<<a.threeSumClosest(tmp,target)<<endl;

    return 0;
}

/*
in:
4 -1 2 1 -4
1

out:
2

*/