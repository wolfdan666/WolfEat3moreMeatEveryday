这么课程的副标题是: 从平地到万丈高楼，谁敢说自己的课程是万丈高楼呢？我敢

侯捷老师nb

在英文里，101就是包罗万象，什么都有


gnu-c中的allocator比较丰富,我们甚至可以去gnu-c抓一个allocator改装到vc这边来

## 演化过程总结
- 先是从最原始的new，delete，malloc，free的直接调用
- 然后再是重载operator_new,oprator_delete
- union借用内存版的重载
- 之后是封装到一个alloctor来调用
  - 因为写法比较固定，所以可以借助macro宏来写这个
- 然后最后G2.9的标准库用16个串起来的链表来管理所有的alloctor，而不是每个alloctor自己单独搞一条


## 内存管理gnu-c,vc,bc5
这个话题其实在之前标准库的课程中出现过，不过没有关系，再看一遍


## 问题遗留
### union借用头4个字节来做指针
老师说的那个union借用区块的前4个字节当做指针，但是我觉得当客户的数据活跃的时候，那么指针就失效了啊，所以非常不理解

### RoundUp(**>>4)
这个扩充量的申请还是不够理解啊---主要是这个它要用来解决什么问题我不懂


后面发现源码的骚操作写法---暂时不去深入
```cpp
// __ALIGN = 8
static size_t ROUND_UP(size_t bytes) {
  return (((bytes) + __ALIGN-1) & ~(__ALIGN - 1));
}
```

## cookie
因为cookie是内部内存(含2个cookie的8bytes)多少的计数，而且总体大小是16的倍数，所以后4位bit都是0，那么用用最后一位0或1表示内存是否还在手中，1表示内存已经分配出去了，0则表示内存还没有分配出去


## 为什么各个层次都自己实现
因为stl不能依赖c中的malloc，所以自己实现一套，以保证能跑起来

因为c中的malloc要保证跨操作系统，所以自己实现malloc，而不是直接用OS.API去实现(vc10直接用的OS.API因为只用在windows平台了)

## new的种类
new
operator new
array new
placement new---带小括号的new
```cpp
Rep *p = new(extra) Rep;
```
### operator new和placement new的区别
new 关键字
（1）调用operator new分配足够的空间，并调用相关对象的构造函数
（2）不可以被重载

operator new
（1）只分配所要求的空间，不调用相关对象的构造函数。当无法满足所要求分配的空间时，则
->如果有new_handler，则调用new_handler，否则
->如果没要求不抛出异常（以nothrow参数表达），则执行bad_alloc异常，否则
->返回0
（2）可以被重载
（3）重载时，返回类型必须声明为void*
（4）重载时，第一个参数类型必须为表达要求分配空间的大小（字节），类型为size_t
（5）重载时，可以带其它参数

placement new：
只是operator new重载的一个版本。它并不分配内存，只是返回指向已经分配好的某段内存的一个指针。因此不能删除它，但需要调用对象的析构函数。

如果你想在已经分配的内存中创建一个对象，使用new时行不通的。也就是说placement new允许你在一个已经分配好的内存中（栈或者堆中）构造一个新的对象。原型中void* p实际上就是指向一个已经分配好的内存缓冲区的的首地址。

以上: https://blog.csdn.net/f905699146/article/details/82663656

## 后面5讲好像都是来自于前面课程，up主有点粗心啊