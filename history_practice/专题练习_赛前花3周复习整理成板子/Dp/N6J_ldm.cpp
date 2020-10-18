#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;

ll c[maxn][maxn], d[maxn];
int Log[maxn];
ll f[maxn][maxn][12];
ll sum[maxn][maxn];
int n, m;

void init() {
    Log[1] = 0;
    for(int i = 2; i < maxn; i++) Log[i] = Log[i/2] + 1;
}

/*2019年8月3日16:16:39 ldm 找到了bug
-->   m写成n了
-->   吧n改回m就过了
这样如果n<m就会出问题！
*/
void st_pre(int id) {
    for(int i = 1; i <= m; i++) f[id][i][0] = sum[id][i];
    int t = Log[m]+1;
    for(int j = 1; j < t; j++) {
        for(int i = 1; i <= m-(1<<j)+1; i++) {
            f[id][i][j] = min(f[id][i][j-1], f[id][i+(1<<(j-1))][j-1]);
        }
    }
}

ll ask(int l, int r, int id) {
    if(l > r) return 0;
    int k = Log[r-l+1];
    //cout<<id<<" "<<l<<" "<<r<<" "<<k<<" "<< f[id][l][k]<<" "<<f[id][r-(1<<k)+1][k]<<endl;
    return min(f[id][l][k], f[id][r-(1<<k)+1][k]);
}

vector<ll> V;
int main() {
    init(); int kase = 0;
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 0; k < 12; k++) {
                    f[i][j][k] = inf;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%lld", &c[i][j]);
                sum[i][j] = sum[i][j-1] + c[i][j];
            }
            st_pre(i);
        }
        for(int i = 1; i <= m; i++) scanf("%lld", &d[i]);
        /*tp是已经得到的，cur是消耗的*/
        ll ans = 0, tp = 0, cur = 0;
        for(int i = 0; i <= m; i++) {
            tp += d[i];
            cur = 0;
            /*最开始i=0列是空的*/
            for(int j = 1; j <= n; j++) cur += sum[j][i];
            V.clear();
            if(i < m) {
                for(int j = 1; j <= n; j++) V.push_back(ask(i+1, m, j)-sum[j][i]);
                sort(V.begin(), V.end());
                /*V.size()不能全取啊...全取不久又加一个d了*/
                for(int j = 0; j < V.size()-1; j++) {
                    if(V[j] >= 0) break;
                    cur += V[j];
                }
            }
            //cout<<i<<" "<<tp<<" "<<cur<<endl;
            ans = max(ans, tp-cur);
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }


    return 0;
}