/*
2020年5月23日15:34:53 开始看题

2020年5月23日15:36:54 经典的方程组问题，扩展gcd
虽然我有点小忘了，但是可以复习啊，233
2020年5月23日15:43:14 写完方程式发现，这就是小学生题

设 水果 x 元，面点 y 元
a1*x + b1*y = v1;
a2*x + b2*y = v2;

a1*a2*x + b1*a2*y = v1*a2;
a1*a2*x + a1*b2*y = v2*a1;

// 注意1e18 爆 int
// UNKNOWN
if( (v1*a2 - v2*a1) % (b1*a2 - a1*b2) != 0 ) return -1;
y = (v1*a2 - v2*a1) / (b1*a2 - a1*b2);
if( (v1 - b1*y) % a1 != 0 ) return -1;
x = (v1 - b1*y) / a1;
return 0;

// x,y 传引用吧

2020年5月23日16:23:51 被自己scanf的`,`演了20分钟，菜哭
主要是没有判断div 0和 mod 0 ,自己的错误
2020年5月23日16:29:34 没有考虑多解...

2020年5月23日16:38:37 WA 1
您的代码已保存
浮点错误:您的程序运行时发生浮点错误，比如遇到了除以 0 的情况
case通过率为50.00%
估计错在下面这句
有50%的数据案例，上述六个数都属于区间[1,100]；而100%的数据案例，上述六个数都属于区间[0,1e9]。

2020年5月23日17:06:31 竟然还是wa了，输出一大版，很多UNKNOWN我都有输出...
想到自己后面加的没有判断不能整除

110919680 110919679 65897889 1 1 182710022
找出一个错误样例来研究

2020年5月23日17:14:21 Debug自闭，然后牛客TLE交卷了...我就看大佬的代码了



b1*y 爆ll 了
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
int T;
ll a1,b1,v1,a2,b2,v2;

int solve(ll a1,ll b1,ll v1,ll a2,ll b2,ll v2,ll& x,ll& y){
    // 注意1e18 爆 int
    // UNKNOWN
    // 多解判断
    // 两个0的情况
    if(a1 == 0 && b1 == 0 && a2 != 0 && b2 != 0) return -1;
    if(a2 == 0 && b2 == 0 && a1 != 0 && b1 != 0) return -1;
    if(a1 == 0 && a2 == 0 && b1 != 0 && b2 != 0) return -1;
    if(b1 == 0 && b2 == 0 && a1 != 0 && a2 != 0) return -1;

    if(a1 == 0 && b2 == 0 && b1 != 0 && a2 != 0){
        if(v1%b1 && v2/a2) return -1;
        y = v1/b1;
        x = v2/a2;
        return 0;
    }
    if(a2 == 0 && b1 == 0 && a1 != 0 && b2 != 0){
        if(v1%a1 && v2/b2) return -1;
        x = v1/a1;
        y = v2/b2;
        return 0;
    }

    // 3个0的情况
    if( (a1==0)+(a2==0)+(b1==0)+(b2==0) == 3) return -1;

    // 一个0和4个0的情况
    if(a1*b2 == a2*b1) return -1;
    // div 0 , mod 0 必须要判断，上面判断了
    // if( (b1*a2 - a1*b2) == 0) puts("mod 0 or div 0");

    if( (v1*a2 - v2*a1) % (b1*a2 - a1*b2) != 0 ) return -1;
    y = (v1*a2 - v2*a1) / (b1*a2 - a1*b2);

    printf("%lld\n", y);

    // 4个数有一个为0，可以下面这样解
    // if( a1 == 0) puts("mod 0 or div 0");
    if(a1 == 0){
        if( (v2 - b2*y) % a2 != 0 || y < 0) return -1;
        x = (v2 - b2*y) / a2;
    }
    else{




        // 这里b1*y 爆ll 了



        if( (v1 - b1*y) % a1 != 0 || y < 0) return -1;
        x = (v1 - b1*y) / a1;
    }

    printf("%lld\n", x);

    if(x < 0) return -1;

    return 0;
}

int main(){
    T = rd();
    while(T--){
        scanf("%lld %lld %lld %lld %lld %lld",
                &a1,&b1,&v1,&a2,&b2,&v2);
        ll x,y;
        int ret = solve(a1,b1,v1,a2,b2,v2,x,y);

        if( -1 == ret ) puts("UNKNOWN");
        else printf("%lld %lld\n", x,y);
    }

    return 0;
}