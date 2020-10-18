#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

const double eps=1e-8;
const ll inf=1e9;
const ll mod=1e9+7;
const int maxn=1e5+10;

///sum(sum(i*j*(n mod i)(m mod j)) mod 1e9+7
///1e9

int maxv=1e5;

//int zhi[maxn];
bool vis[maxn];

ll work(ll n)
{
    ll l,r,sum=0,a0,b0,q,g,xx,yy,zz;
    for (l=1;l<=n;l=r+1)
    {
        r=n/(n/l);
        if (l==r)
            sum+=n%l*l;
        else
        {
            ///a0=l,b0,q,g
            a0=l;
            b0=n%l;
            q=n/l;
            g=r-l+1;

            ///0^2+1^2+...
            (sum+=a0*b0%mod*g)%=mod;
            if (g&1)
                (sum+=b0*g%mod*((g-1)/2))%=mod;
            else
                (sum+=b0*(g/2)%mod*(g-1))%=mod;
            if (g&1)
                (sum-=a0*q%mod*g%mod*((g-1)/2))%=mod;
            else
                (sum-=a0*q%mod*(g/2)%mod*(g-1))%=mod;

            xx=g-1;
            yy=g;
            zz=2*g-1;
            if (xx%2==0)
                xx/=2;
            else if (yy%2==0)
                yy/=2;
            else
                zz/=2;
            if (xx%3==0)
                xx/=3;
            else if (yy%3==0)
                yy/=3;
            else
                zz/=3;
            (sum-=q*xx%mod*yy%mod*zz)%=mod;
//                q*(g-1)*g*(2*g-1)/6
            ///sum+=a0*b0*g + b0*g*(g-1)/2 - a0*q*g*(g-1)/2 - q*(g-1)*g*(2*g-1)/6;

//            sum+=a0*g-q*g*(g-1)/2;
        }
//        printf("%lld %lld\n",l,r);
    }
    return sum;
}

int main()
{
    /*
    ///n 最小的质因数
    for (i=2;i<=maxv;i++)
    {
        if (!vis[i])
        {
            zhi[++cnt_zhi]=i;
            for (j)
        }
    }
    */

    ll n,m,i;
    ///two parts
    scanf("%lld%lld",&n,&m);
    printf("%lld",(work(n)*work(m)%mod+mod)%mod);
    return 0;
}
/*
1 1
2 2
3 3
4 4
5 5
6 6
7 7
1000000000 1000000000
*/