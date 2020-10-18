#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define rep(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
int n;
long long m;
long long a[1000005];
int q;

map<long long, long long> mp;
long long phi(long long x)
{
    long long xx=x;
    if(mp[x]!=0)
        return mp[x];
    long long ans=x;
    for(long long i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ans=ans/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    }
    if(x!=1)
        ans=ans/x*(x-1);

    return mp[xx]=ans;
}

long long MOD(long long a,long long b)
{
    if(a<b)
        return a;
    else
        return (a%b)+b;
}

long long powd(long long a,long long b,long long mod)
{
    long long ans=1;
    while(b>0)
    {
        if(b%2==1)
            ans=MOD(ans*a,mod);
        a=MOD(a*a,mod);
        b/=2;
    }
    return ans;
}

long long solve(int l,int r,long long mod)
{
    if(l==r || mod==1)
    {
        return MOD(a[l],mod);
    }
    else
    {
        return powd(a[l],solve(l+1,r,phi(mod)),mod);
    }
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        ll x, y, m;
        scanf("%lld%lld%lld", &x, &y, &m);
        rep(i, 1, y) a[i] = x;
        ll ans;
        if(y == 0) ans = 1;
        else ans = solve(1, y, m);
        printf("%lld\n", ans%m);
    }
    return 0;
}