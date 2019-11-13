/*
2019年11月12日21:19:39 回来看发现自己傻逼了
**从头开始匹配！**

2019年11月12日21:31:18 模拟笔试结束了,A题模拟还是要点技巧的，没有写完...一开始没有状态，没看清题意...

然后一看，发现有人只考虑了一个 '? ' 也能AC...醉了... 数据太水了吧..

然后又看到有人用dp做，思路很清晰，然后看了一下自己的模拟，发现可能会漏掉很多很多的状态...

https://www.nowcoder.com/questionTerminal/340e0d941b614a12a661d8d0285decf3
果然不用急着处理所有 ？

去看Main_1.java

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
string s,t;

int main(){
    cin>>s>>t;
    int sl = s.length();
    int tl = t.length();
    int k = 0,ans = -1;
    bool ok = 1;
    if(tl > sl) ok = 0,goto END;
    rep(i,0,sl-1){
        if(t[k] != '?'){
            if(t[k] != s[i]){ ok = 0;break;}
            else k++;
        } else {
            int cnt = 1;
            while(t[k+cnt]=='?') cnt++;
            if(k+cnt==n){
                break;
            }
            rep(p,1,3){
                if(t[k+cnt]==s[i+cnt])
            }
        }
    }
    END:
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}