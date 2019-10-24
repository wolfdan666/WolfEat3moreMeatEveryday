#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int n, a[100], cnt;
string s[100];
int main() {
    int T; cin >> T;
    while(T--) {
        int x = 0, y = 0, cnt = 0;
        cin >> n;
        rep(i, 1, n) {
            cin >> s[i];
            int sz = s[i].size();
            rep(j, 0, sz-1) {
                if(s[i][j] == '1') x++;
                else y++;
            }
            a[cnt++] = sz;
        }
        sort(a, a+cnt);
        int ans = 0;
        rep(i, 0, cnt-1) {
            if(a[i] % 2 == 0) {
                if(x >= a[i]) x -= a[i], ans++;
                else if(y >= a[i]) y -= a[i], ans++;
                else {
                    for(int j = 0; j <= x; j += 2) {
                        if(a[i]-j <= y) {
                            x -= j;
                            y -= (a[i]-j);
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        rep(i, 0, cnt-1) {
            if(a[i] % 2 == 1) {
                // if(x >= a[i]) x -= a[i], ans++;
                // else if(y >= a[i]) y -= a[i], ans++;
                // else {
                //     int ok = 0;
                //     for(int j = 0; j <= x; j += 2) {
                //         if(a[i]-j <= y) {
                //             ok = 1;
                //             x -= j, y -= (a[i]-j), ans++;
                //         }
                //     }
                //     if(!ok) {
                //         for(int j = 1; j <= x; j += 2) {
                //             if(a[i]-j <= y) {
                //                 ok = 1;
                //                 x -= j, y -= (a[i]-j), ans++;
                //             }
                //         }
                //     }
                // }
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}