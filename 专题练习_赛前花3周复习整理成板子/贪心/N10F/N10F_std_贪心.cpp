#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=6e5+5;
const int N=6e5+3;
int a[maxn],b[maxn],cnt[maxn],ans,n,r;
vector <int> h[maxn];
multiset <int> s;
void add(int x){
    auto p=s.find(cnt[x]);
    s.erase(p); cnt[x]++;
    s.insert(cnt[x]);
}
void del(int x){
    auto p=s.find(cnt[x]);
    s.erase(p); cnt[x]--;
    s.insert(cnt[x]);
}
int main(){
    cin >> n >> r;
    for (int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        /* 统一右移2*r */
        a[i]+=r*2; b[i]+=r*2;
    }
    for (int i=0;i<n;i++){
        /*打a[i]的时候,把a[i]-r,a[i]+r也叠加上a[i]上面的值,
        这样就能使得a[i]表示打a[i]能获得的总值*/
        h[a[i]-r].pb(b[i]);
        h[a[i]].pb(b[i]);
        h[aa[i]+r].pb(b[i]);
        cnt[b[i]]++; cnt[b[i]-r]++; cnt[b[i]+r]++;
    }
    for (int i=r;i<=N-r;i++) s.insert(cnt[i]);
    for (int i=r;i<=N-r;i++){
        /*得到中间打这里能够得到的个数*/
        int ret=(int)h[i].size();
        /*暂时删除相关的所有列值*/
        for (auto x:h[i]) del(x),del(x-r),del(x+r);
        /*然后得到当下最大的3列值*/
        auto p=s.rbegin();
        ans=max(ans,ret+(*p));
        /*再把列值插回去*/
        for (auto x:h[i]) add(x),add(x-r),add(x+r);
    }
    cout << ans << endl;
}
