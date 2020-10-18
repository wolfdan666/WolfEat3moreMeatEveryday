#include<iostream>
#include<cstdio>
#define LL __int128
using namespace std;
const LL MAXN = 1e6 + 10;
LL n, C[MAXN], M[MAXN], x, y,Max;
template <class T>
inline bool scan_d(T &ret){
    char c;int sgn;
    if(c=getchar(),c==EOF)return 0;
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9')ret = ret *10+(c-'0');
    ret*=sgn;
    return 1;
}
inline void out(LL x){
    if(x>9)out(x/10);
    putchar(x%10+'0');
}
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {x = 1, y = 0; return a;}
    LL r = exgcd(b, a % b, x, y), tmp;
    tmp = x; x = y; y = tmp - (a / b) * y;
    return r;
}
LL excrt() {
    LL n1=M[1],a1=C[1],n2,a2,k1,k2,x0,gcd,c;
    for(int i=2;i<=n;i++){
        n2=M[i],a2=C[i];
        c=a2-a1;
        gcd=exgcd(n1,n2,k1,k2);//解得：n1*k1+n2*k2=gcd(n1,n2)
        if(c%gcd){
          return -1;
        }
        x0=c/gcd*k1;//n1*x0+n2*(c/gcd*k2)=c  PS:k1/gcd*c错误！
        LL t=n2/gcd;
        x0=(x0%t+t)%t;//求n1*x0+n2*y=c的x0的最小解
        a1+=n1*x0;
        n1=n2/gcd*n1;
    }
    return  a1;
}
int main() {
    scan_d(n);scan_d(Max);
    for(int i=1; i<=n; i++)
        scan_d(M[i]),scan_d(C[i]);
    LL ans = excrt();
    if(ans==-1)
    {
        printf("he was definitely lying\n");
    }
    else
    {
        if(ans<=Max)
            out(ans),puts("");
        else
            printf("he was probably lying\n");
    }
}