new不能重载

但是new的底层代码调用operator new是可以重载的

std::nothrow在cpp2.0直接写成noexcept

new源码中的指针会直接调用构造函数，这只能编译器做，如果要自己写，必须写成另一种版本
```cpp
// placement new ，在顶点方向创造new对象
// new(指针)函数名(函数参数)
new(p)Construct;
```

## Array new && Array delete
这里由于delete是10个int，int没有所谓的析构函数，所以调用一次和调用10次没有什么区别，当然还是养成习惯比较好，不过原理上还是要知道
```cpp
int *pi = new int[10];
delete pi;
// delete[] pi;
```

但是如果对于string类型，有指针的class，那么你每次析构都会释放一块指针指向的大块内存，如果你只delete了一次(那上面说法想到于这10个指针以及第一个指针指向的区块被释放)，那么剩下的9个指针指向的东西就没有被释放


其实上面的理解不完全正确...看了老师的下面这幅图才变得更加清晰了，就是说如果每一个数据块里面不是一个小块，而是多个块，那么内存的存放方式就会不同，上面会对出一个对象个数的count，这样就不会简单地调用之前的函数了

![array_delete](array_delete.jpg)