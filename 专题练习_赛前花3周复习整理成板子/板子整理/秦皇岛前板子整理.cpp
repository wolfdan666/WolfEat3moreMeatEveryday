// 快读
inline int read() {
    int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for (;isdigit(ch);ch=getchar())x=x*10+ch-'0';return x*f;
}

// Log预处理
void log_pre() {
    Log[1] = 0;
    for(int i = 2; i < maxn; i++) Log[i] = Log[i/2] + 1;
}

// 这一部分就是st表的rmq预处理 nlog(n)
void st_rmq{
    for (int i = 1; i <= m; i++) f[i][0] = read();
    log_pre();
    for (int j = 1; j <= logn; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

// 单调栈模板去面积题
#include<btis/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e5+10;
int n,h[M],w[M],s[M];
ll ans;

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        if(n==0) break;
        /* init */
        h[n+1] = 0;
        ans = 0;
        int p = 0; s[p] = 0;
        memset(w,0,sizeof(w));
        /*solve*/
        for(int i = 1;i <= n+1;i++){
            if(i!=n+1) cin>> h[i];
            if(h[i]>s[p]){
                s[++p] = h[i],w[p] = 1;
            }else{
                int width = 0;
                while(s[p] > h[i]){
                    width += w[p];
                    ans = max(ans,(ll)width*s[p]);
                    p--;
                }
                s[++p] = h[i],w[p] = width+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

// 字符串Hash+自建Maphash处理冲突_2019上海网络赛G
#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define pre(i,a,n) for(int i=n;i>=a;--i)
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#ifdef ONLINE_JUDGE
    const int N = 1e5+50;
#else
    const int N = 1e2+10;
#endif

char s[N],p[N];
int n, m;
const int bas = 1e9+7;
ull get(int *a) {
    ull ret = 0;
    rep(i,0,27) {
        ret = ret*bas+a[i]+1;
    }
    return ret;
}
struct node {
    ull sta;
    int id;
};
vector<node> g[N];


int ans[N];
ull fac[N];

int clk;

// 手写的Hash,因为unorder_map<int,int> f[26][26]被卡时间
namespace Hash{
  const int hashmod = 218357;
  int v[hashmod];
  unsigned long long h[hashmod];
  int vis[hashmod];
  int &get(unsigned long long S) {
    int t2 = S % hashmod, i;
    // vis[i]是访问过的(clk恒为1)，所以也要走下一个
    // h[i] = S.则发生了hash crash(哈希碰撞)，就要走到下一个，也就是h[i] != S 走下一个
    // i = t2-1说明走了一个轮回了，就不用再走了，再走就是重复走t2位置了,所以i!=t2-1
    for (i = t2; vis[i]==clk && h[i] != S && i != t2 - 1; i = (i + 1) % hashmod);
    // 从未访问过的要初始化计数值为0
    if (vis[i]!=clk) h[i] = S, vis[i] = clk, v[i] = 0;
    return v[i];
  }
};

void solve() {
    scanf("%s",s+1);
    n = strlen(s+1);
    rep(i,1,n) g[i].clear();
    scanf("%d",&m);
    rep(i,1,m) {
        scanf("%s",p+1);
        int len = strlen(p+1);
        node ret;
        ret.id = i;
        int cnt[28]{};
        rep(i,1,len) ++cnt[p[i]-'a'];
        cnt[26] = p[1];
        cnt[27] = p[len];
        ret.sta = get(cnt);
        g[len].pb(ret);
    }
    rep(i,1,m) ans[i] = 0;
    rep(len,1,n) if (g[len].size()) {
        int cnt[28]{};
        // 中间的字母是按照字母顺序来的，所以就是可以的，然后最后两个是按照直接首尾字母来的
        rep(i,1,len) ++cnt[s[i]-'a'];
        cnt[26] = s[1];
        cnt[27] = s[len];
        ull sta = get(cnt);
        ++clk;
        for (int L=1,R=len; R<=n; ++L,++R) {
            ++Hash::get(sta);
            // 左边字符基底为一个fac,而右边为fac^0=1
            sta = sta+(s[L+1]-s[L])*fac[1];
            sta = sta+(ll)(s[R+1]-s[R]);
            // 下面是右移一位整体的字母表的hash值变化
            sta = sta-fac[27-(s[L]-'a')];
            sta = sta+fac[27-(s[R+1]-'a')];
        }
        // 这个t长度下,把各次提问的ans更新
        // hash是这个头尾相同，中间的串是不同排列的  询问串(key) ————> 原串中的个数(value)
        for (auto &&t:g[len]) ans[t.id] = Hash::get(t.sta);
    }
    rep(i,1,m) printf("%d\n",ans[i]);
}

int main() {
    fac[0]=1;
    rep(i,1,30) fac[i]=fac[i-1]*bas;
    int t;
    scanf("%d",&t);
    while (t--) solve();
}

// SA
/*
SA板子声明 :
1. str从0开始,而非像oi-wiki中的从1开始
2. [build使用 n + 1 , calheight 使用 n ](https://www.wolfdan.cn/2019/08/21/%E7%AE%97%E6%B3%95%E6%97%A5%E5%B8%B8-16-100/)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
typedef long long LL;
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

// SA+主席树经典 - CCPC1003
/*ST表维护下 后缀排序后的公共长度 的最小值，然后二分找出左右符合的位置，主席树维护下排序后的序列，然后主席树查询第k大即可*/

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N=100100;
int t1[N],t2[N],sum[N],rk[N],ht[N],sa[N],str[N];char s[100100];
/*最小19*N,保守(2^5)*N(即N<<5)*/
struct node1 {
    int l, r;
    int val;
} tr[N * 22];
int f[N][22];
int root[N], tot;

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
/*对ht数组建立st表,这样就能取区间LCP*/
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

// root[i] = update1(root[i - 1], 1, n, sa[i] + 1);
/*root数组的key是rk,然后值是key对应的值是线段树节点位置(1是主根)
root也是tr的键,val记录的是某个rk的在root[rk]号树上的**位置前缀和**
然后tr数组就就是记录着主席树上的节点轨迹
*/
int update1(int pre, int l, int r, int pos) {
    /*主席树外分支++*/
    int cur = ++tot;
    /*新开轨迹获取之前轨迹的信息,在之前信息上添加*/
    tr[cur] = tr[pre];
    tr[cur].val++;
    if(l == r) return cur;
    int mid = (l + r) >> 1;
    /*动态开左孩子或者右孩子点*/
    if(pos <= mid) tr[cur].l = update1(tr[pre].l, l, mid, pos);
    else tr[cur].r = update1(tr[pre].r, mid + 1, r, pos);
    return cur;
}
// queryk(root[cntl - 1], root[cntr], 1, n, k)
/*cntl - 1 的rk也是LCP符合条件的，所以这里需要cntl-1*/
/*pl.pr是rk区间对应的根区间，他们的val值记录着sa之间的差值，类是于线段树rmq=>可以rkq
然后是主席树是同左同右操作的
*/
int queryk(int pl, int pr, int l, int r, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(tr[tr[pr].l].val - tr[tr[pl].l].val >= k) return queryk(tr[pl].l, tr[pr].l, l, mid, k);
    else return queryk(tr[pl].r, tr[pr].r, mid + 1, r, k - (tr[tr[pr].l].val - tr[tr[pl].l].val));
}

int main(){
    int n, m;int T;
    int l, r, k;
    int ll, rr, mid;
    int tmp;
    int cntl, cntr;int cnt;
    scanf("%d",&T);
    while(T--){
        tot = 0;
        scanf("%d %d", &n, &m);
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<n;i++) str[i] = s[i] - 'a' + 1;
        str[n]=0;
        get_sa(n+1,30);
        /*这里是ht的st_rmq*/
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

// SA + 二分 + RMQ
/*
今天在第二次研究hdu5008的时候,发现好多题目都是没有用rmq的
但是总有大佬不满足于暴力裸sa就完事,于是都加了rmq,
然后我有点看不懂,就去逛oi-wiki,发现居然有不重叠重复两次
的串也可以用rmq，那不就是我昨天做的poj1743的更优做法吗？
是的，然后就在网上搜到了O(test*(nlogn+logn))的做法！

之前的写法是O(test*nlogn)的

但是实测发现RMQ版的反而还慢了100多ms!好像是因为他的check还是O(n)而非O(1)的
而且RMQ是nlog(n)的预处理...  所以当然会慢啊 ---> 所以在更大一个量级的询问的时候再用比较好
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=21000;
int dp1[maxn][20],dp2[maxn][20];
int mm[maxn];
int str[maxn],tmp[maxn];
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int sa[maxn],ranks[maxn],height[maxn];
inline bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(i=0;i<n;i++) ranks[sa[i]]=i;
    int k=0;
    for(i=0;i<n-1;i++)
    {
        if(k) k--;
        j=sa[ranks[i]-1];
        while(r[i+k]==r[j+k]) k++;
        height[ranks[i]]=k;
    }
    return;
}
void initRMQ(int n)
{
    mm[0]=-1;
    for(int i=1;i<=n;i++)
    {
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
        dp1[i][0]=dp2[i][0]=sa[i];
    }
    for(int j=1;j<=mm[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            dp1[i][j]=max(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
            dp2[i][j]=min(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
        }
}
int rmq(int x,int y)
{
    int k=mm[y-x+1];
    return max(dp1[x][k],dp1[y-(1<<k)+1][k])-min(dp2[x][k],dp2[y-(1<<k)+1][k]);
}
bool check(int len,int N)
{
    int s=1,e=1;
    while(e<N)
    {
        if(height[e+1]>=len-1) e++;
        else
        {
            if(rmq(s,e)>=len) return true;
            s=++e;
        }
    }
    return false;
}
int main()
{
    int N;
    while(scanf("%d",&N)&&N)
    {
        for(int i=0;i<N;i++)
            scanf("%d",&str[i]);
        for(int i=0;i<N-1;i++)
            tmp[i]=str[i+1]-str[i]+90;
        tmp[N-1]=0;
        /*这里没有N--,所以直接使用的N,而RMQ使用的N-1,height封锁掉N号位置*/
        da(tmp,N,200);
        initRMQ(N-1);
        height[N]=-1;
        int left=1,right=N/2;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(check(mid,N)) left=mid+1;
            else right=mid-1;
        }
        if(right<5) printf("0\n");
        else printf("%d\n",right);
    }
    return 0;
}


// SAM板子
#include<bits/stdc++.h>
using namespace std;
const int N=250010;
char s[N];
int ans;
struct sam{
    // 注意N是题目给的n的两倍,因为节点数最多有2*n-1个
    int p,q,np,nq,cnt,last,a[N<<1][26],l[N<<1],f[N<<1];
    sam(){cnt=0;last=++cnt;}
    void init(){
        cnt=0;last=++cnt;
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        memset(f,0,sizeof(f));
    }
    void extend(int c){
        p=last;np=last=++cnt;l[np]=l[p]+1;
        while(!a[p][c]&&p)a[p][c]=np,p=f[p];
        if(!p)f[np]=1;
        else{
            q=a[p][c];
            if(l[p]+1==l[q])f[np]=q;
                else{
                    nq=++cnt;l[nq]=l[p]+1;
                    memcpy(a[nq],a[q],sizeof(a[q]));
                    f[nq]=f[q]; f[np]=f[q]=nq;
                    while(a[p][c]==q)a[p][c]=nq,p=f[p];
                }
        }
    }
    void solve(){
        init();
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<n;i++)extend(s[i]-'a');



        printf("%d\n",ans );
    }
} sam;
int T;
int main(){
    sam.solve();
    return 0;
}

// spoj_nsubstr_SAM经典
/*
2019年9月6日20:11:53 开始看题

2019年9月6日20:13:06 题意:
给你一个串,求出出现次数最多的长度为i(属于[1,|S|])的字串,输出它的出现次数

分解任务,先想清楚怎么求出一个字串的出现次数,
应该就是从叶子节点用fa回跳计算cnt[长度],然后不同回跳之间用max维护,
最终输出的时候一定是所有长度[1->|S|之间]都是必定出现过的,所以直接输出就行

叶子节点是转移到无法转移就是叶子节点吗？
2019年9月6日20:27:32 看大佬怎么写

大佬：ww140142
几天没更新，水一发后缀自动机的题解吧；

首先定义后缀自动机的的right集合大小，就是该结点代表的状态能拓展到的子串种类；

那么对于长度为x的子串的答案就是所有长度>=x的结点的right值的最大值；

right值是不能再构建自动机时增量维护的，所以只能在构建这个后缀自动机之后再O(n)搞一遍；

具体就是从反向后缀树的叶子开始，定义每个关键节点的right初始都为1，然后顺着求出所有节点的子树和就可以了；

然后再用right[x]更新f[len[x]]，扫一遍让f[i]=max(f[i],f[i+1])；

时间复杂度O(n)；

然而后缀自动机的构建依然是基本靠背的代码。。

而且大概后缀自动机顺便建出来的反向后缀树比那个识别后缀的本体要有用得多。。真是233
————————————————
原文链接：https://blog.csdn.net/ww140142/article/details/49914211

英雄所见略同

最终有点懵逼，然后又思索到了2019年9月6日21:39:13 才看懂了
[MashiroSky](https://www.cnblogs.com/MashiroSky/p/6287433.html)大佬的博文...
原来之前ccpc1003用的拓扑排序就是基数排序，怪不得当时这么熟悉但是又没有想起来

*/


#include<bits/stdc++.h>
using namespace std;
const int N=250010;
char s[N];
int r[N<<1],id[N<<1],b[N],F[N];
struct sam{
    // 注意N是题目给的n的两倍,因为节点数最多有2*n-1个
    int p,q,np,nq,cnt,last,a[N<<1][26],l[N<<1],f[N<<1];
    sam(){cnt=0;last=++cnt;}
    void init(){
        cnt=0;last=++cnt;
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        memset(f,0,sizeof(f));
    }
    void extend(int c){
        p=last;np=last=++cnt;l[np]=l[p]+1;
        while(!a[p][c]&&p)a[p][c]=np,p=f[p];
        if(!p)f[np]=1;
        else{
            q=a[p][c];
            if(l[p]+1==l[q])f[np]=q;
                else{
                    nq=++cnt;l[nq]=l[p]+1;
                    memcpy(a[nq],a[q],sizeof(a[q]));
                    f[nq]=f[q]; f[np]=f[q]=nq;
                    while(a[p][c]==q)a[p][c]=nq,p=f[p];
                }
        }
    }
    void solve(){
        init();
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<n;i++)extend(s[i]-'a');

        // 给主链的right值先+1.因为他们都是叶子节点(从构造算法就可以看出来,虽然这个性质我做了这个题才知道)
        // 源点就是1号节点
        for(int p=1,i=0;i<n;i++) p=a[p][s[i]-'a'],r[p]++;
        // 按照len[x]从小到大基数排序，相当于对SAM图进行拓扑排序(源点也是加入排序的)
        // 第一for先按照长度计数，然后第二for再对长度赋予排名，最后第三for让节点长度排名对应于节点
        // 同长度下，先出现的节点排名大(数值小)-->这个没有多大关系,因为同长度的必定不在同一条拓扑链上
        // 因为从源点出发的每一条链的长度都是递增的
        for(int i=1;i<=cnt;i++) b[l[i]]++;
        // 下面的for的i表示的是长度
        for(int i=1;i<=n;i++) b[i]+=b[i-1];
        for(int i=1;i<=cnt;i++) id[b[l[i]]--]=i;
        // 从后往前for,自底向上更新parent的right大小
        for(int i=cnt;i>=1;i--) r[f[id[i]]]+=r[id[i]];

        // 更新答案
        // 每个节点的endpos集合就是它自己代表的子串在串中出现的次数
        // 然后以这个子串为后缀的更长的串出现的位置通过拓扑排序累加上来了,
        // 存到了r[i]中表示这个节点代表的子串在整个串中所有出现的位置！<==>出现次数
        // 所以r[i]和F[len[i]]用max维护就行了
        for (int i=1;i<=cnt;i++) F[l[i]]=max(F[l[i]],r[i]);
        // 因为长度较短的串的F[i]值有可能是比F[i+1]小的，这样的话最优策略是取i+1长的串的后i长
        // 所以f[i] = max(F[i],F[i+1])
        for (int i=n;i>=1;i--) F[i]=max(F[i],F[i+1]);

        for (int i=1;i<=n;i++) printf("%d\n",F[i]);
    }
} sam;
int T;
int main(){
    sam.solve();
    return 0;
}

// SPOJ_LCS2_SAM多串匹配
/*
2019年9月5日18:48:57 开始看题
在LCS的基础上加了串，不再是两个串了，而是多个串，而且时间限制为236 ms...太刺激了吧
按之前的LCS的s2串跑s1串的SAM可能行不通.. 想想吧
2019年9月5日18:56:44 想不出...主要不知道往哪个方面去想，没有类似经历，所以去看看大佬怎么想的

[巨佬](https://www.cnblogs.com/mjtcn/p/9335863.html)的想法(果然就是多种值维护一下,但是我竟然没有勇气想下去...):

1.   poj2774上那道题，对一个串建立后缀自动机，另一个在上面匹配。

2.   这道题是对多个串求。那么同样，让每个串在后缀自动机上匹配，
然后记录在后缀自动机的每个节点上记录，
当前串在这个位置和第一个串的最大匹配数，h数组。

然后mn数组，每次对于这所有的节点的h取小，为从第2个串到现在所有的串，都能在这个节点上匹配的长度。

因为一旦某个节点匹配上了，那么它的父节点（parent树）的父节点都会匹配上（因为父节点是当前点的后缀），
所以按拓扑倒序，更新父节点的h，为父节点的len，（即最大长度）。



3.   第二种写法是对n-1个字符串建立SAM，然后用最后一个串在n-1个串上匹配，每个自动机上都有一个当前的指针cur，当前答案ans。
对最后一个串从头开始扫，求出最后一个串和每个串以当前字符结尾的最大匹配长度，在这里面取小，
每次加入一个字符，可以直接判断cur的下一位，不需要从头开始。空间太大。

　　

总结: 　两种写法大同小异，只枚举举的顺序不同而已。


其实方法更简洁，更容易看懂，比解法一的缺点是多花了很多空间

*/


// 方法一 80ms 25.6MB
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for (;isdigit(ch);ch=getchar())x=x*10+ch-'0';return x*f;
}

const int N = 100010;

struct Suffix_Automaton{
    int fa[N<<1], trans[N<<1][26], len[N<<1], Last, Index;
    int v[N], sa[N<<1], mn[N<<1], h[N<<1];
    char s[N];

    void extend(int c) {
        int P = Last,NP = ++Index;
        len[NP] = len[P] + 1;
        for (; P&&!trans[P][c]; P=fa[P]) trans[P][c] = NP;
        if (!P) fa[NP] = 1; //-
        else {
            int Q = trans[P][c];
            if (len[P] + 1 == len[Q]) fa[NP] = Q;
            else {
                int NQ = ++Index;
                fa[NQ] = fa[Q];
                len[NQ] = len[P] + 1;
                memcpy(trans[NQ], trans[Q], sizeof trans[Q]);
                fa[Q] = NQ;
                fa[NP] = NQ;
                for (; P&&trans[P][c]==Q; P=fa[P]) trans[P][c] = NQ;
            }
        }
        Last = NP;
    }
    void build() {
        Last = Index = 1;
        scanf("%s",s+1);
        int n = strlen(s+1);
        for (int i=1; i<=n; ++i) extend(s[i] - 'a');
        // index和第一个串s1的下标大致是对应的，但是中间还有克隆的节点
        for (int i=1; i<=Index; ++i) v[len[i]] ++;
        // 确实是只有n种长度..前缀的后缀-->所有的串-->所以只用n
        // 这里求前缀和只是为了下面能够求出排名数组,让他们按照深度占比权值(有点像权值线段树的那种)
        for (int i=1; i<=n; ++i) v[i] += v[i-1];
        // sa[i] 排名为i的节点。按深度排名（拓扑用）
        // i号节点按照它的len在v中前缀和减减--->其实就是排名,按照节点的长度(也就是深度)--->因为越深越长
        for (int i=1; i<=Index; ++i) sa[ v[len[i]]-- ] = i;
    }
    void calcc() {
        int n = strlen(s+1), now = 0, p = 1;
        memset(h, 0, sizeof(h));
        for (int i=1; i<=n; ++i) {
            int c = s[i] - 'a';
            if (trans[p][c]) p = trans[p][c], now ++;
            else {
                for (; p&&!trans[p][c]; p=fa[p]);
                if (!p) now = 0, p = 1;
                else now = len[p] + 1, p = trans[p][c];
            }
            h[p] = max(h[p], now);
        }
        // 拓扑倒序，parent树中从深度深的到浅的
        for (int i=Index; i>=1; --i) {
            int t = sa[i];
            mn[t] = min(mn[t], h[t]);
            // t节点有匹配,并且它的父节点(后缀link)不为源点--->那么让它的父节点的匹配值等于父节点的长度
            // 因为前面的操作是对最长的适配，所以没有管较短串的匹配,所以这里管一下
            // 但是为什么只对父节点，而不对更爷爷节点什么的呢，因为这个拓扑排序从底部向上，所以父节点在之后会出现
            // 所以爷爷节点由后面出现的父节点去管理就行了 ====》 太精妙了，amazing！
            if (h[t] && fa[t]) h[fa[t]] = len[fa[t]];
        }
    }
    void solve() {
        build();
        memset(mn, 0x3f, sizeof(mn));
        while (scanf("%s",s+1) != EOF) calcc();
        int ans = 0;
        for (int i=1; i<=Index; ++i) ans = max(ans, mn[i]);
        printf("%d",ans);
    }
}sam;

int main() {
    sam.solve();
    return 0;
}


// 方法二---N-1个自动机 130ms 175.1MB
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for (;isdigit(ch);ch=getchar())x=x*10+ch-'0';return x*f;
}

const int N = 200010;

struct SuffixAutomaton{
    int Last, Index, res, cur, fa[N], trans[N][26], len[N];
    SuffixAutomaton() {Last = Index = cur = 1; res = 0;}
    void extend(int c) {
        int P = Last, NP = ++Index;
        len[NP] = len[P] + 1;
        for (; P&&!trans[P][c]; P=fa[P]) trans[P][c] = NP;
        if (!P) fa[NP] = 1;
        else {
            int Q = trans[P][c];
            if (len[P] + 1 == len[Q]) fa[NP] = Q;
            else {
                int NQ = ++Index;
                fa[NQ] = fa[Q];
                len[NQ] = len[P] + 1;
                memcpy(trans[NQ], trans[Q], sizeof trans[Q]);
                fa[Q] = NQ;
                fa[NP] = NQ;
                for (; P&&trans[P][c]==Q; P=fa[P]) trans[P][c] = NQ;
            }
        }
        Last = NP;
    }
    int solve(int c) {
        if (trans[cur][c]) {cur = trans[cur][c]; res++; return res;}
        for (; cur&&!trans[cur][c]; cur=fa[cur]);
        if (!cur) res = 0, cur = 1;
        else res = len[cur] + 1, cur = trans[cur][c];
        return res;
    }
}sam[9];

char s[N];
char str[N>>1];

int main() {
    int n = 0,t = 0,len;
    scanf("%s",str+1);

    while (scanf("%s",s+1)!=EOF) {
        len = strlen(s + 1);
        for (int i=1; i<=len; ++i)
            sam[t].extend(s[i] - 'a');
        t ++;
    }
    int ans = 0;
    len = strlen(str+1);
    for (int i=1; i<=len; ++i) {
        int tmp = 1e9;
        for (int j=0; j<t; ++j)
            tmp = min(tmp, sam[j].solve(str[i] - 'a'));
        ans = max(ans, tmp);
    }
    printf("%d",ans);
    return 0;
}

// CF123_SAM right[v]再加一个经典题
/*
2019年9月17日14:27:46 开始看题
2019年9月17日14:41:55 发现本来要看963D的，但是一个博主给错了链接，让我看到了这题，还不会做，不理解那个连续串的意思，看tutorial


参考：[111qqz](https://111qqz.com/2017/11/cf-123d/)

题意:
如果字符串y在字符串x中出现n次，那么F(x,y)=n*(n+1)/2   (可以看做是一个长为n的串，求滑动区块的总个数)
现在给一个字符串，求所有的F(s,x)的和，x为字符串的所有不相同的子串．

思路：
这道题可以考虑用后缀数组做，麻烦一点：codeforces-123D-解题报告(SA)

直接SAM

right[v]就是SAM上状态表示的所有字符串出现的次数。

那么每个状态的答案就是right[v](right[v]+1)/2(st[v].len-st[st[v].link].len)

累加即可

每个状态点都是本质不同的串，所以一开始的right值都是1,而与endpos有多少个没有太大关系，所以拓扑排序叠加一遍fa值就odk了！
*/

#include <bits/stdc++.h>
#define ms(a, x) memset(a, x, sizeof(a))
typedef long long LL;

using namespace std;
const int N = 5e5 + 7;
struct SAM {
#define MAXALP 30
    struct state {
        int len, link, nxt[MAXALP];
        int leftmost; //某个状态的right集合中r值最小的
        int rightmost; //某个状态的right集合的r的最大值
        int Right; //right集合大小
    };
    state st[N * 2];
    char S[N];
    int sz, last, rt;
    char s[N];
    int cnt[2 * N], rk[2 * N]; //for radix sort
    int idx(char c){
        if (c >= 'a' && c <= 'z')
            return c - 'a';
        return c - 'A' + 26;
    }
    void init(){
        sz = 0;
        ms(st, 0);
        last = rt = ++sz;
        st[1].len = 0;
        st[1].link = -1;
        st[1].rightmost = 0;
        ms(st[1].nxt, -1);
    }
    void extend(int c, int head){
        int cur = ++sz;
        st[cur].len = st[last].len + 1;
        st[cur].leftmost = st[cur].rightmost = head;
        memset(st[cur].nxt, -1, sizeof(st[cur].nxt));
        int p;
        for (p = last; p != -1 && st[p].nxt[c] == -1; p = st[p].link)
            st[p].nxt[c] = cur;
        if (p == -1) {
            st[cur].link = rt;
        } else {
            int q = st[p].nxt[c];
            if (st[p].len + 1 == st[q].len) {

                st[cur].link = q;
            } else {
                int clone = ++sz;
                st[clone].len = st[p].len + 1;
                st[clone].link = st[q].link;
                memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
                st[clone].leftmost = st[q].leftmost;
                st[clone].rightmost = st[q].rightmost;
                for (; p != -1 && st[p].nxt[c] == q; p = st[p].link)
                    st[p].nxt[c] = clone;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    void build(){
        init();
        for (int i = 0, _len = strlen(S); i < _len; i++) {
            st[sz + 1].Right = 1;
            extend(idx(S[i]), i);
        }
    }
    void topo(){
        ms(cnt, 0);
        for (int i = 1; i <= sz; i++) cnt[st[i].len]++;
        for (int i = 1; i <= sz; i++) cnt[i] += cnt[i - 1];
        //rk[1]是len最小的状态的标号
        for (int i = 1; i <= sz; i++) rk[cnt[st[i].len]--] = i;
    }
    //跑拓扑序，预处理一些东西
    void pre(){
        for (int i = sz; i >= 2; i--) {
            int v = rk[i];
            int fa = st[v].link;
            if (fa == -1) continue;
            st[fa].rightmost = max(st[fa].rightmost, st[v].rightmost);
            st[fa].Right += st[v].Right;
        }
    }
    void solve(){
        LL ans = 0;
        for (int i = sz; i >= 2; i--) {
            int v = rk[i];
            if (st[v].link == -1) continue;
            // 前面是串的组合
            // 后面是 st[v].len - st[st[v].link].len是后缀的前缀，是本质不同的串的贡献
            // 每个字母的贡献--->就是每个后缀节点t跳父亲节点fa跳掉的那部分t的前缀中的每一个字母开头的后缀都是和串t出现次数相同的！
            // 这里有个自己的总结点就是求所以本质不同的子串可以遍历跑自动机，但如果只是计数多少个本质不同的串，可以使用这样方式！
            // 其实上面这种思想方法好像也用在了kmp的统计子串个数的骚操作上，但是这个也很好用
            ans = ans + 1LL * st[v].Right * (st[v].Right + 1) / 2 * (st[v].len - st[st[v].link].len);
            // cout<<"TEST: "<<st[v].len - st[st[v].link].len<<endl;
        }
        printf("%lld\n", ans);
    }
    int LCS(char* s){
        int ans = 0, len = 0;
        int p = rt;
        for (int i = 0, _len = strlen(s); i < _len; i++) {
            int ID = s[i] - 'a';
            if (st[p].nxt[ID] != -1) p = st[p].nxt[ID], len++;
            else {
                while (p != -1 && st[p].nxt[ID] == -1) p = st[p].link;
                if (p == -1) p = rt, len = 0;
                else len = st[p].len + 1, p = st[p].nxt[ID];
            }
            ans = max(ans, len);
        }
        return ans;
    }
} A;
char B[N];

int main(){
    scanf("%s", A.S);
    A.build();
    A.topo();
    A.pre();
    A.solve();

    return 0;
}


// SAM+主席树_又是CCPC1003
/*
2019年9月3日20:44:23 开始看
2019年9月4日11:39:03 再看
主席树+SAM都是刚刚学了一点点皮毛，然后就要接受这种魔鬼题目训练，真是毒打

感觉后缀数组用的是各种后缀的前缀，而后缀自动机则是用前缀的后缀比较多，因为endpos就相当于前缀的感觉
后缀数组的LCP(Longest Common Prefix)问题等价于后缀树的最小公共祖先LCA(Least Common Ancestor)问题
前者是后缀的共同前缀，后者是前缀endpos的共同后缀(link)---> 也即sam构成的后缀link树的lca
有一点点的融会贯通的感觉真他妈的爽啊！

题意:
T组,N次询问,  l,r这个子串的第k次出现
*/


#include<iostream>
#include<complex>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<string.h>
using  namespace std;
char s[100010];
int T[200010][30],fa[200010],len[200010],cnt,last,n;

/*这里是建立SAM.大佬的板子真滴简洁..*/
void build(int v){
    int i,p=last,np,q,nq;
    last=np=++cnt;
    len[np]=len[p]+1;
    for(;p&&T[p][v]==0;p=fa[p]) T[p][v]=np;
    if(p==0) fa[np]=1;
    else{
        q=T[p][v];
        if(len[q]==len[p]+1) fa[np]=q;
        else{
            nq=++cnt;
            len[nq]=len[p]+1;
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            for(i=0;i<27;i++) T[nq][i]=T[q][i];
            for(;T[p][v]==q;p=fa[p]) T[p][v]=nq;
        }
    }
}

/*root[i]数组表示的是endpos为i的节点*/
int root[200010],num;
/*开了40倍的这里是主席树,若只考虑最大的大小和n次修改,每次log(n)的话,那么其实只要2n-1+nlog(n)就行
也就是只要19e5===>也可以直接n << 5 ,即(2^5)*n    */
struct Q{
    int L,R,sum;
} A[8000000];

/*
pos[i]=p;---> pos数组就是endpos数组,不懂可以参考[oi-wiki/sam](https://oi-wiki.org/string/sam/)
update(root[p],1,n,i,1);
*/
void update(int &x,int l,int r,int k,int v){
    /*下面三句话就是1. 获取之前的节点(之前也可能是空节点)信息
    2. 让当前的root[]等于新得到的id(sum)_3.然后在这个id上进行玩耍*/
    /*总体上就是记录一条新建的边上的所有信息,最主要的是维护权值--为了求出第k大*/
    /*我们从递归的角度看进去,发现每个node左右点都是从1开始一直加的，所以这就是权值主席树*/
    A[++num]=A[x];
    x=num;
    A[x].sum++;
    if(l==r) return;
    int mid=(l+r)/2;
    if(k<=mid) update(A[x].L,l,mid,k,v);
    else update(A[x].R,mid+1,r,k,v);
}
/*root[u]=mer(root[u],root[v],1,n);*/
int mer(int a,int b,int l,int r){
    if(a==0||b==0) return a+b;
    int z=++num,mid=(l+r)/2;
    if(l==r){
        /*因为sum要么一样,要么某一个为0,所以用'或'操作*/
         A[z].sum=A[a].sum|A[b].sum;
         return z;
    }
    A[z].L=mer(A[a].L,A[b].L,l,mid);
    A[z].R=mer(A[a].R,A[b].R,mid+1,r);
    A[z].sum=A[A[z].L].sum+A[A[z].R].sum;
    return z;
}
/*
u=qkth(root[p],1,n,a);
printf("%d\n",u-k+1);
返回的是endpos值...也就是返回的是串的右端点...也就是说答案是u-k+1
*/
int qkth(int x,int l,int r,int k){
    if(l==r) return l;
    int mid=(l+r)/2;
    if(k<=A[A[x].L].sum) return qkth(A[x].L,l,mid,k);
    else return qkth(A[x].R,mid+1,r,k-A[A[x].L].sum);
}

vector<int>g[200010];
int Fa[200010][25],pos[200010];
/*dfs(1)*/
void dfs(int u){
    int i,v;
    /*这里i为什么是<=19?...--->每次插入主席树一条边需要log(n),这题就是约等18左右,开到19是为了保险
    这里的大的Fa不是sam中的fa*/
    /*最最开始这里的初始化都是0,后面就是链状的，用i来dp，真是太巧妙了！
    比如Fa[u][0]=0;Fa[v][0]=u;Fa[w][0]=v.  那么Fa[w][1]=Fa[v][0]=u
    这就是dp叠层数了===> 所以后面使用的时候就直接用Fa[p][i]就行了*/
    for(i=1;i<=19;i++) Fa[u][i]=Fa[Fa[u][i-1]][i-1];
    for(i=0;i<g[u].size();i++){
        v=g[u][i];
        /*v的直接父亲是u...*/
        Fa[v][0]=u;
        dfs(v);
        root[u]=mer(root[u],root[v],1,n);
    }
}

int main(){
    int i,m,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        cnt=last=1;
        memset(T,0,sizeof(T));
        for(i=0;i<=200000;i++) g[i].clear();

        /*构建SAM*/
        for(i=1;s[i];i++) build(s[i]-'a');
        /*i的后缀link放入i,也就是g表示源点到终止节点的方向,fa数组的反hash*/
        for(i=1;i<=cnt;i++) g[fa[i]].push_back(i);
        int p=1,v;

        memset(root,0,sizeof(root));
        A[0].L=A[0].R=A[0].sum=num=0;
        /*插入构建主席树*/
        for(i=1;s[i];i++){
            v=s[i]-'a';
            /*p就是转移之后的节点啊，所以就是说每个节点在主席树上都是一棵新树*/
            p=T[p][v];
            /*对，pos就是endpos，转移就是转移到下一个状态*/
            pos[i]=p;
            update(root[p],1,n,i,1);
        }
        /*前面生成g[]数组的时候,fa[i]最小值就是1,所以dfs(1)就是从源点跑到各个点去,然后合并每个endpos对应的所有后缀...*/
        dfs(1);


        int l,r,k,u,a;
        while(m--){
            scanf("%d%d%d",&l,&r,&a);
            /*获取endpos为r的状态点*/
            p=pos[r];
            /*这里的k竟然是长度...*/
            k=r-l+1;
            /*为啥又是19,这个是哪来的数字！==>难道说是一个log(n)的大小！好像是！
            那么这里的意思应该就是: 找出最短的长度大于要求的字串长的后缀
            然后如果对应的节点的权值不够a(其实就是题中说的k),那么直接输出-1
            否则就去主席树中找出答案，所以dfs(1)应该就是从源点出发找到终止节点之类的操作


            可得好好研究一下Fa数组的作用! 这里从它的作用来看就是用在了自成一体的fa树！就是
            答案中说的  扒出 parent树 ，然后利用这个来操作...找到这个串位置对应于主席树的位置
            因为之前的fa[]是与主席树没有任何联系的，所以我们需要这个Fa来构建联系
            */
            for(i=19;i>=0;i--) if(len[Fa[p][i]]>=k) p=Fa[p][i];
            if(a>A[root[p]].sum) printf("-1\n");
            else{
                u=qkth(root[p],1,n,a);
                printf("%d\n",u-k+1);
            }
        }
    }
    return 0;
}

// 大数处理py写法--少量
def gcd(a,b):
    return a if b==0 else gcd(b,a%b)

def exgcd(a,b):
    if b==0:
        return 1,0
    y,x=exgcd(b,a%b)
    y-=(a//b)*x
    return x,y

def inv(a,b):
    x,y=exgcd(a,b)
    return (x%b+b)%b

n,M=map(lambda x:int(x),input().split(' '))
m=-1;c=-1
for i in range(n):
    a,b=map(lambda x:int(x),input().split(' '))
    if c==-1:
        m=a;c=b
    else:
        g=gcd(m,a)
        if (c-b)%g!=0:
            print('he was definitely lying')
            exit()
        c+=(inv(m//g,a//g)*(b-c)//g)%(a//g)*m
        m=m*a//g
if M>=c:
    print(str(c))
else:
    print('he was probably lying')

// 矩阵操作
#include<bits/stdc++.h>
using namespace std;
#define NUM 50
int MAXN,n,mod;

//矩阵的类
struct Matrix{
    int a[NUM][NUM];
    //将其初始化为单位矩阵
    void init(){
        memset(a,0,sizeof(a));
        for(int i=0;i<MAXN;i++)
            a[i][i]=1;
    }
} A;

//(a*b)%mod  矩阵乘法
Matrix mul(Matrix a,Matrix b){
    Matrix ans;
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++){
            ans.a[i][j]=0;
            for(int k=0;k<MAXN;k++)
                ans.a[i][j]+=a.a[i][k]*b.a[k][j];
            ans.a[i][j]%=mod;
        }
    return ans;
}

//(a+b)%mod  //矩阵加法
Matrix add(Matrix a,Matrix b){
    int i,j,k;
    Matrix ans;
    for(i=0;i<MAXN;i++)
        for(j=0;j<MAXN;j++){
            ans.a[i][j]=a.a[i][j]+b.a[i][j];
            ans.a[i][j]%=mod;
        }
    return ans;
}

//(a^n)%mod  //矩阵快速幂
Matrix pow(Matrix a,int n) {
    Matrix ans;
    ans.init();
    while(n){
        if(n&1)
            ans=mul(ans,a);
        n/=2;
        a=mul(a,a);
    }
    return ans;
}

//(a+a^2+a^3....+a^n)%mod// 矩阵的幂和
Matrix sum(Matrix a,int n){
    int m;
    Matrix ans,pre;
    if(n==1)
        return a;
    m=n/2;
    //[1,n/2]
    pre=sum(a,m);
    //ans=[1,n/2]+a^(n/2)*[1,n/2]
    ans=add(pre,mul(pre,pow(a,m)));
    if(n&1)
        //ans=ans+a^n
        ans=add(ans,pow(a,n));
    return ans;
}

//输出矩阵
void output(Matrix a){
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            printf("%d%c",a.a[i][j],j==MAXN-1?'\n':' ');
}

int main(){
    freopen("in.txt","r",stdin);
    Matrix ans;
    scanf("%d%d%d",&MAXN,&n,&mod);
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++){
            scanf("%d",&A.a[i][j]);
            A.a[i][j]%=mod;
        }
    ans=sum(A,n);
    output(ans);
    return 0;
}

// 以10为底的矩阵快速幂
#include<bits/stdc++.h>
typedef unsigned long long ULL;
const int SIZE = 3000010;
ULL MOD;
char s[SIZE];
/*矩阵相乘，第一行乘以第一列，第一行乘以第二列……也可以使用for两重循环求*/
void mul(ULL* c1, ULL* c2, ULL *res){
    res[0] = (c1[0] * c2[0] + c1[1] * c2[2]) % MOD;
    res[1] = (c1[0] * c2[1] + c1[1] * c2[3]) % MOD;
    res[2] = (c1[2] * c2[0] + c1[3] * c2[2]) % MOD;
    res[3] = (c1[3] * c2[3] + c1[2] * c2[1]) % MOD;
}

int main() {
    int a,b;
    int x1,x2;
    scanf("%d%d%d%d", &x1, &x2, &a, &b);
    scanf("%s%llu",s, &MOD);
    int len = 0;
    /* 统计长度，并且把个位的值(即最后一位的值)减去1 */
    for(; s[len]; len++);
    s[len-1]--;
    /* 个位减掉了之后向前面借位 */
    for(int i = len - 1; i >= 0 && s[i] < '0'; i--){
        s[i] = '9';
        s[i-1]--;
    }
    ULL now0 = x1, now1 = x2;
    ULL d[4][4];
    d[0][0] = 0;
    d[0][1] = 1;
    d[0][2] = b;
    d[0][3] = a;
    for(int it = len - 1; it >= 0; it--){
        memset(d[1], 0, sizeof(ULL) * 12);
        /*A "常数"矩阵相乘4次*/
        for(int p = 1; p < 4; p++){
            mul(d[p-1], d[p-1], d[p]);
        }
        s[it] -= '0';
        for(int p = 0; p < 4; p++){
            if((s[it] >> p) & 1){
                ULL* ml = d[p];
                std::tie(now0, now1) = std::make_pair((ml[0] * now0 + ml[1] * now1) % MOD,(ml[2] * now0 + ml[3] * now1) % MOD);
            }
        }
        mul(d[1], d[3], d[0]);
    }
    printf("%llu\n", now1);
    return 0;
}

// 组合数隔板法经典题
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 2e3+7;
int C[M][M];
int T,n,m;

void add(ll &a,ll v){
    a += v;
    if(a >= mod) a-=mod;
}

void pre(){
    for(int i=0;i<M;i++) C[i][0]=1;
    for(int i=1;i<M;i++){
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=mod) C[i][j]-=mod;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    pre();
    while(T--){
        cin>>n>>m;
        cout<<C[n+m-2][m-1]<<endl;
    }

    return 0;
}

// 线段树进阶蓝书第一个例题
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 5e5+7;
struct SegmentTree{
    int l,r;
    int lmax,rmax,sum;
    int dat;
} t[SIZE<<2];
int a[SIZE],N,M;

void pushup(int p){
    t[p].sum = t[p*2].sum + t[p*2+1].sum;
    t[p].lmax = max(t[p*2].lmax,t[p*2].sum+t[p*2+1].lmax);
    t[p].rmax = max(t[p*2+1].rmax,t[p*2+1].sum+t[p*2].rmax);
    t[p].dat = max(t[p*2].dat,max(t[p*2+1].dat,t[p*2].rmax+t[p*2+1].lmax));
}

void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){ t[p].sum=t[p].lmax=t[p].rmax=t[p].dat=a[l]; return ; }
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}

void change(int p,int x,int v){
    if(t[p].l==t[p].r){t[p].dat=t[p].sum=t[p].lmax=t[p].rmax=v;return ;}
    int mid = (t[p].l+t[p].r)/2;
    if(x<=mid) change(p<<1,x,v);
    else change(p<<1|1,x,v);
    pushup(p);
}

// int ask(int p,int l,int r){
//     if(l <= t[p].l && r >= t[p].r) return t[p].dat;
//     int mid = (t[p].l + t[p].r)/2;
//     int val = -(1<<30);
//     if(l<=mid) val = max(val,ask(p<<1,l,r));
//     if(r>mid) val = max(val,ask(p<<1|1,l,r));
//     return val;
// }

/* 此处感谢队友帮忙debug */
SegmentTree ask(int p,int l,int r){
    if (l<=t[p].l && r>=t[p].r) return t[p];
    int mid=(t[p].l+t[p].r)>>1;
    int val=-(1<<30);
    SegmentTree a,b,c;
    a.dat=a.sum=a.lmax=a.rmax=val;
    b.dat=b.sum=b.lmax=b.rmax=val;
    c.dat=c.lmax=c.rmax=val;
    c.sum=0;
    /* 要么都在最左边，要么都在最右边，要么跨越了左右，跨越了左右就要判断
    c.dat=max(max(a.dat,b.dat),a.rmax+b.lmax);
    这个点没想到会卡住 --> 我就是从前面的注释的ask函数出错来的*/
    if (l<=mid&&r<=mid){
        a=ask(p<<1,l,r);
        c.sum+=a.sum;
    }
    /* 还要注意左区间r<=mid,右区间l>mid */
    // else if (l>=mid&&r>=mid){
    else if (l>mid&&r>mid){
        b=ask(p*2+1,l,r);
        c.sum+=b.sum;
    }
    else{
        a=ask(p<<1,l,r);
        b=ask(p*2+1,l,r);
        c.sum+=a.sum+b.sum;
    }
    c.dat=max(c.dat,max(max(a.dat,b.dat),a.rmax+b.lmax));
    c.lmax=max(c.lmax,max(a.lmax,a.sum+b.lmax));
    c.rmax=max(c.rmax,max(b.rmax,b.sum+a.rmax));
    return c;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>a[i];
    build(1,1,N);
    int i,x,y;
    while(M--){
        cin>>i>>x>>y;
        if(i==1){
            if(x>y) swap(x,y);
            cout << ask(1, x, y).dat << endl;
        }
        else change(1,x,y);
        // for(int i=1;i<=9;i++){
        //     cout<<"dat: "<<t[i].dat<<" sum: "<<t[i].sum<<" lmax: "<<t[i].lmax<<" rmax: "<<t[i].rmax<<endl;
        // }
    }
    return 0;
}

// 计算几何-矩阵中放三角形
#include<cstdio>
#include<cmath>
int sqr(int x) {return x * x;}
int w, h;
int _a, _b, _c;
struct Point{
    double x, y;
    Point(double x=0, double y=0):x(x),y(y){}
    Point operator-(const Point b)const{
        return Point(x-b.x,y-b.y);
    }
    double dis(){return sqrt(x*x+y*y);}
}an[3];
const double EPS = 1e-12;
void read_input() {
    scanf("%d%d", &w, &h);
    scanf("%d%d%d",&_a,&_b,&_c);
}
bool valid(){
    if(fabs((an[0]-an[1]).dis() - _a) > EPS ||
       fabs((an[0]-an[2]).dis() - _b) > EPS ||
       fabs((an[1]-an[2]).dis() - _c) > EPS) return false;
    for(int i = 0; i < 3; i++) {
        if(an[i].x < -EPS || an[i].y < -EPS) return false;
        if(an[i].x > w + EPS) return false;
        if(an[i].y > h + EPS) return false;
    }
    return true;
}
bool check(int a, int b, int c,Point& X,Point& Y,Point& Z){
    if(sqr(a)+sqr(b)<sqr(c)) return 0;
    X=Point();
    bool suc = 0;
    double angle_ab=acos((double)(sqr(a)+sqr(b)-sqr(c))/(2*a*b));
    /*一整条边在三角形上面*/
    if(b <= w) {
        Z = Point(b, 0);
        Y = Point(a * cos(angle_ab), a * sin(angle_ab));
        if(valid()) suc = 1;
    }
    /*两个点在矩阵上面*/
    else {
        Z = Point(w, sqrt(sqr(b) - sqr(w)));
        double angle_tmp = acos(1.*w/b);
        Y = Point(a * cos(angle_ab + angle_tmp), a * sin(angle_ab + angle_tmp));
        if(valid()) suc = 1;
    }
    if(!suc) {
        if(a <= h) {
            Y = Point(0, a);
            Z = Point(b * sin(angle_ab), a * cos(angle_ab));
            if(valid()) suc = 1;
        }
        else {
            Y = Point(sqrt(sqr(a) - sqr(h)), h);
            double angle_tmp = acos(1.*h/a);
            Z = Point(a * sin(angle_ab + angle_tmp), a * cos(angle_ab + angle_tmp));
            if(valid()) suc = 1;
        }
    }
    if(!suc) return 0;
    for(int i=0;i<3;i++)printf("%.12lf %.12lf%c",an[i].x,an[i].y," \n"[i==2]);
    return 1;
}
void solve() {
    if(check(_a,_b,_c,an[0],an[1],an[2]))return;
    if(check(_a,_c,_b,an[1],an[0],an[2]))return;
    if(check(_b,_a,_c,an[0],an[2],an[1]))return;
    if(check(_b,_c,_a,an[2],an[0],an[1]))return;
    if(check(_c,_a,_b,an[1],an[2],an[0]))return;
    if(check(_c,_b,_a,an[2],an[1],an[0]))return;
    puts("-1");
}
int main () {
    int T;
    scanf("%d", &T);
    while(T--) {
        read_input();
        solve();
    }
    return 0;
}

// N10F依次贪心的一些思想经典
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=6e5+5;
const int N=6e5+3;
int a[maxn],b[maxn],cnt[maxn],ans,n,r;
vector <int> h[maxn];
multiset <int> s;
void add(int x){
    auto p=s.find(cnt[x]);
    s.erase(p); cnt[x]++;
    s.insert(cnt[x]);
}
void del(int x){
    auto p=s.find(cnt[x]);
    s.erase(p); cnt[x]--;
    s.insert(cnt[x]);
}
int main(){
    cin >> n >> r;
    for (int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        /* 统一右移2*r */
        a[i]+=r*2; b[i]+=r*2;
    }
    for (int i=0;i<n;i++){
        /*打a[i]的时候,把a[i]-r,a[i]+r也叠加上a[i]上面的值,
        这样就能使得a[i]表示打a[i]能获得的总值*/
        h[a[i]-r].pb(b[i]);
        h[a[i]].pb(b[i]);
        h[aa[i]+r].pb(b[i]);
        cnt[b[i]]++; cnt[b[i]-r]++; cnt[b[i]+r]++;
    }
    for (int i=r;i<=N-r;i++) s.insert(cnt[i]);
    for (int i=r;i<=N-r;i++){
        /*得到中间打这里能够得到的个数*/
        int ret=(int)h[i].size();
        /*暂时删除相关的所有列值*/
        for (auto x:h[i]) del(x),del(x-r),del(x+r);
        /*然后得到当下最大的3列值*/
        auto p=s.rbegin();
        ans=max(ans,ret+(*p));
        /*再把列值插回去*/
        for (auto x:h[i]) add(x),add(x-r),add(x+r);
    }
    cout << ans << endl;
}

// Manacher的一些奇特用法_2017CCPC哈尔滨
/*
2019年9月14日10:40:30 开始看题
2019年9月14日10:53:57 找到了O(n)判断字串是否为题中所说回文的方法，然后找到暴力解法O(n^2),要想办法怎么重复利用判断结果...
2019年9月14日11:00:04 看大佬怎么想吧


大佬jiachin_zhao:
很明显这里的回文串长度为奇数，所以用manacher处理时不需要添加间隔字符
所以这里的Len[i]表示的就是以i为中心的回文串向左右最远能延伸的长度

那么S[i]=S[2n−i]=S[2n+i−2](1≤i≤n)就等价于
找到一对(i,j),满足i−Len[i]+1<=j<i且j+Len[j]−1>=i
可以用主席树来维护，更简单的方法就是
将j+Len[j]−1按升序排列,然后对于j丢到树状数组里查询贡献就好了。
*/



#include<bits/stdc++.h>
#define P pair<int,int>
#define LL long long
using namespace std;

const int maxn = 5e5 + 10;
const int N = 1e6 + 10;
char s[N];
int Len[N];
int lowbit(int x){return x & (-x);}
int tr[N],R;
int getsum(int pos){
    int ans = 0;
    for(;pos;pos -= lowbit(pos)) ans += tr[pos];
    return ans;
}
void up(int pos){
    for(;pos <= R;pos += lowbit(pos)) tr[pos]++;
}
void Manacher(char *s){
    int len = strlen(s + 1);
    s[0] = '#';
    int mx = 0,center = 0;
    ///mx为当前计算回文串最右边字符的最大值
    ///center为取得mx最大值的中心
    for(int i = 1;i <= len;i++){
        if(mx > i) Len[i] = min(mx - i, Len[2 * center - i]);///考虑i关于center的对称的Len
        else Len[i] = 1;
        while(s[i - Len[i]] == s[i + Len[i]]) Len[i]++;
        if(Len[i] + i > mx) mx = Len[i] + i, center = i; ///更新最右
    }
}
struct node{
    int x,l;
    node(int x,int l):x(x),l(l){};
    node(){};
    bool operator<(const node &rhs)const{
        return l > rhs.l;
    }
}q[N];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
       scanf("%s",s + 1);
       Manacher(s);
       int len = strlen(s + 1);
       R = len;
       for(int i = 1;i <= R;i++) tr[i] = 0;
       // 这下面两行相当于自建有序的map
       for(int i = 1;i <= len;i++) q[i] = node(i, i + Len[i] - 1);
       sort(q + 1, q + len + 1);
       int l = 1;
       LL ans = 0;
       for(int i = len;i >= 1;i--){
            // j+Len[j]−1>=i
            while(l <= len && q[l].l >= i) up(q[l++].x);
            // i−Len[i]+1<=j<i ( 收获这里面的所有选项 )
            ans += getsum(i - 1) - getsum(i - Len[i]);
       }
       printf("%lld\n",ans);
    }
    return 0;
}

// NOIP2012 贪心+高精度板子
#include <algorithm>
#include <stdio.h>
using namespace std;
int n; //丞相人数
int ans[5000]; //其实是前面所有人的累计的乘积值
int tt[5000];
int len; //ans长度
int maxp;
int maxans[5000]; // 存答案的地方
void gx(int a) //高精乘
{
    int t[5000];
    t[1] = 0;
    for (int i = 1; i <= len || (i > len && t[i] != 0); i++) {
        ans[i] *= a;
        ans[i] += t[i];
        t[i + 1] = ans[i] / 10;
        ans[i] %= 10;
        ans[0] = i;
    }
    len = ans[0];
}
void gc(int b) //高精除
{
    bool shit = 0;
    for (int i = len; i >= 2; i--) {
        ans[i - 1] += (ans[i] % b) * 10;
        ans[i] /= b;
        if (!shit) {
            if (!ans[i])
                len--;
            else
                shit = 1;
        }
    }
    ans[1] /= b;
    ans[0] = len;
}
// 自己手动演算了一下，发现确实是对的，高精度除法 关键`tt[i - 1] += (tt[i] % b) * 10;`
void ggc(int b) //高精除
{
    bool shit = 0;
    for (int i = tt[0]; i >= 2; i--) {
        tt[i - 1] += (tt[i] % b) * 10;
        tt[i] /= b;
        if (!shit) {
            if (!tt[i])
                tt[0]--;
            else
                shit = 1;
        }
    }
    tt[1] /= b;
}
struct person //每个人的信息
{
    int a, b, c;
} p[100005];
bool cmp(person x, person y) //判断优劣
{
    return x.c < y.c;
}
void ready() //初始化
{
    maxans[0] = 1;
    maxans[1] = -1;
    ans[1] = p[0].a;
    ans[0] = len = 1;
}
void gcmp(int a[], int b[])
{
    if (a[0] > b[0]) {
        for (int i = a[0]; i >= 0; i--)
            maxans[i] = a[i];
        return;
    } else if (a[0] < b[0])
        return;
    else {
        for (int j = ans[0]; j >= 1; j--) {
            if (a[j] > b[j]) {
                for (int i = a[0]; i >= 0; i--)
                    maxans[i] = a[i];
                return;
            } else if (a[j] < b[j])
                return;
        }
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d%d", &p[i].a, &p[i].b);
        // 空间换时间，防止了多次计算
        p[i].c = p[i].a * p[i].b;
    }
    sort(p + 1, p + 1 + n, cmp);
    //    for(int i=1;i<=n;i++)
    //    printf("%d %d %d\n",p[i].a,p[i].b,p[i].c);
    ready();
    for (int i = 1; i <= n; i++) {
        for (int j = tt[0]; j >= 0; j--)
            tt[j] = 0;
        for (int j = 0; j <= ans[0]; j++)
            tt[j] = ans[j];
        ggc(p[i].b);
        gcmp(tt, maxans);
        gx(p[i].a);
    }
    for (int i = maxans[0]; i >= 1; i--)
        printf("%d", maxans[i]);
    return 0;
}

// 二分+前缀和+离散化
/// poj3179
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 510;

int a[N], b[N], x[N], y[N], g[N][N], sum[N][N], n, C, tx, ty;

inline bool check(int k) {
    //printf("check:%d\n", k);
    int ans = 0;
    for(int i = 1; i <= tx; i++) {
        for(int j = 1; j <= ty; j++) {
            /* x[i]+k就是找到右下角的坐标 */
            int ii = upper_bound(x + i, x + tx + 1, x[i] + k) - x - 1;
            int jj = upper_bound(y + j, y + ty + 1, y[j] + k) - y - 1;
            /// 就是这里！
            //printf("%d %d %d %d ", i, j, ii, jj);
            ans = max(ans, sum[ii][jj] - sum[ii][j - 1] - sum[i - 1][jj] + sum[i - 1][j - 1]);
            if(ans >= C) return 1;
            //printf("ans=%d\n", ans);
            //ii = i; jj = j;
            //while(ii >= 0 && x[ii] - x[i] )
        }
    }
    //printf("%d\n", ans);
    return ans >= C;
}

int main() {
    int m = -1;
    scanf("%d%d", &C, &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        x[i] = a[i];
        y[i] = b[i];
        m = max(m, x[i]);
        m = max(m, y[i]);
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for(int i = 1; i <= n; i++) {
        if(x[i] != x[i - 1]) {
            x[++tx] = x[i];
        }
        if(y[i] != y[i - 1]) {
            y[++ty] = y[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        /* x 可以看作去重量， a可以看作原量 ， 然后 px 可以看作是序列量 */
        int px = lower_bound(x + 1, x + tx + 1, a[i]) - x;
        int py = lower_bound(y + 1, y + ty + 1, b[i]) - y;
        g[px][py]++;
    }
    for(int i = 1; i <= tx; i++) {
        for(int j = 1; j <= ty; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i][j];
        }
    }
    int l = 0, r = m, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            r = mid;
        }
        else l = mid + 1;
    }
    printf("%d", r + 1);
    return 0;
}

// LuoguP3808【模板】AC 自动机（简单版）
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int n;

namespace AC {
int tr[N][26], tot;
int e[N], fail[N];
void insert(char *s) {
  int u = 0;
  for (int i = 1; s[i]; i++) {
    if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
    u = tr[u][s[i] - 'a'];
  }
  e[u]++;
}
queue<int> q;
void build() {
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q.push(tr[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[u][i])
        fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
      else
        tr[u][i] = tr[fail[u]][i];
    }
  }
}
int query(char *t) {
  int u = 0, res = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u][t[i] - 'a'];  // 转移
    for (int j = u; j && e[j] != -1; j = fail[j]) {
      res += e[j], e[j] = -1;
    }
  }
  return res;
}
}  // namespace AC

char s[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s + 1), AC::insert(s);
  scanf("%s", s + 1);
  AC::build();
  printf("%d", AC::query(s));
  return 0;
}

// P3796 【模板】AC 自动机（加强版）
#include <bits/stdc++.h>
using namespace std;
const int N = 156, L = 1e6 + 6;
namespace AC {
const int SZ = N * 80;
int tot, tr[SZ][26];
int fail[SZ], idx[SZ], val[SZ];
int cnt[N];  // 记录第 i 个字符串的出现次数
void init() {
  memset(fail, 0, sizeof(fail));
  memset(tr, 0, sizeof(tr));
  memset(val, 0, sizeof(val));
  memset(cnt, 0, sizeof(cnt));
  memset(idx, 0, sizeof(idx));
  tot = 0;
}
void insert(char *s, int id) {  // id 表示原始字符串的编号
  int u = 0;
  for (int i = 1; s[i]; i++) {
    if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
    u = tr[u][s[i] - 'a'];
  }
  idx[u] = id;
}
queue<int> q;
void build() {
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q.push(tr[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[u][i])
        fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
      else
        tr[u][i] = tr[fail[u]][i];
    }
  }
}
int query(char *t) {  // 返回最大的出现次数
  int u = 0, res = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u][t[i] - 'a'];
    for (int j = u; j; j = fail[j]) val[j]++;
  }
  for (int i = 0; i <= tot; i++)
    if (idx[i]) res = max(res, val[i]), cnt[idx[i]] = val[i];
  return res;
}
}  // namespace AC
int n;
char s[N][100], t[L];
int main() {
  while (~scanf("%d", &n)) {
    if (n == 0) break;
    AC::init();
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1), AC::insert(s[i], i);
    AC::build();
    scanf("%s", t + 1);
    int x = AC::query(t);
    printf("%d\n", x);
    for (int i = 1; i <= n; i++)
      if (AC::cnt[i] == x) printf("%s\n", s[i] + 1);
  }
  return 0;
}

// 回文自动机(回文树)
// APIO2014|luogu3649 回文串

// 建出树来，类似后缀自动机统计出现次数即可


//变量名与上文基本相同，其中ptr为转移指针，数组大小应为字符集大小
class PA {
 private:
  static const int N = 100010;
  struct Node {
    int len;
    int ptr[26], fail;
    Node(int len = 0) : len(len), fail(0) { memset(ptr, 0, sizeof(ptr)); }
  } nd[N];

  int size, cnt;  // size为字符串长度，cnt为节点个数
  int cur;  //当前指针停留的位置，即最后插入字符所对应的节点
  char s[N];

  int getfail(int x)  //沿着fail指针找到第一个回文后缀
  {
    while (s[size - nd[x].len - 1] != s[size]) {
      x = nd[x].fail;
    }
    return x;
  }

 public:
  PA() : size(0), cnt(0), cur(0) {
    nd[cnt] = Node(0);
    nd[cnt].fail = 1;
    nd[++cnt] = Node(-1);
    nd[cnt].fail = 0;
    s[0] = '$';
  }

  void extend(char c) {
    s[++size] = c;
    int now = getfail(cur);  //找到插入的位置
    if (!nd[now].ptr[c - 'a'])  //若没有这个节点，则新建并求出它的fail指针
    {
      int tmp = ++cnt;
      nd[tmp] = Node(nd[now].len + 2);
      nd[tmp].fail = nd[getfail(nd[now].fail)].ptr[c - 'a'];
      nd[now].ptr[c - 'a'] = tmp;
    }
    cur = nd[now].ptr[c - 'a'];
  }

  int qlen() { return nd[cur].len; }
} A, B;

// windows+linux对拍
// windows1
@echo off
:loop
    rand.exe %random% > data.in
    std.exe < data.in > std.out
    my.exe < data.in > my.out
    fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop

// windows2
@echo off
:again
r > input
a < input > output.a
b < input > output.b
fc output.a output.b > nul
if not errorlevel 1 goto again

// linux
#!/bin/bash
while true; do
    ./r > input
    ./a < input > output.a
    ./b < input > output.b
    diff output.a output.b
    if [ $? -ne 0 ] ; then break ; fi
done

// 输出自己一发
#include <stdio.h>
char *s = "#include<stdio.h>%cchar%c*s=%c%s%c%c%cint main(){printf(s,10,32,34,s,34,59,10);}";
int main() { printf(s, 10, 32, 34, s, 34, 59, 10); }


