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


int main(){
    // char*转换为string

    // （注意，定义char *变量，并直接赋值，最好定义为const变量，否则编译器警告）
    const char *st = "hello";

    // 赋值转换
    string st1 = st;
    cout << st1 << endl;

    // 构造转换
    string s1(st, st + strlen(st));
    cout << s1 << endl;

    // 改变const char *变量值---> 这里的编译环境竟然没有报错( * const 修饰指针，const *修饰变量)
    st = "lalala";
    cout << st << endl;

    return 0;
}