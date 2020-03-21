/*
2020年3月21日17:50:48 STDOUT:
123
f2()
请按任意键继续. . .

*/

#include<stdio.h>
template< typename T >
class c1 {
public:
   T *t;
   void f1()
   {
       printf("%d\n", t->xxx); // t 是模板类型T的指针，这样即使不知道t的具体定义,
                                          // 也可以访问到其成员，可以调用到其方法
                                          // 若非通过模板，就不能这样
       t->f2();
   }
};

class c2: public c1< c2 > {   // 这样这里
public:
   void f2(){ printf("f2()\n");}
   int xxx ;
   void f3()
   {
       xxx = 123;
       t = this;  // 这个需要这样设置
   }
};
int main()
{
   c2 c;
   c.f3();
   c.f1();
   return 0;
}