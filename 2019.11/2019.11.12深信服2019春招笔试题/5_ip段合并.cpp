/*
2019年11月12日19:56:40 好像想得太简单了...
unsigned int ... 内存开不了...
所以直接读入pair,然后sort,然后O(n)处理

2019年11月12日20:16:12 交了一发

过了40%...  竟然有错误样例查看！

发现自己傻逼了，原来有些没有连接！只有P[pre].se >= P[i+1].fi ，都可以更新se！===>取max

数据有 6  5， a>b,但是题目没说...

2019年11月12日20:21:48 再交---AC--签到成功
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
typedef pair<int,int> Pii;
int N,a,b;
vector<pair<int,int> > P;

bool cmp(Pii a,Pii b){
    return a.fi == b.fi ? a.se > b.se : a.fi < b.fi;
}

int main(){
    N = rd();
    while(N--){
        a = rd(); b = rd();
        if(a>b) swap(a,b);
        P.pb({a,b});
    }
    sort(P.begin(), P.end(), cmp);
    int sz = P.size();

    // for(auto x : P){
    //     cout<<"Test: "<<x.fi<<" "<<x.se<<endl;
    // }

    int pre = 0;
    rep(i,0,sz-2){
        if(i+1 == sz - 1 ){
            if(P[pre].se >= P[i+1].fi ){
                P[pre].se = max(P[pre].se,P[i+1].se);
                printf("%d %d\n", P[pre].fi,P[pre].se);
            } else {
                printf("%d %d\n", P[pre].fi,P[pre].se);
                pre = i+1;
                printf("%d %d\n", P[pre].fi,P[pre].se);
            }
        } else {
            if(P[pre].se >= P[i+1].fi){
                P[pre].se = max(P[pre].se,P[i+1].se);
            } else {
                printf("%d %d\n", P[pre].fi,P[pre].se);
                pre = i+1;
            }
        }
    }

    return 0;
}