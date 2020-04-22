dispatch  多态辨析


double dispatch


## 精髓
- 这个模式稳定的是各种对象(子类对象如果不稳定的话，那么这个模式就不能用了)和大的Visitor框架，动态变化的是小的Visitor新的类添加---新的操作VisitorX的添加

- accept动态辨析一次，visitElementX动态辨析一次，双重分发