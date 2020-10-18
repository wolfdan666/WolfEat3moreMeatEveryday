#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define pre(i,a,n) for(int i=n;i>=a;--i)
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#ifdef ONLINE_JUDGE
    const int N = 1e5+50;
#else
    const int N = 1e2+10;
#endif

char s[N],p[N];
int n, m;
const int bas = 1e9+7;
ull get(int *a) {
    ull ret = 0;
    rep(i,0,27) {
        ret = ret*bas+a[i]+1;
    }
    return ret;
}
struct node {
    ull sta;
    int id;
};
vector<node> g[N];


int ans[N];
ull fac[N];

int clk;
/*
namespace Hash {
    const int hashmod = 1635947;
    int v[hashmod];
    ull h[hashmod];
    bool vis[hashmod];
    int &get(unsigned long long S) {
        int t2 = S%hashmod, i;
        for (i = t2; vis[i]==clk&&h[i]!=S; i = (i + 1) % hashmod);
        if (vis[i]!=clk) h[i] = S, vis[i] = clk, v[i] = 0;
        return v[i];
    }
};
*/

namespace Hash{
  const int hashmod = 218357;
  int v[hashmod];
  unsigned long long h[hashmod];
  int vis[hashmod];
  int &get(unsigned long long S) {
    int t2 = S % hashmod, i;
    for (i = t2; vis[i]==clk && h[i] != S && i != t2 - 1; i = (i + 1) % hashmod);
    if (vis[i]!=clk) h[i] = S, vis[i] = clk, v[i] = 0;
    return v[i];
  }
};

void solve() {
    scanf("%s",s+1);
    n = strlen(s+1);
    rep(i,1,n) g[i].clear();
    scanf("%d",&m);
    rep(i,1,m) {
        scanf("%s",p+1);
        int len = strlen(p+1);
        node ret;
        ret.id = i;
        int cnt[28]{};
        rep(i,1,len) ++cnt[p[i]-'a'];
        cnt[26] = p[1];
        cnt[27] = p[len];
        ret.sta = get(cnt);
        g[len].pb(ret);
    }
    rep(i,1,m) ans[i] = 0;
    rep(len,1,n) if (g[len].size()) {
        int cnt[28]{};
        // 中间的字母是按照字母顺序来的，所以就是可以的，然后最后两个是按照直接首尾字母来的
        rep(i,1,len) ++cnt[s[i]-'a'];
        cnt[26] = s[1];
        cnt[27] = s[len];
        ull sta = get(cnt);
        ++clk;
        for (int L=1,R=len; R<=n; ++L,++R) {
            ++Hash::get(sta);
            sta = sta+(s[L+1]-s[L])*fac[1];
            sta = sta+(ll)(s[R+1]-s[R]);
            sta = sta-fac[27-(s[L]-'a')];
            sta = sta+fac[27-(s[R+1]-'a')];
        }
        for (auto &&t:g[len]) ans[t.id] = Hash::get(t.sta);
    }
    rep(i,1,m) printf("%d\n",ans[i]);
}

int main() {
    fac[0]=1;
    rep(i,1,30) fac[i]=fac[i-1]*bas;
    int t;
    scanf("%d",&t);
    while (t--) solve();
}