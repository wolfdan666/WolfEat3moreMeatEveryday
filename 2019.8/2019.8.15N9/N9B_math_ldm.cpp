#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;
typedef long long LL;
const LL p = 1e9+7;

LL quick_mod(LL a, LL b, LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

struct T
{
    LL p, d;
};

LL w;

//二次域乘法
T multi_er(T a, T b, LL m)
{
    T ans;
    ans.p = (a.p * b.p % m + a.d * b.d % m * w % m) % m;
    ans.d = (a.p * b.d % m + a.d * b.p % m) % m;
    return ans;
}

//二次域上快速幂
T power(T a, LL b, LL m)
{
    T ans;
    ans.p = 1;
    ans.d = 0;
    while(b)
    {
        if(b & 1)
        {
            ans = multi_er(ans, a, m);
            b--;
        }
        b >>= 1;
        a = multi_er(a, a, m);
    }
    return ans;
}

//求勒让德符号
LL Legendre(LL a, LL p)
{
    return quick_mod(a, (p-1)>>1, p);
}

LL mod(LL a, LL m)
{
    a %= m;
    if(a < 0) a += m;
    return a;
}

LL Solve(LL n,LL p)
{
    if(p == 2) return 1;
    if (Legendre(n, p) + 1 == p)
        return -1;
    LL a = -1, t;
    while(true)
    {
        a = rand() % p;
        t = a * a - n;
        w = mod(t, p);
        if(Legendre(w, p) + 1 == p) break;
    }
    T tmp;
    tmp.p = a;
    tmp.d = 1;
    T ans = power(tmp, (p + 1)>>1, p);
    return ans.p;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        /* int n, p;
        scanf("%d %d",&n,&p);
        n %= p;
        int a = Solve(n, p);
        if(a == -1)
        {
            puts("No root");
            continue;
        }
        int b = p - a;
        if(a > b) swap(a, b);
        if(a == b)
            printf("%d\n",a);
        else
            printf("%d %d\n",a,b);*/
        LL b, c, x = -1, y = -1, x1, x2, y1, y2;
        scanf("%lld%lld", &b, &c);
        for(int i = 0; i < 2; i++) {
            LL d = b+1LL*i*p;
            LL tp = d*d-4*c;
            tp %= p;
            if(tp == 0) {
                y1 = d/2; x1 = d/2;
                if(0 <= x1 && x1 <= y1 && y1 < p && (x1+y1)%p == b && x1*y1%p == c) { x = x1; y = y1; }
                continue;
            }
            y1 = Solve(tp, p);
            if(y1 == -1) continue;
            y2 = p-y1;
            y1 = (y1+d)/2; y2 = (y2+d)/2;
            x1 = d-y1; x2 = d-y2;
            if(0 <= x1 && x1 <= y1 && y1 < p && (x1+y1)%p == b && x1*y1%p == c) { x = x1; y = y1; }
            if(0 <= x2 && x2 <= y2 && y2 < p && (x2+y2)%p == b && x2*y2%p == c) { x = x2; y = y2; }
        }
        printf("%lld %lld\n", x, y);
    }
    return 0;
}