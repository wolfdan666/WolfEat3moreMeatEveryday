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
    char* (*pf[3])(char* p);
    // 函数名是一个地址，可以将他赋值给一个指向函数的指针。前面加了&符号其意义是一样的。
    // 比如定义一个数组arr[]，arr表示这个数组的首地址，但&arr同样表示他的首地址。这些都是设计语言时这样规定的
    // https://blog.csdn.net/zhangzhi123456789/article/details/49253171
    pf[0] = fun1;   // 可以直接用函数名
    pf[1] = &fun2;  // 可以用函数名加上取地址符（感觉这里应该是引用）
    pf[2] = &fun3;
    pf[0]("fun1");
    pf[1]("fun2");
    pf[2]("fun3");
    return 0;
}