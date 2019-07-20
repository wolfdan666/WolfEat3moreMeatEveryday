#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 2000
#define MOD 1000000007
int n,m;
int dp[MAXN+5][MAXN+5];
int main()
{
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=n+m;i++)
            for(int j=0;j<=n+m;j++)
                dp[i][j]=0;
        dp[0][0]=1;
        for(int i=0;i<=n+m;i++)
            for(int j=0;j<=n+m;j++){
                if(i+1<=j+n&&j<=i+m)
                    dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
                if(i<=j+n&&j+1<=i+m)
                    dp[i][j+1]=(dp[i][j+1]+dp[i][j])%MOD;
            }
        printf("%d\n",dp[n+m][n+m]);
    }
}