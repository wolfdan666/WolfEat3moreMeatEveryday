#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const int base = 233;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;

int x[N], y[N], tot;
set<int> cnt[N];
set<pii> st;

int Hash(pii tp) {
    int x = tp.fi, y = tp.se;
    int tmp = ((base*x+y)%N+N)%N;
    return tmp;
}

int main() {
    int n;
    scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%d%d", &x[i], &y[i]);
    }
    rep(i, 1, n) {
        rep(j, i, n) {
            pii tp = mk((x[i]+x[j]), (y[i]+y[j]));
            st.insert(tp);
            int id = Hash(tp);
            cnt[id].insert(i);
            cnt[id].insert(j);
        }
    }
    int ans = 0;
    rep(i, 0, N-1) {
        ans = max(ans, (int)cnt[i].size());
    }
    printf("%d\n", n-ans);


    return 0;
}