// 2019年4月3日22:04:44开始看题
// 理解：翻转一个区段，然后找出最大不减长度
// 思路：压缩成 1,2长度的区段值，然后对4个(或不足4个)滑块求sum的max(因为翻转中间两个就相当于使4个长度相加)
// 2019年4月3日22:33:30过了样例，但是wa test3，看不出test3是哪个思路错，所以看tutorial
#include<bits/stdc++.h>
using namespace std;
const int M=2010;
int a[M],b[M];
int ans;

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    a[0]=1;
    int k=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1]) b[k]++;
        else b[++k]=i==1?0:1;
    }
    // b[k]=b[k+1]=b[k+2]=0;
    for(int i=0;i<=n;i+=2){
        int t=0;
        for(int j=i;j<i+4;j++){
            t+=b[j];
        }
        ans=max(ans,t);
    }
    cout<<ans<<endl;
    return 0;
}




// tutorial中O(n)的方法没看懂啊，先理解简单的O(n^2)(也就是我的思路)
#include<bits/stdc++.h>
using namespace std;
int n,x,j,dp[6];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(j=2;j<=5;j++)
            dp[j]=max(dp[j-1],dp[j]+(j%2+1==x));
    }
    cout<<dp[5];
}
// 2019年4月3日22:56:57再回去理解理解
#include <bits/stdc++.h>
using namespace std;
int a[2005],dp[2005][4],b[5]={0,1,2,1,2};
int main(){
    ios::sync_with_stdio(false);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<5;i++)
        for(int j=1;j<=n;j++)
            dp[j][i]=max(dp[j-1][i]+(b[i]==a[j]),dp[j][i-1]);
    cout<<dp[n][4]<<endl;
    return 0;
}