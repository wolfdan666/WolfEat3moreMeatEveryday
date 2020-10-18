// 2019年3月24日20:09:15 开始看题   2019年3月24日20:24:31  心烦意乱，所以边听歌边写题，明天一天一定可以写完模电作业一二章的，可以借鉴
// 直接看了答案

// #include <bits/stdc++.h>
// using namespace std;

// #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl "\n"
// #define int long long

// const int N = 2e5 + 5;
// const int MOD = 1e9 + 7;

// int pow(int a, int b, int m)
// {
//     int ans=1;
//     while(b)
//     {
//         if(b&1)
//             ans=(ans*a)%m;
//         b/=2;
//         a=(a*a)%m;
//     }
//     return ans;
// }

// int n, k, sz, ans = 0;
// bool vis[N];
// vector<int> g[N];

// void dfs(int u)
// {
//     if(vis[u])
//         return;
//     sz++;
//     vis[u] = 1;
//     for(auto &it:g[u])
//         dfs(it);
// }

// int32_t main()
// {
//     IOS;
//     cin>>n>>k;
//     int ans = pow(n, k, MOD);
//     for(int i=1;i<=n-1;i++)
//     {
//         int u, v, x;
//         cin>>u>>v>>x;
//         if(x == 0)
//             g[u].push_back(v), g[v].push_back(u);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(vis[i])
//             continue;
//         sz = 0;
//         dfs(i);
//         ans -= pow(sz, k, MOD);
//         ans += MOD;
//         ans %= MOD;
//     }
//     cout<<ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;
ll n, k, sz, ans = 0;
bool vis[N];
vector<ll> g[N];

ll pow(ll a, ll b, ll m){
    ll ans=1;
    while(b){
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}

void dfs(ll u){
    if(vis[u])
        return;
    sz++;
    vis[u] = 1;
    for(auto &it:g[u])
        dfs(it);
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    ll ans = pow(n, k, MOD);
    for(ll i=1;i<=n-1;i++){
        ll u, v, x;
        cin>>u>>v>>x;
        if(x == 0)
            g[u].push_back(v), g[v].push_back(u);
    }
    for(ll i=1;i<=n;i++){
        if(vis[i])
            continue;
        sz = 0;
        dfs(i);
        ans -= pow(sz, k, MOD);
        ans += MOD;
        ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}