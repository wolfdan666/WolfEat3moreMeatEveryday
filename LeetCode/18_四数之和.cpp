/*
2020年1月26日18:58:24 开始看题

2020年1月26日19:00:11 感觉就是先sort,然后双指针

我记得好像覃超老师提醒过思路来的，然后我现在居然忘了...再想想

好像是求出所有的两数之和，并且标上记号，然后就可以再做一次两数之和就行了

所以复杂度是O(n^2),2020年1月26日19:10:37 尝试写一发吧

2020年1月26日19:15:12 不知道怎么在LeetCode的class里面建立含有两个下标和一个value的struct
所以看题解吧

2020年1月26日19:21:57 发现题解是 O(n^3)的解法...
然后想到自己的解法第一遍O(n^2),然后第二遍就是在O(n^2)的基数上O(N^2) === 也就是说我其实还是O(n^4)...自己傻逼了...

2020年1月26日19:32:29 还是没有看懂为啥a一定要变动
2020年1月26日19:35:18 懂了,因为a是b的外循环,小的a早就已经和所有的b走过一圈了，然后如果a不变的话，后面会产生很多重复的vector.
b不变同理.
1 2 2 2 4     target = 9,  [1,2,2,4] 如果b不变,又会产生两组这种值，对的

2020年1月26日19:40:31 finish，也就是说花了42分钟，果然还是要保持手感！怪不得秦皇岛之后一直落落落...
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        if(n<4) return ans;

        set<TValue>
    }
};

// 作者：misakasagiri-2
// 链接：https://leetcode-cn.com/problems/4sum/solution/shuang-zhi-zhen-jie-fa-can-zhao-san-shu-zhi-he-ge-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        if(nums.size()<4)
        return res;
        int a,b,c,d,_size=nums.size();
        for(a=0;a<=_size-4;a++){
            if(a>0&&nums[a]==nums[a-1]) continue;      //确保nums[a] 改变了
            for(b=a+1;b<=_size-3;b++){
                if(b>a+1&&nums[b]==nums[b-1])continue;   //确保nums[b] 改变了
                c=b+1,d=_size-1;
                while(c<d){
                    if(nums[a]+nums[b]+nums[c]+nums[d]<target)
                        c++;
                    else if(nums[a]+nums[b]+nums[c]+nums[d]>target)
                        d--;
                    else{
                        res.push_back({nums[a],nums[b],nums[c],nums[d]});
                        while(c<d&&nums[c+1]==nums[c])      //确保nums[c] 改变了
                            c++;
                        while(c<d&&nums[d-1]==nums[d])      //确保nums[d] 改变了
                            d--;
                        c++;
                        d--;
                    }
                }

            }
        }
        return res;
    }
};

int main(){


    return 0;
}