/* 
2019年10月03日19:25:19 开始看题
只与左边和上边有关,应该就是dp

写一个 人人为我 dp吧

2019年10月03日20:14:58 wa on test 1...

Note that you don't have to minimize the number of operations. 

那么讨论这么多情况干嘛,还错了...傻逼!
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
int ma[M][M];bool vis[M][M];
int n,m;
vector<pair<int,int> > ans;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ cin>>ma[i][j]; vis[i][j]=0;}
    }
    for(int i=1;i<n;i++){
        // 第一个填好了没
        bool no_fi=1;
        for(int j=1;j<m;j++){
            if(vis[i-1][j-1]) continue;
            int ttp = ma[i-1][j-1]&&ma[i-1][j]&&ma[i][j-1]&&ma[i][j];
            if(ttp==4){
                int tp = ma[i-1][j+1]+ma[i][j+1];
                if(no_fi==1){
                    // 先前没看过但是还满足的地方,必须优先执行!
                    // ans.push_back({i+1 -1,j+1 -1});
                    ans.push_back({i,j});
                    no_fi=0;
                    // vis[i][j]=1; 下标搞错了...
                    vis[i-1][j-1]=1;
                }
                else if(tp == 2){
                    // ans.push_back({i+1 -1,j+1 });
                    ans.push_back({i,j+1});
                    // vis[i][j+1] = 1; 这要需要下标!
                    vis[i-1][j] = 1;
                } else if(tp==1){
                    cout<<"-1"<<endl; return 0;
                } else {
                    // ans.push_back({i+1 -1,j+1 -1});
                    ans.push_back({i,j});
                    // vis[i][j]=1; 下标搞错了...
                    vis[i-1][j-1]=1;
                }
            } else if(ttp){
                if(no_fi){
                    int tp = ma[i-1][j+1]+ma[i][j+1];
                    if(ma[i-1][j]&&ma[i][j] && tp == 2){
                        ans.push_back({i,j+1});
                        vis[i-1][j] = 1;
                        no_fi = 0;
                    } else {
                        cout<<"-1"<<endl; return 0;
                    }
                } else {
                    // 1101
                    // 1101
                    cout<<"-1"<<endl; return 0;
                }
            }
        }
    }
    int sz = ans.size();
    cout<<sz<<endl;
    for(int i=0;i<sz;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;
}