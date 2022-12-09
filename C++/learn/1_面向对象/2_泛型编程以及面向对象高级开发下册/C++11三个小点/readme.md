### variadic template(since C++11)
数量不定的模板参数

```cpp
// `...`的位置没有道理可言,就是设计规定的
// 递归print含参数的,最后是一个和空包,最最后空包
// 不能在调用这个函数了，所以要定一个void print(){}
void print(){}
template<typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    cout<< firstArg <<endl;
    print(args...)
}

int main(){
    // sizeof...(args)可以获取一包的大小
    print(7.5,"hello",bitset<16>(377),42);
}
```

![](%E6%A8%A1%E6%9D%BF%E5%8F%82%E6%95%B0%E5%8C%85.jpg)

### auto
```cpp
list<string> c;
// ...
list<string>::iterator ite;
ite = find(c.begin(), c.end(),target);
```

```cpp
list<string> c;
// ...
// C++一定要清楚类型,你很知道类型才用auto,而非盲目用
// auto一定要通过右边来判定,所以右边不能为空
auto ite = find(c.begin(), c.end(),target);
```

### ranged-base for(since C++11)
```cpp
/*
for ( decl : coll ) {
    statement
}
*/

for (int i : { 2, 3, 5, 7, 9, 13, 17, 19 } ){
    cout<< i <<endl;
}

vector<double> vec;
// 传值
for( auto elem : vec ) {
    cout<< elem <<endl;
}

// 传引用,别名影响整体,引用的底层就是指针
for( auto& elem : vec ) {
    elem *= 3;
}
```


2020年6月6日09:30:03 复习

2022年03月19日20:54:53 复习

2022年12月06日13:53:50 复习