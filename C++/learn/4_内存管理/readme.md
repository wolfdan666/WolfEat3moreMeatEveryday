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