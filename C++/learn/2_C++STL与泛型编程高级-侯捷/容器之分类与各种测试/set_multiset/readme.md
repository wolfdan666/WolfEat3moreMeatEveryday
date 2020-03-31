set/multiset以rb_tree为底层容器，有自动排序特性(key)

可以遍历以及使用iterator

我们**无法**使用iterator来改变元素值，使用const_iterator

set元素的key必须独一无二，因此其insert()用的是rb_tree的insert_unique()

multiset的元素的key可以重复，因此其insert()用的是rb_tree的insert_equal()


