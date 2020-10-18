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

class Solution {
public:
    int jumpFloor(int n) {
        // 注意偏移
        n++;
        if(n==0 || n==1) return n;

        int a = 0,b = 1;
        for(int i=2;i<=n;i++){
            int tp = b;
            b = a + b;
            a = tp;
        }

        return b;
    }
};

int F(int n) {
    if(n==0 || n==1) return n;

    int a = 0,b = 1;

    for(int i=2;i<=n;i++){
        int tp = b;
        b = a + b;
        a = tp;
        cout<< i << " "<< b <<endl;
    }

    return b;
}

int main(){
    F(20);

    return 0;
}