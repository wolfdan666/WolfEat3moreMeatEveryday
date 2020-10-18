/*这是后面大家过度优化到看不懂逻辑的代码...
卡了我一个小时，我佛了...是我菜了

去看一血版本！！！
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
P node[1000006];
ll L, R, n;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> L >> R;
        L *= 2, R *= 2;
        node[i*3] = {L, 1};
        node[i*3+1] = {(L+R)/2, -2};
        node[i*3+2] = {R, 1};
    }
    sort(node, node+3*n);
    for(int i=0;i<3*n;++i) cout<<"First: "<<node[i].first<<" Second: "<<node[i].second<<endl;
    ll ans = 0, tmp = 0, cnt = 0, ma = 0;
    for(int i=0;i<3*n-1;++i){
        cnt += node[i].second;
        tmp = node[i+1].first-node[i].first;
        ma += cnt*tmp;
        ans = max(ma, ans);
        cout<<"cnt: "<<cnt<<" tmp: "<<tmp<<" ma: "<<ma<<" ans: "<<ans<<endl;
    }
    cout << ans << endl;
    return 0;
}

