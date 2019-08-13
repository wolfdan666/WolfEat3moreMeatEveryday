/*
题目链接：https://nanti.jisuanke.com/t/40549
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,p,ans;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>p;
        ans = 0;
        ll x = n/p;
        for(ll r = 0; r < p ; r++ ){
            /*求出b的种类数*/
            ll bn = m/(p/__gcd(r,p));
            /*分别对应题解的1,2,3种情况,其实1,3可以合并*/
            if(!r) ans+=x*bn;
            else if(0<r && r<=n%p) ans+=(x+1)*bn;
            else ans+=x*bn;
        }
        cout<<ans<<endl;

    }

    return 0;
}