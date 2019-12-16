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
vector<int> tp;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return upper_bound(data.begin(), data.end(), k) -
                 lower_bound(data.begin(), data.end(), k);
    }
};

int main(){
    tp.pb(1);
    tp.pb(3);
    tp.pb(4);
    tp.pb(4);
    tp.pb(5);
    if(upper_bound(tp.begin(), tp.end(), 6)==tp.end()) cout<<"没找到的话-确实是指向最后一个"<<endl;
    if(lower_bound(tp.begin(), tp.end(), 6)==tp.end()) cout<<"没找到的话-确实是指向最后一个"<<endl;

    Solution sol;
    cout<< sol.GetNumberOfK(tp,4) <<endl;

    return 0;
}