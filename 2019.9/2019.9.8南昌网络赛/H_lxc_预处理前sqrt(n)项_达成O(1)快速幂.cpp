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
const int P = 998244353;
const int sqr = 473844410;
const int C = 438914993;
const int A = 262199973;
const int B = 736044383;
const int N = 2e6+10,S = N-100;
int fa[N],fb[N];
int ffa[N],ffb[N];
int qpow(int *f, int *ff, int a, int n) {
    return (ll)ff[n/S]*f[n%S]%P;
}

int solve(ll n) {
    n %= P-1;
    return (ll)C*(qpow(fb,ffb,B,n)-qpow(fa,ffa,A,n))%P;
}

int main() {
    fa[0]=fb[0]=1;
    REP(i,1,S) {
        fa[i]=(ll)fa[i-1]*A%P;
        fb[i]=(ll)fb[i-1]*B%P;
    }
    ffa[0]=ffb[0]=1;
    REP(i,1,S) {
        ffa[i]=(ll)ffa[i-1]*fa[S]%P;
        ffb[i]=(ll)ffb[i-1]*fb[S]%P;
    }
    int q;
    ll n;
    cin>>q>>n;
    int ans = 0;
    REP(i,1,q) {
        int ret = solve(n);
        if (ret<0) ret+=P;
        ans ^= ret;
        n ^= (ll)ret*ret;
    }
    printf("%d\n",ans);
}

