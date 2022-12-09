# 面向对象设计OOD,面向对象编程OOP


### 复合
一个类拥有另一个类,比如queue类拥有deque类

母体---容器,子体---组件
母体子体共生的,构造析构顺序可以类比穿衣服
#### construct
子体先创建,母体再创建
(有了子体组件，才能组装成容器)

#### destruct
母体先析构,子体再析构
(先把容器拆了，再把它的组件也拆了)

### 委托Delegation.Composition by reference
一个类拥有指向另一个类的指针,
即使是指针,也将成Composition by reference
因为学术上不讲pointer

母体等到要用子体的时候再创建自己
母体的功能可以全部由子体来实现
母体handle可以不变,而我们可以弹性转化子体Body


3个对象指向同一个类,然后写时复制,谁要改变内容就触发拷贝


### Inheritance(继承),is-a
人类是一种哺乳类
java只能public继承
而cpp可以public,private,protect,主要是public

继承最有价值的部分是虚函数

母体---子类,子体---base类,父类
(父类在类视图里面确实是子体，镶嵌在子类框里，2020年5月13日10:51:49 复习)

母体子体共生的,构造析构顺序可以类比穿衣服(类似于复合)
#### construct
子体先创建,母体再创建

#### destruct
母体先析构,子体再析构


#### virtual
base class的dtor必须是virtual,否则会出现undefined behavior

子类对象很大，因为它包含了父类，所以我们要讲讲虚函数了

继承可以继承数据和函数，数据就是内存上继承，而函数呢,则应该说成是继承了父类函数的调用权

##### 非虚函数
你不希望父类的函数被重新定义(override,覆写)时使用

##### virtual function
你希望子类重新定义(override,覆写),而且你已经有了默认的定义了

##### 纯虚函数
你希望子类必须重新定义,父类中没有没有定义(其实可以有定义)



通过子类对象调用父类函数,如果遇到虚函数的话,优先使用子类定义的函数---通过this调用其中的函数，所以就是子类的this

Template Method(模板函数---设计模式)

MFC就是这样赚钱的

##### 继承和复合关系下的构造和析构
我没有自己写,直接拷贝了别人的代码，先快速学习先


### Delegation+Inheritance(委托+继承)
例子，4个窗口观察同一份数据，以不同的形式展开，比如就是以图表的形式展开啊，以数列的形式展开啊

```cpp
class Subject
{
    int m_value;
    // 这里是委托,然后Observer被继承
    vector<Observer*> m_views;

public:
    void attach(Observer* obs)
    {
        m_views.push_back(obs);
    }
    // ...没有继续写下去了
}

class Observer
{
    ...
}
```

#### Composite(设计模式中的一种)
文件夹下面又有文件夹的那种

因为对象不一定是相同的大小的，所以为了vector,只好`vector<Component*>`

![Composite](https://img-blog.csdnimg.cn/20200320193609168.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25ldmVfZ2l2ZV91cF9kYW4=,size_16,color_FFFFFF,t_70)

#### Prototype(设计模式中的一种)
父类中要包含未来才会创建的子类，但是无法知道未来的定义的子类名字，那我们怎么办呢?

解决方法就是子类将来创建的时候，自己创造自己在父类中的东西

子类把自己声明成为静态的，然后把构造函数声明成为私有的函数，最后就可以做到自己构造自己，然后把自己addPrototype(this)，把自己注册给古老的父类

子类还要自己准备clone()拷贝函数,通过第一个原型去addPrototype注册给父类，然后父类通过原型去使用clone创造更多个

这种方式让侯捷老师都拍案叫绝
2020年3月21日17:55:04 是这篇文档的第二天的学习又学习了'因成员模板而引申研究父类调用子类成员函数'-->见'../2_泛型编程/因成员模板而引申研究父类调用子类成员函数/readme.md'

这就是你要使用古老的框架要付出的一点点代价:
- 私有静态的自己(**要记得在函数外头定义(分配空间)**)
- 私有的ctor(调用父类的static函数addPrototype(),为了通过类型访问)
- clone()
- 一个新的protect或者private的构造函数,多设一个参数防止ambiguous，其实这个参数可以不用 --- 这个构造函数用来给clone调用



**太美妙了,太精妙了,没想到软件设计模式这么美妙**



2020年5月13日11:01:36 来复习了一次
2020年6月5日17:26:30 第二次复习

2022年03月05日16:34:48 复习3
2022年12月05日19:58:33 复习4