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