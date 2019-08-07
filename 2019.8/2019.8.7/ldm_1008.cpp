/*签到暂时不重写了*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        ll k, m;
        scanf("%lld%lld", &k, &m);
        ll ans = -1;
        /* 利用f(n,m)-n约等于m(范围大概0到400)(200WA了..)很小的特性对这个式子进行枚举，
        然后还利用一点简单的异或变化 */
        // for(ll i = 1000; i >= m; i--) {
        for(ll i = 400; i >= m; i--) {
            ll n = (k^i);
            int cnt = 0;
            for(ll j = 1; j < i; j++) {
                if(gcd(n, n+j) == 1) cnt++;
            }
            if(cnt == m-1 && gcd(n, n+i) == 1) {
                if(ans == -1) ans = n;
                else ans = min(ans, n);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}