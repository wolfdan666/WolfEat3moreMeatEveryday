### 容器分类
- Sequence Containers
  - Array
  - Vector
  - Deque(双向队列)
  - List(双向链表，底层是双向环状链表)
  - Forward-List(单向链表,比List节约指针内存)
- Associative Containers(红黑树底层实现)
  - Set/Multiset(Multi表示可以重复元素)(其实底层很可能是HashTable Separate Chaining--碰撞了就链表--若链表太长又会进行打散优化)
  - Map/Multimap(Multi表示可以重复key)
- Unordered Containers
  - Unordered Set/Multiset
  - Unordered Map/Multimap

老师说 Unordered Containers其实也是一种 Associative Containers


#### 老师分享测试代码习惯
- 每个测试放在同一个namespace中
- 每个namespace前放这个namespace需要的头文件
  - 头文件有保护机制
- 测试程序的变量定义不把所有变量放在初始块的地方，而是在要用的时候声明初始化，然后因为散落在各行，可能不好找，老师就把数据行的缩进去掉


#### Array
只记录自己觉得重要的
```cpp
const int ASIZE = 5e5;
array<long,ASIZE> c;

int compareLongs(const void* a,const void* b){
    return ( *(long*)a - *(long*)b );
}

// c.data()是首地址
qsort(c.data(),ASIZE,sizeof(long),compareLongs);
cin>> target;
// bsearch是C语言中的
long* pItem = (long*)bsearch(&target,c.data(),ASIZE,sizeof(long),compareLongs);
if(pItem) cout<< *pItem;
```

#### Vector
老师说的是不够放了扩展内存,一般来说是2倍增的，但是老师的测试的vector.capacity()不是严格的vector.size(),所以等到源码的时候再看这个问题

2020年3月26日20:22:32 懂了，老师的capacity()=1,048,576=$2^{20}$,而size()=1,000,000正好小于等于$2^{20}$，而大于$2^{19}$__524,288。

```cpp
// find是cpp的一个模板函数，其实pItem的类型是
// vector<T>::iterator
auto pItem = ::find(c.begin(),c.end(),target);

if(pItem != c.end()) cout<<"finded"<<endl;

// 老师说如果不是频繁查找，只找几次，可以直接find()遍历查找，如果要多次查找的话才sort后二分查找，bsearch()
```

#### list
双向链表

list,Forward-List,deque都有max_size()这个函数


```cpp
list<string> c;
// 自己有sort一般用自己的sort，我突然想到之前ldm有一个算法题超时了，就是因为没有用容器自己的sort(),而是用的标准的sort()导致超时了
c.sort();
```

#### forward_list

```cpp
forward_list<string> c;

// 只有push_front();而且没有back(),size()
c.push_front("ok");
```

##### slist
也是一个单向链表，forward_list是cpp11的标准库中的，而这个是非标准库的
```cpp
#include<ext\slist>

__gnu_cxx::slist<string> c;

// 之后的函数用法与forward_list相同
c.push_front("ok");

```


#### deque
Vector是在别的地方找到一块两倍大的内存，然后把原来的数据搬过去，deque是一段段的buffer数据块，老师说之后再讲源码

老师说每次扩充多少这个概念一定要有，这关系到它的效率和内存用量

```cpp
deque<string> c;

c.push_back("ok");

c.size();
c.front();
c.back();
// deque的max_size()测试> forward_list.max_size() > list.max_size()
c.max_size();
// deque没有内部的sort()
::sort(c.begin(), c.end())
```

#### stack和queue
**stack和queue都是使用deque来实现**
**所以stack和queue应该算是Container Adapter**
当然也可以叫容器，一个先进先出，一个先进后出，所以不提供iterator，否则可以用iterator改变中间的值，或者插入什么的
##### stack
```cpp
stack<string> c;

c.push("ok");

c.size();
c.top();
c.pop();

```

##### queue
```cpp
queue<string> c;
c.push("ok");

c.front();
c.size();
c.back();

c.pop();
```

#### multiset
multiset可以看成key就是value,value就是key
红黑树---有序的
```cpp
multiset<string> c;

c.insert("ok");
c.size();
c.max_size();
// 记得有一次也是ldm debug用了标准库的而非自身的导致超时了
// 记得自己曾经傻傻地用了sizeof(vector),而非vector.size()... 好像ldm也有过，所以只会用，不了解原理其实比较容易忘记怎么用
c.find();
::find(c.begin,c.end);
```

#### multimap
```cpp
multimap<long,string> c;
c.insert(pair<long,string>(1,"ok"));
// 下面这种应该也是可以的
c.insert({1,"ok"});
// multimap不能用[]做insert，我想原因应该是key可以multi重复的原因

c.size();
c.max_size();
```

下面取自http://www.cplusplus.com/reference/map/multimap/insert/
```cpp
// multimap::insert (C++98)
#include <iostream>
#include <map>

int main ()
{
  std::multimap<char,int> mymultimap;
  std::multimap<char,int>::iterator it;

  // first insert function version (single parameter):
  mymultimap.insert ( std::pair<char,int>('a',100) );
  mymultimap.insert ( std::pair<char,int>('z',150) );
  it=mymultimap.insert ( std::pair<char,int>('b',75) );

  // second insert function version (with hint position):
  mymultimap.insert (it, std::pair<char,int>('c',300));  // max efficiency inserting
  mymultimap.insert (it, std::pair<char,int>('z',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::multimap<char,int> anothermultimap;
  anothermultimap.insert(mymultimap.begin(),mymultimap.find('c'));

  // showing contents:
  std::cout << "mymultimap contains:\n";
  for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  std::cout << "anothermultimap contains:\n";
  for (it=anothermultimap.begin(); it!=anothermultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
```

Output:
```
mymultimap contains:
a => 100
b => 75
c => 300
z => 400
z => 150
anothermultimap contains:
a => 100
b => 75
```

#### unordered_multiset
以前叫hash_multiset

一般是放了个数达到篮子的个数时，加倍篮子数，然后打散数据，老师说这个以后讲

```cpp
unordered_multiset<string> c;

c.insert("set")

c.size();
c.max_size();
c.bucket_count();
c.load_factor();
c.max_load_factor();
c.max_bucket_count();
// 打印第一个篮子装的元素数量
c.bucket_size(1);
```

#### unordered_multimap

```cpp
unordered_multimap<long,string> c;

c.size();
c.max_size();
```

#### set

```cpp
set<string> c;

c.insert("ok");
c.size();

```

#### map
```cpp
map<long, string> c;
c[i] = string("ok");

```

#### 其他
unordered_map,unordered_set略

priority_queue老师说自己比较少用，还有heap(不是讲内存的时候说的heap)，用得少，且是借用其他容器做的

比较老的容器,非标准,你要自己注意在哪个库里面
hash_set
hash_map
hash_multiset
hash_multimap