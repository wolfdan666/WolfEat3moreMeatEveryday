/*
2019年9月4日19:49:50 开始看题

求字串出现了几次，
显然可以使用后缀数组rank[l]然后二分左右区间做的！因为后缀数组
然后出题人说他没有卡hash的做法！所以做法二应该是hash
然后这个题目出现在了sam专题，所以肯定也是可以使用sam做!
先用sam做法，然后之后再了解好另外两种做法

感觉这一题比求第k次出现的位置简单很多，可以直接用ccpc1003的做法简化之后直接怼上去就行
但是应该有更简单的做法  2019年9月4日20:00:33 再想想 ---> 直接看倍增数组跳动了几次就ok了！
2019年9月4日20:02:45 试着去写
2019年9月4日20:27:41 发现自己写的拼凑版果然不对..要么0要么12，所以错了，看答案吧
2019年9月4日20:32:49 看了队友的，发现队友写得真好，还是先去看题解先把..


2019年9月4日20:38:41 mdzz .. 看错题目了...
题目是要求出l,r之间所有的不同字串个数，而不是求[l,r]这个字串出现了多少次...傻逼了

发现括号型注释虽然在操作系统源码中常用，但是有时候有点冲突，所以在行间还是用单行注释比较好，函数间再用大注释

2019年9月4日21:15:25 自己重写怎么还是有bug,静下心来认真看
2019年9月4日21:41:18 自闭了，无法静下心来看到底哪里出错了...oi-wiki给的板子有毒
*/


// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const ll mod=1000000007;
// const int inf = 0x3f3f3f3f;
// const int MAXLEN = 2010;
// int T;
// vector<int>g[MAXLEN];
// int Fa[MAXLEN][25],pos[MAXLEN];
// struct state {
//   int len, link;
//   std::map<char, int> next;
// };
// state st[MAXLEN * 2];
// int sz, last;

// void sam_init() {
// /*sz在重复使用的时候可要小心...*/
//   st[0].len = 0;
//   st[0].link = -1;
//   sz++;
//   last = 0;
// }

// void sam_extend(char c) {
//   int cur = sz++;
//   st[cur].len = st[last].len + 1;
//   int p = last;
//   while (p != -1 && !st[p].next.count(c)) {
//     st[p].next[c] = cur;
//     p = st[p].link;
//   }
//   if (p == -1) {
//     st[cur].link = 0;
//   } else {
//     int q = st[p].next[c];
//     if (st[p].len + 1 == st[q].len) {
//       st[cur].link = q;
//     } else {
//       int clone = sz++;
//       st[clone].len = st[p].len + 1;
//       st[clone].next = st[q].next;
//       st[clone].link = st[q].link;
//       while (p != -1 && st[p].next[c] == q) {
//         st[p].next[c] = clone;
//         p = st[p].link;
//       }
//       st[q].link = st[cur].link = clone;
//     }
//   }
//   last = cur;
// }

// /*log(2010)+1=11*/
// void dfs(int u){
//     for(int i=0;i<=11;i++) Fa[u][i] = Fa[Fa[u][i-1]][i-1];
//     for(int i=0;i<(int)g[u].size();i++){
//         int v = g[u][i];
//         Fa[v][0] = u;
//         dfs(v);
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);cin.tie(0);
//     cin>>T;
//     while(T--){
//         string s;int n;
//         cin>>s>>n;
//         int len = s.length();
//         for(int i=0;i<len;i++) sam_extend(s[i]-'a');
//         for(int i=1;i<=sz;i++) g[st[i].link].push_back(i);

//         int p = 1,v;
//         for(int i=0;s[i];i++){
//             v = s[i] - 'a';
//             p = st[p].next[v];
//         }
//         dfs(1);
//         while(n--){
//             int ans = 0;
//             int l,r;
//             cin>>l>>r;
//             p = pos[r];
//             int k = r - l + 1;
//             for(int i=11;i>=0;i--){
//                 if(st[Fa[p][i]].len>=k){
//                     p = Fa[p][i];
//                     ans++;
//                 }
//             }
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }

/*
大佬:
- 给这个字符串的所有区间都建一遍sam就能得到所有区间的不同子串个数
- 每添加一个字符, 以这个字符为结尾的不同子串个数就是step[cur]-step[pre[cur]],
  添加字符的过程中求一下和就能得到字符串的子串个数
- 由于sam的构建是一个一个添字符, 我们在构造区间[l,n]的sam时,
  区间[l,r](r<=n)的sam都会被构造一遍, 于是我们枚举左端点去构造即可
- ~~真暴力
*/

#include <bits/stdc++.h>
#define mset(a,b) memset(a,(b),sizeof(a))
#define scan(a) scanf("%d",&a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int maxn = 2005;
struct suffix_automation{
    int tot,last,go[maxn<<2][26],pre[maxn<<2],step[maxn<<2];
    int cnt;
    int new_node(int s){
        step[++tot] = s;
        pre[tot] = 0;
        mset(go[tot],0);
        return tot;
    }
    int idx(char c){return c-'a';}
    void init(){
        tot = cnt = 0;
        last = new_node(0);
    }
    int insert(char ch){
        int c = idx(ch);
        int p = last,cur = new_node(step[last]+1);
        while(p&&!go[p][c])
            go[p][c] = cur,p = pre[p];
        if(!p)pre[cur] = 1;
        else{
            int q = go[p][c];
            if(step[q]==step[p]+1)
                pre[cur] = q;
            else{
                int nq = new_node(step[p]+1);
                memcpy(go[nq],go[q],sizeof(go[q]));
                pre[nq] = pre[q];
                pre[cur] = pre[q] = nq;
                while(p&&go[p][c]==q)
                    go[p][c] = nq,p = pre[p];
            }
        }
        last = cur;
        cnt+=step[cur]-step[pre[cur]];
        return cnt;
    }
}sam;
char s[maxn];
int ans[maxn][maxn];

int main(){
    int t;
    scan(t);
    while(t--){
        scanf("%s",s);
        for(int i = 0,n = strlen(s);i<n;++i){
            sam.init();
            for(int j = i;j<n;++j)
                ans[i+1][j+1] = sam.insert(s[j]);
        }
        // for(int i = 0,n = strlen(s);i<n;++i){for(int j = i;j<n;++j) cout<<ans[i][j]; cout<<endl;}
        int q;
        scan(q);
        while(q--){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",ans[a][b]);
        }
    }
    return 0;
}



/*自己重写*/
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const ll mod=1000000007;
// const int inf = 0x3f3f3f3f;
// const int MAXLEN = 2010;
// int T,ans[MAXLEN][MAXLEN],tp;
// struct state {
//   int len, link;
//   std::map<char, int> next;
// };
// state st[MAXLEN * 2];
// int sz, last;

// void sam_init() {
//   st[0].len = 0;
//   st[0].link = -1;
//   /*这个破板子，sz不清零..*/
//   sz = 0;
//   sz++;
//   last = 0;
//   tp = 0;
// }

// int sam_extend(char c) {
//   int cur = sz++;
//   st[cur].len = st[last].len + 1;
//   int p = last;
//   while (p != -1 && !st[p].next.count(c)) {
//     st[p].next[c] = cur;
//     p = st[p].link;
//   }
//   if (p == -1) {
//     st[cur].link = 0;
//   } else {
//     int q = st[p].next[c];
//     if (st[p].len + 1 == st[q].len) {
//       st[cur].link = q;
//     } else {
//       int clone = sz++;
//       st[clone].len = st[p].len + 1;
//       st[clone].next = st[q].next;
//       st[clone].link = st[q].link;
//       while (p != -1 && st[p].next[c] == q) {
//         st[p].next[c] = clone;
//         p = st[p].link;
//       }
//       st[q].link = st[cur].link = clone;
//     }
//   }
//   last = cur;
//   tp += st[cur].len - st[st[cur].link].len;
//   return tp;
// }

// int main(){
//     ios::sync_with_stdio(false);cin.tie(0);
//     cin>>T;
//     while(T--){
//         string s;int n;
//         cin>>s>>n;
//         int len = s.length();
//         for(int i=0;i<len;i++){
//             sam_init();
//             for(int j=i;j<len;j++){
//                 ans[i][j] = sam_extend(s[j]);
//             }
//         }
//         for(int i = 0;i<len;++i){for(int j = i;j<len;++j) cout<<ans[i][j]; cout<<endl;}
//         while(n--){
//             int l,r;
//             cin>>l>>r;
//             l--,r--;
//             cout<<ans[l][r]<<endl;
//         }
//     }

//     return 0;
// }