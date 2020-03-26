/*
2020年3月21日17:43:24
STDOUT:

f2(123);
请按任意键继续. . .

*/

#include <stdio.h>
class c2;
class c1
{
   public:
       c2 *c;
       void (c2::*f)(int);
       void f1()
       {
          (c->*f)(123); // 这里就可以随便调了，只要对c、f都赋好值了。
                            // 如果要把子类同一类成员函数通过函数指针数组方式调用，
                             // 那么也类似地当然是可以实现的
                             // 注意这里的括号与*，都需要
       }
};

class c2: public c1
{
   public:
       void f2(int i)
       {
          printf("f2(%d);\n", i);
       }
       void f3()
       {
          c = this;      // 传对象的指针。成员函数访问需要通过对象，所以还必须用它
          f = &c2::f2; // 给函数指针赋值
       }
};

int main()
{
   c2 c;
   c.f3();
   c.f1();
   return 0;
}