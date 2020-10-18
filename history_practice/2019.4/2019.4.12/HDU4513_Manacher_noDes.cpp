// 2019年4月12日19:44:29开始看题
// 2019年4月12日19:46:19 发现这个题目是Manacher+简单的判断，所以自己照着板子试着写一手


// 2019年4月12日19:57:57 再次研读Manacher,类比记忆,kmp输出f[](or next[]),而Manacher输出p[]

// 2019年4月12日20:51:12 自己写了接近一个小时，还是不太会处理，时间不够了，所以还是借鉴先吧

/*#include<bits/stdc++.h>
using namespace std;
const int M = 2e5+10;
int s[100010];
int t[M];int l;

int Init(){
    int len = strlen(s);
    t[0]=2;t[1]=1;
    int j=2;
    for(int i=1;i<=len;i++){
        t[j++]=s[i];
        s[j++]=1;
    }
    t[j]='\0';
    return j;
}

void Manacher(){
    l = Init();
    int mx=0,id=0;
    for(int i=1;i<=l;i++){
        if(i<mx){
            p[i] = min(p[2*id-i],mx-i);
        }
        else p[i]=1;
        while(s[i-p[i]]==s[i+p[i]]) p[i]++;
        if(mx<i+p[i]){
            mx = i+p[i];
            id = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        Manacher();
        int ans=1;
        for(int i=1;i<=l;i++){
            if(p[i]>=2){
                if(t[i]==1){// 发现这个'#'为中心的时候(也就是这里的1的那个位置)的p[i]只能是奇数
                    if(p[i]&1){//偶数的时候非中心，不用判断
                        int tp=p[i]/2;//abba,这样对第二个b不适用！
                        int si=i/2;int f=1;
                        for(int j=si;j<si+tp;j++){
                            if(s[j]<s[j+1]){f=0;break;}
                        }
                        if(f) ans=max(ans,tp);
                    }
                }
                else{
                    if(p[i]>=4&&p[i]%2==0){// 发现实值为中心的时候都是偶数,且根本不会为奇数
                        int tp = p[i]/2-1
                    }
                }
            }
        }
    }
    return 0;
}*/


/*
2019年4月12日20:55:50 看了大佬的code，发现果然和自己想的一样，要把判断嵌入Manacher，但是自己由于太菜而不会嵌入，所以以后多多练习

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 100009;
int s[N*2], p[N*2];

int manacher(int len)
{
    int mx = 0, id = 0, ans = 1;
    p[0] = 0;
    for(int i=1; i<len; i++)
    {
        p[i] = 1;
        if(mx > i)
            p[i] = min(mx-i, p[2*id-i]);
        while(s[i-p[i]] == s[i+p[i]] && s[i-p[i]] <= s[i-p[i]+2])
            p[i]++;
        if(i+p[i] > mx)
            mx = i+p[i], id = i;
        if(ans < p[i]-1)
            ans = p[i]-1;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        s[0] = -1;
        for(int i=1; i<=n; i++)
        {
            s[i*2-1] = 0;
            scanf("%d", &s[i*2]);
        }
        s[2*n+1] = 0;
        printf("%d\n", manacher(2*n+1));
    }
    return 0;
}