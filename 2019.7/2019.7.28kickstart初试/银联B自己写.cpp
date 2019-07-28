/*
第一次写 数论分块，写了好几个bug
2019年7月28日20:49:32 数论分块只过了70%...
2019年7月28日21:24:54 找到bug，bug是因为除号必须在mod前！
ll ans = (n*(n+1)/2%mod)*n;
// ll ans = n*n%mod*(n+1)/2%mod;
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll n,m;
ll inv6;

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

ll f(ll n){ return n*(n+1)%mod*(2*n+1)%mod*inv6%mod;}
ll solve(ll n){
    ll ans = (n*(n+1)/2%mod)*n;
    // ll ans = n*n%mod*(n+1)/2%mod;
    for(int i=1,j;i<=n;i=j+1){
        /*i=j+1,以及n/i要加括号*/
        j = n/(n/i);
        /*其实j不会大于n*/
        if(j>n) j=n;
        ans = (ans - (f(j)-f(i-1))*(n/i)%mod + mod)%mod;
        /*只要保证每次相减时两个都是正数
        然后结果再来一次保证正数操作就不会出错*/
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    inv6 = qpow(6,mod-2);
    cin>>n>>m;
    ll ans = solve(n)*solve(m)%mod;
    cout<<ans<<endl;
    return 0;
}