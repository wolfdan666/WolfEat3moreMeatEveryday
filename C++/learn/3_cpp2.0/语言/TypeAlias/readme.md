# Type Alias
Type

```cpp
// type alias, identical t
// typedef void (*func)(int,int);
using func = void (*)(int,int);
```

```cpp
// type alias can introduce a member typedef name
template<typename T>
struct Container {
    using value_type=T;
    // typedef T value_type;
}

template<typename Cntr>
void fn2(const Cntr& c)
{
    typename Cntr::value_type n;
}
```

```cpp
// Alias template
// type alias used to hide a template parameter
template<class CharT>
using mystring = std::basic_string<CharT,std::char_traits<CharT>>;

mystring<char> str;
```