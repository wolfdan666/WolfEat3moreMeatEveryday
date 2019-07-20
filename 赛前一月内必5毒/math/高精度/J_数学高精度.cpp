#include <iostream>
#include <cstdio>
using namespace std;
typedef __int128 ll;
int main() {
    long long x, a, y, b;
    while (scanf("%lld %lld %lld %lld", &x, &a, &y, &b) != EOF) {
        ll p = x; p *= b;
        ll q = y; q *= a;
        if (p > q) printf(">\n");
        else if (p == q) printf("=\n");
        else printf("<\n");
    }
    return 0;
}