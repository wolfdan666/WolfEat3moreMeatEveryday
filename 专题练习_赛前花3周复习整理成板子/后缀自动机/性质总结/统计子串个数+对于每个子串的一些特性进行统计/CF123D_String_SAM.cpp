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