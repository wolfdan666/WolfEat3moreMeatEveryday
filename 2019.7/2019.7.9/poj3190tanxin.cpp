/*
    2019年7月9日14:20:17 开始看题

    按照开始吃的牛的顺序排序，然后维护一个数组S，记录当前的每个畜栏安排进去的最后一个牛的，一开始没有畜栏
    遍历牛，找畜栏，找个某个畜栏正好在此牛开始时没有牛，就安排，遍历完都没安排就新建一个畜栏 O(n^2)
    所以从用数组来维护 变成 **用优先队列维护结束时间早的牛**，然后就是 O(n*log(n))

    一开始没有看清楚要输出的牛的 顺序，然后就写错了存储的结构...后面改...有点难受，所以一开始就要细心
    先 .first 换成 .first.first 然后 .second 换成 .first.second就可

    2019年7月9日16:01:27 发现是 输出  各 id 的牛 在哪个牛栏吃的！  输出牛栏号....我也是醉了，中途被打断，加上自己菜，导致出了这么多错，导致效率低下！下不为例！

    发现有点难改，所以直接用大佬的代码吧... 尽力高效点

 2019年7月9日14:27:41我需要按照结束时间最早来建立优先队列，但是这里有个问题就是less<P> 怎么比较的我并不知道，所以这题直接去看大佬怎么写
    1. 发现有一个大佬直接使用的是  strut定义的cow ，然后strut 里面重载了  operator < (cow a,cow b)  just like follow behind
    ```cpp
    struct cow
    {
        int bg,ed,num;
        bool friend operator <(cow a,cow b)
        {
            return a.ed>b.ed;
        }
    }x[100005];
    // 这样定义的话priority_queue<cow>后面两个参数是可以缺省的
    ```
    2. 法二： 像sort 的cop 函数一样得写结构类型的比较，或者直接 bool 类型的函数
        2.1 结构类型的比较
        ```cpp
        struct cmp{
            bool operator()(Node &a,Node &b)
            {
                if(a.r != b.r)
                    return a.r > b.r;
                else
                    return a.l > b.l;
            }
        };
        ```
        2.2 bool函数式得比较
        ```cpp
        bool operator < (node a, node b){
            if(a.x > b.x) return 1;
            else if(a.x == b.x)
                if(a.y >= b.y)   return 1;
            return 0;
        }
        ```


[发现有大佬也写了... 还很详细 说了 node &a这样的不行](https://blog.csdn.net/bat67/article/details/77585312)
 */

// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// typedef pair<int, int> tP;
// typedef pair<tP, int> P;
// int N, cnt;
// vector<int> ans;
// // bool operator<(P a, P b) { return a.first.second < b.first.second; }
// // priority_queue<P, vector<P>, less<P>> cow;
// bool operator < (tP &a, tP &b) { return a.second > b.second; }
// struct cmp1 {
//     // 就是说在cmp里面，当两个P使用  ()的时候，他们使用的下面的函数，也就是创建了一个自定义的函数
//     /* 使用时 大概是这样的 cmp1 A, A(a,b) 就类似  非strut的自定义函数了
//         bool cmp(P a,P b){ return a.second<b.second;}
//      */
//     bool operator()(tP a, tP b)
//     { // 重载() 的函数 叫 仿函数-->紫书找到的
//         return a.second > b.second; //小顶堆
//     }
// };
// // bool operator<(tP a, tP b) { return a.second > b.second; } // 使用了缺省的less，这边就没有用了...测试发现  这里根本没有起作用！
// // bool operator<(tP a, tP b) { return a.second < b.second; }
// // priority_queue<tP> cow;
// priority_queue<tP, vector<tP>, cmp1 > cow;
// vector<P> a;
// // 这里的cop函数也是P类型，但是应该不会受到前面重装的影响，因为重装的 < 只出现在P类型的直接未指定比较函数情况下的比较---实验发现确实不影响
// bool cop(P a, P b) { return a.first.first != b.first.first ? a.first.first < b.first.first : a.first.second < b.first.second; }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin >> N;
//     int l, r;
//     for (int i = 0; i < N; i++) {
//         cin >> l >> r;
//         a.push_back({ { l, r }, i });
//     }
//     sort(a.begin(), a.end(), cop);

//     for (auto i : a) {
//         cout << "a l-" << i.first.first << "r-" << i.first.second << " id " << i.second << endl;
//     }

//     cow.push(a[0].first);
//     cout << "cow.top().second : " << cow.top().second << endl;
//     cnt++;
//     ans.push_back(a[0].second + 1);
//     for (int i = 1; i < N; i++) {
//         if(a[i].first.first>cow.top().second){

//             cout << a[i].first.first <<"    " <<cow.top().second << endl;

//             cow.pop();
//             cow.push(a[i].first);
//         } else {
//             cow.push(a[i].first);
//             cnt++;
//             ans.push_back(a[i].second + 1);

//         cout<<"cow.top().second : "<<cow.top().second<<endl;

//         }
//     }
//     cout << cnt << endl;
//     for (int i = 0; i < cnt; i++) {
//         cout << ans[i] << endl;
//     }
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
struct Node {
    int l;
    int r;
    int id; //第几头牛
    int rk; //第几个槽
};
Node a[51000];
int n;
struct cmp {
    // 实在是太菜了，没有看懂这个重载括号是是什么魔鬼操作
    // 对的，确实是大于的时候是 小值 在前，先从sort来思考，如果是>，那么sort是降序，大的在前，而priority_queue与sort的相反,所以就是小值在前
    bool operator()(Node& a, Node& b)
    {
        if (a.r != b.r)
            return a.r > b.r;
        else
            return a.l > b.l;
    }
};
int cmp1(Node a, Node b)
{
    if (a.l != b.l)
        return a.l < b.l;
    return a.r < b.r;
}
int cmp2(Node a, Node b)
{
    return a.id < b.id;
}
void input()
{
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
}
void solve()
{
    int ans = 1;
    sort(a, a + n, cmp1);
    // 大佬为什么把大的值放在前面？
    priority_queue<Node, vector<Node>, cmp> q;
    // priority_queue<Node, vector<Node>, cmp> q;
    a[0].rk = 1;
    q.push(a[0]);
    for (int i = 1; i < n; i++) {
        Node t = q.top();

        if (a[i].l > q.top().r) {



            a[i].rk = t.rk;
            q.pop();
        } else {
            a[i].rk = ++ans;
        }
        q.push(a[i]);
        // cout <<  "q.top().r" << q.top().r << endl;
    }
    sort(a, a + n, cmp2);
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << a[i].rk << endl;
}
int main()
{
#ifdef H_R
    freopen("in.txt", "r", stdin);
#endif // H_R
    cin.tie(false);
    ios::sync_with_stdio(false);
    while (cin >> n) {
        input();
        solve();
    }
    return 0;
}