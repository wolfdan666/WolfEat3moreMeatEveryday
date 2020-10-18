/*
2019年10月30日21:34:02 二次来看这个有趣的题目
直接看题解吧,之前没有想到怎么做

2019年10月30日21:41:59 还是没有看懂English tutorial...再看一遍...

2019年10月30日22:41:55 自闭一个多小时,还是不是很懂,明天再看
*/

// By Cu_Y_Es, contest: Codeforces Round #596 (Div. 2, based on Technocup 2020 Elimination Round 2), problem: (E) Rock Is Push, Accepted, #
#include<bits/stdc++.h>
using namespace std;
const int M=2005,P=1e9+7;
int n,m;
char s[M][M];
int dpR[M][M],dpD[M][M];
int sumR[M][M],sumD[M][M];
int numR[M][M],numD[M][M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    if(s[1][1]=='R'||s[n][m]=='R'){puts("0");return 0;}
    if(n==1&&m==1){puts("1");return 0;}
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--){
            numR[i][j]=numR[i][j+1]+(s[i][j]=='R');
            numD[i][j]=numD[i+1][j]+(s[i][j]=='R');
        }
    dpR[n][m]=dpD[n][m]=sumR[n][m]=sumD[n][m]=1;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--){
            if(i==n&&j==m)continue;
            // 这里卡住了,保持淡定,从根源慢慢想,不要急
            // 右行到了i,j,那么后面的状态对应的是可以下行的状态数(步数),那么所有的下行种类 -
            // m - numR[i][j+1]+1是(i,j+1)在i行能达到的最右距离,那么减少就是(i,最右)下面的石块个数

            // 卡到后面发现它sumD不只是单纯的石块个数了,而是有加入了可移动数...!
            // 所以(当下的下面石块+可移动) - (最右可达的下面石块+可移动) = 当下(i,j)的右数,(因为(i,j+1的下来自这种右))
            dpR[i][j]=(sumD[i][j+1]-sumD[i][m-numR[i][j+1]+1])%P;
            dpD[i][j]=(sumR[i+1][j]-sumR[n-numD[i+1][j]+1][j])%P;
            sumR[i][j]=(sumR[i+1][j]+dpR[i][j])%P;
            sumD[i][j]=(sumD[i][j+1]+dpD[i][j])%P;
        }
    printf("%lld\n",(dpR[1][1]+dpD[1][1]+2ll*P)%P);
    return 0;
}