#include<bits/stdc++.h>
using namespace std;

class C{
public:
    C() : m_b(0), m_a(m_b + 1)
    {}

    void Output(){
        std::cout << "m_a : " << m_a << ", m_b : " << m_b << std::endl;
    }

private:
    int m_a;
    // output: m_a : 1, m_b : 0 . 因为a先声明，所以先赋值
    // 然后这里编译器优化，所以认为b=0,所以a=1,其实可能是任意值
    int m_b = 2;
};

int main(){
    C c;
    c.Output();

    return 0;
}