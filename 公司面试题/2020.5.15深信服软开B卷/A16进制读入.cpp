/*
您的代码已保存
答案错误:您提交的程序没有通过所有的测试用例
case通过率为83.33%

用例:
0x40000001,30

对应输出应该为:

0x80000000

你的输出为:

0x40000000

2020年5月16日00:01:37 估计是引起符号位异常了,不对,他竟然是要输出8000... ?
则在第n位上加1 ....  题目没看清

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
int n;
int x;
// ll x;

int main(){
    // scanf("%I64x",&x);
    scanf("%x",&x);
    n = rd();
    bool noAllZores = false;
    for(int i=0;i<n;i++){
        if( x & (1<<i)){
            noAllZores = true;
            x &= (~(1<<i));
        }
    }
    if(noAllZores) x += (1<<n);
    printf("0x%x\n",x);

    return 0;
}