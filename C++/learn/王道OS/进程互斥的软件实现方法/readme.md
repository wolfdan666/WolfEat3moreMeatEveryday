## 单标志法
字面意思

感觉缺点是单线程可用吧...除非是原子操作

老师说的缺点是某线程获得标志但是没有访问，违背空闲让进原则

## 双标志检查法
两个flag

然后老师讲了我理解的多线程刚进入执行区但还未修改状态的时候多线程切换了的尴尬问题了

所以违反了"忙则等待"---其实单标志也违背了这个

## 双标志后检查法
先改标志再判断,同样在切换后...两个都true...

## Peterson
双标志后检查法+多加了一个礼让标志
但是还是老问题...都是一样的一起卡在while__当然这个还是最终能够解脱出来的，因为共用一个turn__两个while不会一直同时成立

老师举了一个礼让上WC的例子

但是这个操作还是违背了 忙等待 的问题，导致有一段时间是浪费了CPU资源去一直while空操作的
```cpp
bool flag[2];
int turn = 0;
// P0进程
flag[0] = true;
turn = 1;
while (flag[1] && 1==trun);
// critical section; // 访问资源的操作
flag[0] = false;
// remainder section; // 剩下的操作

// P1进程
flag[1] = true;
turn = 0;
while(flag[0] && 0==trun);
// critical section;
flag[1] = false;
// remainder section; // 剩下的操作
```

## 精髓
并发的异步性导致问题