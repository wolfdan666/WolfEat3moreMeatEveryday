/*
自己想了半天没有想明白，然后看到了中国传媒大学的一个队伍提交里面的注释，
感受到注释真是个好东西

当合并这两个集合的时候，应该将这两个集合合并后消失的贡献减去
消失的贡献就应该是选择了一个a，选择了一个b，从剩下的众多集合中选择两个
(即cd,ce,ef......)那么这个怎么算呢，可以用完全平方公式来推导
(a+b+c+d)^2=a^2+b^2+c^2+d^2+2ab+2ac+2bc+2ad+2bd+2cd
所以众多集合中选择任意选择两个的情况可以用（和的平方-平方的和）/2来求（最重要的一步）


*/


#include <bits/stdc++.h>

using ll = long long;
const int MAXN = 100010;

int n, m;
int f[MAXN], sz[MAXN];
ll sum;

inline ll sqr(int x) {
    return 1ll * x * x;
}

inline int getf(int x) {
    return f[x] == x ? x : (f[x] = getf(f[x]));
}

int main() {
    scanf("%d%d", &n, &m);
    ll ans = (__int128) n * (n - 1) * (n - 2) * (n - 3) / 24;
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        sz[i] = 1;
    }
    /*最开始的平方和*/
    sum = n;
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        u = getf(u);
        v = getf(v);
        if(ans==0 || u==v) goto END;
        if (u != v) {
            /*减掉合并部分的平方和*/
            sum -= sqr(sz[u]) + sqr(sz[v]);
            /*后面的(sqr(n - sz[u] - sz[v]) - sum) / 2;就是`和的平方`-`平方和`=`剩下的所有两两组合`*/
            ll tmp = 1ll * sz[u] * sz[v] * (sqr(n - sz[u] - sz[v]) - sum) / 2;
            f[u] = v;
            sz[v] += sz[u];
            /*新的平方和的维护*/
            sum += sqr(sz[v]);
            /*减去合并减少的贡献值*/
            ans -= tmp;
        }
        END:
        printf("%lld\n", ans);
    }
    return 0;
}