/*看了整整一个小时20mins了还是没有看懂...pass先,等杜瑜皓大神讲解吧*/
/*2019年7月23日16:04:33 ldm给我讲了std的理解方法,牛逼! ta先自己写了一手,发现有点复杂然后看std
忘了说谢谢,和牛逼,下次记得说
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> piir;
const int N = 100 + 5;
int n, m, ans;
int dp[2][N][N][N];
vector <piir> lims[N];

inline void Mod(int &x) {
    static int mod = 998244353;//1e9 + 7;
    if (x >= mod) x -= mod;
}

int main() {
    int Case, ans, l, r, x;
    int i, j, k, t, p;
    for (scanf("%d", &Case); Case --; ) {
        ans = 0;
        scanf("%d %d", &n, &m);
        for (i = 1; i <= n; i ++)
            lims[i].clear();
        for (i = 0; i < m; i ++) {
            scanf("%d %d %d", &l, &r, &x);
            lims[r].push_back(piir(l, x));
        }
        /*第一轮是1,后面的轮这里变成了0  */
        dp[0][0][0][0] = 1;
        /*填满n个位置,所以n在最外层*/
        for (i = p = 1; i <= n; i ++, p ^= 1) {
            for (j = 0; j <= i; j ++)
                for (k = 0; k <= j; k ++)
                    for (t = 0; t <= k; t ++)
                        dp[p][j][k][t] = 0;
            for (j = 0; j < i; j ++)
                for (k = 0; k <= j; k ++)
                    for (t = 0; t <= k; t ++) {
                        Mod(dp[p][j][k][t] += dp[p ^ 1][j][k][t]);
                        Mod(dp[p][i - 1][k][t] += dp[p ^ 1][j][k][t]);
                        Mod(dp[p][i - 1][j][t] += dp[p ^ 1][j][k][t]);
                        Mod(dp[p][i - 1][j][k] += dp[p ^ 1][j][k][t]);
                    }
            for (j = 0; j < i; j ++)
                for (k = 0; k <= j; k ++)
                    for (t = 0; t <= k; t ++)
                        for (piir tmp : lims[i])
                            if (1 + (j >= tmp.first) + (k >= tmp.first) + (t >= tmp.first) != tmp.second)
                                dp[p][j][k][t] = 0;
        }
        for (i = 0, p = n & 1; i < n; i ++)
            for (j = 0; j <= i; j ++)
                for (k = 0; k <= j; k ++)
                    Mod(ans += dp[p][i][j][k]);
        printf("%d\n", ans);
    }
    return 0;
}
