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