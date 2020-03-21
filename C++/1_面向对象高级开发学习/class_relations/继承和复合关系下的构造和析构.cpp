/*
 * @filename:    Inheritance.cpp
 * @author:      Tanswer
 * @date:        2018年01月31日 14:59:28
 * @description: 测试继承复合关系下的构造和析构
 */

/*

2020年3月20日19:19:17 运行,参考自:
https://blog.csdn.net/tanswer_/article/details/79217912

Base ctor ...
Component ctor ...
Derived ctor ...
Derived dtor ...
Component dtor ...
Base dtor ...
请按任意键继续. . .


*/

#include<iostream>
using namespace std;

class Component
{
    public:
        Component(){
            cout << "Component ctor ..." << endl;
        }
        ~Component(){
            cout << "Component dtor ..." << endl;
        }
};
class Base
{
    public:
        Base(){
            cout << "Base ctor ..." << endl;
        }
        virtual ~Base(){
            cout << "Base dtor ..." << endl;
        }
        int n;
};

class Derived:public Base
{
    public:
        Derived(){
            cout << "Derived ctor ..." << endl;
        }
        ~Derived(){
            cout << "Derived dtor ..." << endl;
        }
        Component c;
};

int main()
{
    Derived test;

    return 0;
}
