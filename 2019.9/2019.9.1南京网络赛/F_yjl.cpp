#include<bits/stdc++.h>
#define ll long long
#define maxn 200010
using namespace std;
ll n,k,a[maxn],pos[maxn],dis[maxn],vis[maxn];
const ll MAXM=200010;
ll abss(ll a){
    if(a>0)return a;
    else return -a;
}

ll dfs(int cur){
    vis[cur]=1;
    ll i;
    for(i=cur-1;i>=1;i--){
        if(abss(pos[cur]-pos[i])<=k){
            if(!vis[i]){
                dis[cur]=dfs(i)+1;
            }
            else{
                dis[cur]=dis[i]+1;
            }
            break;
        }
    }
    if(!dis[cur])dis[cur]=1;
    return dis[cur];
}


int main(){
    ll t,i;
    cin>>t;
    while(t--){
        memset(pos,0,sizeof(pos));
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        scanf("%lld%lld",&n,&k);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            pos[a[i]]=i;
        }
        for(i=n;i>=1;i--){
            if(!vis[i]){
                dfs(i);
            }
        }
        for(i=1;i<n;i++)printf("%lld ",dis[i]);cout<<dis[i]<<endl;

        //cout<<ans<<endl;
    }


    return 0;
}