/*
2020年5月25日21:19:03 感觉有点像字符串匹配，但又有点奇怪

2020年5月25日21:22:27 决定暴力模拟实现
2020年5月25日21:25:38 由于还有另一套5星卷也要在明天前看完，
所以具体实现先pass


2020年5月25日22:19:12 看了大佬的
map + string 的sub + find_last_of 牛逼

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

struct Node{
    string s;
    // 儿子链表
    Node* nxt;
    Node(string s):s(s),nxt(nullptr){}
    Node(string s,Node *nxt):s(s),nxt(nxt){}
};

int main(){


    return 0;
}