// 最优路径+大数处理
// 直接看大佬怎么写
// 2019年7月7日22:39:34 GG，回去洗澡锻炼，明天再补这题

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma GCC optimize(2)
//#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef double dou;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef map<ll, ll> mii;

#define pai acos(-1.0)
#define M 105
#define inf 0x3f3f3f3f
#define mod 1000000007
#define left k << 1
#define right k << 1 | 1
#define W(a) while (a)
#define ms(a, b) memset(a, b, sizeof(a))

int T, n;
int ans;
int land[M][M];
int dp[M][M][20][2];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> land[i][j];
        }
    }
}

void init(){
    ans = inf;
    ms(dp, inf);
}

void solve()
{
    dp[1][1][0][0] = dp[1][1][0][1] = land[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1)
                continue;
            // 从左向右的递推
            dp[i][j][0][1] = dp[i - 1][j][0][1] + land[i][j];
            // 从上往下的递推
            dp[i][j][0][0] = dp[i][j - 1][0][0] + land[i][j];
            // 这个15真的让我一脸懵逼
            for (int k = 1; k <= 15; k++) {
                dp[i][j][k][1] = min(dp[i - 1][j][k][1], dp[i][j - 1][k - 1][0] + (1 << k - 1)) + land[i][j];
                dp[i][j][k][0] = min(dp[i][j - 1][k][0], dp[i - 1][j][k - 1][1] + (1 << k - 1)) + land[i][j];
            }
        }
    }
}

void output()
{
    for (int i = 0; i <= 15; i++) {
        ans = min(ans, min(dp[n][n][i][1], dp[n][n][i][0]));
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    W(T--){
        init();
        input();
        solve();
        output();
    }

    return 0;
}