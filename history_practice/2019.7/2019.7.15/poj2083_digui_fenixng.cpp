/*
2019年7月15日20:08:51 开始看题

2019年7月15日20:34:23 发现不对，要分解到逐单位行里面去  所以去网上找找怎么搞

看到大佬的解法，马上又想到了自己以前做过...类似的题目，就是逐行直接算出怎么放置！  占好坑位...最后才放置...



 */

// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
// using namespace std;
// #define ll long long
// int n;

// void fun(int n){
//     if(n==1) cout<<"X";
//     else{
//         // 第一行
//         fun(n-1);
//         for(int i=0;i<n-1;i++) cout<<' ';
//         fun(n-1);

//         cout<<endl;
//         // 第二行
//         for(int i=0;i<n-1;i++) cout<<' ';
//         fun(n-1);
//         for(int i=0;i<n-1;i++) cout<<' ';

//         cout<<endl;
//         // 第三行
//         fun(n-1);
//         for(int i=0;i<n-1;i++) cout<<' ';
//         fun(n-1);
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     while(cin>>n){
//         if(n==-1) break;
//         fun(n);
//         cout<<"\n-"<<endl;
//     }
//     return 0;
// }

#include <iostream>
#include<cstring>
using namespace std;
bool map[730][730];
//print()函数并不绘制图形，而是根据坐标改变map[x][y]的值
int muti[] = { 1, 3, 9, 27, 81, 243, 729 }; //3的N次幂表
void print(int x, int y, int cur)
{
    if (cur == 1) {
        map[x][y] = true;
        return;
    }
    //递归绘制左上角的图形
    print(x, y, cur - 1);
    print(x, y + 2 * muti[cur - 2], cur - 1);
    //递归绘制右上角的图形
    print(x + muti[cur - 2], y + muti[cur - 2], cur - 1);
    //递归绘制中间的图形
    print(x + 2 * muti[cur - 2], y, cur - 1);
    //递归绘制左下角的图形
    print(x + 2 * muti[cur - 2], y + 2 * muti[cur - 2], cur - 1);
    //递归绘制右下角的图形
}
int main()
{
    int n;
    while (cin >> n && n != -1) {
        memset(map, false, sizeof(map));
        print(1, 1, n);
        for (int i = 1; i <= muti[n - 1]; i++) {
            for (int j = 1; j <= muti[n - 1]; j++) {
                if (map[i][j])
                    cout << "X";
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}