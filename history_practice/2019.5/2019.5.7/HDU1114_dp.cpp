// 2019年5月7日21:45:50 加速啊，快要10点和别人的约定游戏啦
// 看完了题目，2019年5月7日21:54:41 感觉没有时间了，emmm，而且没懂怎么估计，所以直接看题解


/*
大意：给出存钱罐本身的重量和装钱后的重量，以及存钱罐中钱的面值和重量，求存钱罐装满时，钱的总和最小是多少

思路：完全背包解题，每种钱币都可以装无限个，注意初始化的值

*/


#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 1005
#define INF 0xffffffff
using namespace std;
int d[10005],c[505],v[505];

int main(){
    int T,n,V,i,j,E,F;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&E,&F);
        V = F - E;
        scanf("%d",&n);
        for(i = 0 ; i < n ; i ++)
            scanf("%d%d",&v[i],&c[i]);
        for(i = 1 ; i <= V ; i ++)
            d[i] = 5000000;   //初始化为正无穷，如果求钱币的最大值的话，就初始化为负无穷
        d[0] = 0;
        for(i = 0 ; i < n ; i ++) // 每个币种都试一下
            for(j = c[i] ; j <= V ; j ++)  // 一直更新到V
                d[j] = min(d[j - c[i]] + v[i],d[j]); // 当前质量下装v[i]是不是会变得更小呢(与之前没有装这个时的最小状态d[j-c[i]]在当下装上时比较),是的话就保存状态
        if(d[V] == 5000000)   //没有装满
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",d[V]);
    }
    return 0;
}