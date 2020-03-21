#ifndef __COMPLEX__
#define __COMPLEX__

// template<typename T>
class complex
{
public:
    complex (double r=0, double i=0)
        : re (r) ,im (i)
    { }

    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*,
                             const complex&);

};

// do assign plus
inline complex&
__doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex &
complex::operator += (const complex & r)
{
    return __doapl (this, r);
}

inline complex
operator + (const complex& x, const complex& y)
{
    return complex (real(x) + real(y),
                    imag(x) + imag(y) );
}

inline complex
operator + (const complex& x, double y)
{
    return complex (real(x) + y, imag(x));
}

inline complex
operator + (double x, const complex& y)
{
    return complex (x + real(y), imag(y));
}

// 因为不考虑 c1 << cout; 所以无法使用成员函数定义
// 因为成员函数定义要用对象在左边
#include <iostream.h>
ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real (x) << ','
              << imag (x) << ')';
}

#endif