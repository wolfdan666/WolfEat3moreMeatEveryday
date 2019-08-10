#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
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
    for(int i=1;i<=n;i++) cout<<c[i]<<" "; cout<<endl;
    for(int i = 1; i <= n; i++) {
        /*最后一项表示前面的区间的贡献量
        前面一项表示*/
        ans += 1LL*(n-i+1)*(i-c[i]+1);
        cout<<(n-i+1)<<" ";
        cout<<(i-c[i]+1)<<" ";
        cout<<(n-i+1)*(i-c[i]+1)<<endl;
    }
    printf("%lld\n", ans);

    return 0;
}