// 2019年5月25日16:38:56 开始看题  wolfdan.cn
// 2019年5月25日17:41:36 借鉴<算法进阶指南>和法二大佬的code还没跑出来    加油啊
// 2019年5月25日18:18:28 写算法被导师发现了，然后又把我叫了出去，
// 劝我考研，说现在不早不晚，时机刚刚好，这已经是第五次老师找我谈考研时长达35mins以上，不算那些时不时的简短一句

// 法一：好像要用素数筛，然后对每一个小于自身的素数进行处理，然后再是分治求等比数列(防止出现乘法)，然后辅助以快速幂...
// 东西有点小多  ---> 所以先看看大佬怎么写
// 法二见 ： https://blog.csdn.net/qingshui23/article/details/52154321
// 借鉴了许多法二

// 2019年5月30日20:16:54自己重写的时候总算debug成功 发现自己原来是自己智障了，忘记了乘以一个幂b

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
const int M = 5e7 + 10;
bool prime[M]; // 防在外面一开始会默认初始化为0
ll p[M];
int num[M / 1000], fac[M / 1000];
int k = 0;
int mod = 9901;
int cnt;

// 1代表非素数，0代表素数
void isPrime()
{
    prime[1] = 1;
    for (int i = 2; i < M; i++) {
        if (!prime[i]) {
            p[k++] = i;
            for (int j = i * 2; j < M; j += i)
                prime[j] = 1;
        }
    }
}

ll mypow(ll a, ll b, ll p)
{
    ll ans = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

void Dec(ll x)
{
    cnt = 0;
    memset(num, 0, sizeof(num));
    for (int i = 0; p[i] * p[i] <= x; i++) {
        if (x % p[i] == 0) {
            fac[cnt] = p[i];
            while (x % p[i] == 0) {
                num[cnt]++;
                x /= p[i];
            }
            cnt++;
        }
    }
    if (x > 1) {
        fac[cnt] = x;
        num[cnt++] = 1;
    }
}

// ll getSum(ll p, ll c)
// {
//     if (c == 1)
//         return p + 1;
//     if (c == 2)
//         return p + 1 + mypow(p, c, mod);
//     if (c & 1) {
//         return (1 + mypow(p, ((c + 1) / 2), mod)) * getSum(p, (c - 1) / 2);
//     }
//     return (1 + mypow(p, c / 2, mod)) * getSum(p, c / 2 - 1) + mypow(p, c, mod);
// }

ll getSum(ll p, ll c)
{
    if (c == 0)
        return 1;
    if (c & 1) {
        return (1 + mypow(p, ((c + 1) / 2), mod)) % mod * getSum(p, (c - 1) / 2) % mod; // 及时取mod
    }
    return (1 + mypow(p, c / 2, mod)) % mod * getSum(p, c / 2 - 1) + mypow(p, c, mod) % mod;
}

int main()
{
    // cout<<M<<endl;

    isPrime();
    ll a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        Dec(a);
        ll ans = 1;
        for (int i = 0; i < cnt; i++) {
            ans = (ans * getSum(fac[i], num[i] * b)) % mod;
            // cout << "fac[i] " << fac[i] << " num[i] " << num[i]<<" ans "<< ans << endl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

// 法二：
/*
根据这个公式就可以做了，首先要素数筛，然后素因子分解，快速幂，这里需要注意的是，当我们
进行快速幂的时候，中间有可能爆 long long 所以，在快速幂的过程中加上快速乘法，这样就可
以了。
*/
/**
2016 - 08 - 08 下午
Author: ITAK

Motto:

今日的我要超越昨日的我，明日的我要胜过今日的我，
以创作出更好的代码为目标，不断地超越自己。
**/

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

// 高中生巨佬的分治
// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #define R register int
// #define ll long long
// const int mod = 9901;
// using namespace std;
// int a, b, tot, ans = 1;
// int pm[50010], cnt[50010];

// inline ll q_pow(ll a, ll p)
// {
//     if (a == 0)
//         return 1;
//     R ret = 1;
//     a %= mod;
//     for (; p; p >>= 1, (a *= a) %= mod)
//         if (p & 1)
//             (ret *= a) %= mod;
//     return ret;
// }

// ll sum(ll a, ll c)
// {
//     if (c == 0)
//         return 1;
//     if (c & 1)
//         return ((1 + q_pow(a, (c >> 1) + 1)) % mod * sum(a, (c >> 1)) % mod) % mod;
//     return ((1 + q_pow(a, (c >> 1) + 1)) % mod * sum(a, (c - 1) >> 1) + q_pow(a, c >> 1) % mod) % mod;
// }

// int main()
// {
//     scanf("%d%d", &a, &b);
//     for (R i = 2; i * i <= a; i += (i & 1 ? 2 : 1))
//         if (a % i == 0) {
//             pm[++tot] = i;
//             while (a % i == 0)
//                 cnt[tot]++, a /= i;
//         }
//     if (a != 1)
//         pm[++tot] = a, cnt[tot]++; //要判断一下A本身是不是素数
//     for (R i = 1; i <= tot; i++)
//         ans = (ans * (sum(pm[i], cnt[i] * b) % mod)) % mod;
//     printf("%d\n", ans);
// }