/*这种一血版本反而容易理解一点*/

#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1000010;
struct Q{
    int ps,id;
    bool operator<(const Q&o)const{
        return ps<o.ps;
    }
}q[N];
int l[N],r[N],n,cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
        l[i]*=2,r[i]*=2;
        q[++cnt]=(Q){l[i],1};
        q[++cnt]=(Q){(int)(((LL)l[i]+r[i])/2),2};
        q[++cnt]=(Q){r[i],3};
    }
    sort(q+1,q+cnt+1);
    LL ans=0,A=0,B=0,ret=0;
    for(int i=1;i<=cnt;i++){
        ret+=(q[i].ps-q[i-1].ps)*(A-B)*2;
        if(q[i].id==1)A++;
        if(q[i].id==2)A--,B++;
        if(q[i].id==3)B--;
        if(i==cnt||q[i].ps!=q[i+1].ps)ans=max(ans,ret);
    }
    printf("%lld\n",ans/2);
}