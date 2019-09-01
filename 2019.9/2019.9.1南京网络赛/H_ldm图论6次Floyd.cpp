#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, b, a) for(int i = b; i >= a; i--)
#define fi first
#define se second
const int mod = 1e9 + 7;
const ll inf = 1e18;
const int N = 100000 + 5;

ll dis[305][305];
int n, m;
void floyd() {
    rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        rep(i, 1, n) rep(j, 1, n) dis[i][j] = inf;
        rep(i, 1, n) dis[i][i] = 0;
        rep(i, 1, m) {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            x++; y++;
            dis[x][y] = (ll)w;
        }

        //floyd();
        rep(i, 1, 6) {
            int x, y;
            scanf("%d%d", &x, &y);
            x++; y++;
            floyd();
            //printf("%lld\n", dis[y][x]);
            printf("%lld\n", -dis[y][x]);
            dis[x][y] = -dis[y][x];
        }
    }


    return 0;
}