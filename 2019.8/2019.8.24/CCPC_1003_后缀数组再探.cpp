/*ST表维护下 后缀排序后的公共长度 的最小值，然后二分找出左右符合的位置，主席树维护下排序后的序列，然后主席树查询第k大即可*/

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N=100100;
int t1[N],t2[N],sum[N],rk[N],ht[N],sa[N],str[N];
void get_sa(int n,int m){
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++) sum[i]=0;
    for(int i=0;i<n;i++) sum[x[i]=str[i]]++;
    for(int i=1;i<m;i++) sum[i]+=sum[i-1];
    for(int i=n-1;i>=0;i--) sa[--sum[x[i]]]=i;
    for(int p,j=1;p<=n;j<<=1){
        p=0;
        for(int i=n-j;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(int i=0;i<m;i++) sum[i]=0;
        for(int i=0;i<n;i++) sum[x[y[i]]]++;
        for(int i=1;i<m;i++) sum[i]+=sum[i-1];
        for(int i=n-1;i>=0;i--) sa[--sum[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;
        x[sa[0]]=0;
        for(int i=1;i<n;i++) x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n) break;
        m=p;
    }
    int k=0;n--;
    for(int i=0;i<=n;i++) rk[sa[i]]=i;
    for(int i=0;i<n;i++){
        if(k)k--;else k=0;
        int j=sa[rk[i]-1];
        while(str[i+k]==str[j+k])k++;
        ht[rk[i]]=k;
    }
}

struct node1 {
    int l, r;
    int val;
} tr[N * 22];
int f[N][22];
void build(int n) {
    for(int i = 1; i <= n; i++) f[i][0] = ht[i];
    for(int i = 1; i < 22; i++) {
        for(int j = 1; j + (1 << i) - 1 <= n; j++)
            f[j][i] = min(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
    }
}
int query(int pl, int pr) {
    int t = log2(pr - pl + 1.0);
    return min(f[pl][t], f[pr - (1 << t) + 1][t]);
}
int root[N], tot;
int update1(int pre, int l, int r, int pos) {
    int cur = ++tot;
    tr[cur] = tr[pre];
    tr[cur].val++;
    if(l == r) return cur;
    int mid = (l + r) >> 1;
    if(pos <= mid) tr[cur].l = update1(tr[pre].l, l, mid, pos);
    else tr[cur].r = update1(tr[pre].r, mid + 1, r, pos);
    return cur;
}
int queryk(int pl, int pr, int l, int r, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(tr[tr[pr].l].val - tr[tr[pl].l].val >= k) return queryk(tr[pl].l, tr[pr].l, l, mid, k);
    else return queryk(tr[pl].r, tr[pr].r, mid + 1, r, k - (tr[tr[pr].l].val - tr[tr[pl].l].val));
}
char s[100100];
int main(){
    int n, m;
    int T;
    int l, r, k;
    int ll, rr, mid;
    int tmp;
    int cntl, cntr;
    int cnt;
    scanf("%d",&T);
    while(T--){
        tot = 0;
        scanf("%d %d", &n, &m);
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<n;i++) str[i] = s[i] - 'a' + 1;
        str[n]=0;
        get_sa(n+1,30);
        build(n);
        for(int i = 1; i <= n ; i++) {
            root[i] = update1(root[i - 1], 1, n, sa[i] + 1);
        }
        while(m--) {
            scanf("%d %d %d", &l, &r, &k);
            tmp = r - l + 1;
            l = rk[l - 1];
            ll = 1, rr = l;
            while(ll <= rr) {
                mid = (ll + rr) >> 1;
                cnt = 100000;
                if(mid + 1 <= l) cnt = query(mid + 1, l);
                if(cnt >= tmp) {
                    cntl = mid;
                    rr = mid - 1;
                } else {
                    ll = mid + 1;
                }
            }
            ll = l, rr = n;
            while(ll <= rr) {
                mid = (ll + rr) >> 1;
                cnt = 100000;
                if(l + 1 <= mid) cnt = query(l + 1, mid);
                if(cnt >= tmp) {
                    cntr = mid;
                    ll = mid + 1;
                } else {
                    rr = mid - 1;
                }
            }
            if(cntr - cntl + 1 < k) printf("-1\n");
            else {
                printf("%d\n", queryk(root[cntl - 1], root[cntr], 1, n, k));
            }
        }
    }
    return 0;
}