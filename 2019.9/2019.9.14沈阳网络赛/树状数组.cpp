#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int x;cin>>x;
    while(x>0){
        printf("[%d, %d]\n",x-(x&-x)+1,x );
        x -= x & -x;
    }

    return 0;
}