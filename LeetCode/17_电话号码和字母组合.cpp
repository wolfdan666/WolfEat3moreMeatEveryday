/*
2020年1月19日18:04:16 开始想
感觉就是暴力,不过处理可能需要一点小技巧
中途和别人聊天去了，然后又吃晚饭了


2020年1月19日19:18:24 又开始想，感觉就是写一个递归比较方便

只能想到O(len(digits)*ans.size())

2020年1月19日19:58:46 好久没有写题了,手生了40mins,写完了结果测试为空

2020年1月19日20:28:24 交了第一发
```
7 / 25 个通过测试用例
执行出错信息：
Line 29: Char 33: runtime error: index 4 out of bounds for type 'char [4]' (solution.cpp)
最后执行的输入：
"7"
```

然后自己测试发现
cin: 7
out:
s: 0   id: 6   n: 7
p
q
r
s
t
u
v

不科学啊,为什么还数据了id=8的内容？

我知道了，我分配的char只有4,所以'\0'丢失了！
所以要改成 5 ,char[10][5]


2020年1月19日20:36:55 运行 0ms,然后发现大家都是0ms...原来是题目特判

一个很简单的题目，写了80mins，丢人啊
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
    // char C[10][4] = {{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},
    char C[10][5] = {{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},
                    {'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'},{}};

    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> ans;

        if(!n) return ans;

        add(digits,0,n,ans);

        return ans;
    }

    void add(string digits,int s,int e,vector<string> &ans){
        if(s == e) return;

        int id = digits[s] - '1';
        int n = strlen(C[id]);

        // cout<<"s: "<<s<<"   id: "<<id<<"   n: "<<n<<endl;

        if(s==0){
            for(int i=0;i<n;i++){
                // 这里控制符有"\0",可能导致一些错误...在这里卡了大概15mins以上,mdzz
                // string tp = ""+C[id][i];
                char c = C[id][i];
                string tp;
                stringstream stream;
                stream << c;
                tp = stream.str();

                ans.push_back(tp);

                // rep(i,0,ans.size()-1) cout<<ans[i]<<endl;
            }
        }

        else{
            int m = ans.size();

            vector<string> tmp(ans.begin(), ans.end());

            for(int j=0;j<m;j++){
                ans[j] += C[id][0];
            }

            for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                    string tp = tmp[j] + C[id][i];
                    ans.push_back(tp);
                }
            }
        }

        s++;
        add(digits,s,e,ans);
    }
};

int main(){
    string s;
    cin>>s;
    Solution a;
    vector<string> anstest = a.letterCombinations(s);
    int n = anstest.size();

    rep(i,0,n-1){
        cout<<anstest[i]<<endl;
        // printf("%c","\n\t"[i%10]);
    }

    return 0;
}