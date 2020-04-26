/*
2020年4月26日20:22:34 感觉情况还是有点复杂..
只想到O(n^2)的暴力解法

2020年4月26日21:23:36 再来想想这题
感觉可能是图论问题，而不是计算几何的问题...

2020年4月26日21:32:23 还是想不出来
没时间了，写一发暴力混点分数吧

2020年4月26日21:44:52 交暴力,运行了很久
2020年4月26日21:46:20 超时只能过0%
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
int T,n;
vector<pair<int,int>> A,B;
int x,y;

int main(){
    T = rd();
    while(T--){
        n = rd();
        int ni = n;
        while(ni--){
            x = rd(); y = rd();
            A.pb({x,y});
        }
        while(n--){
            x = rd(); y = rd();
            B.pb({x,y});
        }
        double ans = 1e17;
        // cout<< "ans: " << ans <<endl;
        for(auto i : A){
            for(auto j : B){
                ans = min(ans, sqrt( (i.fi-j.fi)*(i.fi-j.fi) + (i.se-j.se)*(i.se-j.se) ));
                // cout<< "sqrt: "<< sqrt( (i.fi-j.fi)*(i.fi-j.fi) + (i.se-j.se)*(i.se-j.se) ) << endl;
            }
        }
        // cout<< ans <<endl;
        printf("%.3f\n", ans);
    }

    return 0;
}