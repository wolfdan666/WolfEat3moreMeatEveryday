#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int a[4],sum;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    for(int i=0;i<4;i++)cin>>a[i],sum+=a[i];
    for(int i=0;i<4;i++) if(a[i]==sum-a[i]){cout<<"YES"<<endl;return 0;}
    for(int i=1;i<=3;i++){
        int tp = a[0]+a[i];
        if(tp == sum - tp) {cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
    return 0;
}