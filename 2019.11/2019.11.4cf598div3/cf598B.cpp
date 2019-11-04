/*
2019年11月04日21:26:57 开始看题
中途去操作了一下A sb TLE

Each operation can be performed at most once.

2019年11月04日21:36:22 倒着移动就结束了!

2019年11月04日21:43:37 莫名其妙地卡段错误,什么鬼

2019年11月04日21:46:37 SB卡 %s...
2019年11月04日21:47:01 交,wa on test1!
mdzz,想错了...
2019年11月04日22:02:16 AC
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
int q,n,a[110];
bool vi[110];

int main(){
    q = rd();
    while(q--){
        mem(vi,0);
        n = rd();
        rep(i,1,n) a[i] = rd();
        while(1){
            bool ok = 1;
            per(i,n,2){
                if(a[i-1] > a[i]){
                    ok = 0;
                    if(!vi[i]) swap(a[i-1],a[i]),vi[i]=1;
                }
            }
            if(ok) break;
            else{
                bool okk = 1;
                per(i,n,2) if(!vi[i]){
                    if(a[i-1] > a[i]){
                        okk = 0;
                        swap(a[i-1],a[i]),vi[i]=1;
                    }
                }
                if(okk) break;
            }
        }
        // rep(i,1,n) printf("%d%s", a[i]," \n"[i==n]);
        rep(i,1,n) printf("%d%c", a[i]," \n"[i==n]);
    }

    return 0;
}

