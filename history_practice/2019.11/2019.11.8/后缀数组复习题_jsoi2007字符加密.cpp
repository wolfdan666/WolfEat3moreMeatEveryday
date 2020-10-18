/*
RE两个测试集...

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
const int maxn=200010;
int sa[maxn],height[maxn],rank[maxn],t[maxn],t2[maxn],c[maxn];
int n;
char str[maxn];

void build_sa(int m,int n){
    int *x=t,*y=t2;
    for(int i=0;i<m;i++)c[i]=0;
    for(int i=0;i<n;i++)c[x[i]=str[i]]++;
    for(int i=1;i<m;i++)c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
        for(int i=0;i<m;i++)c[i]=0;
        for(int i=0;i<n;i++)c[x[y[i]]]++;
        for(int i=1;i<m;i++)c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        x[sa[0]]=0;p=1;
        for(int i=1;i<n;i++)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++);
        if(p>=n)break;
        m=p;
    }
}

void getheight(int n){
    int k=0;
    for(int i=1;i<=n;i++)::rank[sa[i]]=i;
    for(int i=0;i<n;i++){
        if(k)k--;
        int j=sa[::rank[i]-1];
        while(str[i+k]==str[j+k])k++;
        height[::rank[i]]=k;
    }
}

int main(){
    scanf("%s",str);
    int n = strlen(str);
    rep(i,n,2*n-1) str[i]=str[i-n]; str[2*n]='\0';

    // cout<<str<<endl;

    n <<= 1;
    build_sa(257,n+1);
    getheight(n);
    int tp = n>>1;
    rep(i,1,n){
        if(sa[i]<tp){
            printf("%c", str[sa[i]+tp-1]);
        }
    }


    return 0;
}