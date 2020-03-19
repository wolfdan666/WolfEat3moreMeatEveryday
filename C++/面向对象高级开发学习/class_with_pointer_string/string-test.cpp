#include <iostream>
#include "string.h"
using namespace std;

int main(){
    String s1();
    String s2("hello");

    // 拷贝构造
    String s3(s1);
    cout << s3 << endl;

    // 拷贝赋值
    s3 = s2;

    cout<< s3 << endl;

    return 0;
}