

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

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
//    #ifdef LOCAL
//  freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
//  #endif
    //scanf("%d",&a);
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    while(1){
    int tt = clock();
//测试的时候请对重复使用的数组或者变量清零！！
//    k=0;
//    memset(a,0,sizeof(a));
//  以及后文中该特判return的地方要及时return！
#endif
    int n;
    cin>>n;
    int ans = 0;
    if(n&1) cout<<ans<<endl;
    else cout<<(1<<(n/2))<<endl;

#ifdef LOCAL
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
    }
#endif
    return 0;
}