#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;

int n, m;
int tot;
int vis[maxn], cnt[maxn];

int montekalo(int n) {
    int cur = 0, tp = 1;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    while(tp < n) {
        int x = rand()%2;
        if(x) cur = (cur+1) % n;
        else cur = (cur-1+n) % n;
        if(!vis[cur]) {
            vis[cur] = 1;
            tp++;
        }
    }
    return cur;
}

void gen(int n) {
    int tp = 0;
    while(tp <= 100000) {
        cnt[montekalo(n)]++;
        tp++;
    }
    for(int i = 0; i <= n; i++) cout<<i<<" "<<(double)(cnt[i]+0.0)/(100000)<<endl;
}

int main() {
    gen(11);

    return 0;
}