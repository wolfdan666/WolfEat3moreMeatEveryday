#include <bits/stdc++.h>
using namespace std;
const int maxn = 100020;
typedef long long ll;
//不能声明ws，保留字
int sa[maxn], wv[maxn], wss[maxn], wa[maxn], wb[maxn], r[maxn];
char s[maxn];
int Log[maxn];
ll a[maxn], sum[maxn];
bool cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void init() {
    Log[1] = 0;
    for(int i = 2; i < maxn; i++) Log[i] = Log[i/2] + 1;
}
//O(nlogn)读入下标从0开始
void get_sa(int *r, int *sa, int n, int m)
{
    int *x=wa, *y=wb;
    int p =0, i, j;
    for(i = 0; i < m; i++) wss[i] = 0;
    for(i = 0; i < n; i++) wss[ x[i]=r[i] ]++;
    // for(i = 1; i <= m; i++) wss[i] += wss[i - 1];
    for(i = 1; i < m; i++) wss[i] += wss[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p)
    {
        //对第二关键字排序
        for(p = 0, i = n - j; i < n; i++) // [n-j,n)没有内容
            y[p++] = i;
        for(i = 0; i < n; i++)
            if(sa[i] >= j) y[p++] = sa[i] - j;
        //对第一关键字排序
        for(i = 0; i < n; i++) wv[i] = x[y[i]]; //排名为i的第二关键字对应的第一关键字的排名，x此时相当于rankk，y相当于第二关键字的sa
        for(i = 0; i < m; i++) wss[i] = 0;
        for(i = 0; i < n; i++) wss[wv[i]]++;
        // for(i = 1; i <= m; i++) wss[i] += wss[i - 1];
        for(i = 1; i < m; i++) wss[i] += wss[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
        //相同的字符串排名相同
        swap(x,y);
        for(i = 1, p = 1, x[sa[0]] = 0; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1 : p++;
    }
}
//O(n)
int rankk[maxn], height[maxn];
void get_height(int n)
{
    int k = 0;
    for(int i = 1; i <= n; i++) rankk[sa[i]] = i;
    for(int i = 0; i < n; i++)
    {
        k ? k-- : 0;//根据性质height[rank[i]] ≥ (height[rank[i-1]] -1)
        int j = sa[rankk[i] - 1];//上一名的开始下标
        while(r[i + k] == r[j + k]) k++;
        height[rankk[i]] = k;
    }
}
int asa[maxn], dsa[maxn][30], ah[maxn], dh[maxn][30]; //2<<30
void rmq_init(int n,int a[], int d[][30])
{
    for(int i = 0; i < n; i++)
        d[i][0] = a[i];
    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 0; i + (1 << j) -1 < n; i++)
            d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
    }
}
int rmq(int l ,int r, int d[][30])
{
    // int k = int(log((double)(r - l +1)) / log(2.0));
    int k = Log[r - l +1];
    return min(d[l][k], d[r - (1 << k) +1][k]);
}
int main()
{
    //freopen("/Users/zhangkanqi/Desktop/11.txt","r",stdin);
    init();
    while(~scanf("%s",s))
    {
        ll v, t, L = 0, R = 0, k;// k :2^63 开longlong

        int len = strlen(s);
        for (int i = 0; i < len; i++)
            r[i] = (int) s[i];
        r[len] = 0;
        get_sa(r, sa, len + 1, 255);
        get_height(len);
        sum[0] = 0;
        for (int i = 1; i <= len; i++)
            sum[i] = sum[i - 1] + (len - sa[i] - height[i]);
        for (int i = 1; i <= len; i++)
            asa[i - 1] = sa[i]; // rmq数组的下标从0 开始
        rmq_init(len, asa, dsa);

        scanf("%lld", &t);
        while (t--)
        {
            scanf("%lld", &v);
            k = (L ^ R ^ v) + 1;
            if (k > sum[len])
            {
                printf("0 0\n");
                L = R = 0;
                continue;
            }
            int pos = lower_bound(sum + 1, sum + 1 + len, k) - sum; // 是由排名第pos的后缀贡献的
          //  printf("pos:%d\n", pos);
            int lenth = height[pos] + (k - sum[pos - 1]);// 排名第k的子串的长度
            //printf("lenth:%d\n", lenth);
            //找公共前缀长度第一个小于lenth的,若都>=lenth,flow = len，height[len] >= lenth


            /*2019年8月22日18:40:53 和zkq说了这个问题，这里的height是非单调递减的...
                后面2019年8月22日20:01:06 我在写blog的时候,发现这里是个好想法,想要直接获取满足条件的最末端，然后再rmq求最小的左值
            */

            int flow = upper_bound(height + 1 + pos, height + 1 + len, lenth, greater<int>()) - (height + 1);
           // printf("flow:%d\n", flow);
            if(flow < pos) swap(flow, pos);
            int st = rmq(pos - 1, flow - 1, dsa); // 求最小的l
           // printf("st%d\n", st);
            printf("%d %d\n", st + 1, st + lenth);
            L = st + 1, R = st + lenth;
        }
    }
    return 0;
}
