// priority_queue::push/pop
// bool operator<(P a, P b) { return a.second < b.second; } // 这样重载没用
// bool operator<(int & a, int & b) { return a.second > b.second; } // 也没用
// bool cmp(const P& a,const  P& b) { return a.second < b.second; } // 直接定义的是缺省的，前一段时间脑子有点晕，所以不知道前面没写会怎样...结果现在清醒，发现自己就是个傻逼
// 看了一个巨佬的blog，发现         重载运算符的操作不能用于pair类型数据的排序，只能作用于结构体或类对象。

/*
所以用pair的priority_queue只能使用struct的重载比较，why?!
1. 重载运算符的操作不能用于pair类型数据的排序，只能作用于结构体或类对象。---> 所以不能使用node型的priority_queue的函数重载操作符的方法
2. priority_queue定义不支持"嵌入式"函数重载的方法，即  priority_queue<P, vector<P>, cop>，这样会报错  sort(a,a+n,cop)可以
综上：不能函数重载了，那么就只能struct的自定义重载了咯

 */
#include <iostream> // std::cout
#include <queue> // std::priority_queue
using namespace std;

struct node {
    int x, y;
};

bool operator<(const node& a, const node& b)
{
    return a.y > b.y; //less默认大顶堆，改为小顶堆
}
bool cop(const P& a, const P& b) { return a.second > b.second; }

typedef pair<int, int> P;
struct cmp1 {
    // 就是说在cmp里面，当两个P使用  ()的时候，他们使用的下面的函数，也就是创建了一个自定义的函数
    /* 使用时 大概是这样的 cmp1 A, A(a,b) 就类似  非strut的自定义函数了
        bool cmp(P a,P b){ return a.second<b.second;}
     */
    bool operator()(P a, P b){ // 重载() 的函数 叫 仿函数-->紫书找到的
        return a.second > b.second; //小顶堆
    }
};

int main(){
    std::cout << "Popping out elements...";
    // priority_queue<node, vector<node>, less<node>> test;
    priority_queue<P, vector<P>, cmp1> test;
    test.push({ 3, 2 });
    test.push({ 1, 6 });
    test.push({ 2, 8 });
    test.push({ 5, 10 });
    while (!test.empty()) {
        std::cout << ' ' << test.top().second;
        // std::cout << ' ' << test.top().y;
        test.pop();
    }
    cout << endl;
    return 0;
}