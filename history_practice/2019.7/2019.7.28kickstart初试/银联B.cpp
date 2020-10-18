#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll p = 1e9 + 7;
ll n, m, inv6;
ll qmod(ll base, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * base % p;
        base = base * base % p;
        n >>= 1;
    }
    return res;
}

ll f(ll x) {
    return (x * (x + 1) / 2) % p;
}

/*连续平方和公式..n(n+1)(2*n+1)/6...*/
ll f2(ll x) {
    return x * (x + 1) % p * (2 * x + 1) % p * inv6 % p;
}

ll g(ll l, ll r) {
    return (f2(r) - f2(l - 1) + p) % p;
}

int main() {
    /*6的逆元*/
    inv6 = qmod(6, p - 2);
    while (scanf("%lld%lld", &n, &m) != EOF) {
        ll tot = m * f(m) % p;
        for (int i = 1, j; i <= m; i = j + 1) {
            j = m / (m / i);
            tot -= 1ll * g(i, j) * (m / i) % p;
            tot = (tot + p) % p;
        }
        ll res = n * f(n) % p * tot % p;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = n / (n / i);
            res -= 1ll * g(i, j) * (n / i) % p * tot % p;
            res = (res + p) % p;
        }
        printf("%lld\n", res);
    }
    return 0;
}