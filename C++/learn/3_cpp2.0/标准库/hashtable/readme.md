## 结构
结构是vector+list/forwardList

vc 是 list
gnu-c 是 forwardList

元素个数如果多于了篮子个数，那么篮子就要翻倍(cpp中专门有一个质数翻倍表)，rehashing---重新用数据的hashCode(越乱越好)来mod篮子数 计算落在哪个篮子里面

## C++11又一次学习hashcode
之前在stl标准库学习中学过了一次

然后发现up主把之前stl中讲过的万用hashfunc那两讲没有上传