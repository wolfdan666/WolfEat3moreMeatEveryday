type_traits

pod == plain old data,一般指比较老的数据类型,没有func的那种,一般是c那边的数据

一个类只有在准备当父类的时候才会写virtual func,否则不会写.

当然你强行当做父类也可以,java中有拒绝这种操作的方法，cpp没有


remove_cv --- 移除const,volatile(易挥发的)
```cpp
template<typename _Tp>


```


`__is_enum`这些在标准库中找不到，老师说编译器知道，所以应该是编译器实现的


2020年6月10日20:31:34 复习