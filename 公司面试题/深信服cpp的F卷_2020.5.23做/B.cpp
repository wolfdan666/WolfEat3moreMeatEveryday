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
    puts("Come Func?");  // YES
    cout << "1 a: " << a1 << " b: " << b1 << " v: " << v1 << endl;
    cout << "1 a: " << a2 << " b: " << b2 << " v: " << v2 << endl;


    cout << "error? : "<<(v1*a2 - v2*a1) << endl;
    cout << "error? : "<<(b1*a2 - a1*b2) << endl;
    /*
3
1 2 3 4 5 6
读入出错了？
Come Func?
error? : 0
error? : 0
可见是自己传入参数或者输入写错了
    */
    cout << "error mod? : "<<(v1*a2 - v2*a1) % (b1*a2 - a1*b2) << endl;

    if( (v1*a2 - v2*a1) % (b1*a2 - a1*b2) != 0 ) return -1;
    y = (v1*a2 - v2*a1) / (b1*a2 - a1*b2);

    cout << "y: " << y <<endl;

    if( (v1 - b1*y) % a1 != 0 || y < 0) return -1;
    x = (v1 - b1*y) / a1;

    if(x < 0) return -1;

    cout << "x: " << x <<endl;

    return 0;
}

int main(){
    T = rd();
    while(T--){
        // scanf("%lld,%lld,%lld,%lld,%lld,%lld",
        //         &a1,&b1,&v1,&a2,&b2,&v2);
        scanf("%lld %lld %lld %lld %lld %lld",
                &a1,&b1,&v1,&a2,&b2,&v2);
        cout << "读入出错了？" << endl;
        cout << "1 a: " << a1 << " b: " << b1 << " v: " << v1 << endl;
        cout << "1 a: " << a2 << " b: " << b2 << " v: " << v2 << endl;

        ll x,y;
        int ret = solve(a1,b1,v1,a2,b2,v2,x,y);

        puts("函数错误？");

        if( -1 == ret ) puts("UNKNOWN");
        // else printf("%lld,%lld\n", x,y);
        else printf("%lld %lld\n", x,y);
    }

    return 0;
}