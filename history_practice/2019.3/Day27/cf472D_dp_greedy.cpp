#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 4;

int n, m[MAXN];
int t[MAXN];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &m[i]);

    for (int i = n - 1, cur = 0; i >= 0; --i) {
        cur = max(0, cur - 1);
        cur = max(cur, m[i] + 1);// 这样反过去，虽然t[i]可能会小，但是后一个循环是从左到右
        t[i] = cur;
    }

    ll ans = 0;
    for (int i = 0, cur = 0; i < n; ++i) {
        cur = max(cur, t[i]);// 这里t[i]就代表了m[i]+1(并且满足了后一个比前一个最多多1个的条件),
        // 然后cur从左到右不断增大，从而满足了模拟(不会受前面for循环中t[i]不为真的阶梯值的影响
        // (那些t[i]值可能小一点))，得到了答案
        ans += cur;
    }

    for(int i = 0; i < n; ++i) ans -= (m[i] + 1);
    printf("%lld\n", ans);

    return 0;
}