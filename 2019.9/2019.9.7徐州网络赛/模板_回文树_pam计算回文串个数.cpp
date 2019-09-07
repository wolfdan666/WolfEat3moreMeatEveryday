#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<=b; i++)
#define drep(i, a, b) for (int i=a; i>=b; i--)
#define inf 1e9
using namespace std;
typedef long long ll;
const int maxn=300010;
char s[maxn];
int n;
struct Ptree {
    int last;
    struct Node {
        int cnt, lenn, fail, son[27];
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
        rep(i, 1, n) extend(s[i]-'a', i);
    }
    ll count() {
        drep(i, st.size()-1, 0) st[st[i].fail].cnt+=st[i].cnt;
        ll ans=0;
        rep(i, 2, st.size()-1) ans=max(ans, 1LL*st[i].lenn*st[i].cnt);
        return ans;
    }
}T;
int main() {
    T.init();
    printf("%lld\n", T.count());
}