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

// string substr (size_t pos = 0, size_t len = npos) const;
int main(){
    char * a = "hello";
    cout<< string(a).substr(1,3) <<endl;
    // ell
    cout<< string(a).substr(1,0) <<endl;

    int len = strlen(a);
    cout<< string(a).substr(1,len - 1) <<endl;
    // ello

    rep(i,0,len-1){
        cout<< string(a).substr(i,len - i) <<endl;
    }
    /*
hello
ello
llo
lo
o
    */
    cout<< string(a).substr(len,len - len) <<endl;
    cout<< string(a).substr(len,len - len).length() <<endl;
    // 0

    // 2020年5月19日20:30:04 想到不用转string
    rep(i,0,len){
        cout<< a+i << " and len(*) = " << strlen(a+i) << endl;
    }
    /*
hello and len(*) = 5
ello and len(*) = 4
llo and len(*) = 3
lo and len(*) = 2
o and len(*) = 1
 and len(*) = 0
    */


    return 0;
}