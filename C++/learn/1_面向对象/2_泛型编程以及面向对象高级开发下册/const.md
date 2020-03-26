## 谈谈const
### const member functions(常量成员函数)

```cpp
class complex
{
public:
    complex (double r = 0,double i = 0)
        : re (r) , im (i)
    { }
    complex& operator += (const complex&);
    // 讲的就是下面两个函数中的const
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*,const complex&);
}
```


这种函数保证了我函数不会改数据，这样传入const参数可以调用

不过函数是非const的，那么不能传入const参数
就是说---常量对象(相当于传入的参数)不能调用非常量函数


加不加const算作函数签名(决定了编译器是否ambiguous)的一部分


#### 从字符串的两个函数来谈
字符串底层是共享的数据，当发生改变的时候就COW(copy on write)
写时复制

常量字符串，一定不会被改变，则无需考率COW，这样效率高

![const](https://cdn.jsdelivr.net/gh/wolfdan666/BlogPic/cpp/class/const.jpg)

此种情况下额外的规则:
当成员函数的const和non-const版本同时存在，const object只会(只能)调用const版本，non-const object只会(只能)调用non-const版本