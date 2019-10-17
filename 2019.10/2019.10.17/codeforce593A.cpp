/*
2019年10月17日21:52:44 开始看题
简单贪2 3
2019年10月17日22:00:39 交半天，网真卡...

后面发现网线掉了...
2019年10月17日22:09:41 修好了网络，但是不想交了，测试一下参加比赛并且看题不提交会不会掉分
直接看以前的比赛就可以啊！快去看看
发现不掉rating，所以不交了...因为意外有点不爽
*/

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
int T,a,b,c,ans;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    #endif
    //scanf("%d",&a);

    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        ans = 0;
        int tp = min(b,c/2);
        b -= tp;
        ans += 3*tp;
        tp = min(a,b/2);
        ans += 3*tp;
        cout<<ans<<endl;
    }

    return 0;
}