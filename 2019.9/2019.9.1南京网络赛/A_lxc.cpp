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
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



const int N = 1e6+50;
int n,m,p,cnt;
ll f[N][5],b[N];
pii pos[N][5];

int type(int x, int y) {
    int a=min(abs(x-1),abs(x-n));
    int b=min(abs(y-1),abs(y-n));
    return min(a,b)+1;
}
ll get(int x, int y) {
    int d = type(x,y);
    if (d==n/2+1) return (ll)n*n;
    if (x==pos[d][1].x) {
        return f[d][1]+pos[d][1].y-y;
    }
    if (y==pos[d][2].y) {
        return f[d][2]-x+pos[d][2].x;
    }
    if (x==pos[d][3].x) {
        return f[d][3]+y-pos[d][3].y;
    }
    return f[d][4]+x-pos[d][4].x;
}
int solve(int x, int y) {
    ll t = get(x,y);
    int ret = 0;
    while (t) ret+=t%10,t/=10;
    return ret;
}

struct _ {
    int h,w,type;
    void pr() {
    printf("h=%d,w=%d,type=%d\n",h,w,type);
    }
};
vector<_> e[N],ee[N];
void add(int x, int y, int v, int id) {
    e[x].pb({y,id,v});
}
ll ans[N];
ll cc[N];

ll query(int x) {
    ll ret = 0;
    for (; x; x^=x&-x) ret += cc[x];
    return ret;
}

void add(int x, int v) {
    for (; x<=n; x+=x&-x) cc[x]+=v;
}

void work() {
    cnt = 0;
    f[1][1] = 1;
    f[1][2] = n;
    f[1][3] = 2*n-1;
    f[1][4] = 3*n-2;
    pos[1][1] = pii(n,n);
    pos[1][2] = pii(n,1);
    pos[1][3] = pii(1,1);
    pos[1][4] = pii(1,n);
    int now = n-1;
    REP(d,2,n/2) {
        REP(j,1,4) pos[d][j]=pos[d-1][j];
        --pos[d][1].x,--pos[d][1].y;
        --pos[d][2].x,++pos[d][2].y;
        ++pos[d][3].x,++pos[d][3].y;
        ++pos[d][4].x,--pos[d][4].y;
        f[d][1] = f[d-1][4]+now;
        now -= 2;
        f[d][2] = f[d][1]+now;
        f[d][3] = f[d][2]+now;
        f[d][4] = f[d][3]+now;
    }
    REP(i,0,n+1) e[i].clear(),cc[i]=0,ee[i].clear();
    REP(i,1,m) {
        int x, y;
        scanf("%d%d", &x, &y);
        ee[x].pb({y,solve(x,y),-2});
    }
    REP(i,1,p) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        --x1,--y1;
        add(x2,y2,1,i);
        add(x2,y1,-1,i);
        add(x1,y2,-1,i);
        add(x1,y1,1,i);
        ans[i] =0;
    }
    REP(i,1,n) {
        for(auto t:ee[i]) add(t.h,t.w);
        for(auto t:e[i]) {
            ans[t.w] += t.type*query(t.h);
        }
    }
    REP(i,1,p) printf("%lld\n",ans[i]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) scanf("%d%d%d",&n,&m,&p),work();
}







