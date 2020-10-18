#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=205000;
char ss[maxn];
int belong[maxn];
int s[maxn],rs[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn];
int n,m,tt;
int rank[maxn],height[maxn];
int len,l;
inline int idx(char c){ return c-'a'+1; }
inline char fdx(int x){ return char(x-1+'a'); }
void calheight(int n){
    int i,k=0;
    for (i=0; i<=n; i++) ::rank[sa[i]]=i;
    for (i=0; i<n; i++){
        if (k) k--;
        int j=sa[::rank[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[::rank[i]]=k;
    }
}

void da(int m,int n){
    n++;
    int i,*x=t,*y=t2;
    for (int i=0; i<m; i++) c[i]=0;
    for (int i=0; i<n; i++) c[x[i]=s[i]]++;
    for (int i=1; i<m; i++) c[i]+=c[i-1];
    for (int i=n-1; i>=0; i--)
      sa[--c[x[i]]]=i;
    for (int k=1; k<=n; k<<=1){
        int p=0;
        for (i=n-k; i<n; i++) y[p++]=i;
        for (i=0; i<n; i++) if (sa[i]>=k) y[p++]=sa[i]-k;

        for (i=0; i<m; i++) c[i]=0;
        for (i=0; i<n; i++) c[x[y[i]]]++;
        for (i=1; i<m; i++) c[i]+=c[i-1];
        for (i=n-1; i>=0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p=1;
        x[sa[0]]=0;
        for (i=1; i<n; i++)
        x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])? p-1 : p++;
        if (p>=n) break;
        m=p;
    }
}

/*d[0]存着height的rmq,d[1]存着sa的rmq*/
int d[2][maxn][50];
int LOG[maxn];
int RMQ_init(int x,int A[]){
    for(int i=1; i<=n; i++) d[x][i][0]=A[i];
    for (int j=1; (1<<j)<=n; j++)
        for (int i=1; i+(1<<j)-1<=n; i++)
            d[x][i][j]=min(d[x][i][j-1],d[x][i+(1<<(j-1))][j-1]);
    return 0;
}

int RMQ(int x,int L,int R){
    int k=LOG[R-L+1];
    return min(d[x][L][k],d[x][R-(1<<k)+1][k]);
}
ll num[maxn];
int main(){
    // freopen("in.txt","r",stdin);
    int k=0;
    for (int i=0; i<105000; i++){
        while((1<<(k+1))<=i) k++;
        LOG[i]=k;
    }
    while(~scanf("%s",ss)){
        int l=strlen(ss);
        for(int i=0; i<l; i++) s[i]=idx(ss[i]);
        n=l;
        s[n]=0;
        da(33,n);
        calheight(n);

        for (int i=0; i<=n; i++) num[i]=n-sa[i];
        for (int i=1; i<=n; i++) num[i]-=height[i];
        for (int i=1; i<=n; i++) num[i]+=num[i-1];
        ll tot=num[n];
        scanf("%d",&m);
        ll la=0,lb=0;
        ll k;
        RMQ_init(0,height);
        RMQ_init(1,sa);
        while(m--){
            scanf("%lld",&k);
            k^=la;k^=lb;k++;
            if (k>=1 && k<=tot){
                int pos=lower_bound(num+1,num+1+n,k)-num;
                /*这个len求得很精致,k-(pos-1)位置起始的不同串的个数,这样就能得到k结束位置距离height结束位置的串长，加上height就是正好len*/
                int len=k-num[pos-1]+height[pos];
                int l=pos+1,r=n;
                int mid;
                int L=pos,R;
                /*二分右端点使得右边的最需最长公共字串是我们的k长串*/
                while(l<r){
                    mid=(l+r)>>1;
                    if (RMQ(0,pos+1,mid)>=len) l=mid+1;
                    else r=mid;
                }
                /*因为上面二分是mid+1,所以这里需要保险一下*/
                if (RMQ(0,pos+1,l)>=len) R=l;
                else R=l-1;
/*              只要求右边就可以，左边的height值中前缀rank值都比k小！--->后面看到chanme大佬早就这样干了...
                l=1; r=pos;
                while(l<r){
                    mid=(l+r)>>1;
                    if (RMQ(0,mid,pos)>=len) r=mid;
                    else l=mid+1;
                }
                if (RMQ(0,l,pos)>=len) L=l-1;
                else L=l;
*/
                /*所有地方求最小的sa*/
                la=RMQ(1,L,R);
                lb=la+len-1;
                la++;
                lb++;
                printf("%lld %lld\n",la,lb);
            }
            else la=lb=0,puts("0 0");
        }
    }
    return 0;
}