// 编写一个C函数,将”I am from beijing ”倒置为”beijing from am
// I”,及将句子中的单词位置倒置,而不改变单词内部结构.

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


int main(int argc, char *argv[]) {
    char s[100] = "I am from beijing";
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - 1 - i]);
    }

    int begin = 0;
    int end;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ' || i == n - 1) {
            end = i;
            int length = end - begin;
            for (int j = begin; j < begin + length / 2; j++) {
                swap(s[j], s[begin + end - 1 - j]);
            }
            begin = i + 1;
            if (begin >= n - 1) break;
        }
    }

    cout<<s<<endl;

    return 0;
}


// beijing from am I