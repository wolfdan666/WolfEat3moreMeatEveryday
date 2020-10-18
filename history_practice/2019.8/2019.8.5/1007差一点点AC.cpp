// a[i] = a[i-1]+a[i-3],就是对于第i项有两种情况，要么是直接往上走要么是走闪电

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

ll a[maxn];

int main() {
    a[1] = a[2] = a[3] = 1;
    for(int i = 4; i < maxn; i++) a[i] = (a[i-1]+a[i-3])%mod;
    int T; scanf("%d", &T);
    while(T--) {
        int n, l, r;
        scanf("%d%d%d", &n, &l, &r);
        if(l > r) swap(l, r);
        if(l != 1) l++;
        if(r != n) r--;
        printf("%lld\n", a[r-l+1]);
    }

    return 0;
}