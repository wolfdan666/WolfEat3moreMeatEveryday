#include<bits/stdc++.h>
using namespace std;
#define maxn 10110
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
const ll rec2 = 500000004LL;
const ll mod = 1e9+7;

int ans[maxn];

// void pre(){
//     memset(ans,0,sizeof(ans));
//     ans[0] = 0;
//     for(int i=1;i<maxn;i++){
//         for(int j=i;j<maxn;j+=i){
//             ans[j]++;
//         }
//     }
// }

void echo(ll m,ll n){
    if(m==0){cout<<"0 0"<<endl;return;}
    ll g = __gcd(m,n);
    cout<<m/g<<" "<<n/g<<endl;
}

int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);


    ll x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2){
        ll m = x1*y2+x2*y1;
        ll n = y1*y2;
        echo(m,n);

        m = x1*y2-x2*y1;
        echo(m,n);

        m = x1*x2;
        echo(m,n);

        m = x1*y2;
        n = y1*x2;
        echo(m,n);
    }
    return 0;
}