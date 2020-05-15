/*
2020年5月12日21:33:24 这个之前数据结构课就分析过

2020年5月12日21:45:21 尴尬，一时间竟然想不出,看网上答案吧

2020年5月12日22:00:18 明天再学，有点乏了

2020年5月14日22:26:50 观摩了别人Py写的之后再次尝试

2020年5月14日22:50:22 AC
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
string s;
set<string> strs;

void getAllStrs(const string s,int i,string stk,string printed,set<string>& strs){
    // 注意tmp1和stk是要回溯的，所以这两者不能传引用；而res是一直保留结果的，传引用就对
    string tp_stk = stk;
    string tp_printed = printed;
    if(i == int(s.length()) ){
        reverse(tp_stk.begin(), tp_stk.end());
        tp_printed += tp_stk;
        strs.insert(tp_printed);
        return;
    }
    // 先将当前字母入栈，然后后面选择继续递归入栈或者出栈
    tp_stk += s[i];
    // 继续遍历
    getAllStrs(s,i+1,tp_stk,tp_printed,strs);
    while(!tp_stk.empty()) {
        // 出栈一个之后遍历进入下一个，或者是出栈多个之后遍历进入下一个i+1
        tp_printed += tp_stk.back();
        tp_stk.pop_back();
        getAllStrs(s,i+1,tp_stk,tp_printed,strs);
    }
}

int main(){
    cin >> s;
    string stk = "",printed = "";
    getAllStrs(s,0,stk,printed,strs);
    for(auto i:strs) cout<<i<<endl;

    return 0;
}