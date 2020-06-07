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

class base{
public:
    virtual void vir_func(){ cout<<"I'm virtual func,this is class base."<<endl; }
    void func(){ cout<<"I'm normal function,this is class base."<<endl; }
};

class A:public base{
public:
    virtual void vir_func(){ cout<<"I'm virtual func,this is class A."<<endl; }
    void func(){ cout<<"I'm normal function,this is class A."<<endl; }
};

class B:public base{
public:
    virtual void vir_func(){ cout<<"I'm virtual func,this is class B."<<endl; }
    void func(){ cout<<"I'm normal function,this is class B."<<endl; }
};

int main(){
    base * Base = new(base); base * a = new(A); base * b = new(B);

    Base->func();a->func();b->func();
    cout<<"---------------------------------------"<<endl;

    Base->vir_func();a->vir_func();b->vir_func();
    cout<<"---------------------------------------"<<endl;

    ((A *)b)->vir_func(); ((A*)b)->func();

    return 0;
}

/*
output:
I'm normal function,this is class base.
I'm normal function,this is class base.
I'm normal function,this is class base.
---------------------------------------
I'm virtual func,this is class base.
I'm virtual func,this is class A.
I'm virtual func,this is class B.
---------------------------------------
I'm virtual func,this is class B.
I'm normal function,this is class A.

总结:
1. 当使用类的指针调用成员函数时，普通函数由指针类型决定，而虚函数由`指针`或者`引用调用虚函数`指向的实际类型决定
2. 通过对象内存中的虚函数表指针vptr找到类中共有的虚函数表vtbl的偏移量，接着通过vtbl的偏移量找到对应虚函数的实现区域并进行调用
3.
>构造函数和析构函数可以是虚函数吗？答案是构造函数不能是虚函数，析构函数可以是虚函数且推荐最好设置为虚函数。
下面我们来看看为什么。
首先，我们已经知道虚函数的实现则是通过对象内存中的vptr来实现的。
而构造函数是用来实例化一个对象的，通俗来讲就是为对象内存中的值做初始化操作。
那么在构造函数完成之前，vptr是没有值的，也就无法通过vptr找到作为虚函数的构造函数所在的代码区，所以构造函数只能作为普通函数存放在类所指定的代码区中。
那么为什么析构函数推荐最好设置为虚函数呢？如文章开头的例子中，当我们delete(a)的时候，如果析构函数不是虚函数，那么调用的将会是基类base的析构函数。
而当继承的时候，通常派生类会在基类的基础上定义自己的成员，此时我们当时是希望可以调用派生类的析构函数对新定义的成员也进行析构啦。

参考:
https://zhuanlan.zhihu.com/p/28530472?utm_source=qq&utm_medium=social&utm_oi=894242743738593280

2020年6月6日09:57:40 复习
*/