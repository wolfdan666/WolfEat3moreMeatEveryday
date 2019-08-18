#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

ll len[505];
string str[3];

string dfs(int x, ll a, ll b) {
    /*substr的第二个参数是长度*/
    if(x <= 2) return str[x].substr(a-1, b);
    if(a+b-1 <= len[x-2]) return dfs(x-2, a, b);
    if(a > len[x-2]) return dfs(x-1, a-len[x-2], b);
    /*分段后..x-1可以直接从1开始了*/
    return dfs(x-2, a, len[x-2]-a+1) + dfs(x-1, 1, b-(len[x-2]-a+1));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    str[1] = "COFFEE"; str[2] = "CHICKEN";
    len[1] = 6, len[2] = 7;
    ll mx = 1e17;
    for(int i = 3; i <= 500; i++) {
        /*前缀和*/
        len[i] = len[i-1] + len[i-2];
        /* i=80就会跳出*/
        if(len[i] > mx) {/*cout<<i<<endl;*/break;}
    }
    int T; cin >> T;
    while(T--) {
        int n; ll k;
        cin >> n >> k;
        int x;
        /*提前给x降低大小，所以就可以前面使用break，并且减少递归的次数*/
        for(x = 1; x <= n; x++) {
            if(len[x] >= k+10) break;
        }
        if(x == n+1) cout << dfs(x-1, k, min(10ll, len[x]-k+1)) << endl;
        else {
            if((n-x)%2) x++;
            cout << dfs(x, k, min(10ll, len[x]-k+1)) << endl;
        }
    }

    return 0;
}