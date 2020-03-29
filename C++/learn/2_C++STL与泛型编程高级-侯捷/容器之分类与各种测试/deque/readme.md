一个
`vector<array<T>* p>`
用一个begin，一个end以及一个cur的结构体来操作

这个结构体包含了所指向的buffer块(array)的头，尾的指向指针，当前指向的指向指针，和回到vector母体位置的指针

这里的vector,每次前面或者后面不够了就会自动扩展到2倍，并且把老的数据移动到新的vector的**中间**来


stack和queue默认使用deque作为底层容器

虽然也可以用list，但肯定是deque性能更好



stack还可以用vector实现，但是queue不能，因为vector是不能从头删除

当然你没有调用`queue<int,vector<int>>::pop()`,则不会报错，等调用时报错

