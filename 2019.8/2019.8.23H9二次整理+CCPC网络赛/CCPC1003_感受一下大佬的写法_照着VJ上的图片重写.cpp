#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 2e9;
const int maxn = 1e5+5;
string s;
struct SA{
    int n,m;
    vector<int> a,d,sa,rk,ht;

    void rsort(){
        vector<int> c(m+1);
        for(int i=1;i<=n;i++) c[rk[d[i]]]++;
        for(int i=1;i<=m;i++) c[i]+=c[i-1];
        for(int i=n;i;i--) sa[c[rk[d[i]]]--]=d[i];
    }

    SA(const string& s) : n(s.size()),m(128),a(n+1),d(n+1),sa(n+1),rk(n+1),ht(n+1){
        for(int i=1;i<=n;i++) rk[i]=a[i]=s[i-1], d[i]=i;
        rsort();
        for(int j=1,i,k;k<n;m=k,j<<=1){
            for(i=n-j+1,k=0;i<=n;i++) d[++k] = i;
            for(i=1;i<=n;i++) if(sa[i]>j) d[++k] = sa[i] - j;
            rsort(); swap(rk,d); rk[sa[1]] = k = 1;
            for(i = 2; i <= n; i++){
                rk[sa[i]] = (d[sa[i]] == d[sa[i-1]] && d[sa[i] + j] == d[sa[i - 1] + j]) ? k : ++k;
            }
        }
        int j, k = 0;
        for(int i = 1; i <= n; ht[rk[i++]] = k){
            for(k ? k-- : k, j = sa[rk[i] - 1]; a[i+k] == a[j+k]; ++k);
        }
    }
};

class Tseg{
    private:
        int tot, n;
        struct Tnode{
            Tnode *ls, *rs; int sum;
        } *root[maxn],t[maxn*40];
        Tnode *newnode(){
            ++tot;
            t[tot].ls = t[tot].rs = 0;
            t[tot].sum = 0; return &t[tot];
        }
        void Build(Tnode *&p, int l, int r){
            p = newnode();
            if(l == r) return;
            int mid = (l+r)>>1;
            Build(p->ls,l,mid);
            Build(p->rs,mid+1,r);
        }
        void Insert(Tnode *&p, Tnode *last,int l,int r,int x){
            p = newnode();
            *p = *last; p->sum++;
            if(l == r) return;
            int mid = (l + r) >> 1;
            if(x <= mid) Insert(p->ls,last->ls,l,mid,x);
            else Insert(p->rs,last->rs,mid+1,r,x);
        }
        int Query(Tnode *x,Tnode *y,int l,int r,int k){
            if(l == r) return l;
            int mid = (l+r) >> 1, tmp = y->ls->sum - x->ls->sum;
            if(tmp >= k) return Query(x->ls,y->ls,l,mid,k);
            else return Query(x->rs,y->rs,mid+1,r,k-tmp);
        }
    public:
        void build(int nn){tot=0; n = nn; Build(root[0], 1, n);}
        void insert(int k, int x){
            Insert(root[k],root[k-1],1,n,x);
        }
        int query(int x,int y,int k){
            return Query(root[x-1],root[y],1,n,k);
        }
} T;

struct SegmentTree{
    int l,r;
    ll dat;
} t[8 * maxn];

ll cal(ll a,ll b) {return min(a,b);}

/* build(1,1,n) */
void build(int p,int l,int r,SA &qaq){
    t[p].l = l; t[p].r = r;
    if(l == r){
        t[p].dat = qaq.ht[l]; return;
    }
    build(p*2,l,(l+r)/2,qaq); build(p*2+1,(l+r)/2+1,r,qaq);
    t[p].dat = cal(t[p*2].dat, t[p*2+1].dat);
}

/* [l,r] x*/
int query_1(int p,int r, ll x){
    if(t[p].r <= r){
        if(t[p].dat >= x) return -1;
        if(t[p].l == t[p].r) return t[p].l;
        if(t[p*2 + 1].dat >= x) return query_1(p*2,r,x);
        else return query_1(p*2+1,r,x);
    }
    int res = query_1(p*2,r,x), mid = (t[p].l + t[p].r) / 2;
    if(mid>=r) return res;
    /*else if(mid<r) */return max(res,query_1(p*2+1,r,x));
}

/* [l,n] x*/
int query_2(int p,int l,ll x){
    if(t[p].l >= l){
        if(t[p].l >= l){
            if(t[p].dat >= x) return inf;
            if(t[p].l == t[p].r) return t[p].l;
            if(t[p*2].dat >= x) return query_2(p*2+1,l,x);
            else return query_2(p*2,l,x);
        }
    }
    int res = query_2(p*2+1, l, x), mid = (t[p].l + t[p].r) / 2;
    if(mid < l) return res;
    /*else if(mid >= l) */return min(res, query_2(p*2, l, x));
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        char buf[100005];
        scanf("%s",buf);
        s = string(buf);
        SA qaq(s);
        T.build(n);
        for(int i=1;i<=n;i++) T.insert(i,qaq.sa[i]);
        build(1,1,n,qaq);
        while(q--){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            int curl = query_1(1,qaq.rk[l],r-l+1),curr;
            if(qaq.rk[l] == n) curr = n;
            else{
                curr = query_2(1,qaq.rk[l]+1,r-l+1);
                if(curr == inf) curr = n;
                else curr--;
            }
            bool ok = 1;
            /*这里curl错写成curr,害我检查了一遍全部*/
            if(curr == -1) curl = 1;

            if(curr - curl + 1 < k) ok = 0;
            if(ok){
                int res = T.query(curl,curr,k);
                printf("%d\n", res);
            }
            else printf("-1\n");
        }
    }


    return 0;
}