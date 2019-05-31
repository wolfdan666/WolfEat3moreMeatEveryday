/**
一个数的约数的个数等于把它素因数分解得到的素因数的指数都+1(因为有个0次方)然后累乘   (i就是指数的个数)(可以参考李煜东的书P15页)
小的素因数的指数大的话会更优
now记录现在乘到了多少，ans统计答案，num表示选到了第几个素数


n<=1e18  ll
*/

#include<iostream>
#include<cstdio>
using namespace std;
long long maxx,n;
int t;
int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
void dfs(long long now,long long ans,int num,int aha)
{
    maxx=max(maxx,ans);// 递归出去，找到最大的那一条线
    for(int i=1;i<=aha;i++)// 指数层数，根据数值估计是在16层
    {
        if(now<=n/prime[num])
        {
            now*=prime[num];
            dfs(now,ans*(i+1),num+1,i); // 像树一样分成不同的线
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        maxx=0;
        cin>>n;
        dfs(1,1,0,16);
        cout<<maxx<<endl;
    }
    return 0;
}