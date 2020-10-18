/*
8192K  跑不动线段树..
*/

#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define ptf(x) printf("%d", x)
#define pts puts("")
using namespace std;
const int MAXN = 1e6 + 5;
struct node {
    int l, r, f, lz;
    node() {f = 0;}
}t[MAXN << 2];
void pushUp(int rt) {
    t[rt].f = t[rt<<1].f + t[rt<<1|1].f;
}
void pushDown(int rt) {
    if(t[rt].f != 0) {
        t[rt<<1].lz++;
        t[rt<<1|1].lz++;
        t[rt<<1].f = t[rt].lz % 2;
        t[rt<<1|1].f = t[rt].lz % 2;
        t[rt].lz = 0;
    }
}
void build(int rt, int l, int r) {
    t[rt].l = l, t[rt].r = r, t[rt].f = 0, t[rt].lz = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid + 1, r);
}
void update(int rt, int l, int r) {
    if(t[rt].l == l && t[rt].r == r) {
        // t[rt].lz += 1;
        t[rt].lz = t[rt].lz==1? 0:1;
        return;
    }
    pushDown(rt);
    int mid = (t[rt].l + t[rt].r) >> 1;
    if(r <= mid) update(rt<<1, l, r);
    else if(l > mid) update(rt<<1|1, l, r);
    else {
        update(rt<<1, l, mid);
        update(rt<<1, mid + 1, r);
    }
    pushUp(rt);
}
int T, n, m, l, r;

int main() {
    sc(T);
    while(T--) {
        sc(n), sc(m);
        build(1, 1, n);
        while(m--) {
            sc(l), sc(r);
            l++,r++;
            update(1, l, r);
        }
        ptf(t[1].f), pts;
    }
    return 0;
}