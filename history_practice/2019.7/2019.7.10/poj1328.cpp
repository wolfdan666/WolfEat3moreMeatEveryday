/*
2019年7月10日16:05:05开始看题
1. 先计算每个点对应的 左右区间
2. sort左端点
3. 用一个变量维护最后一台的pos
4. 线性扫描即可
 2019年7月10日16:32:41 开写
2019年7月10日17:17:19 WA了几发，感觉有点奇怪...(一个这么简单的题写了这么久了...淡定，稳住...多练，多看，多学，以后会快起来的！)
 */

// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
// #include<math.h>
#include<cmath>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef pair<double,double> P;
int cnt;
double pos = -inf;
vector<P> a;
int n,d,x,y;
//左右区间 1 100000 和 1 2，所以必须也要比较second---> 也可以直接后面采用 min 取值的策略，两者都用，就鲁棒性更佳
bool cmp(P a,P b){ return a.first != b.first ? a.first < b.first : a.second < b.second; }

int main(){
    ios::sync_with_stdio(false);
    int Case = 0;
    // while(cin>>n>>d && n!=0){
    while(cin>>n>>d ){
        if(n==0 && d==0) break;
        // 多组必须重置数据
        pos = -inf; cnt = 0; a.clear();
        // cout<<pos<<endl;
        bool f = 0;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            if(y > d) f=1;
            else{
                double tem = sqrt(1.0*d*d-y*y);
                double l = 1.0*x - tem, r = 1.0*x + tem;
                a.push_back({l,r});
            }
        }
        if(f){cout << "Case " << ++Case << ": " << "-1"<< endl; continue;}
        sort(a.begin(),a.end(),cmp);
        // 其实0到 n-1也是可以的 `.`好像比`*`优先级高，所以要打括号使用...
        for(vector<P>::iterator i=a.begin();i != a.end();i++){
            if((*i).first <= pos){
            // if((*i).first < pos){ // 我TM的傻逼了，忘了写等于号，然后POJ的数据是真滴强大！这个绝妙的数据卡了我80mins！

                // cout << "(*i).first ："<<(*i).first <<"  pos : "<<pos<<endl;

                // 有上面sort保障，这里可以不要的
                pos = min((*i).second,pos);
            }
            else {
                cnt++;
                pos=(*i).second;
            }
        }
        cout << "Case " << ++Case << ": " << cnt << endl;
    }
    return 0;
}

// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <iostream>
// using namespace std;

// void Read(int& p)
// {
//     p = 0;
//     int f = 1;
//     char c = getchar();
//     while (c < '0' || c > '9')
//         f = (c == '-') ? -1 : 1, c = getchar();
//     while (c >= '0' && c <= '9')
//         p = p * 10 + c - '0', c = getchar();
//     p *= f;
// }

// struct point {
//     double l, r;
//     bool operator<(const point& x) const
//     {
//         if (r != x.r)
//             return r < x.r;
//         return l < x.l;
//     }
// } p[1234];

// int n, x, y, d, sp;
// double delta;

// int main()
// {
//     while (1) {
//         Read(n);
//         Read(d);
//         if (!n && !d)
//             break;
//         bool f = 1;
//         for (int i = 1; i <= n; i++) {
//             Read(x);
//             Read(y);
//             delta = 1.0 * d * d - 1.0 * y * y;
//             if (d >= y)
//                 p[i].l = x - sqrt(delta),
//                 p[i].r = x + sqrt(delta);
//             else
//                 f = 0;
//         }

//         if (!f) {
//             printf("Case %d: -1\n", ++sp);
//             continue;
//         }

//         sort(p + 1, p + 1 + n);
//         double now = p[1].r;
//         int ans = 1;
//         for (int i = 2; i <= n; i++)
//             if (p[i].l > now)
//                 ans++, now = p[i].r;
//         printf("Case %d: %d\n", ++sp, ans);
//     }
// }

// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <fstream>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// using namespace std;

// const int N = 1005;
// struct q {
//     double l, r;
// } q[N];
// bool cmp(struct q q1, struct q q2)
// {
//     return q1.l < q2.l;
// }
// int main()
// {
//     int n, r;
//     int cas = 0;
//     while (scanf("%d%d", &n, &r) && (n || r)) {
//         double a, b;
//         int flag = 0;
//         for (int i = 0; i < n; i++) {
//             scanf("%lf%lf", &a, &b);
//             if (b > r)
//                 flag = 1;
//             else {
//                 q[i].l = a * 1.0 - sqrt(r * r - b * b);
//                 q[i].r = a * 1.0 + sqrt(r * r - b * b);
//             }
//         }
//         if (flag) {
//             printf("Case %d: -1\n", ++cas);
//             continue;
//         }
//         sort(q, q + n, cmp);
//         double ll = q[0].l, rr = q[0].r;
//         int ans = 1;
//         for (int i = 1; i < n; i++) {
//             if (q[i].l > rr) {
//                 ans++;
//                 ll = q[i].l;
//                 rr = q[i].r;
//             } else {
//                 ll = q[i].l;
//                 rr = min(rr, q[i].r);
//             }
//         }
//         printf("Case %d: %d\n", ++cas, ans);
//     }
//     return 0;
// }