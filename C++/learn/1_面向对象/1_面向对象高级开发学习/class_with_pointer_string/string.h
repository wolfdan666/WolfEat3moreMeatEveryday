#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:
    String(const char* cstr = 0);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    char* get_c_str() const { return m_data; }
private:
    char* m_data;
};

#include <string.h>
inline
String::String(const char* cstr = 0)
{
    if (cstr) {
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data, cstr);
    }
    // 未初始化初值
    else {
        m_data = new char[1];
        *m_data = '\0';
    }
}


inline
String::~String()
{
    delete[] m_data;
}

inline
String::String(const String& str)
{
    m_data = new char[ strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
}

inline
String& String::operator=(const String& str)
{
    // self assignment(不仅仅是效率问题)
    // 自我赋值或者浅拷贝之后的对象赋值,
    // 不检测这里会把他们的共用数据块删除
    // 参数中是String& reference,这里是&取地址
    if (this == &str)
        return *this;

    delete[] m_data;
    m_data = new char [ strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
    return *this;
}

#include <iostream>
ostream& operator<<(ostream& os, const String& str)
{
    os << str.get_c_str();
    return os;
}








#endif