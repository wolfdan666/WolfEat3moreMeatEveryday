#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, b, a) for(int i = b; i >= a; i--)
#define fi first
#define se second
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2000 + 5;

char s[N];
struct EDGE {
    int to, nxt;
}edge[N<<1];
int head[N<<1], tot;
char str[N];
int dp[N][N];
struct SuffixAutoMaton {
    //fa[i] —— i节点parent tree的父亲
    //len[i] —— i节点的最长子串的长度
    //siz[i] —— i节点endpos集合的大小，即子串在原串中出现的次数
    //根节点为1号节点（空串）。构建sam直接build即可
    int ans;
    int last,cnt;int ch[N<<1][26],fa[N<<1],len[N<<1],siz[N<<1];
    void ins(int c) {
        int p=last,np=++cnt;last=np;len[np]=len[p]+1;
        for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
        if(!p) fa[np]=1;
        else {
            int q=ch[p][c];
            if(len[p]+1==len[q]) fa[np]=q;
            else {
                int nq=++cnt; len[nq]=len[p]+1;
                memcpy(ch[nq],ch[q],sizeof(ch[q]));
                fa[nq]=fa[q]; fa[q]=fa[np]=nq;
                for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
            }
        }
        siz[np] = 1;
        ans += len[np]-len[fa[np]];
    }
    void add(int u, int v) {
        edge[tot].to = v;
        edge[tot].nxt = head[u];
        head[u] = tot++;
    }
    void build(int L) {
        ans = 0;
        int len = strlen(s);
        last = cnt = 1;
        memset(ch, 0, sizeof(ch));
        for(int i = 0; i < len; i++) {
            ins(s[i]-'a');
            dp[L][L+i] = ans;
        }
    }
    void dfs(int u) {
        for(int i=head[u];i!=-1;i=edge[i].nxt) {
            int v=edge[i].to;
            dfs(v); siz[u] += siz[v];
        }
    }
}sam;

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        memset(dp, 0, sizeof(dp));
        scanf("%s", str);
        int len = strlen(str);
        rep(i, 0, len-1) {
            rep(j, i, len-1) s[j-i] = str[j];
            s[len-i] = '\0';
            sam.build(i);
        }
        int q; scanf("%d", &q);
        while(q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--; r--;
            printf("%d\n", dp[l][r]);
        }
    }

    return 0;
}