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

int a[5] = {12,34,56,78,90};

int main(){
    // *p 是个地址，p是指向地址的指针. --- 2020年3月14日 理解错了
    // 2020年3月15日21:00:06 发现 p 等价于a 地址
    int *p = a;
    cout<< *p++ <<endl;
    // 12
    cout<< *p <<endl;
    // 34
    cout<< a[p-a] <<endl;
    // 34
    cout<< *(&a[3]) <<endl;
    // 78
    cout<< p[3] <<endl;
    // 90
    p++;
    cout<< *p <<endl;
    // 56
    (*p)++;
    cout<< *p <<endl;
    // 57

    return 0;
}