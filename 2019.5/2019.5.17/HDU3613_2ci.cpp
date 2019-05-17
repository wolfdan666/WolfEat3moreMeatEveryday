// 第一次详见 2019.4.12
// 2019年5月17日20:13:06 开始看题
// 2019年5月17日20:17:18 想到的思路是像昨天的poj3376一样的操作，就是先对自身和反串做ekmp，然后看所有位置
// 对模板串的最长相同串长(就是看s[i]处的extend[i]是不是==n-1-i(后面串长))就是让后面要是回文串，
// 前面如果也是回文串(用原串当模板串就okey)就完美

// 2019年5月17日20:22:52 但是还是不会写，所以直接看题解写(因为是第二次) --- 其实ekmp写这题是第一次，等下放一下第二种写法吧
// 2019年5月17日20:27:22 开始抄写借鉴改进(一个一个函数地抄)
// 写完main休息了5min,2019年5月17日21:11:22现在写ekmp
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
char s[MAXN],t[MAXN];
int n;
int next[MAXN],extend[MAXN],extend2[MAXN];
int val[27],sum[MAXN];  // sum是价值前缀和

void ekmp(char* s,char* t,int *next,int *extend){
// 自己苦苦理解了好久，后面去看了一下原来的教程，便豁然开朗
// next是T[i]...T[m - 1]与T的最长相同前缀长度
// 2019年5月17日21:31:29 开写
    // getNext
    next[n] = n;  // 加上这些才能更好理解语义，写算法练思维和表达，以及耐心和速度
    int k = 1,j = 0;
    while(j+1<n && t[k+j]==t[0+j]) j++;
    next[1] = j;
    for(int i=2;i<n;i++){

        // int len = k+next[k]-1,L = next[i-1];
        int len = k+next[k]-1,L = next[i-k];

        if(len-i+1>L) next[i] = L;
        else{
            j = max(0,len-i+1); // 这里长度也是剩余共同的长度

            // while(j+1<n && t[i+j]==t[0+j]) j++;
            while(i+j<n && t[i+j]==t[0+j]) j++;

            next[i] = j;
            k = i;// k 记录的是一个中间值
        }
    }

    //ekmp
    j = 0;

    // while(j+1<n&&s[0+j]==t[0+j]) j++;
    while(j<n&&s[0+j]==t[0+j]) j++;


    extend[0]=j;

    // k = 0;
    k = 1;

    for(int i=1;i<n;i++){

        // int len = k+extend[k]-1,L = next[i-1];// len为下标，L为长度
        int len = k+extend[k]-1,L = next[i-k];// len为下标，L为长度

        if(len-i+1>L) extend[i]=L; //下标-下标+1=长度差,再与另一个长度差做对比
        else{
            j = max(0,len-i+1);

            // while(j+1<n && s[i+j]==t[0+j]) j++;// 这里有两处错误
            while(i+j<n && j<n && s[i+j]==t[0+j]) j++;

            extend[i] = j;
            k = i;
        }
    }
// 2019年5月17日21:45:55 默写完成,先对语义进行一次检查
    // 2019年5月17日21:59:36 发现出了好多错...GG
// 不过领悟更深了，今天又是一题顶3题，明天再刷一遍这题
}

int main(int argc, char const *argv[]){
    int kase;
    cin>>kase;
    while(kase--) {
        for(int i=0;i<26;i++) cin>>val[i];
        scanf("%s",s);
        n = strlen(s);
        for(int i=0;i<n;i++){
            t[i] = s[n-1-i];
            if(i==0) sum[i] = val[s[i]-'a'];
            sum[i] = sum[i-1] + val[s[i]-'a'];
        }
        t[n] = '\0';

        ekmp(t,s,next,extend);
        ekmp(s,t,next,extend2);

        int ans = -1e8;
        // for(int i=1;i<=n;i++){  // extend下标为0的部分一般是不用的

        for(int i=1;i<n;i++){  // 原来第一cv的大佬code没有 = 号，等下写完子函数再探讨这里

            int sc = 0;
            // 前缀i个回文的价值
            if(extend[n-i] + n-i == n){
                sc += sum[i-1];// sum[i]的下标是有0的！所以！emmm
            }
            // 后缀n-i个回文的价值
            if(extend2[i] + i == n){
                sc += sum[n-1] - sum[i-1];
            }
            ans = max(ans,sc);
        }
        cout<<ans<<endl;
    }
    return 0;
}