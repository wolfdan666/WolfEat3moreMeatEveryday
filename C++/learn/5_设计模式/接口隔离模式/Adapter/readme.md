## 模式定义
将一个类的接口转换成客户希望的另一个接口。Adapter模式使得原本由于接口不兼容而不能--起工作的那些类可以一起工作。

## 精髓
### 1
继承---获取base类的规范
组合---支持被组合类的一种实现的方式

### 2
stack 和 queue 都是用deque做的，也是adapter，这里它们用的组合是直接内含一个deque结构，而不是deque指针

### 对象适配器
使用继承和组合

### 类适配器(不推荐使用)
使用多继承，一个用public继承来继承规范
一个用protected继承来进行实现

但是这里protected继承的类有纯虚接口的话，那就会无法使用，就得继承它的子类

但是这样还是有弊端，就是不够灵活，定死在一个类上面了，没有灵活性---继承的弊端---静态的

不如组合来的好，因为组合里面是动态的指针，可以传入不同的参数

## code
```cpp
//目标接口（新接口）
class ITarget{
public:
    virtual void process()=0;
};

//遗留接口（老接口）
class IAdaptee{
public:
    virtual void foo(int data)=0;
    virtual int bar()=0;
};

//遗留类型
class OldClass: public IAdaptee{
    //....
};

//对象适配器
class Adapter: public ITarget{ //继承
protected:
    IAdaptee* pAdaptee;//组合

public:

    Adapter(IAdaptee* pAdaptee){
        this->pAdaptee=pAdaptee;
    }

    virtual void process(){
        int data=pAdaptee->bar();
        pAdaptee->foo(data);

    }


};


//类适配器
class Adapter: public ITarget,
               protected OldClass{ //多继承

}


int main(){
    IAdaptee* pAdaptee=new OldClass();

    // 旧类套用Adapter之后就可以符合新接口的规范了
    ITarget* pTarget=new Adapter(pAdaptee);
    pTarget->process();
}

class stack{
    deqeue container;

};

class queue{
    deqeue container;

};
```