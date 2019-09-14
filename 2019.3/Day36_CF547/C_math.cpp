// 2019年3月22日10:33:56开始，然后浪玩sublime vim,2019年3月22日10:51:33 开始看题
// 2019年3月22日11:00:03 开写
// 2019年3月22日11:36:57交第一发，wa on test 1？
// 2019年3月22日11:46:45第二发，wa on test 37...GG，直接看bug处，发现是大数据n=200000是出了错！
// 2019年3月22日11:53:20 猜测是n*n的时候数据溢出了，所以把n改成ll   果然是这样的  2019年3月22日11:54:43AC...
#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int M = 2e5+5;
int p[M],q[M];bool vis[M];
ll sum[M];

int main(int argc, char const *argv[])
{
    // int n;
    ll n;
    cin>>n;
    ll /*sum[0]=0,*/sq=0,sp=(1+n)*n/2;// sum是前缀和,sq是前缀和的和
    for(int i=1;i<n;i++){
        cin>>q[i];
        sum[i]=sum[i-1]+q[i];
        sq+=sum[i];
    }
    p[1]=(sp-sq)/n;
    if(p[1]<=0||p[1]>n){return puts("-1")*0;}
    else{vis[p[1]]=true;}
    for(int i=2;i<=n;i++){
        p[i]=sum[i-1]+p[1];  // p[i]=q[i-1]+p[i-1];也行

        // cout<<p[i]<<"  d"<<endl;

        // if(vis[i]||p[i]<=0||p[i]>n){return puts("-1")*0;}// ...
        if(vis[p[i]]||p[i]<=0||p[i]>n){return puts("-1")*0;}
        else{vis[p[i]]=true;}
    }
    for(int i=1;i<n;i++){
        printf("%d ",p[i]);
    }
    printf("%d\n",p[n]);
    return 0;
}