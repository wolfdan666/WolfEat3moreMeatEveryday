## 思想核心
- 动态的看问题，不要静态的看问题
- 开闭原则: 对扩展开放，对更改封闭
- 基类写个虚析构函数
- 这里为了方便才把代码写到同一个文件,工程中一般要写成多个文件
- 多态性要指针的，引用也可以，但极少用引用
- 我们讲的复用是**编译意义上的复用**，复制上面的东西不变，不叫复用---果然自己当年太年轻了，还是要多读书，多实现，多努力

## 模式定义
定义一系列算法,把它们一个个封装起来,并且使它们可互相替换(**变化**)。该模式使得算法**可独立于**使用它的客户程序(**稳定**)而变化(**扩展，子类化**)。

## 暗示
如果你的代码里面出现了很多switch case或者是if else(结构化时代的一种分而治之的思想)，这个时候就是暗示你使用Strategy策略了，当然如果你的if else是绝对不变的时候，那就可以直接写if else，比如一周有7天，这样就可以写if else，而如果业务中需要经常变化的话，那么一般可以考虑Strategy模式了

小方面的if else缺陷: 如果if else很多的时候,都要加载到主存里面，占用了主存，而Strategy可以缓解这种尴尬的场面 -- 当然这不是主要矛盾，前面才是

## 总结
- 方便在**运行时**切换算法
- 条件判断的另一种选择---虚函数表去判断
- 如果Strategy对象没有实例变量，那么各个上下文可以共享同一个Strategy对象，从而节省对象开销

## 代码
### 代码一,静态式
```cpp
enum TaxBase {
	CN_Tax,
	US_Tax,
	DE_Tax,
	FR_Tax       //更改
};

class SalesOrder{
    TaxBase tax;
public:
    double CalculateTax(){
        //...

        if (tax == CN_Tax){
            //CN***********
        }
        else if (tax == US_Tax){
            //US***********
        }
        else if (tax == DE_Tax){
            //DE***********
        }
		else if (tax == FR_Tax){  //更改
			//...
		}

        //....
     }

};
```


### 代码二，Strategy面向对象模式
```cpp
class TaxStrategy{
public:
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};


class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};


// 可以单独编译成一个dll加载进入原来的应用
//扩展
//*********************************
class FRTax : public TaxStrategy{
public:
	virtual double Calculate(const Context& context){
		//.........
	}
};


class SalesOrder{
private:
    TaxStrategy* strategy;

public:
    // Strategy调用进来的对象就行
    SalesOrder(StrategyFactory* strategyFactory){
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder(){
        delete this->strategy;
    }

    public double CalculateTax(){
        //...
        Context context();

        double val =
            strategy->Calculate(context); //多态调用
        //...
    }

};
```