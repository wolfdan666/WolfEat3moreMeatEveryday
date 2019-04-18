// 2019年4月18日20:14:27 再次看题
// 计算next循环节(自己匹配自己)的个数即可
// 自己居然忘了咋写的了，看下板子

// #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int M = 1e6+10;
int f[M];

void getFail(string p){
    int n = int(p.length());
    f[0]=f[1]=0;
    for(int i=1;i<n;i++){
        int j = f[i];
        while(j&&p[i]!=p[j]) j=f[j];
        f[i+1] = p[i]==p[j]? j+1:0;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string s;
    while((cin>>s)&&s[0]!='.') {
        getFail(s);
        int n = int(s.length());
        int l = n - f[n];
        if(n%l==0){
            cout<<n/l<<endl;
        }
        else cout<<1<<endl;
    }
    return 0;
}