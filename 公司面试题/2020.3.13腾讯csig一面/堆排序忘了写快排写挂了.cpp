#include <bits/stdc++.h>
using namespace std;

// 原来我的random是宏...
#define random(a,b) ((a)+rand()%((b)-(a)+1))


int partition(vector<int>& a,int s,int end){
    if(s == end) return s;

    // 选择随机一个值做为末尾基准值
    int index = random(s,end);
    if(index!=end) swap(a[index],a[end]);

    // 将小于end 的 放在small处
    // int small = s;
    int small = s-1;
    for(int i = s;i < end;i++){
        if(a[i] < a[end]){
            small++;
            if(i != small){
                swap(a[small], a[i]);
            }
        }
    }

    small++;
    // if(a[small] < a[end]) swap(a[small], a[end]);
    // 错误二: 基准位置必须换回来，我没换...
    swap(a[small], a[end]);

    return small;
}

void mysort(vector<int> &a,int s,int end){
    if(a == nullptr) return ;
    int length = a.size();
    // if(length <= 1 || end - s <= 1 || s < 0 || end >= length) return ;
    if(length <= 1 || end - s <= 0 || s < 0 || end >= length) return ;

    int index = partition(a,s,end);
    if(index > s) mysort(a,s,index - 1);
    if(index < end) mysort(a,index + 1,end);
}

int main() {
    vector<int> test;
    test.push_back(6);
    test.push_back(2);
    test.push_back(4);
    test.push_back(9);
    test.push_back(4);
    test.push_back(7);

    int sz = test.size();
    cout<< "sz: " << sz <<endl;

    // mysort(test,0,test.size());
    // 错误一: 这里end搞错了
    mysort(test,0,test.size() - 1);

    for(auto i:test){
        cout<< i << " ";
    }
    cout<<endl;

    return 0;
}