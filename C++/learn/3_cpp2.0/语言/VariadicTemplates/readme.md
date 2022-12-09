```cpp
void print()
{
}

template<typename T,typename... Types>
void print(const T& firstArg,const Type&... args)
{
    cout<<firstArg<<endl;
    print(args...);
}
```


2020年6月13日09:02:50 复习
2022年12月08日15:25:57 复习(包含同目录下的5个cpp文件的复习)