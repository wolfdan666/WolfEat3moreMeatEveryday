#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
// head
ll n,m;
ll ans;

ll qpow(ll a,ll b){
    ll tmp = 1;
    while(b){
        if(b&1) tmp = (a*tmp)%mod;
        a = a*a%mod;
        b>>=1;
    }
    return tmp;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    #endif
    //scanf("%d",&a);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        ans = qpow(m,n-1);
        cout<<ans<<endl;
    }

    return 0;
}