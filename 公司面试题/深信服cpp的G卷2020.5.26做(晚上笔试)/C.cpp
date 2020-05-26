/*
2020年5月26日16:22:12 感觉就是简单的滑动窗口

2020年5月26日16:40:40 就是让单调队列的窗口可以任意

2020年5月26日16:56:35 感觉自己有点紧张，脑子有点糊，直接去看滑动窗口的资料吧

2020年5月26日16:59:56 交卷看吧，自己有点不在状态，没事，尽力而为把
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 300006, INF = 0x3f3f3f3f;
int n, m, s[N], q[N];

int main() {
    cin >> n ;
    // cin >> n >> m;
    m = n;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        s[i] += s[i-1];
    }
    int l = 1, r = 1, ans = INF;
    q[1] = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && q[l] < i - m) l++;
        // ans = max(ans, s[i] - s[q[l]]);
        ans = min(ans, s[i] - s[q[l]]);
        // while (l <= r && s[q[r]] >= s[i]) r--;
        while (l <= r && s[q[r]] <= s[i]) r--;
        q[++r] = i;
        cout<< "q[l]: "<< q[l] <<endl;
    }
    cout << ans << endl;
    return 0;
}