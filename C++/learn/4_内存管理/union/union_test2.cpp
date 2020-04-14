#include <iostream>
#include <string>
#include <vector>

union S
{
    std::string str;
    std::vector<int> vec;
    ~S() {} // 需要知道哪个成员活跃，仅在联合体式的类中可行
};          // 整个联合体占有 max(sizeof(string), sizeof(vector<int>)) 的内存

int main()
{
    S s = {"Hello, world"};
    // 在此点，从 s.vec 读取是未定义行为
    std::cout << "s.str = " << s.str << '\n';
    s.str.~basic_string();

    // placement_new 直接调用construct
    new (&s.vec) std::vector<int>;
    // 现在，s.vec 是联合体的活跃成员
    s.vec.push_back(10);
    std::cout << s.vec.size() << '\n';
    s.vec.~vector();
}

/*
s.str = Hello, world
1
*/
