/*
2019年10月18日15:29:07 开始看题
2019年10月18日15:52:02 开始写，读题太慢了兄弟

题意:
- 首先就是n^2的位置.从1最矮到n^2最高
- u>v,则水管可以一次传送一单位的水过去
- 将实验室分成n组，每组n个，不同组之间相互传水
- 一组能传到另一组的水量就是，这组内与另一组之间组成的pair组数
- 我们现在是让所以的组之间的最小输水量最大

这种贪心肯定是固定的，所以可以找规律

整理一下发现规律显然，1 2 3,4 5 6,7 8 9
1 6 7
2 5 8
3 4 9


看了一下发现B题确实比C题难一点，因为C题的提交人数明显比B题多...
所以我没有get到那个思路的时候苦想好几个小时也无可厚非...
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
const int M = 310;
int a[M][M];
int n;

int main(){
    n = rd();
    int cnt=1;
    rep(j,1,n){
        rep(i,1,n){
            if(j&1){
                a[i][j]=cnt++;
            } else {
                a[n+1-i][j]=cnt++;
            }
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            printf("%d%c", a[i][j]," \n"[j==n]);
        }
    }
    return 0;
}