#include<bits/stdc++.h>
using namespace std;

class Fraction
{
public:
    Fraction(int num, int den=1)
     : m_numerator(num), m_denominator(den) { }
    // 这里的const是大家风范，尽量const
    // 因为有些函数外面是const.你里面没const会报错
    operator double() const {
        // return (double)(m_numerator / m_denominator);
        return (double)m_numerator / m_denominator;
    }


private:
    // 下面的注释和代码写在一起其实也没有关系，因为共生
    int m_numerator; // 分子
    int m_denominator; // 分母
};

int main(){
    Fraction f(3,5);
    // 先找是否有重载 + (int,Fraction)
    // 然后再找是否能先把f转化成double,然后就能找到
    double d = 4 + f;
    // 老师也说是输出4,改掉之后4.6了
    // 所以老师故意写错f的转double?
    // 可能这不是重点吧,我改一下
    cout<< d << endl;
    cout<< f << endl;

    return 0;
}