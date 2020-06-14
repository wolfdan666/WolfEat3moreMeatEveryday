## Rvalue_references_introduction
![Rvalue_references_introduction](Rvalue_references_introduction.jpg)

C++ with its user-defined types has introduced some subtleties regarding modifiability and assignability that cause this definition to be incorrect

C++及其用户定义类型引入了一些有关可修改性和可分配性的细微差别，这些细微差别导致该定义不正确


右值不可以放左边，临时对象就是一种右值
(2020年6月10日21:08:18 复习以前的之后，再复习这里，可以联系到 (i++)++;非法，而++++i合法__但其实是i++变成了右值，无法作为增量操作数_和这里的右值不能放左边有点像，而++i还是左值__底层实现的原因)

但是cpp作者推翻了这个准则

函数返回的东西是右值，你去取地址是不可以的...因此出现了右值引用

偷---move---浅拷贝
原来的东西不会再用

如果你本来不是右值，是左值，但你之后不去用原来的对象了，你可以`std::move(youself)`显式地声明调用偷的版本，浅拷贝的版本

不完美的传送就是传送过程中因为一些调用的参数传递，把原本的右值经过下一层传递调用成了下层的左值的版本的函(比如常量传达第一层函数后有了变量名，然后下一层函数中它就成了左值调用了)

所以完美传递的中间处理过程的话就会使用一些特殊操作保证完美的右值引用的传递，比如用move啥的

2020年6月10日21:26:26 复习