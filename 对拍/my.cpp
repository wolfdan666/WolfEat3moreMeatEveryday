#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 1e3+10;
ll n,m;
typedef pair<ll,ll> P;
// P a[M];
ll p,c;
ll mi,ans;
P tp;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n>>m){
        cin>>p>>c;
        tp = {p,c};
        mi = ceil(1.0*m/c)*p;

        // cout<<"mi: "<<mi<<" c: "<<tp.se<<" p: "<<tp.fi<<endl;

        for(int i=1;i<n;i++){
            cin>>p>>c;
            // int tmp = ceil(1.0*m/c)*p;
            ll tmp = ceil(1.0*m/c)*p;
            if(tmp < mi) mi = tmp,tp = {p,c};
            else if(tmp == mi) {
                if(1.0*c/p > 1.0*tp.se/tp.fi){
                    tp = {p,c};
                }
            }

            // cout<<"mi: "<<mi<<" c: "<<tp.se<<" p: "<<tp.fi<<endl;

        }
        // ans = mi/tp.fi*c;
        ans = mi/tp.fi*tp.se;
        cout<<mi<<" "<<ans<<endl;
    }

    return 0;
}