/*
感觉有点像找规律，但是又很奇怪...打个表先___打表就溢出了...好难啊，这一套题

然后看解析，发现这题数据可能传错了

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
string s="111";
int a=1,b=1,c=1;
char buffer [33];

int main(){
    rep(i,1,100){
        int tp = a+b+c;
        itoa (tp,buffer,10);
        s+=buffer;
        a = b;
        b = c;
        c = tp;
    }
    cout<<s<<endl;

    return 0;
}