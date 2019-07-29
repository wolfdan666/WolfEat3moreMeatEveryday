#include<bits/stdc++.h>
using namespace std;
int N,M,T;
// unordered_map<int, int> cnt;
map<int, int> cnt;
int main(){
    for(scanf("%d",&T);T--;){
        cnt.clear();
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++){
            int t;scanf("%d",&t);
            int now=M-t;
            int ans=i;
            // for(int j=1;j<=100;j++){
            for(auto i:cnt){
                int get=min(now/i.first,i.second);
                now-=get*i.first;
                ans-=get;
            }
            cnt[t]++;
            printf("%d%c",ans,' ');
            if(i==N-1) puts("");
        }
    }
    return 0;
}