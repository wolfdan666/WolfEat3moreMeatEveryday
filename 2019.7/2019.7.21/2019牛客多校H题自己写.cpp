/*
5 10
0100101100
0010110110
1000011110
1000110010
1111110010

*/


#include<bits/stdc++.h>
using namespace std;
const int M = 1e3+5;
int dp[M][M];
int ddz[M],w[M];
vector<int> ans;
int n,m;

void solve(int *f){
    int top = 0;
    ddz[top] = -1;
    f[m+1] = -1;
    for(int i=1;i<=m+1;i++){
        /*等于时是否弹出这需要自己注意一下,就是严不严格单调的选择*/
        // if(ddz[top]<f[i]) ddz[++top]=f[i],w[top]=1;
        // else{
        //     int width = 0;
        //     /*此处注意要先加宽度*/
        //     while(top&&f[i]<ddz[top]){ width+=w[top],ans.push_back(ddz[top]*width),ans.push_back(ddz[top]*(width-1));top--;}
        //     /*我的做法是 : 等于是加入,不严格单调*/
        //     ddz[++top]=f[i],w[top]=width+1;
        // }
        /*推荐下面的方法*/
        if(ddz[top] <= f[i]) ddz[++top] = f[i];
        else {
            int cnt = 0;
            /*然后这里可以写宽度进行优化*/
            while(top && ddz[top] > f[i]) {
                cnt++;
                ans.push_back(ddz[top] * cnt);
                top--;
            }
            while(cnt--) ddz[++top] = f[i];
            ddz[++top] = f[i];
        }
    }
}

int main(){
    char c[M];
    while(~scanf("%d%d",&n,&m)) {
        /*init*/
        ans.clear();
        for(int i=1;i<=n;i++){
        /*对于每一列的每一行进行连续高度扫描*/
            scanf("%s",c);
            /*此行非0,则可以接上上面连续来的高度(可能为0)*/
            for(int j=1;j<=m;j++) dp[i][j] = c[j-1] == '0'? 0 : dp[i-1][j]+1;
        }
        // for(int i = 1;i<=n;i++) {for(int j=1;j<=m;j++) cout<<dp[i][j]; cout<<endl;} cout<<endl;
        /*solve*/
        /*对每一行进行直方图扫描求解*/
        for(int i=1;i<=n;i++) solve(dp[i]);
        sort(ans.begin(),ans.end());
        /*考虑特例*/
        int sz = ans.size();
        if(sz<=1) printf("0\n");
        printf("%d\n", ans[sz-2]);
    }
    return 0;
}