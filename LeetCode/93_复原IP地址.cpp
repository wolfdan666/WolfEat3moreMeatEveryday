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


2020年5月30日12:39:34 反思了一下，发现可以直接把dfs写成4重for(3)循环...真实...
2020年5月30日12:50:55 决定写一手
2020年5月30日13:12:09
terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::substr: __pos (which is 5) > this->size() (which is 4)
最后执行的输入：
"1111"

2020年5月30日13:16:49(25分钟)
执行用时: 4 ms , 在所有C++提交中击败了81.72% 的用户
内存消耗: 6.7 MB , 在所有C++提交中击败了100.00% 的户

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

class Solution_for {
public:
    bool substr_ok(string sub){
        int tp = atoi(sub.c_str());
        int k = sub.size();
        if(k==3 && tp>255) return false;
        if(tp!=0 && sub[0]=='0') return false;
        if(tp==0 && k>1) return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        int sz = s.size();
        for(int i=1;i<4;i++){
            if(i > sz) continue;
            string sub1 = s.substr(0,i);
            if(!substr_ok(sub1)) continue;

            for(int j=1;j<4;j++){
                if(i+j > sz) continue;
                string sub2 = s.substr(0+i,j);
                if(!substr_ok(sub2)) continue;

                for(int k=1;k<4;k++){
                    if(i+j+k > sz) continue;
                    string sub3 = s.substr(i+j,k);
                    if(!substr_ok(sub3)) continue;

                    int left_sz = sz - (i+j+k);
                    if(left_sz<=0 || left_sz>3) continue;
                    // for(int p=1;p<=left_sz;p++){
                    string sub4 = s.substr(i+j+k,left_sz);
                    if(!substr_ok(sub4)) continue;

                    ans.push_back(sub1+'.'+sub2+'.'+sub3+'.'+sub4);
                    // }
                }
            }
        }

        return ans;
    }
};

int main(){
    // Solution test;
    Solution_for test;
    // string s = "25525511135";
    // string s = "010010";
    string s = "1111";
    vector<string> ans;
    ans = test.restoreIpAddresses(s);
    for(auto x:ans) cout<<x<<endl;

    return 0;
}