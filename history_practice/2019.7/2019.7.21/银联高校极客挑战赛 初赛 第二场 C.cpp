/*
2019年7月21日18:57:28 在网上找到的大佬的代码

大佬一:

题意：给出一个n表示点数，请问由n个节点构成的所有有标号无根树的叶子节点数总和。


首先这个“有标号无根树”的描述就强烈暗示与purfer序列有关了，每一个不同的purfer序列唯一地表示一种树的构成，
并且这个序列对答案的贡献等于序列中没有出现过的数字的个数。

然后我们就可以去求每个恰好出现过k个颜色的序列的方案数，也就是说，我们可以发现这个方案数恰好为C(n,k)*T(n,k)*k!
 T为第二类斯特林数，第二类斯特林数我们需要用NTT卷积的方式nlogn地求出，可以去找个板子来求。

大佬二：
简单的就是让你求n个点的组成的所有树中  总共有多少个叶子节点（就是每棵树上的叶子节点加起来）

n个点的无根树一共有n^(n-2) 棵  （定理）

自己写几个简单的数据
比如:

N    =   2              3              4       

ans =   2              6              36

ans/N   1              2              9     

        1^0           2^1            3^2

    (2-1)^(2-2)     (3-1)^(3-2)    (4-1)^(4-2)


由于N<=1e5

直接预处理出ans/N数组  sum[i]；

ans = sum[N] * N %mod;
---------------------
作者：Cherry_93
原文：https://blog.csdn.net/Daxian911/article/details/96728897
*/

#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=4e5+10;
const LL P=998244353,yg=3;
LL n,fac[N],inv[N],f[N],g[N],S2[N];
LL bin[N];

LL power(LL x,LL p) {
    LL ret=1;
    for (;p;p>>=1) {
        if (p&1) ret=(ret*x)%P;
        x=(x*x)%P;
    }
    return ret;
}

void NTT(LL *a,LL n,LL op) {  //NTT:系数a数组，长度为n，op=1求值op=-1插值
    for(LL i=0;i<n;i++) bin[i]=(bin[i>>1]>>1)|((i&1)*(n>>1));
    for(LL i=0;i<n;i++) if(i<bin[i]) swap(a[i],a[bin[i]]);
    for(LL i=1;i<n;i<<=1) {
        LL wn=power(yg,op==1?(P-1)/(2*i):(P-1)-(P-1)/(2*i)),w,t;
        for(LL j=0;j<n;j+=i<<1) {
            w=1;
            for(LL k=0;k<i;k++) {
                t=a[i+j+k]*w%P;w=w*wn%P;
                a[i+j+k]=(a[j+k]-t+P)%P;a[j+k]=(a[j+k]+t)%P;
            }
        }
    }
    if(op==-1) {
        LL Inv=power(n,P-2);
        for(LL i=0;i<n;i++) a[i]=a[i]*Inv%P;
    }
}
long long C(long long n,long long m){return fac[n]*inv[m]%P*inv[n-m]%P;}
int main()
{
    cin>>n;
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    if(n==2)
    {
        printf("2\n");
        return 0;
    }
    fac[0]=inv[0]=1;
    for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%P,inv[i]=power(fac[i],P-2);
    for (int i=0;i<=n;i++) f[i]=(power(-1,i)+P)%P*inv[i]%P;
    for (int i=0;i<=n;i++) g[i]=power(i,n-2)*inv[i]%P;

    LL N=n-1;
    LL len=1;while(len<(n+1)<<1) len<<=1;

    NTT(f,len,1); NTT(g,len,1);
    for (int i=0;i<len;i++) S2[i]=(f[i]*g[i])%P;  //求f.g的卷积为S2
    NTT(S2,len,-1);

    long long ans=0;
    for(int i=1;i<=n-2;i++)
    {
        long long d=fac[i]*S2[i];
        d%=P;
        //printf("%d %lld %lld\n",n-i,d,S2[i]);
        ans+=d*C(n,i)%P*(n-i)%P;
        ans%=P;
    }
    ans%=P,ans+=P,ans%=P;
    printf("%lld\n",ans);
    return 0;
}



#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const int maxn=1e6+5;
ll sum[maxn];
ll n;
ll ksm(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b&1) ans = (ans * a) %mod;
        a =a * a%mod;
        b>>=1;
    }
    return ans%mod;
}
int main()
{
    scanf("%lld",&n);
    for(int i=2;i<=n;i++) {
        sum[i] = ksm(i-1,i-2);
    }
    printf("%lld\n",n*sum[n] %mod);
    return 0;
}