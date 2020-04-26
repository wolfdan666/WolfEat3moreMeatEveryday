/*
2020年4月26日20:02:53 这个直接队列模拟

2020年4月26日20:19:24 傻逼front()想了半天

2020年4月26日20:20:53 AC做第二题了
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
int T,n;
string s;
int val;

int main(){
    T = rd();
    while(T--){
        n = rd();
        queue<int> q;

        while(!q.empty()) q.pop();

        while(n--){
            cin >> s;
            if("PUSH" == s){
                val = rd();
                q.push(val);
            } else if("POP" == s){
                if(!q.empty()) q.pop();
                else puts("-1");
            } else if("TOP" == s){
                if(!q.empty()) cout<<q.front()<<endl;
                else puts("-1");
            } else if("SIZE" == s){
                cout<< q.size()<<endl;
            } else {
                while(!q.empty()) q.pop();
            }
        }
    }

    return 0;
}