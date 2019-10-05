#include <bits/stdc++.h>
#define scll(x) scanf("%lld", &x)
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", &x)
#define ptf(x) printf("%d", x)
#define ptfs(x) printf("%s", x)
#define ptfb printf(" ");
#define ptfll(x) printf("%lld", x)
#define pts puts("")
#define rep(i, x, n) for(int i = x; i <= n; i++)
#define per(i, x, n) for(int i = n; i >= x; i--)
#define met(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double eps = 1e-8;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 6;
ll qpow(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % MOD;a = a * a % MOD;b >>= 1;}return ans;}
ll inv(ll a) {return qpow(a, MOD - 2);}
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
int h, c, r[1050], w[1050], mp[1050][1050];
int main() {
    while(cin >> h >> c) {
        rep(i, 1, h) cin >> r[i];
        rep(i, 1, c) cin >> w[i];
        bool flag = 1;
        met(mp);
        rep(i, 1, h) {
            rep(j, 1, r[i]) {
                mp[i][j] = 1;
            }
            mp[i][r[i] + 1] = 2;
        }
        rep(i, 1, c) {
            rep(j, 1, w[i]) {
                //cout << "mp " <<  mp[j][i] << endl;
                if(mp[j][i] == 2) {
                    flag = 0;
                    break;
                }
                else mp[j][i] = 1;
            }
            //cout << flag << endl;
            if(flag == 0) break;
            if(mp[w[i] + 1][i] == 1) {
                flag = 0;
                break;
            }
            else mp[w[i] + 1][i] = 2;
        }
        //cout << h << " " << c << endl;
        /* rep(i, 1, h) {
            rep(j, 1, c) {
                cout << mp[i][j]<< " ";
            }
            cout << endl;
        } */
        int cnt = 0;
        rep(i, 1, h) {
            rep(j, 1, c) {
                if(mp[i][j] == 0) cnt++;
            }
        }
        if(flag == 0) cout << 0 << endl;
        else cout << qpow(2, cnt) % MOD << endl;
    }
    return 0;
}