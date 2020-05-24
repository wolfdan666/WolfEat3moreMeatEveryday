/*
2020年5月23日15:14:53 开始看题

2020年5月23日15:18:58 简单的DP

2020年5月23日15:21:50 想了一下，这明明是简单的贪心
优先放 2U的， 并且优先叠满 h高度，就完事了

2020年5月23日15:34:02 AC
5星卷的第一题真签到... 但是自己签得有点慢
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
int T,a,b,h;

int solve(int a,int b,int h){
    // 一个可以放的b的个数
    int bc = h/2;
    if(bc <= 0) return -1;

    // 一个机架放满额的b之后还能放a的个数 0 or 1
    // int ac = h%2;

    // 满额放b需要多少机架
    int cnt = b/bc;
    if(b%bc != 0) cnt++;

    // 现有机架还可以放多少个 1 U的设备
    int left = cnt*h - b*2;
    if(left >= a) return cnt;
    else{
        // 要用新机架的 1 U 设备数
        int tmp = (a-left);
        cnt+=tmp/h;
        if(tmp%h != 0) cnt++;
        return cnt;
    }
}

int main(){
    T = rd();
    while(T--){
        a = rd(); b = rd(); h = rd();
        int ans = solve(a,b,h);
        printf("%d\n", ans);
    }

    return 0;
}