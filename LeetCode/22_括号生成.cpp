/*
2020年2月16日13:06:07 真实开始
以前好像做过类似的题目，暴力法是写个递归

想想怎么用循环实现，分叉太多了，就用递归写吧

2020年2月16日13:30:14 感觉自己还是不会写，完了，
完全没有手感了...好久没有写算法题...参考一下答案吧


2020年2月16日14:29:17 看了题解AC...花了1个半小时...中途浪聊天了30mins
执行用时: 4 ms , 在所有C++提交中击败了93.29% 的用户
内存消耗: 17 MB , 在所有C++提交中击败了61.20% 的用户
这段时间还是要多练
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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tp = "";
        dfs(0,0,n,tp,ans);
        return ans;
    }

    void dfs(int a,int b,int n,string tp,vector<string> & ans){
        if(int(tp.length()) == n*2){
            ans.push_back(tp);
            return;
        }

        if(a < n) dfs(a+1,b,n,tp+"(",ans);
        if(b < a) dfs(a,b+1,n,tp+")",ans);
    }
};

int main(){
    int n = 3;
    // cin >> n;
    Solution a;
    vector<string> ans = a.generateParenthesis(n);
    for(auto i:ans){
        cout<< i <<endl;
    }

    return 0;
}