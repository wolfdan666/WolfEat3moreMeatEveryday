#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 20;

ll cnt[maxn];
ll C[maxn][maxn];
ll POW[maxn];


void init() {
    for(int i = 0; i < maxn; i++) C[i][0] = 1;
    for(int i = 1; i < maxn; i++) {
        for(int j = 1; j < maxn; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    POW[0] = 1;
    for(int i = 1; i < maxn; i++) POW[i] = POW[i-1]*9;
}


int Len(ll x) {
    int res = 0;
    while(x) {
        res++;
        x /= 10;
    }
    return res;
}


ll res;
int a[maxn];
int tot;
void dfs(int cur, int num, int d) {
    if(cur < 0) {
        res += num;
        return;
    }
    for(int i = 0; i < a[cur]; i++) {
        if(i == d) res += POW[cur]+cnt[cur];
        else res += cnt[cur];
        return;
    }
    dfs(cur-1, num+(a[cur]==d), d);
}



ll f(int d, ll k) {
    res = 0;
    int len = Len(k);
    for(int i = 1; i < len; i++) {
        for(int j = 1; j <= 9; j++) {
            if(j == d) res += POW[i-1]+cnt[i-1];
            else res += cnt[i-1];
        }
    }
    ll tp = k;
    tot = 0;
    while(tp) {
        a[tot++] = tp%10;
        tp /= 10;
    }
    dfs(tot-2, 0, d);
    if(a[tot-1] == d) res += POW[tot-1];
    for(int i = 1; i < a[tot-1]; i++) {
        if(i == d) res += POW[tot-1]+cnt[tot-1];
        else res += cnt[tot-1];
    }
    return res;
}



int main() {
    init();
    for(int i = 1; i < maxn; i++) {
        cnt[i] = 0;
        for(int j = 1; j <= i; j++) {
            cnt[i] += j*C[i][j]*POW[i-j];
        }
    }
    int T; scanf("%d", &T);
    while(T--) {
        int d; ll x;
        scanf("%d%lld", &d, &x);
        while(f(d, x) != x) {
            x--;
        }
        printf("%lld\n", x);
    }


    return 0;
}