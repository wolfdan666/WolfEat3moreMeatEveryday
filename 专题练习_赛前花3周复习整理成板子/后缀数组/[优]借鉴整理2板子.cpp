/*
板子声明 : str从0开始,而非像oi-wiki中的从1开始

*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
typedef long long LL;
int sa[maxn],height[maxn],rank[maxn],t[maxn],t2[maxn],c[maxn];
int n;
char str[maxn];

void build_sa(int m,int n){
    int *x=t,*y=t2;
    for(int i=0;i<m;i++)c[i]=0;
    for(int i=0;i<n;i++)c[x[i]=str[i]]++;
    for(int i=1;i<m;i++)c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
        for(int i=0;i<m;i++)c[i]=0;
        for(int i=0;i<n;i++)c[x[y[i]]]++;
        for(int i=1;i<m;i++)c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        x[sa[0]]=0;p=1;
        for(int i=1;i<n;i++)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++);
        if(p>=n)break;
        m=p;
    }
}

void getheight(int n){
    int k=0;
    for(int i=1;i<=n;i++)::rank[sa[i]]=i;
    for(int i=0;i<n;i++){
        if(k)k--;
        int j=sa[::rank[i]-1];
        while(str[i+k]==str[j+k])k++;
        height[::rank[i]]=k;
    }
}