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



const int N = 1100;
int a[N],n;
int ans;
set<multiset<int> > s;
void dfs(int d, int sum) {
    // sum是两个数的加和,d是第几个数
    if (sum>2*n) return;
    if (d>n) {
        int s1=0,s2=1;
        REP(i,1,n) s1+=a[i],s2*=a[i];
        if (s1!=s2) return;
        ++ans;
        s.insert(multiset<int>(a+1,a+1+n));
        return;
    }
    REP(i,1,n) a[d]=i,dfs(d+1,sum+i);
}

int main() {
    cin>>n;
    dfs(1,0);
    cout<<ans<<endl;
    for(auto t:s) {
        int s=0;
        for(auto a:t) cout<<a<<',',s+=a;
        cout<<s<<endl;
    }
}