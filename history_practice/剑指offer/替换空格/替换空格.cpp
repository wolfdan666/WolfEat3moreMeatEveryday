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

const int strLen = 1024;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == nullptr || length <= 0) return;

        int originLength = 0,numberOfBlank = 0;
        int i = 0;
        while(str[i] != '\0'){
            originLength++;

            if(str[i] == ' ') numberOfBlank++;

            i++;
        }

        int newLength = originLength+numberOfBlank*2;
        if(newLength > length) return ;

        int indexOfOrigin = originLength;
        int indexOfNew = newLength;
        while(indexOfOrigin>=0 && indexOfNew >= indexOfOrigin){
            if(str[indexOfOrigin] == ' '){
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            } else {
                str[indexOfNew--] = str[indexOfOrigin];
            }

            indexOfOrigin--;
        }
    }
};

int main(){
    char s[strLen];
    // scanf("%s",s);
    cin.getline(s,strLen);
    // 设置变化后的最长长度
    int len = 1000;
    Solution A;

    A.replaceSpace(s,len);
    cout<<s<<endl;

    return 0;
}