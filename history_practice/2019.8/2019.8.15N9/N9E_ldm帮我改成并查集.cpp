/*
错误原因，团里面的size是相乘的，而我直接相加了...

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

ll C[maxn][5];
int p[maxn], sz[maxn], cnt[maxn];
int n, m;
int tot;
int now, tuancnt, sum;

void init() {
    for(int i = 0; i < maxn; i++) C[i][0] = 1;
    for(int i = 1; i < maxn; i++) {
        for(int j = 1; j < 5&&j<=i; j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
}

int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if(fx != fy) {
        if(fx > fy) swap(fx, fy);
        p[fx] = fy;
        if(sz[fx] > 1) tuancnt--;
        cnt[sz[fx]]--;
        if(sz[fy] > 1) tuancnt--;
        cnt[sz[fy]]--;
        sz[fy] += sz[fx];
        cnt[sz[fy]]++;
        if(sz[fy] > 1) tuancnt++;

    }
}


int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    cnt[1] = n;
    printf("%lld\n", C[n][4]);
    tuancnt = 0;
    while(m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        Union(u, v);
        ll ans = 0;
        now = cnt[1], sum = n-cnt[1];

        if(now+tuancnt<4){cout<<0<<endl; continue;}
        if(now>=4){
            for(int i=0;i<=4 && i<=tuancnt;i++){
                if(i==0) {ans+=C[now][4];continue;}
                ans += C[now][4-i]*(C[tuancnt][i]*i/tuancnt*sum);
            }
        }
        else{
            for(int i=0;i<=now;i++){
                int j = 4 - i;
                ans += C[now][i]*(C[tuancnt][j]*j/tuancnt*sum);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}