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

namespace test{
    template<typename... Values> class tuple;
    template<> class tuple<> { };

    template<typename Head,typename... Tail>
    class tuple<Head,Tail...>
    {
        typedef tuple<Tail...> composited;
    protected:
        composited m_tail;
        Head m_head;
    public:
        tuple() { }
        tuple(Head v,Tail... vtail)
         : m_tail(vtail...),m_head(v){ }

        Head head() { return m_head; }
        composited& tail() { return m_tail; }
    };

    void run(){
        tuple<int,float,string> t(41,6.3,"linmin");
        cout<< sizeof(t) <<endl;
        cout<< sizeof(int) <<endl;
        cout<< sizeof(float) <<endl;
        cout<< sizeof(string("linmin")) <<endl;

        cout<< t.head() << endl;
        cout<< t.tail().head() << endl;
        cout<< t.tail().tail().head() << endl;

        tuple<string,complex<int>,bitset<16>,double>
            it2("Ace",complex<int>(3,8),bitset<16>(377),3.141592453);
        cout<< sizeof(it2) <<endl;
        cout<< sizeof(string("Ace")) <<endl;
        cout<< sizeof(complex<int>(3,8)) <<endl;
        cout<< sizeof(bitset<16>(377)) <<endl;
        cout<< sizeof(double) <<endl;
        cout<< it2.head() <<endl;
        cout<< it2.tail().head() << endl;
        cout<< it2.tail().tail().head() << endl;
        cout<< it2.tail().tail().tail().head() << endl;
    }
    /*
这个size我无法理解,老师的输出第一个竟然是16,第二个也是40

卡了一个多小时...2020年4月10日17:34:09 去查资料
2020年4月10日18:02:03 按照run2的分析之后就能懂得了为什么
这里是32，首先是这里一开始填4bytes，但是根据后面展开的结构体最宽的对齐
所以填完第一个的偏移量是8，之后填入4又同样的原因第二个后偏移到16
之后8和最后展开的一个空的一起都各自为8，所以是32

之后的40同理解释
32
4
4
8
41
6.3
linmin
40
8
8
4
8
Ace
(3,8)
0000000101111001
3.14159
    */

/*
对于嵌套的结构体，需要将其展开。对结构体求sizeof时，上述两种原则变为：
       （1）展开后的结构体的第一个成员的偏移量应当是被展开的结构体中最大的成员的整数倍。

       （2）结构体大小必须是所有成员大小的整数倍，这里所有成员计算的是展开后的成员，而不是将嵌套的结构体当做一个整体。

例子1：

struct stru5  
{  
      short i;  
      struct   
      {  
           char c;  
           int j;  
      } tt;   
      int k;  
};

结构体stru5的成员tt.c的偏移量应该是4，而不是2。整个结构体大小应该是16。
————————————————
版权声明：本文为CSDN博主「海月汐辰」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_37858386/article/details/75909852

*/

    void run2(){
        struct stru1
        {
            short i;
            struct
            {
                char c;
                int j;
            } tt;
            int kl;
        };
        struct stru2
        {
            short i;
            struct
            {
                char c;
                int j;
                struct{
                    // 估计多加4，事实确实
                } tt2;
            } tt;
            int kl;
        };
        struct stru3
        {
            string a;
            struct
            {
                // 估计加8
            } sT;
        };
        cout<< sizeof(stru1) <<endl;
        cout<< sizeof(stru2) <<endl;
        cout<< sizeof(stru3) <<endl;
        // 16
        // 20
        // 16
    }
}


int main(){
    test::run();
    test::run2();

    return 0;
}
