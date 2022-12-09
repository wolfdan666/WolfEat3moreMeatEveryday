## 简介

map/multimap也是以rb_tree为底层结构，因此有自动排序特性(key)

可以遍历以及使用iterator


我们**无法**使用iterator来改变元素的key值(排序规则的依据)，但是我们可以用它来改变元素的data。因此map/multimap内部自动将user指定的key type设置为const，这样就能禁止用户对元素的key的赋值


map元素的key必须独一无二，因此其insert()用的是rb_tree的insert_unique()

multimap的元素的key可以重复，因此其insert()用的是rb_tree的insert_equal()

```cpp
template <class Key,
          class T,
          class Compare = less<Key>,
          class Alloc=alloc>
class map {
public:
    typedef Key key_type;
    typedef T data_type;
    typedef T mapped_type;
    // 这里放了const Key
    typedef pair<const Key, T> value_type;
    typedef Compare key_compare;
private:
    typedef rb_tree<key_type, value_type,
                    select1st<value_type>,key_compare,Alloc> rep_type;
    rep_type t;
public:
    typedef typename rep_type::iterator iterator;
    // ...
};

{
    map<int,string> imap;
}
```

## 容器map,独特的operator[]
看了源码的实现，**发现核心是lower_bound(targetKey),这样就是大于等于，如果是等于，那么就是返回最左边的那个**，这样就导致了multiset不能用这个`[]`操作符，因为如果是相同的key的话，那么就会导致总是对同一个操作，所以这个`[]`符号只能用在key是独一无二的map上面

先`lower_bound()`然后再看是否能够找到，找不到insert一个key再赋值data，找到直接返回key更新data，当然在集中赋key不同的值的时候，直接insert()的效率更高，不过`[]` 看起来很直观

2020年6月9日21:54:50 复习
2022年12月08日10:34:45 复习