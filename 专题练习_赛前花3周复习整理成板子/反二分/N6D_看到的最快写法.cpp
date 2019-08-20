#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1086;
int v[N],vis[N];
int n,k;
bool check(int vv){
    int num=k;
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    int left=n;
    int maxx=n,no=1;
    while(num){
        int sp=vv;
        for(int i=maxx;i>0;i--){
            //如果当前剩余容量比最小的更小，不能继续装，退出循环
            if(sp<v[no])break;
            //如果当前剩余容量足够，并且物品i还没有装过，则装入
            if(sp>=v[i]&&!vis[i]){
                sp=sp-v[i];vis[i]=1;left--;
                //如果无剩余，直接退出循环
                if(!sp)break;
            }
        }
        //压缩下次寻找的范围
        while(vis[maxx])maxx--;
        while(vis[no])no++;
        num--;
    }
    //如果无剩余，则正好输出
    if(!left)return 1;
    return 0;
}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int ti=1;ti<=cases;ti++){
        scanf("%d%d",&n,&k);
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
            sum+=v[i];
        }
        sort(v+1,v+n+1);
        int b=sum/k;
        if(sum%k)b++;
        int maxx=max(v[n],b);
        int ans=maxx;
        int i=maxx;
        while(i){
            if(check(i)){
                ans=i;break;
            }
            i++;
        }
        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
}