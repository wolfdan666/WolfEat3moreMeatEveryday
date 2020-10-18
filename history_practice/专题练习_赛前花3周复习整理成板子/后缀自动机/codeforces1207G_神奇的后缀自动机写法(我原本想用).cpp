/*
借鉴大佬的代码 , 猛男大佬开小号,EDU71 rank 4
59299826    Contestant:Makabaka    1207G - 14  GNU C++11   Accepted    2339 ms 478092 KB   2019-08-22 18:42:31 2019-08-23 08:45:13

注释自己加的
2019年10月14日19:07:24 认真看了许久了,只是现在才加头注释
*/


#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#define N 400020
#define S 26
using namespace std;

namespace Trie {
class Node {
   public:
    map<int, int> s;
    int i;

    Node(void) : i(0) { return; }
};

Node f[N];
int g[N];
int h[N], s[N], p[N];
int l[N], t[N], c;

void InitChain(int x) {
    int i;
    // 0到26,就是直接扫描trie
    for (i = 0, s[x] = 1, h[x] = -1; i < S; i++)
        if (f[x].s.count(i)) {
            // p数组, 即parent数组,让自己的孩子指向自己
            p[f[x].s[i]] = x;
            InitChain(f[x].s[i]);
            // s数组就是size数组,加上自己遍历完的孩子的size得到自己的size加和值
            s[x] += s[f[x].s[i]];

            // h数组是获得最右孩子 , 之所以能这么明锐的意识到是右孩子,还因为自己之前看的AC自动机版的这题代码就是用的右孩子兄弟结构,莫非trie都这样用???
            if (h[x] == -1 || s[h[x]] < s[f[x].s[i]]) h[x] = f[x].s[i];
        }

    return;
}

void ConnectChain(int x, int t) {
    int i;

    // 看到后面对 l 数组的使用的使用的时候才发现这是一个右儿子的dfs遍历,并且 l[] 记录下各节点他们的孩子们在在这次遍历中的序号是多少(第几次被遍历)
    l[x] = c++;
    Trie::t[x] = t;
    // 按理来说没有右孩子肯定也没有下面的for循环啊,为啥不写在一起呢? --- > t[最右孩子] = 父亲,t[其他] = 自己,c是s[0]...为啥要加加,是不是大佬比赛的时候写挫了
    if (h[x] != -1) ConnectChain(h[x], t);

    for (i = 0; i < S; i++)
        if (f[x].s.count(i) && f[x].s[i] != h[x])
            ConnectChain(f[x].s[i], f[x].s[i]);

    return;
}
}  // namespace Trie

namespace Segment {
class Node {
   public:
    Node *s[2];
    int v;

    Node(void) : v(0) {
        s[0] = s[1] = NULL;

        return;
    }
};

// 把节点的信息放到线段树的线段上的p点
void SetSegment(Node *&x, int l, int r, int p) {
    int m;

    if (!x) x = new Node();
    if (l == r) {
        x->v = 1;

        return;
    }

    m = (l + r) >> 1;
    if (p <= m)
        SetSegment(x->s[0], l, m, p);
    else
        SetSegment(x->s[1], m + 1, r, p);

    // 下面这里是pushup,线段树的常规操作
    x->v = (x->s[0] ? x->s[0]->v : 0) + (x->s[1] ? x->s[1]->v : 0);

    return;
}

// 合并两个线段树中节点的信息值
Node *MergeSegment(Node *x, Node *y) {
    Node *t;

    if (!x) return y;
    if (!y) return x;

    t = new Node();
    if (!x->s[0] && !x->s[1])
        t->v = 1;
    else {
        t->s[0] = MergeSegment(x->s[0], y->s[0]);
        t->s[1] = MergeSegment(x->s[1], y->s[1]);
        t->v = (t->s[0] ? t->s[0]->v : 0) + (t->s[1] ? t->s[1]->v : 0);
    }

    return t;
}

// 求和
int SumSegment(Node *x, int l, int r, int s, int t) {
    int m;

    if (!x || l > t || r < s) return 0;
    if (l >= s && r <= t) return x->v;

    m = (l + r) >> 1;

    return SumSegment(x->s[0], l, m, s, t) +
           SumSegment(x->s[1], m + 1, r, s, t);
}
}  // namespace Segment

namespace SAM {
class Node {
   public:
    map<int, int> s;
    int f;
    int l;

    Node(void) : f(-1), l(0) { return; }
};

Node f[N << 1];
int c;
Segment::Node *s[N << 1];
int v[N], h[N << 1];
pair<int, int> q[N << 1];

void InitSAM(void) {
    c = 1;

    return;
}

// InsertSAM(Trie::c, i, Trie::l[Trie::f[s].s[i]],q[l].second)
// 第一个参数就是总个数,然后k就是字母值,然后i --- l[节点]就是节点在dfs右孩子左兄弟树过程中被遍历的次序,然后d---q[l].se就是bfs序中的次序
// 看了很久之后发现bfs其实是为了维护层数和父子关系的一个借用的值
// 又看了很久之后发现原来trie上每个节点都建立了自动机,然后建立了映射关系,真暴力啊
int InsertSAM(int n, int k, int i, int d) {
    int p, q, b;

    if (f[d].s.count(k)){
        // q是当前节点的trie上的序号
        q = f[d].s[k];
        // q节点的长度是bfs序中d的长度+1,也就是说q是d的下一层
        if (f[q].l == f[d].l + 1) {
            // printf("k = %d, d")
            // s是线段树的节点,大佬是如果做到复用这么多同名的东西看不晕的,巨佬

            // q插到i号,说明线段树的最小面一层的次序是按照dfs序来的
            Segment::SetSegment(s[q], 0, n - 1, i);
        } else {
            // c这里是SAM的节点个数
            f[b = c++] = f[q];
            // 利用bfs的层数来维护长度序
            f[b].l = f[d].l + 1;
            // 因为q不在下一层,所以q的父亲是b
            f[q].f = b;
            // 然后把新建的节点加入线段树(同样是按照dfs序)
            Segment::SetSegment(s[b], 0, n - 1, i);

            for (p = d; p != -1 && f[p].s[k] == q; p = f[p].f) f[p].s[k] = b;
        }
        d = f[d].s[k];
        // d竟然获取他的一个孩子返回了?!
        return d;
    }

    // trie的叶子节点或着不是特定的k之母的时候
    p = d;
    f[d = c++].l = f[p].l + 1;
    Segment::SetSegment(s[d], 0, n - 1, i);
    // 我们让它和它的父亲们的所有节点都接出一个k字符为d,有一种用SAM实现了AC自动机的感觉...
    for (; p != -1 && !f[p].s.count(k); p = f[p].f) f[p].s[k] = d;

    if (p == -1)
        f[d].f = 0;
    else {
        q = f[p].s[k];
        if (f[q].l == f[p].l + 1)
            f[d].f = q;
        else {
            f[b = c++] = f[q];
            f[b].l = f[p].l + 1;
            f[q].f = f[d].f = b;

            for (; p != -1 && f[p].s[k] == q; p = f[p].f) f[p].s[k] = b;
        }
    }

    return d;
}

// 这里应该就是一个拓扑排序
void MergeSAM(void) {
    int i;

    for (i = 0; i < c; i++) v[f[i].l]++;
    for (i = 1; i < N; i++) v[i] += v[i - 1];
    for (i = c - 1; i > -1; i--) h[--v[f[i].l]] = i;

    // 不太懂为啥要多次Merge,那上面的部分不是重复执行了大概log(n) - 1次???
    for (i = c - 1; i > 0; i--)
        s[f[h[i]].f] = MergeSegment(s[f[h[i]].f], s[h[i]]);

    // 添加空叶子节点
    for (i = 0; i < c; i++)
        if (!s[i]) s[i] = new Segment::Node();

    // for(i=0;i<c;i++)cout<<f[i].l<<' ';cout<<endl;
    // for(i=0;i<c;i++)cout<<(s[i]?s[i]->v:0)<<' ';cout<<endl;

    return;
}

void BuildSAM(void) {
    int s, l, r;
    int i;

    InitSAM();
    l = r = 0;

    for (q[r++] = make_pair(0, 0); l < r; l++) {
        s = q[l].first;
        for (i = 0; i < S; i++)
            if (Trie::f[s].s.count(i))
                // bfs遍历trie构造自动机
                // q是一个pair<int,int> 的数组 , 每个pair 的 fi是对应遍历的点在trie中的值
                q[r++] = make_pair(Trie::f[s].s[i],InsertSAM(Trie::c, i, Trie::l[Trie::f[s].s[i]],q[l].second));
    }
    // cout<<c<<endl;
    MergeSAM();

    return;
}
}  // namespace SAM

char s[N];

inline int ID(char c) { return c - 97; }

int Solve(int x) {
    int i, p, o;

    // 直接跑硬的自动机,牛逼了
    for (i = p = 0; s[i]; i++) {
        if (!SAM::f[p].s.count(ID(s[i]))) return 0;
        p = SAM::f[p].s[ID(s[i])];
    }

    // cout<<"VER "<<x<<endl;

    // 跑完成立就回跳fa树,而且还用了线段树来求SUM,真滴猛男
    for (o = 0; x ; x = Trie::p[Trie::t[x]]) 
        o += Segment::SumSegment(SAM::s[p], 0, Trie::c - 1, Trie::l[Trie::t[x]],Trie::l[x]);

    return o;
}

int main(void) {
    int n, m, x;
    int i, p;

    scanf("%d", &n);
    for (i = 1, p = 0; i <= n; i++) {
        scanf("%d", &x);
        if (x == 1)
            p = 0;
        else {
            scanf("%d", &x);
            // g[x]是x号点在trie中父亲节点对应的节点位置
            p = Trie::g[x];
        }

        // printf("parent = %d\n", p);

        scanf("%s", s);
        // 寻找节点p的父亲
        if (!Trie::f[p].s.count(ID(s[0]))) {
            Trie::f[p].s[ID(s[0])] = i;
            Trie::g[i] = i;
        } else
            Trie::g[i] = Trie::f[p].s[ID(s[0])];
    }
    Trie::InitChain(0);
    Trie::ConnectChain(0, 0);
    SAM::BuildSAM();

    scanf("%d", &m);
    while (m--) {
        scanf("%d %s", &x, s);
        x = Trie::g[x];
        printf("%d\n", Solve(x));
    }

    return 0;
}