#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<' ';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
const int N = 1e6+10;
int n, m, tot, cnt, last;
int fail[N], len[N], ch[N][26];
int f[N], p[N], val[N];
char s[N], ss[N];
ll ans[N];

int getfail(int x) {
    while (ss[cnt-len[x]-1]!=ss[cnt]) x=fail[x];
    return x;
}
void insert(int c, int pos) {
    ss[++cnt] = c;
    int p = getfail(last);
    if (!ch[p][c]) {
        len[++tot] = len[p]+2;
        fail[tot] = ch[getfail(fail[p])][c];
        ch[p][c] = tot;
        val[tot] = val[p]|(1<<c);
//        p[tot] = pos;
    }
    last = ch[p][c], ++f[last];
}
void clear() {
    REP(i,0,tot) {
        memset(ch[i],0,sizeof ch[0]);
        len[i]=fail[i]=f[i]=val[i]=0;
    }
    ss[0]='#',fail[0]=1,last=0;
    len[0]=0,len[1]=-1,tot=1,cnt=0;
}

int main() {
    while (~scanf("%s", s+1)) {
        n = strlen(s+1);
        clear();
        REP(i,1,n) ans[i] = 0;
        REP(i,1,n) {
            s[i] -= 'a';
            insert(s[i],i);
        }
        PER(i,2,tot) f[fail[i]]+=f[i];
        ll ans = 0;
        REP(i,2,tot) {
            ans += (ll)f[i]*__builtin_popcount(val[i]);
        }
        printf("%lld\n", ans);
    }
}