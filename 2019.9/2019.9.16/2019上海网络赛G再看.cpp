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

// 手写的Hash,因为unorder_map<int,int> f[26][26]被卡时间
namespace Hash{
  const int hashmod = 218357;
  int v[hashmod];
  unsigned long long h[hashmod];
  int vis[hashmod];
  int &get(unsigned long long S) {
    int t2 = S % hashmod, i;
    // vis[i]是访问过的(clk恒为1)，所以也要走下一个
    // h[i] = S.则发生了hash crash(哈希碰撞)，就要走到下一个，也就是h[i] != S 走下一个
    // i = t2-1说明走了一个轮回了，就不用再走了，再走就是重复走t2位置了,所以i!=t2-1
    for (i = t2; vis[i]==clk && h[i] != S && i != t2 - 1; i = (i + 1) % hashmod);
    // 从未访问过的要初始化计数值为0
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
            // 左边字符基底为一个fac,而右边为fac^0=1
            sta = sta+(s[L+1]-s[L])*fac[1];
            sta = sta+(ll)(s[R+1]-s[R]);
            // 下面是右移一位整体的字母表的hash值变化
            sta = sta-fac[27-(s[L]-'a')];
            sta = sta+fac[27-(s[R+1]-'a')];
        }
        // 这个t长度下,把各次提问的ans更新
        // hash是这个头尾相同，中间的串是不同排列的  询问串(key) ————> 原串中的个数(value)
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