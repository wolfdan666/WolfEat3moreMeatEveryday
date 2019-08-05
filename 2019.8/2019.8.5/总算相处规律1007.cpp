#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int inf = 0x3f3f3f3f;
const int M = 2000;
int T,N,x,y;
ll ans;ll C[M][M];
/*5000/3-> 1667个闪电...但是不是阶层！1 1 1 闪,不会有6种！是C(1 4)*/
/*傻逼了！是10^5/3!!!--->内存太大，开不下...*/
/*所以最后一个样例过不了！因为要16876的区间的C*/

/*从5毒dp - N5G拿过来用*/
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
    pre();
    cin>>T;
    while(T--){
        ans = 1;
        cin>>N>>x>>y;
        if(N<=3){ cout<<1<<endl; continue; }
        if(x>y) swap(x,y);
        /*要特判直接上升的！*/
        int tl = x==1 ? 1 : x + 1;
        int th = y==N ? N : y - 1;
        /*计算最大闪电的数量*/
        int gap = th - tl;
        int mx = gap/3;
        /*0个闪电就是ans = 1*/
        for(int i = 1;i <= mx; i++){
            /*计算1的上升数和闪电的上升数*/
            int n = (gap - mx*3) + mx;
            ans = (ans + C[n][i])%mod;

            // cout<<C[n][mx]
        }

        /*1-1=0的话就是偶数就没关系*/
        int l = x - 1;
        int h = N - y;
        if(x>=4 && (l&1)) ans = ans*2%mod;
        if(y+3<=N && (h&1)) ans = ans*2%mod;

        cout<<ans<<endl;
    }
    return 0;
}