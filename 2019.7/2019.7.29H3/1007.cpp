/*
第一发wa了？？？2019年7月29日12:48:30 找了很久感觉没有问题...
取消输入输出同步的话，没有endl或者return 0不输出..
2019年7月29日13:01:45 让队友帮忙debug

2019年7月29日13:16:34 队友ldm写暴力拍出了一个数据
5 5
5 1 5 2 5

不能把1清除掉！

要让后后一个看到前面的清掉的都是大的值，如果清掉1就是把小的清理了
所以每次保存好最小的就行

然后又拍出了错误...
5 5
1 5 1 2 5

q的push刚刚忘了从w[i]改成tmp
2019年7月29日13:37:24 再让队友拍，傻掉了

5 5
1 1 2 5 2
啊啊啊，我想得太简单了2019年7月29日13:40:34 坑队友了
如果前面小的话还是要把所有东西补回来

所以暴力点，直接保存所有数的优先队列，每次出队放入一个vector，然后再丢回来，但是n是2e5,
这就变成n*n*log(n)了---> 所以要特判一些，比如w[i]=m直接输出i-1
w[i]=m-1,就找一下有没有1,然后找到1

cd说为什么不把w[i]加进去再弹出，我说题意不容许，后面一想为啥不搞两个队列？
不加入弹出得到答案，加入的弹出得到下一个的队列！
正好有swap函数--->不行，总有一个队列会被污染！
用一个小顶堆来取代之前的pre

好把，TLE--->确实接近n*n的复杂度
2019年7月29日14:43:16
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 2e5 + 7 ;
int Q, n, m, w[M];
ll sum;
int k;
priority_queue<int,vector<int>,greater<int>> pre;
priority_queue<int,vector<int>,less<int>> q;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>Q;
    while(Q--){
        /* init */
        sum = 0;k=0;
        while(!q.empty()) q.pop();
        while(!pre.empty()) pre.pop();
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++){
            /* 根据题意不能弹出本次加入的 */
            /* 根据题意应该不会在空的时候满足条件 */
            // int pre=inf;
            /*每弹出一个k++,所以每回收pre一个k--*/
            // while(!pre.empty()) pre.pop();
            while(!q.empty()&&sum+w[i]>m){
                k++;
                pre.push(q.top());
                sum-=q.top();
                q.pop();
            }
            /*输出*/
            cout<<k<<" ";
            if(i==n){ cout<<endl; break; }
            /*回溯*/
            ll tmp = 0;
            /* = 再想想*/
            bool f=0;
            while(!pre.empty()&&tmp+pre.top()<=w[i]){
                f=1;
                tmp += pre.top();
                q.push(pre.top());
                k--;
                pre.pop();
            }
            /*能加入一个就无需加本身了,要加回之前的sum值
            本身未加入的话就相当于弹出了一个k++*/
            /*不对,加回本身,让其在后面的循环中进入pre*/
            // if(f) sum += tmp,k++;
            if(f) sum += tmp;
            q.push(w[i]);
            sum += w[i];
        }
    }

    return 0;
}