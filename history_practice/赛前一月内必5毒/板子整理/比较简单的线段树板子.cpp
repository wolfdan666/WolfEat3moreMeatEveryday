/*
2019年7月29日21:42:07 开始
第一次写线段树，所以半借鉴半写

2019年7月29日22:25:52 发现自己没有仔细看题目说x,y可能要交换
2019年7月29日22:30:47还是有问题，看下别人的代码-->发现我change只改了dat

2019年7月30日10:14:53 感觉还是有点不熟，想不出哪里错了，手画一颗线段树先

2019年7月30日11:02:27 找到了bug，但是提交wa了...
2019年7月30日11:27:05 找不到bug，自闭，去吃饭吧

2019年7月30日12:16:45 让队友帮忙debug，因为午饭时队友说帮忙debug

队友ldm说为啥不写个pushup，4行一样的回溯

果然是询问出了问题
2019年7月30日13:40:24 总算在各方帮助下debug完毕，并写出题解，继续努力-->写题解到14点
[题目](https://www.acwing.com/problem/content/description/246/)
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 5e5+7;
struct SegmentTree{
    int l,r;
    int lmax,rmax,sum;
    int dat;
} t[SIZE<<2];
int a[SIZE],N,M;

void pushup(int p){
    t[p].sum = t[p*2].sum + t[p*2+1].sum;
    t[p].lmax = max(t[p*2].lmax,t[p*2].sum+t[p*2+1].lmax);
    t[p].rmax = max(t[p*2+1].rmax,t[p*2+1].sum+t[p*2].rmax);
    t[p].dat = max(t[p*2].dat,max(t[p*2+1].dat,t[p*2].rmax+t[p*2+1].lmax));
}

void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){ t[p].sum=t[p].lmax=t[p].rmax=t[p].dat=a[l]; return ; }
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}

void change(int p,int x,int v){
    if(t[p].l==t[p].r){t[p].dat=t[p].sum=t[p].lmax=t[p].rmax=v;return ;}
    int mid = (t[p].l+t[p].r)/2;
    if(x<=mid) change(p<<1,x,v);
    else change(p<<1|1,x,v);
    pushup(p);
}

// int ask(int p,int l,int r){
//     if(l <= t[p].l && r >= t[p].r) return t[p].dat;
//     int mid = (t[p].l + t[p].r)/2;
//     int val = -(1<<30);
//     if(l<=mid) val = max(val,ask(p<<1,l,r));
//     if(r>mid) val = max(val,ask(p<<1|1,l,r));
//     return val;
// }

/* 此处感谢队友帮忙debug */
SegmentTree ask(int p,int l,int r){
    if (l<=t[p].l && r>=t[p].r) return t[p];
    int mid=(t[p].l+t[p].r)>>1;
    int val=-(1<<30);
    SegmentTree a,b,c;
    a.dat=a.sum=a.lmax=a.rmax=val;
    b.dat=b.sum=b.lmax=b.rmax=val;
    c.dat=c.lmax=c.rmax=val;
    c.sum=0;
    /* 要么都在最左边，要么都在最右边，要么跨越了左右，跨越了左右就要判断
    c.dat=max(max(a.dat,b.dat),a.rmax+b.lmax);
    这个点没想到会卡住 --> 我就是从前面的注释的ask函数出错来的*/
    if (l<=mid&&r<=mid){
        a=ask(p<<1,l,r);
        c.sum+=a.sum;
    }
    /* 还要注意左区间r<=mid,右区间l>mid */
    // else if (l>=mid&&r>=mid){
    else if (l>mid&&r>mid){
        b=ask(p*2+1,l,r);
        c.sum+=b.sum;
    }
    else{
        a=ask(p<<1,l,r);
        b=ask(p*2+1,l,r);
        c.sum+=a.sum+b.sum;
    }
    c.dat=max(c.dat,max(max(a.dat,b.dat),a.rmax+b.lmax));
    c.lmax=max(c.lmax,max(a.lmax,a.sum+b.lmax));
    c.rmax=max(c.rmax,max(b.rmax,b.sum+a.rmax));
    return c;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>a[i];
    build(1,1,N);
    int i,x,y;
    while(M--){
        cin>>i>>x>>y;
        if(i==1){
            if(x>y) swap(x,y);
            cout << ask(1, x, y).dat << endl;
        }
        else change(1,x,y);
        // for(int i=1;i<=9;i++){
        //     cout<<"dat: "<<t[i].dat<<" sum: "<<t[i].sum<<" lmax: "<<t[i].lmax<<" rmax: "<<t[i].rmax<<endl;
        // }
    }
    return 0;
}