#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<=b; i++)
#define drep(i, a, b) for (int i=a; i>=b; i--)
#define inf 1e9
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=2001000;
char s[maxn];
ll ten[maxn];
int n;
struct Ptree {
    int last;
    struct Node {
        int cnt, lenn, fail, son[10];
        ll num;
        Node(int lenn, int fail):lenn(lenn), fail(fail), cnt(0){
            memset(son, 0, sizeof(son));
        };
    };
    vector<Node> st;
    inline int newnode(int lenn, int fail=0) {
        st.emplace_back(lenn, fail);
        return st.size()-1;
    }
    inline int getfail(int x, int n) {
        while (s[n-st[x].lenn-1] != s[n]) x=st[x].fail;
        return x;
    }
    inline void extend(int c, int i) {
        int cur=getfail(last, i);
        if (!st[cur].son[c]) {
            int nw=newnode(st[cur].lenn+2, st[getfail(st[cur].fail, i)].son[c]);
            if (st[nw].lenn == 1) st[nw].num=c;
            else if (st[nw].lenn == 2) st[nw].num=c*10+c;
            else st[nw].num=((c+st[cur].num*10)%mod+c*ten[st[cur].lenn+1])%mod;
            st[cur].son[c]=nw;
        }
        st[ last=st[cur].son[c] ].cnt++;
    }
    void init() {
        scanf("%s", s+1);
        n=strlen(s+1);
        s[0]=0;
        newnode(0, 1), newnode(-1);
        last=0;
        ten[0]=1;
        rep(i, 1, maxn-1) ten[i]=ten[i-1]*10%mod;
        rep(i, 1, n) extend(s[i]-'0', i);
    }
    ll count() {
        ll ans=0;
        rep(i, 2, st.size()-1) ans=(ans+st[i].num)%mod;
        return ans;
    }
}T;
int main() {
    T.init();
    printf("%lld\n", T.count());
}