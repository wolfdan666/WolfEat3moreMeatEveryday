// 分发礼物，每个人三种不同种类的礼物，也就是 把数组 从左到右  依次三个每个减一减到不能减的时候就完事了，所以只有不断重复sort就行
// 大到小的sort->  nlog(n) * 分类离散序列化后的类数的量级
// 显然不是最好的算法，而且是可以很大优化的 (比如前三个都是某个数的倍数的话，就是求__gcd(__gcd(a,b),c)) 2019年7月7日21:02:17 花了10mins了，看别人算法

/*
这篇可以作为优先队列的入门来写

看了大佬的代码，感觉自己受到了思维训练
1. 重复的sort  --->   优先队列   直接解决
2. 可以使用map取代离散化（他们的反hash都可以使用lower_bound() (大于 >) 来二分查找相应值的序列位置）----> 这里不好使用离散化，因为离散化不会记录每个值的数量... 所以本题直接map，与hash没有关系
大佬的 priority_queue 的定义方式我没有懂，所以 去查一下资料  2019年7月7日21:19:19 加速
[果然看了一下cplusplus的定义以及各个参数的含义自己清楚多了](http://www.cplusplus.com/reference/queue/priority_queue/?kw=priority_queue)

 看cplusplus.com上面的介绍好想笑233
 Elements are popped from the "back" of the specific container, which is known as the top of the priority queue.


 1. mdzz了 ， greater 是小值在前...缺省的less是大值在前
 2. 使用了 __gcd(__gcd(a,b),c)之后，反而只通过 43.75%？！  ---> 因为gcd 递归 太多层了，反而超时或者爆栈了吧o(╥﹏╥)o ？
 3. VScode粘贴后撤销一步就可以使用原来复制过来时候的格式了
 */

/**
* Copyright(c)
* All rights reserved.
* Author : Universal
* Description : sample
*/
// #include <bits/stdc++.h>
// #define MAXN 100005
// #define INF 0x3f3f3f3f
// #define PI acos(-1)
// using namespace std;
// typedef long long ll;

// priority_queue<ll, vector<ll>, less<ll>> que;
// map<ll, ll> s;
// map<ll, ll>::iterator it;

// int main()
// {
//     ll n;
//     cin >> n;
//     ll p;
//     for (ll i = 0; i < n; i++) {
//         scanf("%lld", &p);
//         s[p]++;
//     }
//     for (it = s.begin(); it != s.end(); it++) {
//         que.push(it->second);
//     }
//     ll sign = 1;
//     ll ans = 0;
//     while (sign) {
//         if (que.size() < 3)
//             break;
//         ll a = que.top();
//         que.pop();
//         ll b = que.top();
//         que.pop();
//         ll c = que.top();
//         que.pop();
//         ans++;
//         a--;
//         b--;
//         c--;
//         if (a)
//             que.push(a);
//         if (b)
//             que.push(b);
//         if (c)
//             que.push(c);
//     }
//     cout << ans << endl;
//     return 0;
// }

// 2019年7月7日21:29:40 自己动手写一遍
#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<ll,vector<ll>,less<ll>> que;
map<ll,ll> s;
map<ll,ll>::iterator it;
ll n,p,a,b,c,ans;

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>p;
        s[p]++;
    }
    // 这里auto可能判断为实体了，所以不能用`->` , 而是 ` . `
    // for(auto it : s){
    //     que.push(it.second);
    // }
    for (it = s.begin(); it != s.end(); it++) {
        que.push(it->second);
    }
    bool sign = 1;
    while(sign){
        // if(que.size()<3) break;
        // // for(auto it : s){
        // //     cout<<it.second<<endl;
        // // }
        // ll a=que.top(); que.pop();
        // ll b=que.top(); que.pop();
        // ll c=que.top(); que.pop();
        // ll t = __gcd(__gcd(a,b),c);
        // // cout<<"t="<<t<<endl;
        // ans += t;
        // a-=t; b-=t; c-=t;
        // if(a) que.push(a);
        // if(b) que.push(b);
        // if(c) que.push(c);
        if(que.size()<3) break;
        ll a = que.top();
        que.pop();
        ll b = que.top();
        que.pop();
        ll c = que.top();
        que.pop();
        ans ++;a--;b--;c--;
        if(a)que.push(a);
        if(b)que.push(b);
        if(c)que.push(c);
    }
    cout<<ans<<endl;
    return 0;
}

poj