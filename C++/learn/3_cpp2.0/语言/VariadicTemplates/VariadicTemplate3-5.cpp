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

namespace test3{
    // 使用stl库里面的函数
    void run(){
        cout<< max({57,48,60,100,20,18}) <<endl;
    }
    // 100
}

namespace test4{
    int maximum(int n){ return n; }

    template<typename... Args>
    int maximum(int n,Args... args){
        return std::max(n,maximum(args...));
    }

    void run(){
        // cout<< max({57,48,60,100,20,18}) <<endl;
        // 2022年12月08日15:18:06 FIXED: 这里不明白为啥用max..然后用maximum又不会传参了...
        // chatGPT问`int maximum(int n,Args... args) 如何传参` 得知的答案，666，去掉括号就好
        cout<< maximum(57,48,60,100,20,18) <<endl;
    }
    // 100
}

namespace test5{
/*
这个测试样例要注意调用的输出函数放最下面(run前面的一个)
然后partial specialization 要放在 全特化 后面，否则会报错 重定义！
*/

    // boost: util/printtuple.hpp
    // helper: print element whit index IDX of tuple
    //         with MAX elements
    template<int IDX,int MAX,typename... Args>
    struct PRINT_TUPLE {
        static void print(ostream& os,const tuple<Args...>& t){
            os << get<IDX>(t) << (IDX+1 == MAX ? "":",");
            PRINT_TUPLE<IDX+1,MAX,Args...>::print(os,t);
        }
    };

    // partial specialization to end the recursion
    template <int MAX,typename... Args>
    struct PRINT_TUPLE<MAX,MAX,Args...> {
        static void print(std::ostream& os,const tuple<Args...>& t){
        }
    };

    // output operator for tuples
    template<typename... Args>
    ostream& operator<<(ostream& os,const tuple<Args...>& t){
        os<<"[";
            PRINT_TUPLE<0,sizeof...(Args),Args...>::print(os,t);
        return os<<"]";
    }

    void run(){
        cout<< make_tuple(7.5,string("hello"),bitset<16>(377),42);
        // provided there is a overloaded operator << for bitset
    }
    // [7.5,hello,0000000101111001,42]
}


int main(){
    test3::run();
    test4::run();
    test5::run();

    return 0;
}


// 2020年6月13日10:14:25 复习