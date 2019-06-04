/*
2019年6月4日10:53:29 开始看题

1. 由于b,c数组可能有a数组不含有的值,为了边输入b,c边记数操作,所以不好只对a序列化,然后就可以想到用set,
但是你这是很稚嫩没有顾全大局的简单想法,因为set不能用下标值索引,所以还是要顾全大局

所以先输入n个科学家会的语言,并对语言计数,
*/

#include<bits/stdc++.h>
using namespace std;
const int M = 6e5+10;
int cnt[M];
int a[M],b[200010],c[200010];
int d[M];
int k=0;

void discrete(){
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(i==1||a[i]!=a[i-1])
            d[++k]=a[i];
}

int query(int x){
    return lower_bound(d+1,d+k+1,x)-d;
}

int main(int argc, char const *argv[]){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    cin>>m;
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        a[n+i]=b[i];
    }
    for(int i=1;i<=m;i++){
        scnaf("%d",&c[i]);
        a[n+m+i]=c[i];
    }
    discrete();
    for(int i=1;i<=n;i++){

    }

    return 0;
}