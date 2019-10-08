#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>
#define N 400020
#define S 26
using namespace std;
 
namespace Trie
{
    class Node
    {
    public:
        map<int, int> s;
        int i;
 
        Node(void) : i(0)
        {
            return;
        }
    };
 
    Node f[N];
    int g[N];
    int h[N], s[N], p[N];
    int l[N], t[N], c;
 
    void InitChain(int x)
    {
        int i;
 
        for(i = 0, s[x] = 1, h[x] = -1; i < S; i ++)
            if(f[x].s.count(i))
            {
                p[f[x].s[i]] = x;
                InitChain(f[x].s[i]);
                s[x] += s[f[x].s[i]];
 
                if(h[x] == -1 || s[h[x]] < s[f[x].s[i]])
                    h[x] = f[x].s[i];
            }
 
        return;
    }
 
    void ConnectChain(int x, int t)
    {
        int i;
 
        l[x] = c ++;
        Trie::t[x] = t;
        if(h[x] != -1)
            ConnectChain(h[x], t);
 
        for(i = 0; i < S; i ++)
            if(f[x].s.count(i) && f[x].s[i] != h[x])
                ConnectChain(f[x].s[i], f[x].s[i]);
 
        return;
    }
}
 
namespace Segment
{
    class Node
    {
    public:
        Node *s[2];
        int v;
 
        Node(void) : v(0)
        {
            s[0] = s[1] = NULL;
 
            return;
        }
    };
 
    void SetSegment(Node *&x, int l, int r, int p)
    {
        int m;
 
        if(!x)
            x = new Node();
        if(l == r)
        {
            x -> v = 1;
 
            return;
        }
 
        m = (l + r) >> 1;
        if(p <= m)
            SetSegment(x -> s[0], l    , m, p);
        else
            SetSegment(x -> s[1], m + 1, r, p);
        x -> v = (x -> s[0] ? x -> s[0] -> v : 0) + (x -> s[1] ? x -> s[1] -> v : 0);
 
        return;
    }
 
    Node *MergeSegment(Node *x, Node *y)
    {
        Node *t;
 
        if(!x)
            return y;
        if(!y)
            return x;
 
        t = new Node();
        if(!x -> s[0] && !x -> s[1])
            t -> v = 1;
        else
        {
            t -> s[0] = MergeSegment(x -> s[0], y -> s[0]);
            t -> s[1] = MergeSegment(x -> s[1], y -> s[1]);
            t -> v = (t -> s[0] ? t -> s[0] -> v : 0) + (t -> s[1] ? t -> s[1] -> v : 0);
        }
 
        return t;
    }
 
    int SumSegment(Node *x, int l, int r, int s, int t)
    {
        int m;
 
        if(!x || l > t || r < s)
            return 0;
        if(l >= s && r <= t)
            return x -> v;
 
        m = (l + r) >> 1;
 
        return SumSegment(x -> s[0], l, m, s, t) + SumSegment(x -> s[1], m + 1, r, s, t);
    }
}
 
namespace SAM
{
    class Node
    {
    public:
        map<int, int> s;
        int f;
        int l;
 
        Node(void) : f(-1), l(0)
        {
            return;
        }
    };
 
    Node f[N << 1];
    int c;
    Segment::Node *s[N << 1];
    int v[N], h[N << 1];
    pair<int, int> q[N << 1];
 
    void InitSAM(void)
    {
        c = 1;
 
        return;
    }
 
    int InsertSAM(int n, int k, int i, int d)
    {
        int p, q, b;
 
        if(f[d].s.count(k))
        {
            q = f[d].s[k];
            if(f[q].l == f[d].l + 1)
            {
                // printf("k = %d, d")
                Segment::SetSegment(s[q], 0, n - 1, i);
            }
            else
            {
                f[b = c ++] = f[q];
                f[b].l = f[d].l + 1;
                f[q].f = b;
                Segment::SetSegment(s[b], 0, n - 1, i);
 
                for(p = d; p != -1 && f[p].s[k] == q; p = f[p].f)
                    f[p].s[k] = b;
            }
            d = f[d].s[k];
 
            return d;
        }
 
        p = d;
        f[d = c ++].l = f[p].l + 1;
        Segment::SetSegment(s[d], 0, n - 1, i);
        for(; p != -1 && !f[p].s.count(k); p = f[p].f)
            f[p].s[k] = d;
 
        if(p == -1)
            f[d].f = 0;
        else
        {
            q = f[p].s[k];
            if(f[q].l == f[p].l + 1)
                f[d].f = q;
            else
            {
                f[b = c ++] = f[q];
                f[b].l = f[p].l + 1;
                f[q].f = f[d].f = b;
 
                for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                    f[p].s[k] = b;
            }
        }
 
        return d;
    }
 
    void MergeSAM(void)
    {
        int i;
 
        for(i = 0; i < c; i ++)
            v[f[i].l] ++;
        for(i = 1; i < N; i ++)
            v[i] += v[i - 1];
        for(i = c - 1; i > -1; i --)
            h[-- v[f[i].l]] = i;
 
        for(i = c - 1; i > 0; i --)
            s[f[h[i]].f] = MergeSegment(s[f[h[i]].f], s[h[i]]);
        for(i = 0; i < c; i ++)
            if(!s[i])
                s[i] = new Segment::Node();
 
        // for(i=0;i<c;i++)cout<<f[i].l<<' ';cout<<endl;
        // for(i=0;i<c;i++)cout<<(s[i]?s[i]->v:0)<<' ';cout<<endl;
 
        return;
    }
 
    void BuildSAM(void)
    {
        int s, l, r;
        int i;
 
        InitSAM();
        l = r = 0;
 
        for(q[r ++] = make_pair(0, 0); l < r; l ++)
        {
            s = q[l].first;
            for(i = 0; i < S; i ++)
                if(Trie::f[s].s.count(i))
                    q[r ++] = make_pair(Trie::f[s].s[i], InsertSAM(Trie::c, i, Trie::l[Trie::f[s].s[i]], q[l].second));
        }
        // cout<<c<<endl;
        MergeSAM();
 
        return;
    }
}
 
char s[N];
 
inline int ID(char c)
{
    return c - 97;
}
 
int Solve(int x)
{
    int i, p, o;
 
    for(i = p = 0; s[i]; i ++)
    {
        if(!SAM::f[p].s.count(ID(s[i])))
            return 0;
        p = SAM::f[p].s[ID(s[i])];
    }
 
    // cout<<"VER "<<x<<endl;
    for(o = 0; x; x = Trie::p[Trie::t[x]])
        o += Segment::SumSegment(SAM::s[p], 0, Trie::c - 1, Trie::l[Trie::t[x]], Trie::l[x]);
 
    return o;
}
 
int main(void)
{
    int n, m, x;
    int i, p;
 
    scanf("%d", &n);
    for(i = 1, p = 0; i <= n; i ++)
    {
        scanf("%d", &x);
        if(x == 1)
            p = 0;
        else
        {
            scanf("%d", &x);
            p = Trie::g[x];
        }
 
        // printf("parent = %d\n", p);
 
        scanf("%s", s);
        if(!Trie::f[p].s.count(ID(s[0])))
        {
            Trie::f[p].s[ID(s[0])] = i;
            Trie::g[i] = i;
        }
        else
            Trie::g[i] = Trie::f[p].s[ID(s[0])];
    }
    Trie::InitChain(0);
    Trie::ConnectChain(0, 0);
    SAM::BuildSAM();
 
    scanf("%d", &m);
    while(m --)
    {
        scanf("%d %s", &x, s);
        x = Trie::g[x];
        printf("%d\n", Solve(x));
    }
 
    return 0;
}