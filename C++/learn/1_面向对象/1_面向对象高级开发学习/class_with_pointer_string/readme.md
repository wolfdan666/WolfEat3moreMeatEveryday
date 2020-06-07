## 声明
老师说标准库的string用到太多知识点，写得太复杂，所以这里是老师自己写的一个够用的版本

## 三个特殊函数
### 拷贝构造,拷贝赋值,析构函数
complex复数类可以直接使用编译器自动生成的拷贝构造函数

而带指针的String类如果用默认的(**浅拷贝**)，则只是拷贝指针，那么就有两个指针指向同一个数据块，还可能导致调用者原来的指针指向的地方内存泄露，这样就可能出问题，所以需要自己写深拷贝
![浅拷贝](https://img-blog.csdnimg.cn/20200319094320572.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25ldmVfZ2l2ZV91cF9kYW4=,size_16,color_FFFFFF,t_70)

```cpp
inline
String::String(const String& str)
{
    m_data = new char[ strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
}
```

![深拷贝](https://img-blog.csdnimg.cn/2020031909442637.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25ldmVfZ2l2ZV91cF9kYW4=,size_16,color_FFFFFF,t_70)

你含有指针的类，多半要自己操作析构函数，因为清理不会主动清理指向的地方

new 出来的要自己析构
s1,s2会自己在离开作用域的时候自己调用析构函数，但是new出来的就不会自动调用析构了，所以要自己写`delete p`
```cpp
{
    String s1();
    String s2("hello");

    String* p = new String("hello");
    delete p;
}
```


## 堆栈和内存管理
- block{}里的东西放在栈(stack)中,包括函数地址等等,new的东西放在堆(heap)中,heap相当于一个全局的变量,你自己可以用new来申请空间,但是你申请之后就得自己释放,否则会内存泄露
- 内存块cookie的最后一位为1表示系统把数据给出去,0表示数据收回,一般是两个饼干夹着一些数据块在一起
- 倒数第二位是看多少个16的倍数
- 每一块都是16的倍数，保证了地址最后4位都是0
- **array new一定要搭配array delete**,虽然comlex复数类最终会释放实体，所以complex类不用array delete虽然不会想含有指针类一样出错(内存泄露)，但是为了养成习惯，所以还是array new搭配array delete

![array_delete](https://img-blog.csdnimg.cn/20200319124352174.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25ldmVfZ2l2ZV91cF9kYW4=,size_16,color_FFFFFF,t_70)

## 复习一下传引用返回值
**只要不是local object就可以return by reference,因为local object在函数结束之后马上会释放，如果传这种对象的引用则会造成返回后的东西不知道是什么**

以及要用连续操作符的时候一般要设计成return by reference

```cpp
String& operator=(const String& str);
```


## 类知识的扩展补充
### static
static类数据只有一份，然后static类函数和普通函数的区别在于，static函数没有调用者的this指针，所以只能处理静态数据

写一行下来，使得一个变量获得内存，数据，则称这一步为**定义**
```cpp
class Account {
public:
    static double m_rate;
    static void set_rate(const double& x)
    { m_rate = x; }
};

// 静态的数据要在外头写这么一行,
// 至于要不要给初值都行
double Account::m_rate = 8.0;

int main() {
    Account::set_rate(5.0);

    Account a;
    // 对象也能调用，但是不会传this
    a.set_rate(7.0);
}
```

### 把ctors构造函数放在private
单例模式
```cpp
class A {
public:
    static A& getInstance();
    setup() { ... }
private:
    A();
    A(const A& rhs);
    ...
};

A& A::getInstance()
{
    static A a;
    return a;
}

int main(int argc, char const *argv[])
{
    A::getInstance().setup();
    return 0;
}
```

### cout
重载了超级多的`<<`

### 模板
```cpp
template<typename T>
class complex
{
public:
    complex (T r=0, T i=0)
        : re (r) ,im (i)
    { }

    complex& operator += (const complex&);
    T real () const { return re; }
    T imag () const { return im; }
private:
    T re, im;

    friend complex& __doapl (complex*,
                             const complex&);

};

{
    complex<double> c1(2.5,1.5);
    complex<int> c1(2,1);

}
```


### function template
类模板使用时要自己指定，而函数模板会自动参数推导，当然如果你有特殊的类，要自己重载比大小的符号


```cpp
template <class T>
inline
const T& min(const T& a, const T& b)
{
    return b < a ? b : a;
}

{
    stone r1(2,3), r2(2,3), r3;
    r3 = min(r1, r2);
}
```



2020年5月13日11:17:32 复习,2020年5月13日11:48:33 发现老师给的代码跑不起来，搞了半天也不会，算了先

2020年6月5日20:34:57 复习第二次