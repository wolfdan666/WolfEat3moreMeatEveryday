// 算法进阶指南  书40页
// 2019年7月8日21:51:17 看题

// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int M = 2550;
typedef pair<int,int> P;
int C,L;
// 下面这样实现没有将一头牛的大小值绑定在一起
// int mi[M],ma[M];
int mi,ma;
vector<pair<int,int> > a;
int sp,cnt;
vector<P> b;
int ans;

bool cop(P m,P n){ return m.first > n.first; }

int main(){
    ios::sync_with_stdio(0);
    cin>>C>>L;
    for(int i=0;i<C;i++){
        cin>>mi>>ma; a.push_back({mi,ma});
    }
    for(int i=0;i<L;i++){
        cin>>sp>>cnt; b.push_back({sp,cnt});
    }
    sort(a.begin(),a.end(),cop);
    sort(b.begin(),b.end(),cop);
    // poj的G++竟然不支持for auto...
    // for(auto &c:a){
    //     // 这里由于我是第一次大量地使用auto,所以由于不熟悉,导致出了错误,没有用&,导致b数组的值并没有确切被更改,导致出现了ans出现了问题---VScode的debug真香,除了gdb对中文名不友好之外
    //     for(auto &d:b)
    //         if (c.first <= d.first && c.second >= d.first && d.second){
    //             ans++,d.second--;
    //             break;
    //         }
    // }
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < L; j++) {
            if (a[i].first <= b[j].first && a[i].second >= b[j].first && b[j].second) {
                ans++, b[j].second--;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}