/*
直接看了题解看std代码，但还是有点不理解为什么
要把比to[i]后面的值都加上a[i]
change(a[i], to[i], n + 1, 1, n + 1, 1);

2019年7月29日20:25:41 不耗了，明天继续过来，因为已经接近两个小时了

2019年7月30日14:34:20 再来
2019年7月30日15:18:17 看了队友两人发的解法，感觉标程写的思路还是比较自然一点，所以自己写一下

 */


#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;
double pi = acos(-1);
#define mod 1000000007
#define inf 0x3fffffff
long long int a[200010], number[200010 << 2], number2[200010 << 2], bz[200010 << 2], bz2[200010 << 2];
struct node {
    int id;
    long long int b;
    /* data */
} no[200010];
bool cmp(const node& fi, const node& se)
{
    if (fi.b == se.b)
        return fi.id < se.id;
    return fi.b < se.b;
}
int to[200010];
void PushUp(int rt)
{
    number[rt] = number[rt * 2];
    if (number[rt * 2 + 1] > number[rt])
        number[rt] = number[rt * 2 + 1];
}

/* 难道上面的number2不用清理？ */
void build(int l, int r, int rt)
{
    bz[rt] = 0;
    number[rt] = 0;
    bz2[rt] = 0;
    if (l == r) {
        number[rt] = 0;
        number2[rt] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, rt * 2);
    build(mid + 1, r, rt * 2 + 1);
    PushUp(rt);
}
/* 下推标记 */
void pushdown(int rt, int l, int r)
{
    int mid = (l + r) / 2;
    if (bz[rt]) {
        bz[rt * 2] += bz[rt];
        bz[rt * 2 + 1] += bz[rt];
        number[rt * 2] += (bz[rt]);
        number[rt * 2 + 1] += (bz[rt]);
        bz[rt] = 0;
    }
    if (bz2[rt]) {
        bz2[rt * 2] += bz2[rt];
        bz2[rt * 2 + 1] += bz2[rt];
        number2[rt * 2] += (bz2[rt]);
        number2[rt * 2 + 1] += (bz2[rt]);
        bz2[rt] = 0;
    }
}
/* change(1e9, n + 1, n + 1, 1, n + 1, 1); */
/* 自己重写的时候发现是每次更改的时候递归到叶子节点然后加区间的个数加1 */
/* change(a[i], to[i], n + 1, 1, n + 1, 1); */
/* 这里是让to[i]的地方到n+1的区段每个节点的个数值都加1 */
void change(long long int o, int L, int R, int l, int r, int rt){
    if (L > R)
        return;
    /* 记录的是一个区间的和，不是每个都加一下 */
    if (l == r) {
        number[rt] += o;
        number2[rt] += 1;
        return;
    }
    if (L <= l && R >= r) {
        number[rt] += o;
        bz[rt] += o;
        bz2[rt] += 1;
        return;
    }
    int mid = (l + r) / 2;
	/* 下推标记 */
    pushdown(rt, l, r);
    if (L <= mid)
        change(o, L, R, l, mid, rt * 2);
    if (R > mid)
        change(o, L, R, mid + 1, r, rt * 2 + 1);
	/* 上推数值 */
    PushUp(rt);
}
/*long long int k = query(m - a[i], 1, n + 1, 1); */
long long int query(long long int k, int l, int r, int rt){
    if (l == r)
        return number2[rt];
    int mid = (l + r) / 2;
    pushdown(rt, l, r);
    int ans;
	/* 左孩子大于k，所以直接找左边，否则找右边 */
    if (number[rt * 2] > k)
        ans = query(k, l, mid, rt * 2);
    else
        ans = query(k, mid + 1, r, rt * 2 + 1);
    PushUp(rt);
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n = 1, m = 1;
        scanf("%d %d", &n, &m);
        build(1, n + 1, 1);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            no[i].b = a[i];
            no[i].id = i;
        }
        sort(no + 1, no + n + 1, cmp);
		/* 这里只是n+1的位置修改成为1e9,其他地方是不变的 */
        change(1e9, n + 1, n + 1, 1, n + 1, 1);
		/* 这里已经是sort之后的了，所以no[i].id不一定是i */
        for (int i = 1; i <= n; i++)
            to[no[i].id] = i;
        for (int i = 1; i <= n; i++) {
            long long int k = query(m - a[i], 1, n + 1, 1);
            printf("%lld ", i - k);
			/* 第一个number的叠加有什么意义？
			这里是把比i号元素大的元素都加上a[i]？
            记录的是一个区间的和，不是每个都加一下
            (第二天巩固了线段树算法并且再次看了题解之后才发现) */
			/* 所以number是区间数值和，number2是数值个数 */
            change(a[i], to[i], n + 1, 1, n + 1, 1);
        }
        printf("\n");
    }
    return 0;
}
