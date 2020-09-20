/* 
2020年09月20日15:40:01 开始
想到的是 0 ， 1， 2 ... n 个元素组成
每次都抓取一个元素，和上一次的vector进行合并‘

时间复杂度都是 O(n^2)---2020年09月20日16:02:27 发现不对，应该是O(n*n*max(过程vector.size()))

空间先用set存,所以可以尽量小

2020年09月20日16:03:28 而且发现自己的插入方法不如这种https://leetcode-cn.com/problems/subsets/solution/hui-su-wei-yun-suan-di-gui-deng-gong-4chong-fang-s/

所以自己改一下

2020年09月20日17:18:42 因为在mac上新配bits/stdc++,以及忘了return..
导致折腾好久

其他解法
https://leetcode-cn.com/problems/subsets/solution/zi-ji-by-leetcode-solution/
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
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> tmp_empty;
        ans.push_back(tmp_empty);

        for (auto num : nums) {
            for (int i = 0, j = ans.size(); i < j; i++) {
                vector<int> tmp(ans[i]);
                tmp.push_back(num);
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};

int main(){
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {1,2,3};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    Solution sol;
    vector<vector<int> > ans = sol.subsets(fifth);
    for (auto x : ans) {
        cout << "[";
        int sz = x.size();
        for (int i=0; i < sz; i++){
            if(i) cout << ",";
            printf("%d", x[i]);
        }
        cout << "]" << endl;
    }

    return 0;
}