/*
5
5
1 1
2 4
60 59
3 1
1000 10

50
我输出0
所以不仅超时,答案也错了...

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll inf = 1e18;
const int M = 1e5+10;
int T,n,x,y;
struct node{
    ll x,y;
} a[M];
multiset<ll> b;
bool cmp(node a,node b){return a.x<b.x;}

ll check(int i,ll t,ll yes){
    ll tp = a[i].x; auto j = b.find(t);
    b.erase(j);
    j = upper_bound(b.begin(),b.end(),tp);
    auto k = j; k--;
    // auto k = j - 1;
    if(j==b.end()){
        /* 那么*k必定比mx大，直接返回 */
        b.insert(a[i].y);return abs(*k-tp);
    }
    if(*j<yes) {b.insert(a[i].y);return inf;}
    if(*k<yes){b.insert(a[i].y); return abs(*j-tp);}
    /* 下面是都大于yes */
    ll ta = abs(tp - *j), tb = abs(tp - *k);
    if(ta>tb) j=k,ta=tb;
    b.insert(a[i].y);
    return ta;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        b.clear();
        for(int i=0;i<n;i++){
            cin>>a[i].x>>a[i].y;
            b.insert(a[i].y);
        }
        sort(a,a+n,cmp);
        ll ans = 1e18;
        ll mx = 0;
        for(int i=0;i<n;i++){
            if(i) mx = max(mx,a[i-1].y);
            ans = min(ans,check(i,a[i].y,mx));
        }
        cout<<ans<<endl;
    }

    return 0;
}