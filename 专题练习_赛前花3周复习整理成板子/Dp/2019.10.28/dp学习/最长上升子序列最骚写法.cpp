#include<bits/stdc++.h>
using namespace std;
const int M = 1e2;
int n,a[M],dp[M],mx,ans;


int main(int argc, char const *argv[]){
    cin>> n;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    memset(dp, 0x1f, sizeof dp);
    mx = dp[0];

    // cout<<mx<<endl;//522133279

    for (int i = 0; i < n; ++i) {
      *std::lower_bound(dp, dp + n, a[i]) = a[i];
    }

    for (int i = 0; i < n; ++i) cout<<dp[i]<<" \n"[i==n-1];

    ans = 0;
    while (dp[ans] != mx) ++ans;

    cout<<ans<<endl;
    return 0;
}


/*
in:
5
1 2 8 7 2
out:
1 2 7 522133279 522133279
3


*/