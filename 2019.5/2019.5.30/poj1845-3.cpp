// 2019年5月30日20:04:38 再来重写此题，debug不行了，直接重写吧---> 逐个函数重写
// 2019年5月30日20:53:33 MLT3次了,为啥别人的code没有超内存！？
// 2019年5月30日20:56:00 模仿别人，把M值取小50倍就可以了
// 分析: 64位ll-->8B*5e7=4e8=4M>30M?  好像不对，不过反正此题真的不需要太多内存数组，因为后面素数没那么多

#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
#define ll long long
// const int M = 5e7+10;
const int M = 1e6+5;
const int mod = 9901;
bool noprime[M];
int p[M];
int k = 0;
ll fac[M/100],num[M/100];
int cnt = 0;

void isPrime(){
    k = 0;
    noprime[1] = 1;
    for(int i = 2;i<M;i++){
        if(!noprime[i]){
            p[k++] = i;
            for(int j=i;j<M;j+=i) noprime[j]=1;
        }
    }
}

void Dec(int a){
    cnt = 0;
    memset(num,0,sizeof(num));
    for(int i=0;p[i]*p[i]<=a;i++){
        if(a%p[i]==0){
            fac[cnt]=p[i];
            while(a%p[i]==0) {
                num[cnt]++;
                a/=p[i];
            }
            cnt++;
        }
    }
    if(a>1){
        fac[cnt]=a;
        num[cnt]=1;
        cnt++;
    }
}

ll mypow(ll a,ll b,int mod){
    ll ans = 1;
    for(;b;b>>=1){
        if(b&1) ans = ans*a%mod;  // 如果是奇数，乘掉上次的a值
        a = a*a%mod;
    }
    return ans;
}

ll getSum(ll p,ll c){
    if(c==0) return 1;
    if(c&1) return (1+mypow(p,(c+1)/2,mod))*getSum(p,(c-1)/2)%mod;
    else return ((1+mypow(p,(c)/2,mod))*getSum(p,c/2-1)%mod + mypow(p,c,mod))%mod;
}

int main(int argc, char const *argv[])
{
    isPrime();
    int a,b;
    while(cin>>a>>b){
        Dec(a);
        ll ans = 1;
        for(int i=0;i<cnt;i++){
            ans = (ans*getSum(fac[i],num[i]*b))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}