#### 转换函数
转换函数没有返回类型,因为一般认为你operator之后就已经写了，防止你自己返回类型和operator之后的东西写错成不同的

```cpp
#include<bits/stdc++.h>
using namespace std;

class Fraction
{
public:
    Fraction(int num, int den=1)
     : m_numerator(num), m_denominator(den) { }
    // 这里的const是大家风范，尽量const
    // 因为有些函数外面是const.你里面没const会报错
    operator double() const {
        return (double)m_numerator / m_denominator;
    }


private:
    // 下面的注释和代码写在一起其实也没有关系，因为共生
    int m_numerator; // 分子
    int m_denominator; // 分母
}

int main(){
    Fraction f(3,5);
    // 先找是否有重载 + (int,Fraction)
    // 然后再找是否能先把f转化成double,然后就能找到
    double d = 4 + f;

    cout<< d << endl;

    return 0;
}
```


##### non-explicit-one-argument ctor

```cpp
#include<bits/stdc++.h>
using namespace std;

class Fraction
{
public:
    //non-explicit-one-argument ctor
    // one-argument 只要一个实参就够了
    // non-explicit
    // 看main()中的加double()转化函数,加explicit后会发生什么
    Fraction(int num, int den=1)
     : m_numerator(num), m_denominator(den) { }

    Fraction operator+(const Fraction& f) {
        return Fraction(......);
    }


private:
    // 下面的注释和代码写在一起其实也没有关系，因为共生
    int m_numerator; // 分子
    int m_denominator; // 分母
};

int main(){
    Fraction f(3,5);
    /* 下面调用 non-explictit ctor将4转化成Fraction(4,1)
        然后调用operator+
    */

    /*
    如果上面加上了以下函数
    operator double() const {
        return (double)m_numerator / m_denominator;
    }
    则会导致ambiguous...
    因为可以先4转化成Fraction,也可以先f转double
    所以给构造函数加explict(直率的,精确的),这样就让单个
    的double无法转化到Fraction了,于是下面就会报错无法从
    double转化到Fraction

    这个关键字基本(90%)上用在构造函数,其他只在模板一个很小
    的一个地方用到
    */
    Fraction d = f + 4;

    return 0;
}
```

#### pointer-like classes
##### pointer-like classes,关于智能指针
设计类像一个指针，像一个指针，因为我们想让它比指针更多
做一些事情

```cpp
template<class T>
class shared_ptr
{
public:
    T& operator*() const
    { return *px; }

    T* operator->() const
    { return px; }

    shared_ptr(T* p) : px(p) { }
private:
    T*      px;
    long*   pn;
// ...
};

struct Foo
{
    // ...
    void method(void){};
};

{
    shared_ptr<Foo> sp(new Foo);

    Foo f(*sp);

    // 以下的->被重载.然后转化成px
    // 但其实->被消耗掉还可以继续作用下去
    // 这里是编译器搞得,而上面的*sp,*就是真的消耗掉了
    sp->method();
}
```

##### pointer-like classes,关于迭代器
容器一般都有迭代器,也像指针,但是不仅处理`*`和`->`,
还处理++,--

#### function-like classes
##### 所谓仿函数
接收`()`

重载了(),operator(),然后继承了很多奇特的base classes


#### Template
##### 类模板
要指明类型,比如
```cpp
complex<double> c1;
```

##### 函数模板
使用时不用指明类型，编译器自动判断，
不过对于无法比较的类型，你要重载比较符号这种操作符
```cpp
template <class T>
inline
const T& min(const T& a,const T& b)
{
    return b < a ? b : a;
}

{
    // 定义r1,r2,r3
    r3 = min(r1, r2);
}
```

##### 成员模板
一个模板类里面有另一种模板，就叫做成员模板

```cpp
class Base1 { };
class Derived1:public Base1 { };

class Base2 { };
class Derived2:public Base2 { };

pair<Derived1,Derived2> p;
pair<Base1,Base2> p2(p);

// 上面转化成pair<Base1,Base2> p2(pair<Derived1,Derived2>());


template<class T1,class T2>
struct pair{
// ...
    T1 first;
    T2 second;
    pair() : first(T1()),second(T2()) {}
    pair(const T1& a,const T2& b) :
        first(a),second(b) {}

    // U1应该是T1的子类,U2应该是T2的子类
    // 因为子类可以调用父类的拷贝构造函数
    // 反过来不行,C++ 中，父类是没法调用到子类的成员函数的。当然，静态函数可以被父类调用到；这里只说普通函数。所以不能，是因为父类的定义中，还没有见到子类的定义，所以没法引用到子类的成员函数。
    template<class U1,class U2>
    pair(const pair<U1,U2>& p) :
        first(p.first),second(p.second) {}
};
```

![menber template](https://img-blog.csdnimg.cn/20200321180707232.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25ldmVfZ2l2ZV91cF9kYW4=,size_16,color_FFFFFF,t_70)


```cpp
template<typename _Tp>
class shared_ptr:public __shared_ptr<_Tp>
{
    // ...
    template<typename _Tp1>
    explictit shared_ptr(_Tp1* __p)
        : __shared_ptr<_Tp>(__p){ }
    // ...
};

{
    Base1* ptr = new Derived1; // up-cast

    // 模拟up-cast
    shared_ptr<Base1> shared_ptr(new Derived1);
}
```


![模拟up-cast的智能指针也是成员模板 ](https://img-blog.csdnimg.cn/20200321181157823.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25ldmVfZ2l2ZV91cF9kYW4=,size_16,color_FFFFFF,t_70)

#### 模板特化,specialization
##### 全特化
```cpp
// 这里是泛化
template <class Key>
struct hash { };

// 下面是各种特化
// template<>   ===  __STL_TEMPLATE_NULL
template<>
struct hash<char> {
    size_t operator() (char x) const { return x; }
};

template<>
struct hash<int> {
    size_t operator() (int x) const { return x; }
};

template<>
struct hash<long> {
    size_t operator() (long x) const { return x; }
};

{
    cout << hash<long>() (1000);
}
```

##### 偏特化,partial specialization
###### 个数的偏
可以先只绑定左边的若干个,必须从左到右,不能跳跃

```cpp
// `<>`里面是模板的参数
template<typename T,typename Alloc=......>
class vector
{
    // ...
};

template<typename Alloc=......>
class vector<bool, Alloc>
{
    // ...
}

```

###### 范围的偏
原来是所有的类型，然后你特化一下指针类型的的特化

```cpp
template<typename T>
class C
{
    // ...
};

// 这里把T写成U也是一样的
template<typename T>
class C<T*>
{
    // ...
};

{
    // 没有特化string类型，所以直接使用默认的第一种模板
    C<string> obj1;

    // 由于特化了指针类型，所以使用第二种模板
    C<string*> obj2;
}
```

#### template template parameter,模板模板参数


```cpp
// 其中模板参数`< >`中的typename也可以写成class
// 这是由于之前没有typename这个关键字的历史因素导致的
// 但是class也只有在这里可以替换等效于typename
// Container前的class和XCls前的class就不能共通替换了
template<typename T,
         template <typename T>
             class Container
        >
class XCls
{
private:
    Container<T> c;
public:
    // ...
};

// 下面两个是C++11(C++2.0)的特性，老师暂时不讲
template<typename T>
using Lst = list<T, allocator<T>>;

{
    // 前面的模板模板参数写对了,这里运行不起来
    // 是因为容器一般有多个参数,虽然平时我们可以用
    // 一个参数,其他做缺省值,但是其实不行,要加上
    // 前面两行用第二种写法,老师没有讲了
    XCls<string, list> mylst1; // X,错的
    XCls<string, Lst> mylst2;
}
```


```cpp
template<typename T,
         template <typename T>
             class SmartPtr
        >
class XCls
{
private:
    SmartPtr<T> sp;
public:
    XCls() : sp(new T) { }
    // ...
};

// 上面是没问题的，下面有两个不能用是因为他们指针自己
// 的独特特性决定的
XCls<string, shared_ptr> p1;
XCls<double, unique_ptr> p2; // x
XCls<int, weak_ptr> p1; // x
XCls<long, auto_ptr> p1;
```

##### 非template template parameter
模板是没有写死的，是可以模糊匹配的，而写死了，就不是
模板了

```cpp
template <class T, class Sequence = deque<T>>
class stack {
    // ..
protected:
    Sequence c; // 底层容器
}

stack<int> s1; // 这里可以说是模板
stack<int,list<int>> s2; // 这里写死了,已经不是一个模板了
```


#### 老师谈标准库
老师说一个年轻的学编程的人一定要认真地把标准库里的东西都自己去尝试使用一下，这是一个很愉悦的事情，因为大神已经帮你写好了，然后不要眼高手低，一定要自己去尝试，手写，不要只是看网上总结的东西而不去实践


![很早前就认为算法和数据结构就是编程](https://img-blog.csdnimg.cn/20200321194357728.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25ldmVfZ2l2ZV91cF9kYW4=,size_16,color_FFFFFF,t_70)

2020年6月6日09:55:39 复习

2022年12月07日15:08:20 复习