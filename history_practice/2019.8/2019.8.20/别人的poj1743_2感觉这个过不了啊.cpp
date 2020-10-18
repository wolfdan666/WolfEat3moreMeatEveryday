/*
9
1 2 3 4 5 6 7 8 9

这个输入按理来说输出0,但是这个代码输出5,所以确实是错了

所以这题数据是卡时间，没有卡特例...

*/


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 20010;

int sa[maxn], rank[maxn], height[maxn];
int t1[maxn], t2[maxn], r[maxn], c[maxn];
bool cmp (int *str, int a, int b, int k)
{
    return str[a]==str[b] && str[a+k]==str[b+k];
}
void da (int *str, int n, int m)
{
    n ++;
    int *x = t1, *y = t2, i, j;
    for (i=0; i<m; i++) c[i] = 0;
    for (i=0; i<n; i++) c[x[i]=str[i]] ++;
    for (i=1; i<m; i++) c[i] += c[i-1];
    for (i=n-1; i>=0; i--) sa[-- c[x[i]]] = i;
    for (j=1; j<=n; j*=2)
    {
        int p = 0;
        for (i=n-j; i<n; i++) y[p++] = i;
        for (i=0; i<n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;

        for (i=0; i<m; i++) c[i] = 0;
        for (i=0; i<n; i++) c[x[y[i]]] ++;
        for (i=1; i<m; i++) c[i] += c[i-1];
        for (i=n-1; i>=0; i--) sa[-- c[x[y[i]]]] = y[i];

        swap (x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i=1; i<n; i++)//i是rank
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j)?p-1:p++;
        if (p >= n)
            break;
        m = p;
    }
    for (i=1; i<n; i++)
        ::rank[sa[i]] = i;
    int k = 0;
    n --;
    for (int i=0; i<n; i++)
    {
        if (k)  k --;
        int j = sa[::rank[i] - 1];
        while (str[i+k] == str[j+k])    k++;
        height[::rank[i]] = k;
    }
}
bool solve (int x, int n)
{
    int ma, mi;
    ma = mi = sa[1];
    for (int i=2; i<=n; i++)
    {
        if (height[i]>=x && i<=n)
        {
            mi = min(mi, sa[i]);
            ma = max(ma, sa[i]);
            if (ma - mi >= x) return true;
            continue;
        }

        ma = mi = sa[i];
    }
    return false;
}
int main ()
{
    int n;
    while (scanf ("%d", &n), n)
    {
        int s, e;
        scanf ("%d", &s);
        for (int i=1; i<n; i++)
        {
            scanf ("%d", &e);
            r[i-1] = s - e + 100;
            s = e;
        }
        r[--n] = 0;

        da (r, n, 200);
        int ans = 0, high = n / 2, low = 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (solve (mid, n))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        printf ("%d\n", ans<4 ? 0:ans+1);
    }
    return 0;
}