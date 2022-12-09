# reference

## 基本属性

```cpp
int x=0;
// 老师喜欢*挨着int，因为这样可以
// 叫p为变量，一个指向int的指针变量

// 这里是p指向x
int* p = &x;

// r是x的引用,别名,r 和 x都是0
// 底层是指针实现(输出变量地址相同和输出变量大小相同
// 都是假象)
// 引用一个之后就不能再引用别人了
int& r = x;

int x2=5;

r = x2;
//r不能代表其他变量,所以这里是赋值
int& r2 = r;
// 这里r2是5,(r2是r别名,相当于也是x别名)

// java中全是reference

```


## 常用于参数传递
reference 通常不用于声明变量，而用于参数的类型和返回类型的描述
```cpp
void func1(Cls* pobj) { pobj->xxx(); }
// 2,3的调用端写法相同,而且3的传参速度更快,内存消耗少
// 所以reference很好
void func2(Cls obj) { obj.xxx(); }
void func3(Cls& obj) { obj.xxx(); }

Cls obj;
func1(&obj); // 接口不同,困扰
// 调用端的接口相同,很好
func2(obj);
func3(obj);
```

以下被视为相同的签名,不能共存,所以编译器会ambiguous
```cpp
double imag(const double& im) const { ... }
double imag(const double im) const { ... }
```

Q: ()之后的const也是签名的一部分
A: 所以上面两个函数()后一个加const,一个不加const就可以共存

2020年6月5日23:00:21 复习

2022年03月19日20:28:20 复习

2022年12月06日11:51:11 复习