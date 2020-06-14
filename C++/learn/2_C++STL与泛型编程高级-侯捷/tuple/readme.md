```cpp
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

    cout<< sizeof(int) << endl;
    cout<< sizeof(string) << endl;
    cout<< sizeof(double) << endl;
    cout<< sizeof(complex<double>) << endl;

    // 老师说这里输出32是未解之谜，应该是28的
    //  但我觉得32是对的...
    tuple<string,int,int,complex<double>> t;
    cout<<"sizeof= " <<sizeof(t)<<endl;

    tuple<int,float,string> t1(41,6.3,"nico");
    cout<< "tuple<int,float,string> size: "<< sizeof(t1)<<endl;


    return 0;
}
```

## tuple实现
元之组合，数之组合
```cpp
// 要先声明自己
template<typename... Values>class tuple;
template<>class tuple<> { };

// 自己继承自己
template<typename Head,typename... Tail>
class tuple<Head,Tail...>
 :private tuple<Tail...>
 {
    typedef tuple<Tail...> inherited;
 public:
    tuple() { }
    tuple(Head v,Tail... vtail)
     :m_head(v),inherited(vtail...){ }

    typename Head::type head(){ return m_head; }
    inherited& tail(){ return *this; }
 protected:
    Head m_head;
 };

```


2020年6月10日20:29:07 复习