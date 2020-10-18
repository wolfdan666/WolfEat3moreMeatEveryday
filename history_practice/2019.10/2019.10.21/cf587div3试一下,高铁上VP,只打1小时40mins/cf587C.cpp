/*
2019年10月21日14:35:34 开始看题
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
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
int c[3][5],x1,x2,y1,y2;
bool ans;

int main(){
    scanf("%d%d%d%d",x1,y1,x2,y2);
    rep(i,1,2) rep(j,1,4) c[i][j] = rd();
    rep(i,1,2){
        if(c[i][1]<=x1 && c[i][2]<=y2){
            if(c[i][3]>=x2 && c[i][4]>=y2){
                ans = 1;
            } else if(c[i][3]>=x2){
                y1 = c[i][4];
            }
        }
    }

    return 0;
}