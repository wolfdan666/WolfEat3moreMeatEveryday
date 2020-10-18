/*
2019年7月19日20:10:26 开始看题
2019年7月19日20:36:55 Runtime Error(ACCESS_VIOLATION) --> ??
mdzz 多组数据又忘了清空...

易错点总结:
- mdzz 多组数据又忘了清空...
- 还有求和为了鲁棒性一定要直接 long long
- 求max时记得把影响因子初始化成了-inf

2019年7月19日20:57:13 G++和C++ 都 Runtime Error(ACCESS_VIOLATION)... 自闭...

2019年7月19日21:01:49再次认真读题，发现 竟然是L,R可以到顶然后狂按...
2019年7月19日21:10:10 C++ 还超时， G++ 没有超时...  突然感觉杭电和poj其实差不多，主要是自己太菜了

这个题目刷了一小时..GG
 */

// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
#define ll long long
const int inf = 0x3f3f3f3f;
const int M = 1e6+10;
stack<int> a,b;
/* sum是前缀和，f是i下标前的最大前缀和，为了鲁棒性，统一用ll */
ll sum[M],f[M];
int q,x;
char _;

int main(){
    ios::sync_with_stdio(false);
    while(cin>>q){
    // while(~scanf("%d",&q)){
        /*init */
        while(!a.empty()) a.pop();
        while(!b.empty()) b.pop();
        int top = 0;
        sum[0] = 0, f[0] = -inf;

        while(q--){
            cin>>_;
            if(_ == 'I'){
                cin>>x;
                top++;
                a.push(x);
                sum[top] = sum[top-1] + x;
                f[top] = max(f[top-1],sum[top]);
            }
            else if(_ == 'D') a.pop(),top--;
            /* 查了一下发现pop()没有返回值！
               要检测左右是否到底了... */
            else if(_ == 'L'){ if(!a.empty()){ b.push(a.top()),a.pop(),top--;}}
            else if(_ == 'R'){
                if(!b.empty()){
                    int tmp = b.top();
                    a.push(tmp),b.pop();
                    top++;
                    sum[top] = sum[top-1] + tmp;
                    f[top] = max(f[top-1],sum[top]);
                }
            }
            else{
                cin>>x;
                cout<<f[x]<<endl;
            }
        }
    }

    return 0;
}