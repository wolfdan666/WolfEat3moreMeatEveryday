## 结构
结构是vector+list/forwardList

vc 是 list
gnu-c 是 forwardList

元素个数如果多于了篮子个数，那么篮子就要翻倍(cpp中专门有一个质数翻倍表)，rehashing---重新用数据的hashCode(越乱越好)来mod篮子数 计算落在哪个篮子里面

## C++11又一次学习hashcode
之前在stl标准库学习中学过了一次

然后发现up主把之前stl中讲过的万用hashfunc那两讲没有上传


2020年6月10日21:03:37 复习
补充就是之所以用质数，是因为用合数的话，容易造成hash碰撞，因为有数学证明，可以发现合数会导致某些bit位的取模作用等于没有，所以从而导致更容易hash碰撞，所以一般用质数