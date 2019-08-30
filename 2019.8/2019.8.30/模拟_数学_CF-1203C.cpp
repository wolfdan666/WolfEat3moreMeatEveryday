/*
2019年8月30日21:29:58 开始看题
样例2感觉和我理解的题意不一样  --- > 2019年8月30日21:34:16 去看tutorial
果然理解错了，不是求出g(见下面),而是要求出g的约数个数！

Let g=gcd(a1,a2,…,an) is the greatest common divisor of all elements of the array.
You can find it by Euclidean algorithm or some standard library functions.
 Then the answer is just the number of divisors of g. You can find this value in √g.

2019年8月30日21:45:23 走人(15mins)
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    long long g = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        g = __gcd(g, x);
    }

    int ans = 0;
    for (int i = 1; i * 1ll * i <= g; ++i) {
        if (g % i == 0) {
            ++ans;
            if (i != g / i) {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}