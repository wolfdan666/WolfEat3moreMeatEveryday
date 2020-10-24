/*
LeetCode1024_视频拼接

2020年10月24日14:49:38 开始看题

感觉是个递归，就是总体先判断能否拼成(总的区间加起来是否连续)
然后减去为1的段，再看子段是否可以
接近O(nlog(n))

但是递归好像不如贪心，sort一下，然后贪心拼接，好，写
2020年10月24日14:58:14 写贪心

2020年10月24日16:22:13 尴尬
30 / 52 个通过测试用例
状态：解答错误
提交时间：几秒前
输入：
[[5,7],[1,8],[0,0],[2,3],[4,5],[0,6],[5,10],[7,10]]
5
输出：
2
预期：
1

if (nxt_st >= T) break;
改成
if (nxt_st >= T) return ans;

2020年10月24日16:24:38
执行用时：8 ms, 在所有 C++ 提交中击败了49.89%的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了54.27%的用户

去看题解
https://leetcode-cn.com/problems/video-stitching/solution/shi-pin-pin-jie-by-leetcode-solution/
题解也不错
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
    // 问题在于这cmp是一个成员函数，您需要一个指向成员的指针才能调用它。
    // error: reference to non-static member function must be called sort(clips.begin(), clips.end(), cmp);
                                                                                                 //   ^~~ 1 error generated.
    // bool cmp(vector<int>& a, vector<int>& b) {
    static bool cmp(vector<int>& a, vector<int>& b) {
        vector<int>::iterator it_a = a.begin();
        vector<int>::iterator it_b = b.begin();
        if (*it_a == *it_b) {
            // vector<int>::iterator it_b = a.begin() + 1;
            // 这里 b.begin()写成了a,而且it_b++,不是b.begin()+1
            it_a++;
            it_b++;
            return *it_a > *it_b;
        }
        // printf("*it_a is %d, *it_b is %d\n", *it_a, *it_b);
        return *it_a < *it_b;
    }

    int videoStitching(vector<vector<int>>& clips, int T) {
        int ans = 0;
        sort(clips.begin(), clips.end(), cmp);

        // st - T
        int st = 0;
        int nxt_st = -1;
        int sz = clips.size();
        for (int i = 0; i < sz; i++) {
            if (clips[i][0] <= st) {
                // 找到起始小于等于st中end最大的
                if (clips[i][1] > nxt_st) nxt_st = clips[i][1];
                continue;
            }
            // 2020年10月24日16:03:07 debug发现需要i--
            i--;
            if (nxt_st <= st) return -1;
            ans++;
            if (nxt_st >= T) return ans;
            st = nxt_st;
        }
        // 最后还要有处理,VScode 调试不错
        if (nxt_st <= st) return -1;
        ans++;
        if (nxt_st < T) return -1;
        st = nxt_st;

        return ans;
    }
};

int main(){
    vector<vector<int>> clips;
    int x = 0,y = 2;
    for (int i = 0; i < 3; i++) {
        int a[] = {x, y};
        x += 2;
        y += 2;
        vector<int> tmp(a,a+sizeof(a)/sizeof(int));
        clips.push_back(tmp);
    }
    int a[] = {1, 3};
    vector<int> tmp(a,a+sizeof(a)/sizeof(int));
    clips.push_back(tmp);

    Solution sol;
    cout << sol.videoStitching(clips, 6) << endl;

    return 0;
}