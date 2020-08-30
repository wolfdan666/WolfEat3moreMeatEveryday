/*
2020年8月30日20:45:29 这么简单的题目写了 40 分钟
中途还把临时变量传入一直void返回的函数，这不行啊，多练啊

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
    void reverseWord(string & s, int start, int len) {
        /*
        len 没有加 start 偏移，所以函数中的东西都要加start偏移
        */
        int half_len = start + (len >> 1);
        int end = start + len;
        for (int i = start; i < half_len; i++) {
            swap(s[i], s[(end - 1) - i + start]);
        }
    }

    // 首尾当成空白
    string reverseWords(string s) {
        int len = s.length();
        int pre_black = -1;
        for (int i = 0; i <= len; i++) {
            if (i == len || s[i] == ' ') {
                reverseWord(s, pre_black + 1, (i - 1) - pre_black);
                pre_black = i;
            }
        }

        return s;
    }
};

int main(){
    string s("hello world");
    Solution sol;
    cout << sol.reverseWords(s) << endl;

    return 0;
}