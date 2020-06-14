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

// 递归继承 === 之前学侯捷老师的stl的时候学过这个
namespace test{
    template<typename... Values> class tuple;
    template<> class tuple<> { };

    template<typename Head,typename... Tail>
    class tuple<Head,Tail...>
     : private tuple<Tail...>
    {
        typedef tuple<Tail...> inherited;
    // protected:
    //     Head m_head;
    public:
        tuple() { }
        tuple(Head v,Tail... vtail)
         : m_head(v),inherited(vtail...){ }

        // typename Head::type head() { return m_head; }
        // 上面Head类型不一定有type的定义,比如int or float
        // 简单版
        Head head() { return m_head; }
        // 检测版,要把m_head声明在这个函数前
        // 利用auto和 -> decltype() 把返回类型写在后面推断出来
        // auto head()->decltype(m_head){return m_head;}

        /*
        老师说*this指向最后一个tail的位置.假设有3个数据,return
         *this就可以获得那三个数据,转型成父类就缩小范围到两个
        */
        inherited& tail() { return *this; }
    protected:
        Head m_head;
    };

    void run(){
        tuple<int,float,string> t(41,6.3,"linmin");
        cout<< sizeof(t) <<endl;

        cout<< t.head() << endl;
        cout<< t.tail().head() << endl;
        cout<< t.tail().tail().head() << endl;
    }
    /*
16
41
6.3
linmin
    */
}


int main(){
    test::run();

    return 0;
}

// 2020年6月13日10:16:47 复习