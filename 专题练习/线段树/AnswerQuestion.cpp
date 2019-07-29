/*
2019年7月29日21:42:07 开始
第一次写线段树，所以半借鉴半写

2019年7月29日22:25:52 发现自己没有仔细看题目说x,y可能要交换
2019年7月29日22:30:47还是有问题，看下别人的代码-->发现我change只改了dat
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

void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){ t[p].sum=t[p].lmax=t[p].rmax=t[p].dat=a[l]; return ; }
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].sum = t[p*2].sum + t[p*2+1].sum;
    t[p].lmax = max(t[p*2].lmax,t[p*2].sum+t[p*2+1].lmax);
    t[p].rmax = max(t[p*2+1].rmax,t[p*2+1].sum+t[p*2].rmax);
    t[p].dat = max(t[p*2].dat,max(t[p*2+1].dat,t[p*2].rmax+t[p*2+1].lmax));
}

void change(int p,int x,int v){
    if(t[p].l==t[p].r){t[p].dat=t[p].sum=t[p].lmax=t[p].rmax=v;return ;}
    int mid = (t[p].l+t[p].r)/2;
    if(x<=mid) change(p<<1,x,v);
    else change(p<<1|1,x,v);
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
    t[p].lmax = max(t[p * 2].lmax, t[p * 2].sum + t[p * 2 + 1].lmax);
    t[p].rmax = max(t[p * 2 + 1].rmax, t[p * 2 + 1].sum + t[p * 2].rmax);
    t[p].dat = max(t[p * 2].dat, max(t[p * 2 + 1].dat, t[p * 2].rmax + t[p * 2 + 1].lmax));
}

int ask(int p,int l,int r){
    if(l <= t[p].l && r >= t[p].r) return t[p].dat;
    int mid = (t[p].l + t[p].r)/2;
    int val = -(1<<30);
    if(l<=mid) val = max(val,ask(p<<1,l,r));
    if(r>mid) val = max(val,ask(p<<1|1,l,r));
    return val;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>a[i];
    build(1,1,N);
    int i,x,y;
    while(M--){
        cin>>i>>x>>y;
        if(x>y) swap(x,y);
        if(i==1) cout<<ask(1,x,y)<<endl;
        else change(1,x,y);
    }
    return 0;
}