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