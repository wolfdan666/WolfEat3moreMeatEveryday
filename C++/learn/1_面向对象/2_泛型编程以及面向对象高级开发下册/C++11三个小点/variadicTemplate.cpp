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

void print(){}

template<typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    cout<< firstArg <<endl;
    print(args...);
}

int main(){
    // sizeof...(args)可以获取一包的大小
    print(7.5,"hello",bitset<16>(377),42);

    return 0;
}

/*
7.5
hello
0000000101111001
42
请按任意键继续. . .
*/
