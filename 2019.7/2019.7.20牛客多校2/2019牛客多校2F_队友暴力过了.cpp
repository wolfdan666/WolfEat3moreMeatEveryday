/*
感觉队友的暴力写的真好...自己好菜呀

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

ll d[50][50];
int a[50], b[50];
int N;
int cnt1, cnt2;
ll ans;

void dfs(int cur, ll val) {
    if(cur > 2*N) {
        ans = max(ans, val);
        return;
    }
    ll tp;
    /*cnt1或者cnt2选择当前值,这样递归下去*/
    if(cnt1 < N) {
        a[cnt1++] = cur;
        tp = 0;
        /*与cnt2比较的竞争值*/
        for(int i = 0; i < cnt2; i++) tp += d[cur][b[i]];
        dfs(cur+1, tp + val);
        cnt1--;
    }
    if(cnt2 < N) {
        b[cnt2++] = cur;
        tp = 0;
        for(int i = 0; i < cnt1; i++) tp += d[a[i]][cur];
        dfs(cur+1, tp + val);
        cnt2--;
    }

}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= 2*N; i++) {
        for(int j = 1; j <= 2*N; j++) {
            scanf("%d", &d[i][j]);
        }
    }
    ans = 0;
    dfs(1, 0);
    printf("%lld\n", ans);

    return 0;
}