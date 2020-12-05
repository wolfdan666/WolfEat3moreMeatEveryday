/*
2020年12月05日22:00:38 开始看题

2020年12月05日22:02:23
感觉应该就是n + 1大小的一个窗口，窗口里面可以放任意种类中的一个
计算最小长度，给每一类计数，然后最大计数 max_k
max_k 就是窗口个数
然后前 max_k - 1个窗口的实际大小都是 n + 1,然后最后一个窗口是同样max_k个计数的种类数

还要考虑一个窗口装不下的情况

有点像 `俄罗斯方块` ， 消除一行行，有的行比较长

A
AB
ABC
ABCDEFG

A最多，所以先消除A，用n+1的框子，从左边开始一行行消除
对种类计数O(n),然后消除又不超过O(n) ( 有max_k 层遍历 ) --- 分析得有点粗略

所以需要对每个种类计数映射
以及最大计数的种类数

2020年12月05日22:17:54 觉得不是很好的思路，看看答案
2020年12月05日22:40:06 结果发现自己的想法完全和答案接近，就差一点点就直接可以准确获取了...

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode-solution-ur9w/

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
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }

        // 最多的执行次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
        })->second;
        // 具有最多执行次数的任务数量
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
            return acc + (u.second == maxExec);
        });

        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};


int main(){


    return 0;
}