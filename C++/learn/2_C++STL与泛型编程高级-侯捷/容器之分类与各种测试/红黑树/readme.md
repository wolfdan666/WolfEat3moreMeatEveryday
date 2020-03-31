## 容器rb_tree
Red-Black tree是平衡二元搜索树中常被用到的一种

re_tree提供遍历操作以及iterator.
按正常的规则(++ite)遍历，便能获得排序状态(sorted)

我们**不应该**使用rb_tree的iterator改变元素值,因为这些值还是要用在红黑树的排序规则的。编程层面**并非阻止这样的事情**，如此设计是正确的，因为rb_tree即将成为set和map的服务(作为底层支持),而map容许元素的data的改变，只有元素key不能改变，因为是根据key来排序生成红黑树的

rb_tree提供两种的insertion，一种是针对的是key独一无二的红黑树insert_unique(),如果插入相同key的话会导致失败，另一种容许相同的key就是insert_equal()


对于大小为0的class，编译器创造出来的对象的大小是1byte，比如传入的class是函数or仿函数的话，那么它创建的对象大小编译时大小为1byte，当然最后还是要字节对齐

![rb_tree_size1](https://cdn.jsdelivr.net/gh/wolfdan666/BlogPic/cpp/stl_source/rb_tree_size1.jpg)

```cpp
// 这里的value是指map中的(key和data)，或者是set中的data__这里为了理解直接类比应用了
// 所以当Key和Value都是int的时候，那么就是set那类的红黑树

// 这里是C++标准库
template <class Key,
          class Value,
          class KeyOfValue,
          class Compare,
          class Alloc>
class rb_tree{
    // ...
};

rb_tree<int,
        int,
        identity<int>,
        less<int>,
        alloc>
myTree;

// 这里的identity<int>是KeyOfValue的实际参数，就是要证明我的Value里面的key是哪个，也就是说用哪个来排序

// identity是gnu-c独有的，不是标准库的一部分
template<class T>
struct identity : public unary_function<T, T>{
    // 重载`()`的仿函数
    const T& operator()(const T& x) const { return x; }
}
```
![rb_tree_use1](https://cdn.jsdelivr.net/gh/wolfdan666/BlogPic/cpp/stl_source/rb_tree_use1.jpg)

![rb_tree_use2](https://cdn.jsdelivr.net/gh/wolfdan666/BlogPic/cpp/stl_source/rb_tree_use2.jpg)

![rb_tree_use3](https://cdn.jsdelivr.net/gh/wolfdan666/BlogPic/cpp/stl_source/rb_tree_use3.jpg)

# 关于G2.9版和G4.9版
老师好G2.9好追踪溯源，好理解，而G4.9版十分不友好，但其实还是有它的设计理念的，就是handle和body，主体中用一个指针指向body

但是还是不能用public继承allocator，违背了is a的public继承意思