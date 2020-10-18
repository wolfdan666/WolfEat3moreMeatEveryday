// 发现当年交到 poj 的 c++上不用从string！  然后发现自己现在交G++好像慢了好多...
#include <algorithm>
#include <cstdio>
#include<cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

int main(){
    char s[5][5];
    int mark[5][5];
    int x[20], y[20];
    // 发现当年交到 poj 的 c++上不用从string！
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i][j] == '+') {
                mark[i][j] = !mark[i][j]; //下面的操作中，i，j这个位置翻转了操作了两次，等于没操作，所以上边这里再操作一次，这样让这个位置                                                           也被操作了
                for (int k = 0; k < 4; k++) {
                    mark[i][k] = !mark[i][k];
                    mark[k][j] = !mark[k][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mark[i][j]) {
                x[ans] = i + 1;
                y[ans] = j + 1;
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
        printf("%d %d\n", x[i], y[i]);
    return 0;
}