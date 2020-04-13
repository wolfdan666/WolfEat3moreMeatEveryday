placement_new容许我们将对象建构于我们已经分配好的空间上面，**所以其实placement_new没有分配内存**

![placement_new](placement_new.jpg)

根据源码可以知道，placement_new就是等同于构造函数