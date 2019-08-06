#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 111111

int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b] && r[a+l]==r[b+l];
}
int sa[MAXN],rnk[MAXN],height[MAXN];
void SA(int *r,int n,int m){
    int *x=wa,*y=wb;

    for(int i=0; i<m; ++i) ws[i]=0;
    for(int i=0; i<n; ++i) ++ws[x[i]=r[i]];
    for(int i=1; i<m; ++i) ws[i]+=ws[i-1];
    for(int i=n-1; i>=0; --i) sa[--ws[x[i]]]=i;

    int p=1;
    for(int j=1; p<n; j<<=1,m=p){
        p=0;
        for(int i=n-j; i<n; ++i) y[p++]=i;
        for(int i=0; i<n; ++i) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(int i=0; i<n; ++i) wv[i]=x[y[i]];
        for(int i=0; i<m; ++i) ws[i]=0;
        for(int i=0; i<n; ++i) ++ws[wv[i]];
        for(int i=1; i<m; ++i) ws[i]+=ws[i-1];
        for(int i=n-1; i>=0; --i) sa[--ws[wv[i]]]=y[i];
        swap(x,y); x[sa[0]]=0; p=1;
        for(int i=1; i<n; ++i) x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }

    for(int i=1; i<n; ++i) rnk[sa[i]]=i;
    int k=0;
    for(int i=0; i<n-1; height[rnk[i++]]=k){
        if(k) --k;
        for(int j=sa[rnk[i]-1]; r[i+k]==r[j+k]; ++k);
    }
}

int n,st[17][MAXN];
void ST(int *a){
    for(int i=1; i<=n; ++i) st[0][i]=a[i];
    for(int i=1; i<17; ++i){
        for(int j=1; j<=n; ++j){
            if(j+(1<<i)-1>n) continue;
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
        }
    }
}
int logs[MAXN];
int rmq(int a,int b){
    int k=logs[b-a+1];
    return min(st[k][a],st[k][b-(1<<k)+1]);
}
int lcp(int a,int b){
    if(a==b) return n-sa[a];
    return rmq(a+1,b);
}

int tree[MAXN<<2],N,x,y;
void update(int i,int j,int k){
    if(i==j){
        tree[k]=y;
        return;
    }
    int mid=i+j>>1;
    if(x<=mid) update(i,mid,k<<1);
    else update(mid+1,j,k<<1|1);
    tree[k]=min(tree[k<<1],tree[k<<1|1]);
}
int query(int i,int j,int k){
    if(x<=i && j<=y){
        return tree[k];
    }
    int mid=i+j>>1,ret=MAXN;
    if(x<=mid) ret=min(ret,query(i,mid,k<<1));
    if(y>mid) ret=min(ret,query(mid+1,j,k<<1|1));
    return ret;
}

char str[MAXN];
int a[MAXN];

long long sum[MAXN];
int dis[MAXN];

int main(){
    for(int i=1; i<MAXN; ++i){
        logs[i]=log2(i)+1e-6;
    }
    while(~scanf("%s",str)){
        n=strlen(str);
        for(int i=0; i<n; ++i){
            a[i]=str[i]-'a'+1;
        }
        a[n]=0;
        SA(a,n+1,28);
        ST(height);

        memset(tree,127,sizeof(tree));
        for(N=1; N<n; N<<=1);
        for(int i=1; i<=n; ++i){
            x=i; y=sa[i];
            update(1,N,1);
        }

        for(int i=1; i<=n; ++i){
            sum[i]=n-sa[i]-height[i]+sum[i-1];
            dis[i]=height[i];
        }

        int q;
        long long v,ansl=0,ansr=0;
        scanf("%d",&q);
        while(q--){
            scanf("%I64d",&v);
            long long k=(ansl^ansr^v)+1;

            if(k>sum[n]){
                ansl=0; ansr=0;
                puts("0 0");
                continue;
            }

            int tmp=lower_bound(sum+1,sum+1+n,k)-sum;
            int len=dis[tmp]+k-sum[tmp-1];

            int l=1,r=tmp;
            while(l<r){
                int mid=l+r>>1;
                if(lcp(mid,tmp)>=len) r=mid;
                else l=mid+1;
            }
            x=l;

            l=tmp; r=n;
            while(l<r){
                int mid=l+r+1>>1;
                if(lcp(tmp,mid)>=len) l=mid;
                else r=mid-1;
            }
            y=l;

            ansl=query(1,N,1)+1; ansr=ansl+len-1;
            printf("%I64d %I64d\n",ansl,ansr);
        }
    }
    return 0;
}