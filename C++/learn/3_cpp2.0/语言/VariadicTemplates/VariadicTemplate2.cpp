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

void Tprintf(const char* s){
    while(*s) {
        if(*s == '%' && *(++s) != '%')
            throw std::runtime_error("invalid format string: missing arguments");
        std::cout<< *s++;
    }
}

template<typename T,typename... Args>
void Tprintf(const char* s,T value,Args... args)
{
    while(*s) {
        if(*s == '%' && *(++s) != '%'){
            std::cout<< value;
            // call even when *s == 0 to decect extra argument
            // 这里指向while外的那句
            Tprintf(++s,args...);
            return;
        }
        std::cout<< *s++;
    }

    throw std::logic_error("extra arguments provided to printf");
}

namespace test{
    void printf(const char* s){
        while(*s) {
            if(*s == '%' && *(++s) != '%')
                throw std::runtime_error("invalid format string: missing arguments");
            std::cout<< *s++;
        }
    }

    template<typename T,typename... Args>
    void printf(const char* s,T value,Args... args)
    {
        while(*s) {
            if(*s == '%' && *(++s) != '%'){
                std::cout<< value;
                // call even when *s == 0 to decect extra argument
                // 这里指向while外的那句
                printf(++s,args...);
                return;
            }
            std::cout<< *s++;
        }

        throw std::logic_error("extra arguments provided to printf");
    }

    void run(){
        int *pi = new int;
        printf("%d %s %p %f\n", 15,"This is Ace.",pi,3.141592653);
    }
}


int main(){
    int *pi = new int;
    Tprintf("%d %s %p %f\n", 15,"This is Ace.",pi,3.141592653);
    test::run();

    return 0;
}

// 15 This is Ace. 0xc827b0 3.14159
/*
我必须写成Tprintf才行，不然void printf(const char* s)会报错ambiguous


15 This is Ace. 0x8127b0 3.14159
15 This is Ace. 0x8125a0 3.14159

测试发现不放在全局命名空间又可以
*/


// 2020年6月13日09:49:55 复习