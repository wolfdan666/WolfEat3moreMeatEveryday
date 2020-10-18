#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

long double a[maxn];
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        long double tp = 1.0, mx = 0.0;
        for(int i = 1; i <= n; i++) {
            scanf("%Lf", &a[i]);
            tp *= (1.0-a[i]);
            mx = max(mx, a[i]);
        }
        long double ans;
        if(mx >= 0.5) ans = mx;
        else {
            ans = 0.0;
            for(int i = 1; i <= n; i++) {
                if(a[i] < 0.5) ans += a[i]*tp/(1-a[i]);
            }
        }

        printf("%.12Lf\n", ans);
    }

    return 0;
}