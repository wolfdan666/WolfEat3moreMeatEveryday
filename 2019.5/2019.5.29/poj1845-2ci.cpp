// 2019年5月29日16:21:08 再看高中生巨佬的代码
// 2019年5月29日16:27:11 还是发现我的代码和高中生巨佬和其他一个大佬的运行结果有点不同，所以继续debug
#include <algorithm>
#include <cstdio>
#include <iostream>
#define R register int
#define ll long long
const int mod = 9901;
using namespace std;
int a, b, tot, ans = 1;
int pm[50010], cnt[50010];

inline ll q_pow(ll a, ll p)
{
    if (a == 0)
        return 1;
    R ret = 1;
    a %= mod;
    for (; p; p >>= 1, (a *= a) %= mod)
        if (p & 1)
            (ret *= a) %= mod;
    return ret;
}

ll sum(ll a, ll c)
{
    if (c == 0)
        return 1;
    if (c & 1)
        return ((1 + q_pow(a, (c >> 1) + 1)) % mod * sum(a, (c >> 1)) % mod) % mod;
    return ((1 + q_pow(a, (c >> 1) + 1)) % mod * sum(a, (c - 1) >> 1) + q_pow(a, c >> 1) % mod) % mod;
}

int main()
{
    scanf("%d%d", &a, &b);
    for (R i = 2; i * i <= a; i += (i & 1 ? 2 : 1))
        if (a % i == 0) {
            pm[++tot] = i;
            while (a % i == 0)
                cnt[tot]++, a /= i;
        }
    if (a != 1)
        pm[++tot] = a, cnt[tot]++; //要判断一下A本身是不是素数
    for (R i = 1; i <= tot; i++){
            ans = (ans * (sum(pm[i], cnt[i] * b) % mod)) % mod;
            cout << "pm[i] " << pm[i] << " cnt[i] " << cnt[i]<<" ans "<< ans << endl;
    }
    printf("%d\n", ans);
}


// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <iostream>
// #include <queue>
// #include <set>
// #include <vector>
// using namespace std;
// typedef long long LL;
// typedef unsigned long long ULL;
// const int INF = 1e9 + 5;
// const int MAXN = 1e6 + 5;
// const LL MOD = 9901;
// const double eps = 1e-7;
// const double PI = acos(-1.0);
// using namespace std;
// LL p[MAXN];
// int k = 0;
// bool prime[MAXN];
// void isprime()
// {
//     k = 0;
//     memset(prime, 0, sizeof(prime));
//     prime[1] = 1;
//     for (int i = 2; i < MAXN; i++) {
//         if (!prime[i]) {
//             p[k++] = i;
//             for (int j = i + i; j < MAXN; j += i)
//                 prime[j] = 1;
//         }
//     }
// }
// LL fac[MAXN / 100], num[MAXN / 100];
// int cnt = 0;
// void Dec(LL x)
// {
//     cnt = 0;
//     memset(num, 0, sizeof(num));
//     for (int i = 0; p[i] * p[i] <= x; i++) {
//         if (x % p[i] == 0) {
//             fac[cnt] = p[i];
//             while (x % p[i] == 0) {
//                 num[cnt]++;
//                 x /= p[i];
//             }
//             cnt++;
//         }
//     }
//     if (x > 1) {
//         fac[cnt] = x;
//         num[cnt++] = 1;
//     }
// }
// LL multi(LL a, LL b, LL c)
// {
//     LL ans = 0;
//     while (b) {
//         if (b & 1)
//             ans = (ans + a) % c;
//         b >>= 1;
//         a = (a + a) % c;
//     }
//     return ans;
// }
// LL quick_mod(LL a, LL b, LL c)
// {
//     LL ans = 1;
//     while (b) {
//         if (b & 1)
//             ans = multi(ans, a, c); ///可能爆 long long
//         b >>= 1;
//         a = multi(a, a, c);
//     }
//     return ans;
// }

// int main()
// {
//     isprime();
//     LL A, B;
//     while (~scanf("%lld%lld", &A, &B)) {
//         Dec(A);
//         LL ans = 1, x, y, tmp;
//         for (int i = 0; i < cnt; i++) {
//             LL MM = MOD * (fac[i] - 1); ///MM * MM 容易爆 long long
//             tmp = quick_mod(fac[i], num[i] * B + 1, MM);
//             tmp--;
//             tmp = (tmp % MM + MM) % MM;
//             tmp /= (fac[i] - 1);
//             ans = (ans * tmp) % MOD;
//         }
//         ans = (ans % MOD + MOD) % MOD;
//         printf("%lld\n", ans);
//     }
//     return 0;
// }
