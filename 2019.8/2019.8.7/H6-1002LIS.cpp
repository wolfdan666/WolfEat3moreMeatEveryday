#include<bits/stdc++.h>
#define MAXN 50005
using namespace std;
int p[MAXN],k[MAXN],ans[MAXN],maxlen;
int T,n;
bool nofrozen[MAXN];
int an[MAXN];

inline int get_len(int *p,int n){
    int j=1;
    for(;j<=n;j++) if(nofrozen[j]) break;
    ans[1] = p[j];
    int len=1;
    for(int i=j+1; i<=n; ++i){
        if(nofrozen[i]){
            if(p[i]>ans[len])
                ans[++len]=p[i];
            else{
                int pos=lower_bound(ans,ans+len,p[i])-ans;
                ans[pos] = p[i];
            }
        }
    }
    // for(int i=1;i<=len;i++) cout<<"check ans[]: "<<ans[i]<<endl; cout<<endl;
    return len;
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        /*init*/
        memset(nofrozen,1,sizeof(nofrozen));
        scanf("%d",&n);
        for(int i=1; i<=n; ++i)
            scanf("%d",&p[i]);
        maxlen = get_len(p,n);
        // cout<<"maxlen: "<<maxlen<<endl;
        /*solve*/
        memset(nofrozen,0,sizeof(nofrozen));
        vector<int>::iterator it;
        int tmplen=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&k[i]);
            nofrozen[k[i]]=1;
            if(tmplen == maxlen) an[i]=maxlen;
            else{
                tmplen = get_len(p,n);
                an[i] = tmplen;
            }
        }
        // cout<<"sz: "<<sz<<endl;
        for(int i=1;i<=n;i++) printf("%d%c",an[i]," \n"[i==n] );
    }
    return 0;
}