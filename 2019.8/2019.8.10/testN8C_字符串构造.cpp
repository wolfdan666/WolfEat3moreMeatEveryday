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
const int maxn = 2000;
string s="11",t="10";
vector<string> ans[11];
int Log[maxn];

string res(string s){
    string t;
    int n = s.length();
    rep(i,0,n){
        t+=s[i]=='1'?'0':'1';
    }
    return t;
}

void init() {
    Log[1] = 0;
    for(int i = 2; i < maxn; i++) Log[i] = Log[i/2] + 1;
}

int main(){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    #endif
    //scanf("%d",&a);
    init();
    ans[1].pb(s);
    ans[1].pb(t);
    rep(i,2,11){
        int sz = ans[i-1].size();
        rep(j,0,sz){
            string ca = ans[i-1][j];
            string cb = res(ca);
            ans[i].pb(ca+ca);
            ans[i].pb(ca+cb);
        }
    }
    int m;
    while(~scanf("%d",&m)){
        // int k = log(m)/log(2);
        int k = Log[m];
        int sz = ans[k].size();
        rep(j,0,sz){
            // cout<<ans[k][j]<<endl;
            int sz2 = ans[k][j].length();
            rep(i,0,sz2){
                if(ans[k][j][i]=='0'){
                    printf("%3d", -1);
                }
                else printf("%3d", 1);
            }
            puts("");
        }
    }
    return 0;
}