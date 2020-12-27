/*
2020年12月27日09:44:47 感觉就是简单的使用一个map或者char[26]数组

2020年12月27日09:59:05 wa -- [ab, aa]
就是value不能是以前有过的value

2020年12月27日10:06:31 AC之后
看了答案，应该用hash_map
然后快了20ms --- 36ms到16ms

双hash_map也行，可以不set
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
    bool isIsomorphic(string s, string t) {
        int sz = s.size();
        if (sz <= 1)
            return true;

        char_map.clear();
        vals.clear();
        char_map[s[0]] = t[0];
        vals.insert(t[0]);
        for (int i = 1; i < sz; i++) {
            if (char_map.find(s[i]) != char_map.end()) {
                if (char_map[s[i]] != t[i])
                    return false;
                continue;
            }
            if (vals.find(t[i]) != vals.end())
                return false;
            // key 是 新的，val也得是新的
            char_map[s[i]] = t[i];
            vals.insert(t[i]);
        }
        return true;
    }
private:
    // map<char, char> char_map;
    unordered_map<char, char> char_map;
    set<char> vals;
};

int main(){
    Solution sol;
    string s("paper");
    string t("title");
    cout << sol.isIsomorphic(s, t) << endl;

    return 0;
}