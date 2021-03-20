# 摘要
- char* p是p指针指向一个字符串常量，char p[]是数组
- 全局const变量不能通过指针引用改变，函数内的const变量可以


# 原文
https://mp.weixin.qq.com/s?__biz=MzA3MTU1MzMzNQ==&mid=2247485009&idx=1&sn=ef6a6ed0fd891aa18a43fa3c7a695ddd&chksm=9f2a9e09a85d171f87f5ce22316635d8bc708767765b3a397360ab12c4489ddc8e2f9b57254b&scene=90&xtrack=1&subscene=93&clicktime=1585664355&enterid=1585664355&ascene=56&devicetype=android-29&version=27000c51&nettype=WIFI&abtest_cookie=AAACAA%3D%3D&lang=zh_CN&exportkey=AQG%2FwOuyaNIstpx83xcZlTA%3D&pass_ticket=bCn7%2BCOdfWQHJzMXGSUjOtwlKMQpYIPpWizmnyxmY%2Bw%3D&wx_header=1

在一个夜深人静的晚上，有一个读者给我发了一个C语言题目。他问我，发哥，帮我看看这个代码有什么问题。我看了代码之后，心里一阵恐慌。我自认为我不是C语言高手。但我确实是一个喜欢解决问题的男人。就是在这样的背景驱使下，我写下了这篇文章。
```cpp
char *str1 = "hello";
char str2[] = "hello";
```
我们看这两个定义。我们说这个是定义而不是声明，是因为定义在内存里面分配了房子。而声明，只给了个房产证却不给你分房子。

str1 是 char *类型 。它是一个指针，这个指针指向一个字符串。

str2 是 char [] 类型。它是一个数组，他代表了这堆内存空间。

“hello”字符串在内存中是这样存放的

我之前写过一个不同变量地址分配在内存不同区域的文章，有不清晰的可以再回去看看。

str1 str3都是指向字符串的指针(在下面的代码)，而且这个字符串是保存在字符串常量区的。这个常量区里面的东西是不能被修改的。编译器让他们指向了同一个地址。这个地址保存的东西是 “hello”这个字符串。

大家看看下面这个代码有什么问题？
```cpp
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(void)
{
    char *str1 = "hello";
    char *str3 = "hello";
    char str2[] = "hello";

    memcpy(str3,"worldtest",strlen("worldtest")+1);

    printf("str1:%s str3:%s str2:%s\n",str1,str3,str2);

    str3 = "world";
    printf("str1:%s str3:%s str2:%s\n",str1,str3,str2);
    printf("hello,world\n");
    return (0);
}
```
memcpy尝试向一个非法的地址拷贝东西，这个是不允许的。为什么说这个地址非法呢？因为字符常量区里面的内容，只可以读，不可以写。

如果改成这样的呢？应该输出什么结果呢？
```cpp
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(void)
{
   char *str1 = "hello";
   char *str3 = "hello";
   char str2[] = "hello";

   //memcpy(str3,"worldtest",strlen("worldtest")+1);

   printf("str1:%s str3:%s str2:%s\n",str1,str3,str2);

   str3 = "world";
   printf("str1:%s str3:%s str2:%s\n",str1,str3,str2);
   printf("hello,world\n");
   return (0);
}
```
我之前在文章里面讨论一个问题，我们说指针的时候，要说指针变量。指针变量保存的内容是一个地址。既然是变量，那么保存的地址是可以变化的。只要类型符合。都可以保存。


同样的，在上面的例子中，如果我们尝试这样

`str1[1] = 'a';`
这样也是错误的。这样也是写操作了非法的地址。

试试下面这段代码
```cpp
#include <stdio.h>
int main(){
    char* str1="Hello";
    printf("\nstr1: %s, address: %p, sizeof(str1): %u", str1, str1, sizeof(str1));
    str1 = "world";
    printf("\nstr1: %s, address: %p, sizeof(str1): %u", str1, str1, sizeof(str1));
    return 1;
}
```
输出
str1: Hello, address: 0000000000404000, sizeof(str1): 8
str1: world, address: 0000000000404031, sizeof(str1): 8
--------------------------------
Process exited after 0.0226 seconds with return value 1
请按任意键继续. . .

通过赋值运算后，str1的值也发生了改变。

但是str2情况会不一样，str2是一个数组。（看下面）

既然是数组，我们看看这段小代码
```cpp
#include<stdio.h>
int main(){
    char str2[] = "hello";
    printf("\nstr2: %s, address: %p, sizeof(str2): %u", str2, str2, sizeof(str2));
    str2[2] = 'A';
    printf("\nstr2: %s, address: %p, sizeof(str2): %u", str2, str2, sizeof(str2));
    strcpy(str2, "world");
    printf("\nstr2: %s, address: %p, sizeof(str2): %u", str2, str2, sizeof(str2));
    return 1;
}
```
输出日志

str2: hello, address: 000000000062FE10, sizeof(str2): 6
str2: heAlo, address: 000000000062FE10, sizeof(str2): 6
str2: world, address: 000000000062FE10, sizeof(str2): 6
--------------------------------
Process exited after 0.04063 seconds with return value 1
请按任意键继续. . .
送一个图

晚上回来我写了一个小程序。大家看看
```cpp
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

const int a = 1;
const int a1 = 1;
char * s = "hello";

int main()
{
    const int b = 2;
    const int b1 = 2;
    char * s1 = "hello";

    printf("s:%p s1:%p\n",s,s1);
    printf("a:%p a1:%p b:%p b1:%p\n",&a,&a1,&b,&b1);

    return 1;
}
```
输出如下：

s:0000000000404008 s1:0000000000404008
a:0000000000404000 a1:0000000000404004 b:000000000062FE14 b1:000000000062FE10

--------------------------------
Process exited after 0.03901 seconds with return value 1
请按任意键继续. . .
**可以看到，s,s1,a,a1在一个内存区域。这个内存区域的内容是不允许改变的。如果你对这里的内存区域赋值，就会出现段错误。**

但是b和b1这个内存区域大家看看。我们可以写个小代码测试一下。
```cpp
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

const int b = 2;

int main()
{
    const int b1 = 2;
    int *p = &b1;
    printf("b1:%d\n",b1);
    *p = 3;
    printf("b1:%d\n",b1);

    return 1;
}
```
输出：

b1:2
b1:3

--------------------------------
Process exited after 0.0403 seconds with return value 1
请按任意键继续. . .
但是我们写成这样呢？
```cpp
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

const int b = 2;

int main()
{
    const int b1 = 2;
    int *p = &b;
    printf("b:%d\n",b);
    *p = 3;
    printf("b:%d\n",b);

    return 1;
}
```
输出：

b:2

--------------------------------
Process exited after 3.743 seconds with return value 3221225477
请按任意键继续. . .
如果放到gcc下，可以看到，执行到代码

*p = 3;
会出现段错误。因为访问了不能访问的地址。这也就是我们很多时候给空指针赋值出现段错误的原因。操作了非法的地址。
