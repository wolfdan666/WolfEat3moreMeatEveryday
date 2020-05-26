/*
2020年5月26日19:06:37 看题

1e5内

两个小时的窗口

感觉可以用滑动窗口来写一发

2020年5月26日19:15:34 觉得可以直接搜索一发
每个起点加一个两小时的窗户，但是可以直接爆1e10

再细致地看清楚题意再想想

题意应该是综合所有的天，找到黄金两小时

24*3600 = 86400
无数个 7200

23860+7200 = 31060
28+18+15+29+25+11+29+25+12+28+24+20+17+28+10+16+15+11+17

2020年5月26日19:33:21
378啊，样例数据让我懵逼

就算刚清楚也暂时不会写，所以2020年5月26日19:35:39 快去写A

2020年5月26日22:43:53 补了别人java版本，感觉第二题还简单点...自己就是太生疏了
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
const int M = 1e5+10;

struct node{
    int date;
    int time;
    int money;
    node(){}
    node(int d,int t,int m):date(d),time(t),money(m){}
} a[M];

int n,d,t,m;
int ans_m;

int main(){
    // cout<< 24*3600 << endl;
    // cout<< 23860+7200 << endl;
    // cout<< 28+18+15+29+25+11+29+25+12+28+24+20+17+28+10+16+15+11+17 << endl;
    n = rd();
    rep(i,1,n){
        d=rd();t=rd();m=rd();
        a[i].date = d;
        a[i].time = t;
        a[i].money = m;
        if(t>=23860 && t < 31060){
            ans_m += m;
        }
    }
    printf("%d\n", ans_m);

    return 0;
}