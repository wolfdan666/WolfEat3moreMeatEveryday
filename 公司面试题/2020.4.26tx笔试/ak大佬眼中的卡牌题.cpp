/*
作者：qin_peng
链接：https://www.nowcoder.com/discuss/417957?type=post&order=time&pos=&page=0&channel=
来源：牛客网

有n张卡牌， 正面时 ai ,反面时 bi ,每次可以任意选择相邻俩张卡牌，交换位置，
然后并且翻转，并且使得 a不减 ，求最小操作次数。
状压dp , 不过要预处理下 ，将偶数下标的 a_i, b_i ,swap 。
跑子集dp ，我的更新是 dp[S][k]=min(dp[S][k],dp[S-k][j]+合法的) k属于 S集合
有点不好描述啊
*/

#include<bits/stdc++.h>
using namespace std;
#define me(a,x) memset(a,x,sizeof(a))
#define sc scanf
#define pr printf
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+6;
const int mod=1e9+7;
int O(){putchar('\n');return 0;}template<typename T,typename... Ty>
int O(const T& a,const Ty&... b){cout<<a<<' ';return O(b...);}
void I(){}template<typename T,typename... Ty>void I(T& a,Ty&... b){cin>>a;I(b...);}
template<typename T>void db(T *bg,T *ed){while(bg!=ed)cout<<*bg++<<' ';pr("\n");}
inline ll mul_64(ll x,ll y,ll c){return (x*y-(ll)((long double)x/c*y)*c+c)%c;}
inline ll ksm(ll a,ll b,ll c){ll ans=1;for(;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;return ans;}
int n,a[20],b[20];
int dp[1<<20][20];
const int INF=1e9;
int main(){
    I(n);
    for(int i=0;i<n;i++)sc("%d",&a[i]);
    for(int i=0;i<n;i++)sc("%d",&b[i]);
    for(int i=1;i<n;i+=2)swap(a[i],b[i]);
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++)dp[1<<i][i]=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==INF)continue;
            for(int k=0;k<n;k++){
                if(i>>k&1)continue;
                int x=__builtin_popcount(i)&1;
                if(x){
                    if(b[k]<a[j])continue;
                }else{
                    if(a[k]<b[j])continue;
                }
                int ans=0;
                for(int l=k+1;l<n;l++){
                    if(i>>l&1)ans++;
                }
                dp[i|1<<k][k]=min(dp[i|1<<k][k],dp[i][j]+ans);
            }
        }
    }
    int ans=INF;
    for(int i=0;i<n;i++)ans=min(ans,dp[(1<<n)-1][i]);
    if(ans==INF)O(-1);
    else O(ans);
}