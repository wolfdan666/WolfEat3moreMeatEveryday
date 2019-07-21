/*2019年7月21日14:19:29 花了一会儿快速写完，然后样例都没过..*/
/*有两个人AC了，说明题目应该没有问题...*/
/*2019年7月21日14:24:53 发现自己智障ans为赋值为0...*/
/*TLE!要优化计算!--->先看C题*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
/*int mul(LL a, LL b) {
  a *= b;
  return a >= mod ? a % mod : a;
}
*/
// int qmul_mod(LL a,LL b,int mod){
int mul(LL a,LL b){
    int ans=0;
    while(b){
        if((b%=mod)&1)ans+=a%=mod;//这里需要b%=mod 以及a%=mod
        b>>=1;a<<=1;
    }
    return ans%mod;  //ans也需要对mod取模
}

/*int mpow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}*/

int main() {
  LL n,m,ans=0;
  cin>>n>>m;
  if(n>m){
    for(int i=1;i<=n;i++){
      int tmp = mul(i,n%i);
      for(int j=1;j<=m;j++){
        // ans = (ans + mul(mul(mul(i,j),n%i),m%j)) % mod;
        ans = (ans + mul(mul(j,tmp),m%j)) % mod;
      }
    }
  }else{
    for(int j=1;j<=m;j++){
      int tmp = mul(j,m%j);
      for(int i=1;i<=n;i++){
        ans = (ans + mul(mul(i,tmp),n%i)) % mod;
      }
    }
  }
  cout<<ans<<endl;
}
