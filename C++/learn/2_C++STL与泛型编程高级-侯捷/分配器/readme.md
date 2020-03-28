# 分配器
## 声明
老师讲的都是gnu c++的分配器
windows的c++不一定有这些分配器

## 使用
如果自己使用分配器的话，就得要记住自己申请时的分配器的大小，这样子很不方便

不如使用new，delete，或他们的底层实现malloc和free，他们释放的时候都无需记住大小


## 先谈operator new() 和 malloc()
分配器allocators可能使用new()最终malloc()来申请内存

每一块申请内存的前后被一些东西包住

如果申请的内存小，那么占比小，辅助空间占比大
如果申请的内存大，那么占比大，辅助空间才能相对小


### VC6的默认分配器
VC6的默认分配器是简单调用new()和delete()，没有任何特殊的设计

**所以每一个小块都是一个小类型，那么辅助空间将是申请空间的几倍，这样就太浪费内存了**

`alloctor<int>()`临时对象没有名称

使用如下
```cpp
// 分配 512 ints
int* p = alloctor<int>().allocate(512,(int *)0);
alloctor<int>().deallocate(p,512);
```

### BC5
BC5和VC6设计完全一样，也是简单调用new()和delete()

使用如下
```cpp
// 分配 512 ints
// 比VC6好一点点是allocate的第二个参数缺省为0
int* p = alloctor<int>().allocate(512);
alloctor<int>().deallocate(p,512);
```

### G2.9
gnu-c,GCC2.9也是简单调用new()和delete()

不过G++ <defalloc.h>中注释说: 请不要使用这个头文件，我们有另外的allocator函数，这个头文件没有包含在任何的文件中

### G2.9 STL对allocator的使用__alloc
不是使用上面的那个allocator分配器，而是使用alloc分配器

这个的源码很有价值，要在内存分析的那一门课程中去讲解

alloc实现在<stl_alloc.h>

主要是因为容器中的元素大小都是一样的，所以我们可以共享一些记录值是相同的东西，这样就可以减少内存的浪费，比如辅助空间中的元素大小


16条链表，第0条负责每一个区块是8字节的

所有的容器，要内存，就来这里取内存，容器的每一块都调整成为8字节的整数倍

cookie上下填充头，两个加起来就8字节了...

如果变成16条链表，就使用很少的cookie了

### G4.9
G4.9又回到了简单调用new(),delete(),不过__pool_alloc就是之前G2.9中的alloc
要这样用
```cpp
vector<string,__gnu_cxx::__pool_alloc<string>> vec;
```

老师说他也不知道为啥不让标准设置成原来的好东西，他说源码中也没有说这件事