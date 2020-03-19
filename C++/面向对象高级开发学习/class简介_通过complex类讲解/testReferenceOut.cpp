#include<bits/stdc++.h>
using namespace std;

// error: invalid initialization of reference of type 'int&' from expression of type 'const int'
//      return a;
//             ^

// 我试了一下，发现是不行的啊
// 等下，a变成了const int?!那应该就是说其实return之后应该也可以
// 变成int吧，难道老师说错了，待会试试复数类的东西吧

// 后面复习的时候突然想到了为什么这里不行了
// 因为这里a 已经变成了一个临时变量了?
// 然后自己尝试把const去掉，编译成功了
// 所以就是说接受者const,传参者随意
// 但是如果接受者不const,传参者不能const
// 这就是之前老师说的你设计的函数尽量加const！
// int & zheng(const int& a)
// {
//     return a;
// }
// 引用真香!!!!!

int & zheng(int& a)
{
    return a;
}

const int & zheng3(const int & a)
{
    return a;
}

int zheng2(const int& a)
{
    return a;
}

int main(){
    int a = 233;
    cout<< zheng(a)<<endl;
    cout<< zheng2(a)<<endl;
    cout<< zheng3(a)<<endl;

    return 0;
}