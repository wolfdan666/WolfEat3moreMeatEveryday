#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+50;
int ls[maxn*80],rs[maxn*80],rt[maxn*80],sum[maxn*80],cnt;

void update(int &o,int l,int r,int pos){
    if(!o)o=++cnt;
    if(l==r){
        sum[o]++;return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)update(ls[o],l,mid,pos);
    else update(rs[o],mid+1,r,pos);
    sum[o]=sum[ls[o]]+sum[rs[o]];
}

int merger(int o,int pre,int l,int r){
    if(!o)return pre;if(!pre)return o;
    int k=++cnt;
    if(l==r){
        sum[k]=sum[o]+sum[pre];
        return k;
    }int mid=(l+r)/2;
    ls[k]=merger(ls[o],ls[pre],l,mid);
    rs[k]=merger(rs[o],rs[pre],mid+1,r);
    sum[k]=sum[ls[k]]+sum[rs[k]];
    return k;
}

int query(int o,int l,int r,int k){
    if(sum[o]<k)return -1;
    if(l==r)return l;
    int mid=(l+r)/2;
    if(sum[ls[o]]>=k)return query(ls[o],l,mid,k);
    else return query(rs[o],mid+1,r,k-sum[ls[o]]);
}

struct Q{
    int l,r,k,id;
    bool operator<(const Q &o)const{
        return r<o.r;
    }
} my[maxn];
int n;
char s[maxn];
int ans[maxn];

struct SAM{
    int fa[maxn],ch[maxn][26],maxlen[maxn],tot,last;
    int sz[maxn],a[maxn],b[maxn];
    void init(){
        cnt=0;
        fill(rt,rt+n*80,0);
        fill(ls,ls+n*80,0);
        fill(rs,rs+n*80,0);
        fill(sum,sum+n*80,0);
        tot=last=1;maxlen[1]=fa[1]=0;
        memset(ch[1],0,sizeof(ch[1]));
    }
    void add(int x,int id){
        int np=++tot,p=last;last=np;update(rt[np],1,n,id);
        maxlen[np]=maxlen[p]+1;sz[np]=1;
        memset(ch[np],0,sizeof(ch[np]));
        while(p&&!ch[p][x])ch[p][x]=np,p=fa[p];
        if(!p)fa[np]=1;
        else{
            int q=ch[p][x];
            if(maxlen[q]==maxlen[p]+1)fa[np]=q;
            else{
                int nq=++tot;
                memcpy(ch[nq],ch[q],sizeof(ch[q]));
                fa[nq]=fa[q],fa[np]=fa[q]=nq;
                maxlen[nq]=maxlen[p]+1;
                while(p&&ch[p][x]==q)ch[p][x]=nq,p=fa[p];
            }
        }
    }
    int pa[maxn][25];
    void Sort(){///拓扑排序 得到每个集合里的串出现次数
        for(int i=1;i<=tot;i++)a[i]=0;
        for(int i=1;i<=tot;i++)a[maxlen[i]]++;
        for(int i=1;i<=tot;i++)a[i]+=a[i-1];
        for(int i=1;i<=tot;i++)b[a[maxlen[i]]--]=i;
        for(int i=tot;i;i--)sz[fa[b[i]]]+=sz[b[i]];
        for(int i=tot;i;i--){
            int k=b[i];
            pa[k][0]=fa[k];
            rt[fa[k]]=merger(rt[fa[k]],rt[k],1,n);
        }
        for(int i=1;i<=20;i++){
            for(int j=1;j<=tot;j++){
                int v=pa[j][i-1];
                pa[j][i]=pa[v][i-1];
            }
        }
    }
    int go(int id,int len){
        for(int i=20;i>=0;i--){
            if(maxlen[pa[id][i]]>=len)id=pa[id][i];
        }
        return id;
    }
    int m;
    void slove(){
        for(int i=1;i<=m;i++){
            cin>>my[i].l>>my[i].r>>my[i].k;
            my[i].id=i;
        }
        sort(my+1,my+1+m);
        int now=1;
        int tail=1;
        for(int i=1;i<=n;i++){
            int x=s[i]-'a';
            now=ch[now][x];
            while(tail<=m&&my[tail].r==i){
                int len=my[tail].r-my[tail].l+1;
                int where=go(now,len);
                int aa=query(rt[where],1,n,my[tail].k);
                if(aa==-1)ans[my[tail].id]=-1;
                else{
                    ans[my[tail].id]=aa-len+1;
                }
                tail++;
            }
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
    }
} S;

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;cin>>S.m;
        cin>>s+1;
        n=strlen(s+1);S.init();
        for(int i=1;i<=n;i++)S.add(s[i]-'a',i);
        S.Sort();
        S.slove();
    }
    return 0;
}
