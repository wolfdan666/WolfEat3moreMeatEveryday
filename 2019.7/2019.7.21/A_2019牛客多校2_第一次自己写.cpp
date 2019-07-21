/*
2019年7月21日17:36:17
发现自己动手写的时候发现自己连最简单的快速幂都敲不动...

原来自己学习的是"哑巴算法与数据结构"--> 自己犯下了当年自己嘲笑他们不愿意动手的错误...原来自己也是这样的

所以以后任何自己必须掌握的技术和能力都要实现多次！
之所以覃超看起来讲的课没深度，却能拿一个区域赛的金牌的原因大概就是多敲算法吧

因为其实区域赛金牌也没有用到太多高深的算法，关键是要把所有基础算法掌握扎实，然后快速熟练地实现即可！
好的，以后一定多实现！

#define mod 1e9+7 // 这个会导致很多错误！
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
int T,n,m;
ll ans;

ll mul(ll a,ll b){
    a *= b;
    return a>=mod?a%mod:a;
}

ll qpow(ll a,ll b){
    ll ret = 1;
    while(b){
        if(b&1) ret = mul(a,ret);
        /* b>>1,那么a就要变成a*a */
        b>>=1;
        a = mul(a,a);
    }
    return ret;
}

ll inv(ll a){ return qpow(a,mod-2); }

ll solve(ll n,ll m){
    if(n==1) return 1;
    if(m==0) return 0;
    return inv(n-1);
}

int main(){
    ios::sync_with_stdio(false);
    /*init*/
    ans = 1;
    cin>>T;
    while(T--){
        cin>>n>>m;
        /*solve*/
        ans = mul(ans,solve(n,m));
        cout<<ans<<endl;
    }
    return 0;
}