/*
手贱写错，tp.se... 导致没有及时能交... ==> 多多练习
然后还好队友先过了

用备用号交了，结果wa了...不知道什么特例把我卡了

应该是p 1e9    c 1e4  所以  c/p 的默认double精度15-16位应该够啊！
所以是 m/c*p 爆int 了....


mdzz 没有考虑数据范围---> 结果还是wa了...
debug 50mins ，pass，做字符串去
*/

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