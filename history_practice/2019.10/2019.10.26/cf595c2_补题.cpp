/*
2019年10月26日16:26:47 英文太烂了,没有看懂tutorial,所以看了一个大佬的博文
1.贪心算法~；
2.对于任意一个正整数n，它有两种可能：case1:3^a ≤ n ≤ (3^(a+1)-1)/2 和 case2:(3^(a+1)-1)/2 < n < 3^(a+1)（其中a为对应常数）；
3. (3^(a+1)-1)/2是如何求的呢，是3^0+3^1+…+3^a，如果处在case2中的数，那大于等于它的good number肯定就是3a+1啦；
4. 处在case1中的数，那大于等于它的good number肯定有3^a这个因子，我们只需将3^a保存下来，然后去递归求大于等于n-3^a的good number就好啦；
5. 为了保证运行效率，我们可以提前将3^0 ~ 3^39的结果保存起来，也将(3^1-1)/2 ~ (3^39-1)/2的结果保存起来；
6. 次方运算就用循环算吧，用pow的话算3^39是不对的 ^ _ ^（至少我机器上算出来不对）；


原文链接：https://blog.csdn.net/qq_45228537/article/details/102710825

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power_3[40];
ll cil[40];
vector<int> v;
void dfs(ll n){
    if(n<=0) return;
    int pos;
    for(pos=0;pos<=39&&n>=power_3[pos+1];pos++);
    if(n>cil[pos]) v.push_back(pos+1);
    else{
        v.push_back(pos);
        dfs(n-power_3[pos]);
    }
}
int main(){
    // cout<<log(1e18+10)/log(3)+1<<endl;
    int q;
    cin>>q;
    ll power=1;
    for(int i=0;i<=39;i++,power*=3) power_3[i]=power;
    for(int i=0;i<=38;i++) cil[i]=(power_3[i+1]-1)>>1;
    for(int i=0;i<q;i++){
        ll n;
        cin>>n;
        v.clear();
        dfs(n);
        ll ans=0;
        for(auto e:v) ans+=power_3[e];
        cout<<ans<<'\n';
    }
    return 0;
}
