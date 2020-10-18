/*
转载自大佬
https://www.cnblogs.com/Dillonh/p/11209476.html?tdsourcetag=s_pctim_aiomsg

qpow(2,mod-2)---> 这就是q^(-1)   --> 逆元... 数学基础知识都忘了...

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<LL, int> pLi;
typedef pair<int, LL> pil;;
typedef pair<int, int> pii;
typedef unsigned long long uLL;

#define lson rt<<1
#define rson rt<<1|1
#define lowbit(x) x&(-x)
#define name2str(name) (#name)
#define bug printf("*********\n")
#define debug(x) cout<<#x"=["<<x<<"]" <<endl
#define FIN freopen("D://Code//in.txt","r",stdin)
#define IO ios::sync_with_stdio(false),cin.tie(0)

const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n;
int a[maxn], inv[maxn], cnt[maxn];

LL qpow(LL x, int n) {
    LL res = 1;
    while(n) {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int tmp = qpow(2, mod - 2);
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++i) {
            cnt[i] = 1;
            for(int j = 1; j <= n; ++j) {
                if(i == j) continue;
                cnt[i] = 1LL * cnt[i] * ((1LL * a[j] * a[j] % mod - 1LL * a[i]* a[i] % mod) % mod + mod) % mod;
            }
            /* 分母都要乘以同余模 */
            cnt[i] = qpow(cnt[i], mod - 2);
            cnt[i] = 1LL * cnt[i] * qpow(a[i], mod - 2) % mod;
            cnt[i] = 1LL * cnt[i] * tmp % mod;
        }
        LL ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = ((ans + cnt[i]) % mod + mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
