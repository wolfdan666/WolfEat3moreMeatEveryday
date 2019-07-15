/*
NOIP2012
国王游戏https://www.luogu.org/problemnew/show/P1080
2019年7月15日14:10:56 开始(已经看过了书上的核心解题思路)看stdin
// 2019年7月15日14:33:06 只过了60%！死在了高精度上面...

2019年7月15日14:43:24 顶不住了，先用大佬的高精度看看先

2019年7月15日15:27:08 AC了...
 */
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
// using namespace std;
// #define ll long long
// ll ans = 0;
// ll n,a,b,x,y;
// typedef pair<ll,ll> P;
// vector<P> peo;
// bool cmp(P a,P b){ return a.first*a.second < b.first*b.second; }

// int main(){
//     ios::sync_with_stdio(false);
//     cin>>n>>x>>y;
//     for(int i=0;i<n;i++){
//         cin>>a>>b;
//         peo.push_back({a,b});
//     }
//     sort(peo.begin(),peo.end(),cmp);
//     ll pre = x;
//     for(int i=0;i<n;i++){
//         // 不要算上自己的左手
//         ll tem = pre / peo[i].second;
//         ans = max(ans,  tem);
//         // ans = max(ans, peo[i].first * pre / peo[i].second);
//         pre*=peo[i].first;
//     }
//     cout<<ans<<endl;

//     return 0;
// }
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