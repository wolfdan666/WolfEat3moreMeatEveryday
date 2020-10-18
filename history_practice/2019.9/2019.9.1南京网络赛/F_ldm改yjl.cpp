/*
原来之前一直读错题目了！题目是让我构造出n个si
然后依次输出他们的串长...

然后我理解错了，以为是只构建一个si,然后输出就是si中的每个元素
GG...

然后有技巧地贪心模拟..

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, b, a) for(int i = b; i >= a; i--)
#define fi first
#define se second
#define ls rt<<1
#define rs rt<<1|1
#define lson ls, l, mid
#define rson rs, mid+1, r
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 100000 + 5;

int n, k, a[N], b[N], vis[N], dp[N];

int dfs(int u) {
    if(vis[u]) return dp[u];
    vis[u] = 1;
    /*贪心最大的递减并符合条件的元素，然后dp记录元素值,
    可以用上之前的结果*/
    per(v, u-1, 1) {
        if(abs(b[u]-b[v]) <= k) {
            dp[u] = dfs(v)+1;
            break;
        }
    }
    if(!dp[u]) dp[u] = 1;
    return dp[u];
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        rep(i, 1, n) {
            scanf("%d", &a[i]);
            b[a[i]] = i;
        }
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        rep(i, 1, n) {
            if(i == 1) printf("%d", dfs(i));
            else printf(" %d", dfs(i));
        }
        puts("");
    }

    return 0;
}