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

namespace test1{
    void print()
    {
    }

    template<typename T,typename... Types>
    void print(const T& firstArg,const Types&... args)
    {
        cout<<"Now the first arg is: "<<firstArg<<"\t,and the follow counts is: "<<
            sizeof...(args)<<endl;
        print(args...);
    }

    void run(){
        print(7.5,"hello",bitset<16>(377),42);
    }
/*
Now the first arg is: 7.5       ,and the follow counts is: 3
Now the first arg is: hello     ,and the follow counts is: 2
Now the first arg is: 0000000101111001  ,and the follow counts is: 1
Now the first arg is: 42        ,and the follow counts is: 0
*/
}

namespace test2{
    // typedef int size_t;

    #include<functional>

    template<typename T>
    inline void hash_combine(size_t& seed,const T& val){
        seed^= std::hash<T>()(val) + 0x9e3779b9
            + (seed<<6) + (seed>>2);
    }

    template<typename T>
    inline void hash_val(size_t& seed,const T& val){
        hash_combine(seed,val);
    }

    template<typename T,typename... Types>
    inline void hash_val(size_t& seed,const T& val,const Types&... args){
        hash_combine(seed,val);
        hash_val(seed,args...);
    }

    template<typename... Types>
    inline size_t hash_val(const Types&... args){
        size_t seed = 0;
        hash_val(seed,args...);
        return seed;
    }

    void run(){
        // cout<< hash_val("linmin","shan",1) <<endl;
        // cout<< hash_val("linmin","shan",1L) <<endl;
        // error: invalid use of incomplete type 'struct std::hash<char [7]>'
         // seed^= std::hash<T>()(val) + 0x9e3779b9
        // 明明和老师一样的GCC4.9,但是不知道为啥不行

        cout<< hash_val(3,2,1L) <<endl;
    }
    // 11093822468169
}

int main(){
    test1::run();
    test2::run();

    return 0;
}

// 2020年6月13日09:18:15 复习