#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int a[maxn], b[maxn], c[maxn];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        /*c[i]记录的是a[i]的上一个位置加1的位置*/
        c[i] = b[a[i]]+1;
        b[a[i]] = i;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += 1LL*(n-i+1)*(i-c[i]+1);
    }
    printf("%lld\n", ans);

    return 0;
}