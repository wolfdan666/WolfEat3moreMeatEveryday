## 迭代器的分类iterator_category
5种
```cpp
struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag:public input_iterator_tag{};
struct bidirectional_iterator_tag:public forward_iterator_tag{};
struct random_access_iterator_tag:public bidirectional_iterator_tag{};
```

### 很多的typedef
有些时候，我们父类里面只有typedef，然后子类继承父类就等同于拥有了那些typedef...之后就没有什么了

### random_access_iterator_tag
只有连续空间才是random_access,这样才可以直接指针相减得到distance()