/*2019��7��21��14:19:29 ����һ�������д�꣬Ȼ��������û��..*/
/*��������AC�ˣ�˵����ĿӦ��û������...*/
/*2019��7��21��14:24:53 �����Լ�����ansΪ��ֵΪ0...*/
/*TLE!Ҫ�Ż�����!--->�ȿ�C��*/

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
        if((b%=mod)&1)ans+=a%=mod;//������Ҫb%=mod �Լ�a%=mod
        b>>=1;a<<=1;
    }
    return ans%mod;  //ansҲ��Ҫ��modȡģ
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
