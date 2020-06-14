## 小点
### noexcept
noexcept要常常放在数据类型类中的move construct后面，并且保证函数不会异常，这样你的数据类才能用于vector,别人也会用得安心放心

```cpp
class MyString {
private:
    char* _data;
    size_t _len;
//...
public:
    // move constructor
    MyString(MyString&& str) noexcept
        :_data(str._data),_len(str._len) {...}

    // move assignment
    MyString& operator=(MyString&& str) noexcept
    {... return *this; }
}
```

### override
你标明你要override，则会在你不小心写错了参数表的时候(变成了重写函数了)就会通过报错提醒你

### final
使用final，就不准下面的冬季再继承了
```cpp
struct Base1 final;

struct Derived: Base1{};
// [Error]cannot derive from 'final' base 'Base1' in derived type 'Derived1'

struct Base2 {
    virtual void f() final;
};

struct Derived2 : Base2{
    void f();
    // [Error] override final function 'virtual void Base2::f()'
}
```



### decltype
typeof在gnu-cpp中有，但是不成熟，而且不是标准库，所以在标准库实现了一个decltype

defines a type equivalent to the type of an expression

```cpp
map<string,float> coll;
decltype(coll)::value_type elem;

// 上面等价于
map<string,float>::value_type elem;
```

#### used to declare return types
Sometimes,the return type of a function depends on an expression processed with arguments.

Howerer,something like
```cpp
template<typename T1,typename T2>
decltype(x+y) add(T1 x,T2 y);
// 这里x,y 出现得太早了,decltype还不认识，所以有下面的写法
```
was not possible before C++11,bacause the return expression uses objects not introduced or in scope(范围) yet;

But with C++11,you can alternatively declare the return type of a function behind the parameter list:
```cpp
template<typename T1,typename T2>
auto add(T1 x,T2 y) -> decltype(x+y);
// 这里的auto是暂定的意思
```

This uses the same syntax as for lambdas to declare return types.

$[...](...)$$mutable_{opt}$ $throwSpec_{opt}$ -> $retType_{opt}${...}


#### use in metaprogramming
用在元编程，老师说别想得太严肃，其实就是用在模板编程上面

看下面的例子，其中只要加上了`::`就要在前面加typename告诉编译器我们这里是个typename，不然编译器会犹豫，因为编译这一块的时候，obj是什么是不得而知的
```cpp
// 这里应该把 T命名成为Container，起到提醒作用
template<typename T>
void test18_decltype(T obj){
    map<string,float>::value_type elem1;

    map<string,float> coll;
    decltype(coll)::value_type elem2;

    // 这里设计成为 模板函数 , 接收任意类型obj

    /* 只要加上了`::`就要在前面加typename告诉编译器我们这里是个typename，不然编译器会犹豫，因为编译这一块的时候，obj是什么是不得而知的 */
    typedef typename decltype(obj)::iterator iType;
    // 上面等价于下面这种
    typedef typename T::iterator iType;
    // 当然如果使用的obj没有iterator就会报错

    decltype(obj) anotherObj(obj);
}

#### decltype,used to pass the type of a lambda
```cpp
auto cmp = [](const Person& p1,const Person& p2){
    return p1.lastname() < p2.lastname() ||
        ( p1.lastname() == p2.lastname() &&
          p1.firstname() < p2.firstname() );
}

// ...

// coll也要传cmp,很关键，详见lambda那一部分
std::set<Person,decltype(cmp)> coll(cmp);
```


2020年6月13日10:24:59 复习