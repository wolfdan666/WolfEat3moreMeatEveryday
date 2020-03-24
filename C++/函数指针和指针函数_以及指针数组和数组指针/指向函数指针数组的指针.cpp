/*
指向函数指针数组的指针
示例：char* (*(*fun)[3])(char* p)
理解：这里的 fun和上一节的 fun就完全是两码事了。上一节的 fun
并非指针，而是一个数组名；这里的 fun确实是实实在在的指针。这个指针指向一个包含了
3
个元素的数组；这个数字里面存的是指向函数的指针；这些指针指向一些返回值类型为指向字符的指针、参数为一个指向字符的指针的函数。
其图示如下：
https://img-blog.csdn.net/20170520111721581?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvY2hlcmlzaGluZ2luZw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast
————————————————
原文链接：https://blog.csdn.net/cherishinging/article/details/72229626
*/

#include <stdio.h>
#include <string.h>

char* fun1(char* p) {
    printf("%s\n", p);
    return p;
}

char* fun2(char* p) {
    printf("%s\n", p);
    return p;
}

char* fun3(char* p) {
    printf("%s\n", p);
    return p;
}

int main() {
    char* (*a[3])(char* p);
    char* (*(*pf)[3])(char* p);
    pf = &a;
    a[0] = fun1;
    a[1] = &fun2;
    a[2] = &fun3;
    pf[0][0]("fun1");
    (*pf)[0]("fun1");
    pf[0][1]("fun2");
    pf[0][2]("fun3");
    return 0;
}