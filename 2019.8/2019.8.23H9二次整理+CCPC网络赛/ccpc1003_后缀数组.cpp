#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
int T,query;
char ss[maxn];
int belong[maxn];
int s[maxn],rs[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn];
int n,m,tt;
int rank[maxn],height[maxn];
int l,r;
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
    // ios::sync_with_stdio(false);cin.tie(0);
    scanf("%d",&T);
    int k=0;
    for (int i=0; i<105000; i++){
        while((1<<(k+1))<=i) k++;
        LOG[i]=k;
    }
    while(T--){
        scanf("%d%d",&n,&query);
        scanf("%s",ss);
        for(int i=0; i<n; i++) s[i]=idx(ss[i]);
        /*da函数里面有n++,所以odk的*/
        s[n]=0; da(33,n); calheight(n);
        while(query--){
            scanf("%d%d%d",&l,&r,&k);
            l--,r--;
            int pos = ::rank[l],len = r-l+1;

            int pl=pos+1,pr=n;
            int mid;
            int L,R;

            /*2019年8月23日13:48:06 发现这里的rmq是求位置值,是不对的
            我们应该直接在rank[l]左右遍历求第k大sa就行了!,odk,重写*/



            /*二分右端点使得右边的最需最长公共字串是我们的k长串*/
            while(pl<pr){
                mid=(pl+pr)>>1;
                if (RMQ(0,pos+1,mid)>=len) pl=mid+1;
                else pr=mid;
            }
            /*因为上面二分是mid+1,所以这里需要保险一下*/
            if (RMQ(0,pos+1,pl)>=len) R=pl;
            else R=pl-1;

            pl=1; pr=pos;
            while(pl<pr){
                mid=(pl+pr)>>1;
                if (RMQ(0,mid,pos)>=len) pr=mid;
                else pl=mid+1;
            }
            if (RMQ(0,pl,pos)>=len) L=pl-1;
            else L=pl;

            if(R-L+1<k) printf("-1\n");
            else{
                /*总之要遍历左右排序sa,那为什么还要rmq求出L,R
                直接暴力L,R更节约时间吧...*/
                vector<int> ans;
                for(int i=L;i<=R;i++){
                    ans.push_back(sa[i]);
                }
                sort(ans.begin(), ans.end());
                // cout<<ans[k-1]<<endl;
                printf("%d\n",ans[k-1] );
            }
        }

    }

    return 0;
}