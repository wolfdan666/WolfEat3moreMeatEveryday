// 开始读题
// 思路：快乐值大到小的sort，然后前缀和长度，然后遍历时间长度数组和快乐值的max
// 改进:后面两步可以直接一起，也就是说，不用开一个大的sum前缀和数组了
// 结果沉迷卖货gcp，所以明天写吧2019年3月25日22:54:55
// 发现自己昨天好像想简单了...
// 2019年3月26日20:26:22 后面自己没有想到解题的一条思路主线，后面看了tutorial，发现遍历beauty(当做min来对待).然后求最大
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define first x
// #define second y
// typedef pair<int,int> P;
// const int maxn = 3e5+5;
// P p[maxn];ll sum;

// int main(int argc, char const *argv[]){
//     ios::sync_with_stdio(false);
//     int n,k;
//     int a,b;
//     cin>>n>>k;
//     for(int i=0;i<n;i++){
//         cin>>a>>b;
//         p[i].make_pair(a,b);
//     }
//     return 0;
// }

// tutorial中大佬的code
// 他巧妙使用pair.first当做b，这样对b,t的pair排序的compare就不用自己写了
// 从大到小遍历和假定最小Beauty配合起来很关键，这里就很好做到了不能选择未遍历到的地方
// 我昨天没想到的就是很关键的假定最小的操作，嗯，多思考以后

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5+9;
int n, k;
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    ll res = 0;
    ll sum = 0;
    set<pair<int, int> > s;
    for(int i = n - 1; i >= 0; --i){
        s.insert(make_pair(a[i].second, i));
        sum += a[i].second;
        while(s.size() > k){
            auto it = s.begin();
            sum -= it->first; // Cpp的set有序
            s.erase(it);
        }

        res = max(res, sum * a[i].first);
    }

    cout << res << endl;
    return 0;
}