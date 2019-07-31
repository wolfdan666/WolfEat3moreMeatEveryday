#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
int a[M],T,n,m,L1,R1,p1,K1,L,R,p,K,ans;
multiset<int> tmp;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        /* init */


        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        while(m--){
            /*init*/
            tmp.clear();ans=0;
            cin>>L1>>R1>>p1>>K1;
            L=L1^ans,R=R1^ans,p=p1^ans,K=K1^ans;
            // cout<<"L: "<<L<<" R: "<<R<<" P: "<<p<<" K: "<<K<<endl;
            for(int i=L;i<=R;i++){
                tmp.insert(abs(a[i]-p));
            }
            auto j = tmp.begin();
            // for(auto i:tmp) cout<<i<<" "; cout<<endl;
            // ans = *(j+K);
            K--;
            while(K--) j++;
            ans = *j;
            cout<<ans<<endl;
        }
    }

    return 0;
}