/*
2019年10月24日23:06:44 卡到现在快要可以进了,A题在刷新了
2019年10月24日23:07:13 看题

坏掉就是出两个...真实

2019年10月24日23:23:03 AC
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
int t,ans;
string s;
int a[26];

int main(){
    t = rd();
    while(t--){
        cin>>s;
        mem(a,0);
        int sz = s.length();
        if(sz == 1){ cout<<s<<endl;continue; }
        rep(i,0,sz-2){
            if(s[i]==s[i+1]){
                i++;
                if(i==sz-2){
                    a[s[i+1]-'a']++;
                }
            }
            else{
                a[s[i]-'a']++;
                if(i==sz-2){
                    a[s[i+1]-'a']++;
                }
            }
        }
        rep(i,0,25) if(a[i]) cout<<char('a'+i);
        cout<<endl;
    }

    return 0;
}