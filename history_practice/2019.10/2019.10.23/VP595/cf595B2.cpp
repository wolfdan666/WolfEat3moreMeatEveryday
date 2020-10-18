/*
2019年10月23日20:21:14 容易观察到性质,如果互相传送成了一个环的话,那么这一圈的人的ans必定相同,所以直接用set存起来,然后直接所以已经vis的点直接cout,set.size()
所以就可以O(n)

2019年10月23日20:29:53 AC,好爽啊
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
const int M = 2e5+10;
int q,n,p[M],a[M];
bool vis[M];
set<int> s;

int main(){
    q = rd();
    while(q--){
        n = rd();
        mem(a,0);mem(vis,0);
        rep(i,1,n) p[i]=rd();
        rep(i,1,n){
            if(vis[i]) continue;
            s.clear();
            int tp = i;
            s.insert(i);
            while(p[tp] != i) tp = p[tp],s.insert(tp);
            int sz = s.size();
            for(auto k:s){
                vis[k] = 1; a[k] = sz;
            }
        }
        rep(i,1,n) printf("%d%c", a[i]," \n"[i==n]);
    }

    return 0;
}