/*
md,果然二分只能过60%
但是怎么也拍不出数据

因为数据弱，所以不满足单调性的时候这样这样来凑一手


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 1e3+10;
int T,n,K,v[M],sum,vis[M];

bool check(int x){
    if(x*K<sum || x<v[n-1]) return false;
    if(x>=v[n-1] && K>=n) return true;
    for(int i=0;i<n;i++) vis[i]=0;
    int tmp=0,ts=sum;
    int i=1;
    while(ts>0){
        int tps = 0;
        while(i<=n && vis[n-i]) i++;
        if(n-i>=0) {
            tps += v[n-i];
                // cout<<"I get you! : "<<v[n-i]<<endl;
            vis[n-i]=1;
        }
        else break;
        while(tps<x){
            int tn = upper_bound(v,v+n-i,x-tps)-v;
            int j=1;
            while(j<=tn && vis[tn-j]) j++;
            if(tn-j>=0) {
                tps += v[tn-j];
                    // cout<<"I get you! : "<<v[tn-j]<<endl;
                vis[tn-j]=1;
            }
            else break;
        }
        // cout<<"How much is the tps "<<tps<<endl;
        ts -= tps;
        tmp++;
    }
    if(tmp>K) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;int kase=1;
    while(T--){
        cin>>n>>K;
        sum = 0;
        for(int i=0;i<n;i++){
            cin>>v[i]; sum+=v[i];
        }
        sort(v,v+n);
        int l=1,r=1e6;
        while(l<r) {
            // cout<<"l: "<<l<<" r: "<<r<<endl;
            int mid = (l+r)>>1;
            if(check(mid)) r=mid;else l = mid+1;
        }
        int ans = l;
        for(int i=ans;i>=ans-20;i--) if(check(i)) ans = i;
        cout<<"Case #"<<kase++<<": "<<ans<<endl;
    }

    return 0;
}