/*
为什么卡在了样例五，提前取模样例五会出错...
对的，因为tp是次方,次方那里是不能提前取模的，但是这样就会超内存的..
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int T;ll a,b,m,ans;

ll mpow(ll a,ll b,ll m){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll a,b,m;
    cin>>T;
    while(T--){
        // ans = 0;
        ll tp = 1;
        cin >> a >> b >> m;
        if(b==0) { cout<<1<<endl; continue; }
        for(int i=0;i<b;i++){
            tp = mpow(a,tp,m);
            // cout<<" test: "<< tp<<endl ;
            cout<<" test: "<< tp%m<<endl ;
        }
        cout<<tp<<endl;
    }

    return 0;
}