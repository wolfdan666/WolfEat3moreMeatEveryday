// 郭炜老师

// // 递归   90ms 207K
// #include <iostream>
// using namespace std;
// int a[30];
// int N;
// int Ways(int w, int k)
// { // 从前k种物品中选择一些，凑成体积w的做法数目
//     if (w == 0)
//         return 1;
//     if (k <= 0)
//         return 0;
//     return Ways(w, k - 1) + Ways(w - a[k], k - 1);
// }
// int main()
// {
//     cin >> N;
//     for (int i = 1; i <= N; ++i)
//         cin >> a[i];
//     cout << Ways(40, N);
//     return 0;
// }


// 动规解法  13ms 208k


#include <iostream>
using namespace std;
int a[40];
int N;
int Ways[50][40]; //Ways[i][j]表示从前j种物品里凑出体积i的方法数
int main()
{
    cin >> N;
    // memset(Ways, 0, sizeof(Ways));
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
        Ways[0][i] = 1;
    }
    Ways[0][0] = 1;
    for (int w = 1; w <= 40; ++w)
    {
        for (int k = 1; k <= N; ++k)
        {
            Ways[w][k] = Ways[w][k - 1];
            if (w - a[k] >= 0)
                Ways[w][k] += Ways[w - a[k]][k - 1];
        }
    }
    cout << Ways[40][N];
    return 0;
}