## 更改架构心得
- 感觉主要是用组合和接口去代替傻傻的继承，因为原先的架构没有深入理解is a其实应该算一个大跨度的东西，而不应该是一个小跨度的东西，更不应是一个接口能解决的用继承，这是优先接口和组合原则中说的
- 然后通过把静态的类型换成动态的运行时的类型---真理是编译的时候不变化，然后运行的时候让它变化，这就是一个快乐的思想
- 然后继承一个Stream,主要是使用Stream定义的接口规范，让下面的Read,Seek,Write函数能有个规范
- 所以一个继承的Stream使用的Stream的接口规范，然后含有的Stream*指针是为了多态而存在的


## 总结
- 继承为代码引入了静态的特质，无法变化
- 同时继承又组合同一个类，很可能就是装饰模式
- 接口上表现为is-a，实现上表现为has-a
- Decorator模式应用的要点在于解决“主体类在多个方向上的扩展功能”---这就是“装饰”的含义

## 感受
- 太神奇了，鬼斧神工，设计模式太美了