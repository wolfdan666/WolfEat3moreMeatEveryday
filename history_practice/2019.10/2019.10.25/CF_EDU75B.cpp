/*
这是一个观察输入输出的结论题...
很容易知道如果是奇数串长,那么一定可以调整成为回文串
然后如果是偶数串,那么一定可以调节成为有偶数个放两边的状态

因此:
1.只要有一个奇数串.一定可以输出n,因为总可以让偶数串分到偶数个1或0,从而必定回文==> ans=n;
2.没有奇数串,那么一定就是只有0的个数是偶数个(这样1的个数也是偶数)的时候ans=n,
  否则让一个串来接收那个奇数值,其他就可以组成偶数个0或1,这样就ans = n-1

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
int Q,n,zs,os;
bool f;
char s[55];

int main(){
    Q = rd();
    while(Q--){
        n = rd();
        f = 0;os=zs=0;
        rep(i,1,n){
            scanf("%s",s+1);
            int len = strlen(s+1);
            if(len & 1) f = 1;
            rep(j,1,len) s[j]-'0'?os++:zs++;
        }
        if(!f&&(os%2||zs%2)) printf("%d\n", n-1);
        else printf("%d\n", n);
    }

    return 0;
}