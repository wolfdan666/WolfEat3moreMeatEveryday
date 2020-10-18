/*
2019年11月13日22:27:36 开始看别人的code

发现深信服的面试题真的全是dp...

真学好dp==>打爆面试

sb了,这就是一个极其简单的dp上楼梯的问题,自己竟然没有写出来,丢人...

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n, a[3];
int res = 0;

void fun(int h){
    if (h == n){
        res++;
        return;
    }
    if (h > n) return;
    for (int i = 0; i < 3; i++){
        fun(h + a[i]);
    }
}

int main(){
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    fun(0);
    cout << res << endl;

    getchar();
    return 0;
}