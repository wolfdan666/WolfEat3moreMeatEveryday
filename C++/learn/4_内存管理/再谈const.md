## 函数签名
返回值不是函数的签名，参数列表和const才算是函数的签名
```cpp
// cpp规则，如果函数const版本和no-const版本同时存在，则常量对象只能调用const版，非常量对象只能调用no-const版(防止调用了const版本而无法做出改变--因为本来它有权力调用const版本，所以加了这样的准则)

// 不考虑cow
// 常量字符串不会被改，而且只能调用const类型
charT operator[](size_type pos) const
{
}

// COW -- copy on write
// 用中括号选择index出的char来改变
reference
operator[](size_type pos)
{
}

```