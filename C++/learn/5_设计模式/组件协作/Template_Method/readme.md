## 动机
自己的稳定结构，有些部分要去晚绑定---后期使用


## 操作要点
- 基类写成虚函数，让子类能自己动态调用自己的析构函数


## 重点概念
### 早晚绑定
晚定义的东西调用早定义的东西叫做早绑定

早定义的东西调用晚定义的东西叫做**晚绑定**(一般是通过动态绑定调用，base指针指向子类对象)

### 模式定义
定义一个操作中的算法的框架(**稳定**)，然后使用Template Method使得子类重定义(Override 重写)一些特定步骤

缺点: 若框架不稳定，要经常改变，那么这个模式不可用
优点: 只要变化需要变化的

对于写Application程序员的缺点:只写一些步骤，有一种只见树木，而不见森林的感觉，对技术成长不是很有利 ---> 需要主动学习，不然很容易死掉，可替代性太大，太码农，价值创造太少了，不过如果需要变动的地方设计发挥空间很大也还可以练练自己的产品设计能力

而Library开发者就得操作整个框架，就能够成长很快

## 看框图技巧
一定要去想哪些地方是稳定的，哪些是可以变动的，这样子就可以更有深度


## 总结
这个模式非常的常用，非常的基础，应用极其广泛
面向对象最基础的点

为应用框架提供了灵活的扩展点

反向控制结构==晚绑定--父类对子类说:不要调用我，让我来调用你

Template Method那些可变的函数一般声明成虚函数或者纯虚函数，然后因为这些函数一般嵌入在框架中，单独使用没有什么意义，所以一般设计成protected方法，供子类和父类自己调用 