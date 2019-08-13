#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 2e3+7;
int C[M][M];
int T,n,m;

void add(ll &a,ll v){
    a += v;
    if(a >= mod) a-=mod;
}

void pre(){
    for(int i=0;i<M;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=mod) C[i][j]-=mod;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    pre();
    while(T--){
        cin>>n>>m;
        cout<<C[n+m-2][m-1]<<endl;
    }

    return 0;
}