#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 5;

priority_queue<pii> q;
int n;
int a[maxn], b[maxn];

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        while(!q.empty()) q.pop();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i], &b[i]);
            if(a[i]) q.push(make_pair(a[i], i));
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            while(!q.empty()) {
                pii u = q.top(); q.pop();
                //cout<<i<<" "<<u.fi<<" "<<u.se<<endl;
                if(u.se == i) {
                    if(q.empty()) {
                        q.push(u); break;
                    }
                    else {
                        pii v = q.top(); q.pop();
                        ll det = min(b[i], v.fi);
                        if(v.fi > b[i]) q.push(make_pair(v.fi-b[i], v.se));
                        q.push(u);
                        ans += det;
                        b[i] -= det;
                    }
                } else {
                    ll det = min(b[i], u.fi);
                    if(u.fi > b[i]) q.push(make_pair(u.fi-b[i], u.se));
                    ans += det; b[i] -= det;
                }
                if(!b[i]) break;
            }
        }
        printf("%lld\n", ans);
    }


    return 0;
}