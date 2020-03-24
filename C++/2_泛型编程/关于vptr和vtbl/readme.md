# 对象模型:关于vptr和vtbl
一个虚函数和一百个虚函数都是一个虚函数指针

**继承是继承父类的调用权**

vptr(virtual pointer)指向虚表vtbl(virtual table)



```cpp
class A{
public:
    virtual void vfunc1();
    virtual void vfunc2();
    void func1();
    void func2();
private:
    int m_data1,m_data2;
};

class B: public A{
public:
    // 定义自己的vfunc1(),重载掉之前的
    virtual void vfunc1();
    void func2();
private:
    int m_data3;
};

class C: public B{
public:
    virtual void vfunc1();
    void func2();
private:
    int m_data1,m_data4;
};
```

## 静态绑定,动态绑定
静态绑定编译的时候就编译成为`call xxx`

遇到virtual的话就动态绑定

n是tbl中的第几个,序号根据创建的时候来确定的

![vptr_vtbl](https://cdn.jsdelivr.net/gh/wolfdan666/BlogPic/cpp/class/vptr_vtbl.jpg)


## 关于list一串不同的对象
由于list要存储相同大小的存储空间，所以直接用指针，
然后指针指向不同的对象

然后根据指针指向的对象直接调用虚函数draw(),根据不同的对象
执行不同的draw()

如果C要实现这种功能,就必须if(n==1) drawCircle()...
所以新增类型时很麻烦

我记得我之前写代码的时候也很讨厌以下这种给类似的函数
在函数名字上标序号,当时就简单的想法是想像调用数组一样
使用就好了,原来现在还有虚函数的方式实现

2020年3月24日22:22:05 自己又去研究了一下函数数组，发现
不能直接把函数赋值给函数类型,而且函数也不能返回函数
所以只能函数返回函数指针，但还是那种`case 1:return func1`
所以只能用数组装函数指针，但是还是不够fashion...改动代码还是多
所以OOP还是帅

```cpp
typedef double (*PF)(double *dbData, int iSize);

PF func[10] = {GetMax,GetMin,GetAverage,UnKnown};
```

```cpp
switch i:
    case 1:{
        func1();
        return;
    }
    case 2: {
        func2();
        return;
    }
    default:
        func3();
```

## 动态绑定条件
- 动态绑定必须是指针指向
- 必须是upcast，子类可以动态调用父类的函数
- virtual function

编译成下面这样子
```cpp
(*(p->vptr)[n])(p);
// or 上下是一样的
(* p->vptr[n] )(p);
```
