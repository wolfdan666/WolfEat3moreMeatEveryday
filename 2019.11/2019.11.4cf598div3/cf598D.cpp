/*
2019年11月04日22:03:20 看

k次移动,数0和前面为1的个数

2019年11月04日22:12:59 wo on test 15...
k不能用快读! 尴尬
2019年11月04日22:15:47 AC
去群里看了下,发现大家也有人wa on 15
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
const int M = 1e6+10;
int q,n;
ll k;
char s[M];

int main(){
    q = rd();
    while(q--){
        int sum = 0;
        n = rd(); scanf("%lld",&k);
        scanf("%s",s+1);
        rep(i,1,n){
            if(k == 0) break;
            if(s[i]=='1'){
                sum++;
            } else {
                if(sum){
                    if(k>sum) swap(s[i],s[i-sum]),k-=sum;
                    else{
                        swap(s[i],s[i-k]),k=0;
                        break;
                    }
                }
            }
        }
        printf("%s\n", s+1);
    }

    return 0;
}