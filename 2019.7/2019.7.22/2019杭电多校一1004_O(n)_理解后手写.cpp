#include<bits/stdc++.h>
using namespace std;
int n;
struct car{
    int l,s,v;
};

int main(){
    /*加了cin.tie(0)减少了时间,但是又加了cout.tie(0)后增加了一点时间,所以以后还是不要加cout.tie(0)*/
    ios::sync_with_stdio(false);cin.tie(0);/*cout.tie(0);*/
    while(cin>>n){
        vector<car> c(n+1);
        for(int i=0;i<=n;i++) cin>>c[i].l;
        for(int i=0;i<=n;i++) cin>>c[i].s;
        for(int i=0;i<=n;i++) cin>>c[i].v;
        /* 注意使用`1.0*` */
        double sum = 0; double ans = 1.0*c[0].s/c[0].v;
        for(int i=1;i<=n;i++){
            ans = max(ans,(c[i].s+(sum+=c[i].l))/c[i].v);
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}