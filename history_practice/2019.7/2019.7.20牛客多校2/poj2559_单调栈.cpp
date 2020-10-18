/*
2019年7月20日10:41:44 开始看题

2019年7月20日10:43:37 开写

20minsAC..看了书还这么慢..太菜了
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
const int M = 1e5+10;
int n,h[M],w[M],s[M];
ll ans;

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        if(n==0) break;
        /* init */
        h[n+1] = 0;
        ans = 0;
        int p = 0; s[p] = 0;

        /* 发现自己memset写错了也AC了，原来是因为w数组不用init也行 */
        memset(w,0,sizeof(w));
        // memset(w,sizeof(w),0);
        /*solve*/
        for(int i = 1;i <= n+1;i++){
            if(i!=n+1) cin>> h[i];
            if(h[i]>s[p]){
                s[++p] = h[i],w[p] = 1;
            }else{
                int width = 0;
                while(s[p] > h[i]){
                    width += w[p];
                    ans = max(ans,(ll)width*s[p]);
                    p--;
                }
                s[++p] = h[i],w[p] = width+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}