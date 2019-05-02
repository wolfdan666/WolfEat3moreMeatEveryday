// 2019年4月17日15:57:54开始看题
// 直接裸的Manacher,所以再默写一次
// 2019年4月17日16:10:56 一次过？No，tle了！但是bxbb这个没有出错,疯狂TLE是什么鬼

// 仔细比较了我的代码和别人的代码,2019年4月17日16:36:49发现最终我TLE的原因竟然是while(scanf("%s",s))要在scanf前面加上~！！！
// 果然卡题打铁就是因为自经验不够的原因，所以必须多多刷题，积累各种魔鬼级别的bug
// 40mins，其中30mins在debug...

// #include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;
const int M = 110010; // 记得开两倍是真的
char s[M],t[2*M];
int p[2*M];

int Init(){
    // int n = strlen(s);
    t[0] = '$',t[1] = '#';
    int j=2;
    // for(int i=0;i<n;i++){
    for(int i=0;s[i];i++){
        t[j++] = s[i];
        t[j++] = '#';
    }
    t[j] = '\0';
    return j;
}

int Manacher(){
    int n = Init();
    int max_len = -1;
    int mx=0,id=0;
    for(int i=1;i<n;i++){
        if(i<mx) p[i] = min(p[2*id - i],mx - i);
        else p[i] = 1;
        while(t[i - p[i]] == t[i + p[i]]) {
            p[i]++;
        }
        if(mx<i+p[i]){
            id = i;
            mx = i + p[i];
        }
        max_len = max(max_len,p[i]-1);
    }
    return max_len;
}

int main(int argc, char const *argv[])
{
    // int kase = 0;
    while(~scanf("%s",s)) {
        // kase++;
        // int m = strlen(s);
        // s[m] = '\0';
        // memset(p,sizeof(p),0);  // 都是由前面生成的，所以不用这样
        // memset(t,sizeof(t),0);
        printf("%d\n",Manacher());
    }
    return 0;
}