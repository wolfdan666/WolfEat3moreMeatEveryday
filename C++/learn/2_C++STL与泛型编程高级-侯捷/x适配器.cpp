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


// 这两个测试也可以是绑定文件的输入输出符号
namespace output{
    void test(){
        vector<int> myvector;
        for(int i=1;i<10;i++) myvector.push_back(i*10);

        ostream_iterator<int> out_it(cout,",");
        copy(myvector.begin(), myvector.end(), out_it);

        cout<< endl;
    }
// 10,20,30,40,50,60,70,80,90,
}

namespace input{
    void test(){
        double value1,value2;
        cout<< "Please,insert two values: ";
        // end-of-stream iterator___一个标兵符号
        istream_iterator<double> eos;
        istream_iterator<double> iit(cin);
        if(iit!=eos) value1=*iit;

        ++iit;
        if(iit!=eos) value2=*iit;

        cout<< value1 << "*" << value2 << "="
            << (value1*value2) << endl;
    }
// Please,insert two values: 3 4
// 3*4=12
    void test2(){
        int a[] = {1,2,4,5,6,9,10};
        int n = sizeof(a) / sizeof(int);
        vector<int> c(a,a+n);
        // for (vector<int>::iterator it = c.begin(); it != c.end(); ++it) cout << ' ' << *it;
        for(auto i:c) cout<< i << " "; cout << endl;
        // 1 2 4 5 6 9 10


        istream_iterator<int> iit(cin),eos;

        // 自己给自己绕晕了...这里卡了30分钟了,2020年4月2日16:36:34
        // inserter是从c的c.begin()开始插入,然后插入的来源是iit到eos
        // iit是输入,然后输入遇到eos就退出
        copy(iit,eos,inserter(c,c.begin()));

        cout<<"\n插入后size: " << c.size() << endl;
        for(auto i:c) cout<< i << " "; cout << endl;
// 1 2 4 5 6 9 10
// 520 521
// e

// 插入后size: 9
// 520 521 1 2 4 5 6 9 10
    }
}

int main(){
    int in;
    // int a = (cin>> in); 不行
    cin>> in;
    // cout<< "in是: " << in <<" cin返回值: " << a <<endl;
    cout<< "in是: " << in << endl;
    // output::test();
    // input::test();
    input::test2();

    return 0;
}