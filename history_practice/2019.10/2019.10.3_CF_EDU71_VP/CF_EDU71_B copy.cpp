/* 
2019年10月03日19:25:19 开始看题
只与左边和上边有关,应该就是dp

写一个 人人为我 dp吧

2019年10月03日20:14:58 wa on test 1...

Note that you don't have to minimize the number of operations. 

那么讨论这么多情况干嘛,还错了...傻逼!

如果要考虑的话,情况过多!而且不考虑才是题意啊!

快点写暴力啊!2019年10月03日20:30:36 
只有能填就填,不能填的地方都不填,然后直接对比填出的b是不是a就行!

2019年10月03日20:41:26 才AC这个傻逼题,丢人...连暴力都不会...
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
const int M = 55;
int ma[M][M];int vis[M][M];
int n,m;
vector<pair<int,int> > ans;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ cin>>ma[i][j]; vis[i][j]=0;}
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            // int ttp = ma[i-1][j-1]&&ma[i-1][j]&&ma[i][j-1]&&ma[i][j];
            int ttp = ma[i-1][j-1]+ma[i-1][j]+ma[i][j-1]+ma[i][j];
            if(ttp==4){
                ans.push_back({i,j});
                vis[i-1][j-1]=1;
                vis[i-1][j]=1;
                vis[i][j-1]=1;
                vis[i][j]=1;
            }
        }
    }
    // rep(i,0,n-1){
    //     rep(j,0,m-1){
    //         cout<<ma[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // rep(i,0,n-1){
    //     rep(j,0,m-1){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    rep(i,0,n-1){
        rep(j,0,m-1){
            if(ma[i][j]^vis[i][j]){
                // cout<<ma[i][j]<<" "<<vis[i][j]<<" ";
                cout<<"-1"<<endl;
                return 0;
            }
        }
        // cout<<endl;
    }

    int sz = ans.size();
    cout<<sz<<endl;
    for(int i=0;i<sz;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;
}