/*
法一:大小根堆  自己不会写了 ===>然后先暂时直接借鉴大佬的code先   (用优先队列实现大小根堆,在书P454也说了)
法二:链表+hash===李煜东老师说以后讲
*/


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 10000+100;

int n,a[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        priority_queue<int> q1,q2;
        while(q1.size()) q1.pop();
        while(q2.size()) q2.pop();
        int id;
        scanf("%d%d",&id,&n);
        rep(i,1,n) scanf("%d",&a[i]);
        printf("%d %d\n",id,(n+1)/2);
        int cnt = 0;
        rep(i,1,n){
            if(i == 1) q2.push(-a[i]);// 小根堆   P454也说了
            else if(a[i] > -q2.top()) q2.push(-a[i]); // 大根堆
            else q1.push(a[i]);
            if(q1.size() > i/2) q2.push(-q1.top()), q1.pop();
            if(q2.size() > (i+1)/2) q1.push(-q2.top()), q2.pop();
            if(i%2)
            {
                cnt++;
                printf("%d",-q2.top());
                if(cnt % 10 == 0 || cnt == (n+1)/2) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}