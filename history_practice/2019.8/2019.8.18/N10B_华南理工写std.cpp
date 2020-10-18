#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+5;
const int maxk=2e3+5;
const ll mod=1e9;
ll f[505];
string s="0COFFEE";
string t="0CHICKEN";
void dfs(ll n,ll k)
{
    if(n==2)
    {
        putchar(t[k]);
        return;
    }
    else if(n==1)
    {
        putchar(s[k]);
        return;
    }

    if(f[n-2]>=k) dfs(n-2,k);
    else dfs(n-1,k-f[n-2]);
}
int main()
{
    f[1]=6;f[2]=7;
    for(int i=3;i<=500;i++)
    {
        f[i]=min(f[i-2]+f[i-1],ll(1e13));
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        for(ll i=k;i<=k+9&&i<=f[n];i++)
        {
            dfs(n,i);
        }
        puts("");
    }
}