#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int ans = 1;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    /*48 58.. 所以 0 放前面*/
    cout<<int('0')<<" "<<int(':')<<endl;
    for(int i=1;i<=10;i++) ans*=i;
    cout<<ans<<endl;

    return 0;
}