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
}

```

## 静态绑定,动态绑定
静态绑定编译的时候就编译成为`call xxx`

遇到virtual的话就动态绑定

n是tbl中的第几个