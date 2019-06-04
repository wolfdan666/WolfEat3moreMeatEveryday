/*
2019年6月4日10:53:29 开始看题

1. 由于b,c数组可能有a数组不含有的值,为了边输入b,c边记数操作,所以不好只对a序列化,然后就可以想到用set,
但是你这是很稚嫩没有顾全大局的简单想法,因为set不能用下标值索引,所以还是要顾全大局

先序列化所有语言
然后对和语言人数进行统计
最后针对人数进行择优选择


2019年6月4日20:31:12 一个如此简单的题目，由于自己刷题不连续，导致一个题目做了接近2个半小时，下部为例，做题一定要连续！
发现在特殊的日子里，好像virtual judge的外网路线也断了
2019年6月4日20:39:03 wa on test9！

===> 找到错误发现是因为自己的sort(a+1,a+n+2*m)根本就没有写2*m,而且就算写了也会因为a数组被sort而造成污染
然后 自己是 没写2*m导致query一些不存在的语言的时候就会产生错误的下标值，从而造成不可知的错误

解决:创建辅助数组t
*/

#include<bits/stdc++.h>
using namespace std;
const int M = 6e5+10;
int cnt[M],cnt2[M];
int a[M],t[M],b[200010],c[200010];
int d[M];
int k=0;
int n,m;

void discrete(){
    // sort(a+1,a+1+n);
    sort(t+1,t+1+n+2*m);
    // for(int i=1;i<=n;i++)
    for(int i=1;i<=n+2*m;i++)
        if(i==1||t[i]!=t[i-1])
            d[++k]=t[i];
}

int query(int x){
    return lower_bound(d+1,d+k+1,x)-d;
}

int main(int argc, char const *argv[]){
    cin>>n;
    // for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),t[i]=a[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        t[n+i]=b[i];
        // a[n+i]=b[i];
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&c[i]);
        // a[n+m+i]=c[i];
        t[n+m+i]=c[i];
    }

    discrete();// 对语言进行序列化
    for(int i=1;i<=n;i++){// 对人会的语言进行统计
        cnt[query(a[i])]++;
    }
    int pre = query(b[1]);// 当前的audio语言下标值
    int pre2 = query(c[1]); // 当前的字幕语言下标值
    int ans = 1; // 当前假定的ans
    for(int i=2;i<=m;i++){
        int cur = query(b[i]);
        if(cnt[cur]>cnt[pre]){
            ans = i;
            pre = cur; // 只有变大了,才要进行更换
            pre2 = query(c[i]);
        }
        else if(cnt[cur]==cnt[pre]){
            int cur2 = query(c[i]);
            if(cnt[cur2]>cnt[pre2])
                ans = i,pre=cur,pre2 = cur2;
                // ans = i,pre2 = query(c[i]);  // pre值也要变，不然不是同一部电影了...因为pre记录的是下标而非cnt值，所以必须要变啊
        }
    }
    cout<<ans<<endl;
    return 0;
}