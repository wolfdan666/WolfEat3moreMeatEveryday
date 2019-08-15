#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 2e5+7;
// unordered_set<unordered_set<int>> a;
/*发现只能使用set套set，hash型的用不了*/
set<set<int>> a;
ll n,m,x,y,C[M][5];

/*这里j只要到4就行,且不要mod*/
void pre(){
    for(int i=0;i<M;i++) C[i][0]=1;
    for(int i=1;i<M;i++){
        for(int j=1;j<=4&&j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=mod) C[i][j]-=mod;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    pre();
    cin>>n>>m;
    cout<<C[n][4]<<endl;
    ll now = n;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        ll ans =0, tuancnt =0, sum = 0;
        if(!a.empty()){
            bool f = 1;
            for(auto j:a){
                if(j.find(x)!=j.end()) j.insert(y),now--,f=0;
                else if(j.find(y)!=j.end()) j.insert(x),now--,f=0;
            }
            if(f){
                set<int> tp;
                tp.insert(x); tp.insert(y);
                a.insert(tp);
                now -= 2;
            }
        }
        else{
            set<int> tp;
            tp.insert(x); tp.insert(y);
            a.insert(tp);
            now-=2;
        }


        for(auto i:a){
            tuancnt++;
            sum+=i.size();
        }
        if(now+tuancnt<4){cout<<0<<endl; continue;}
        /*后面的都是now+tuancnt>=4的*/

        // cout<<"now: "<<now<<" tuancnt: "<<tuancnt<<" sum: "<<sum<<endl;
        if(now>=4){
            for(int i=0;i<=4 && i<=tuancnt;i++){
                if(i==0) {ans+=C[now][4];continue;}
                ans += C[now][4-i]*(C[tuancnt][i]*i/tuancnt*sum);
            }
        }
        else{
            for(int i=0;i<=now;i++){
                int j = 4 - i;
                ans += C[now][i]*(C[tuancnt][j]*j/tuancnt*sum);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}