#include<bits/stdc++.h>
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
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



#ifdef ONLINE_JUDGE
const int N = 1e5+50;
#else
const int N = 1e2+10;
#endif


char s[N],p[N];
int n,m;
const int bas = 233;
int get(int *a) {
    int ret = 0;
    REP(i,0,25) {
        // 给hash基底为1
        ret=((ll)ret*bas+a[i]+1)%P;
    }
    return ret;
}
struct node {
    char S,T;
    int sta,id;
};
vector<node> g[N];
unordered_map<int,int> f[26][26];
int ans[N],fac[N];


void work() {
    scanf("%s",s+1);
    n = strlen(s+1);
    REP(i,1,n) g[i].clear();
    scanf("%d",&m);
    REP(i,1,m) {
        scanf("%s",p+1);
        int len=strlen(p+1);
        node ret;
        ret.S=p[1],ret.T=p[len],ret.id=i;
        int cnt[26]{};
        REP(i,1,len) ++cnt[p[i]-'a'];
        ret.sta=get(cnt);
        g[len].pb(ret);
    }
    REP(i,1,m) ans[i]=0;
    REP(len,1,n) if (g[len].size()) {
        REP(i,0,25) REP(j,0,25) f[i][j].clear();
        int cnt[26]{};
        REP(i,1,len) ++cnt[s[i]-'a'];
        int sta = get(cnt);
        for (int L=1,R=len; R<=n; ++L,++R) {
            ++f[s[L]-'a'][s[R]-'a'][sta];
            sta = (sta-fac[25-(s[L]-'a')])%P;
            sta = (sta+fac[25-(s[R+1]-'a')])%P;
            if (sta<0) sta+=P;
        }
        for(auto &&t:g[len]) {
            ans[t.id] = f[t.S-'a'][t.T-'a'][t.sta];
        }
    }
    REP(i,1,m) printf("%d\n",ans[i]);
}

int main() {
    fac[0]=1;
    REP(i,1,30) fac[i]=(ll)fac[i-1]*bas%P;
    int t;
    scanf("%d",&t);
    while (t--) work();
}