new和delete都是一个不能改的表达式

但是他们底层实现的对象可以被重载
operator delete

去创建自己的内存池，老师说暂时不讲

new delete 底层分别调用malloc和free


重载之后优先使用重载的，然后才是全局的
当然可以使用`::`来强制使用全局的


```cpp
class Foo
{
    // ...
}

/*
假设Foo大小为12

*/

Foo* pArray = new Foo[5];
// 这里的大小是12*5+4(存了一个4字节的counter)

```


## 重载new(),delete()
- 参数列是签名
- const也是签名
- 但是返回值不是签名.2020年3月26日15:17:37的昨天面试tx的时候说返回值也是...尴尬了

![new_delete_pair](https://cdn.jsdelivr.net/gh/wolfdan666/BlogPic/cpp/class/new_delete_pair.jpg)

## new分类
- 普通new`int* p = new int`
- array new`int* p = new int[]`
- place new`int* p = new(...) int`


![place_new](https://cdn.jsdelivr.net/gh/wolfdan666/BlogPic/cpp/class/place_new.jpg)


2020年6月6日09:40:48 复习(突然有点害怕等下面试官问内存管理方面，emm,没关系吧)

2022年12月06日14:15:54 复习