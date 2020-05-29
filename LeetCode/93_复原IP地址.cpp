/*
2020年5月29日22:10:56 感觉就是一个简单的dfs

2020年5月29日22:21:03 先休息一下吧
2020年5月29日22:38:09
继续吧，有点不知道用啥数据结构组织起来，有点尴尬
2020年5月29日22:47:54 发现就是简单传一个cur分支就行了...

2020年5月29日23:23:16 Wa 56mins
输入:
"0000"
输出
["0.0.0.0","0.0.00.","0.0.00."]

2020年5月29日23:27:27 又wa了，有0的处理都没考虑...
输入:
"010010"
输出
["0.1.0.010","0.1.00.10","0.1.001.0","0.10.0.10","0.10.01.0","0.100.1.0","01.0.0.10","01.0.01.0","01.00.1.
预期结果
["0.10.0.10","0.100.1.0"]


2020年5月29日23:32:24 AC 65分钟，要是面试写这么久，黄花菜都凉了
执行用时: 0 ms , 在所有C++提交中击败了100.00%的用户
内存消耗: 6.6 MB , 在所有C++提交中击败了100.00% 的用户
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
    void dfs(const string& s,string cur,int i){
        // sz是用掉的尺寸
        // left_sz是剩下的
        int sz = i <= 1 ? cur.size() : cur.size()-(i-1);
        int left_sz = s.size() - sz;
        if(3 == i){
            // cout<< "1 here i == 3 "<<endl;
            if(left_sz<=0 || left_sz > 3) return;
            string sub = s.substr(sz,left_sz);
            // cout<< "2 here i == 3, sub :" <<sub<<endl;
            int tp = atoi(sub.c_str());

            if(tp!=0 && sub[0]=='0') return;
            if(tp==0 && sub.size()>1) return;

            if(tp > 255) return ;

            // cout<< "3 here i == 3 "<<endl;
            ans.push_back(string(cur+'.'+sub));
        }
        else if(2 == i){
            if(left_sz<2 || left_sz>6) return;
            for(int k=1;k<=3;k++){
                string sub = s.substr(sz,k);

                // cout<< "2 here i == 2, sub :" <<sub<<endl;
                int tp = atoi(sub.c_str());
                if(k==3 && tp>255) return;

                if(tp!=0 && sub[0]=='0') return;
                if(tp==0 && sub.size()>1) return;

                dfs(s,cur+'.'+sub,3);
            }
        }
        else if(1 == i){
            if(left_sz<3 || left_sz>9) return;
            for(int k=1;k<=3;k++){
                string sub = s.substr(sz,k);
                // cout<< "2 here i == 1, sub :" <<sub<<endl;
                int tp = atoi(sub.c_str());
                if(k==3 && tp>255) return;

                if(tp!=0 && sub[0]=='0') return;
                if(tp==0 && sub.size()>1) return;

                dfs(s,cur+'.'+sub,2);
            }
        }
        else if(0 == i){
            if(left_sz<4 || left_sz>12) return;
            for(int k=1;k<=3;k++){
                string sub = s.substr(sz,k);
                // cout<< "2 here i == 0, sub :" <<sub<<endl;
                int tp = atoi(sub.c_str());
                if(k==3 && tp>255) return;

                if(tp!=0 && sub[0]=='0') return;
                if(tp==0 && sub.size()>1) return;

                dfs(s,sub,1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        dfs(s,"",0);
        return ans;
    }
private:
    vector<string> ans;
};

int main(){
    Solution test;
    // string s = "25525511135";
    string s = "010010";
    vector<string> ans;
    ans = test.restoreIpAddresses(s);
    for(auto x:ans) cout<<x<<endl;

    return 0;
}