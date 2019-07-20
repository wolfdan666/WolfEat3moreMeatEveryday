/*
2019年7月19日16:30:20 开始看题
统一转化成为10进制，然后转化为其他性质

但是有个问题就是 ： 转化过程中直接用数字存肯定存不下，要用数组来存着进行位运算
上次看过这种，这次直接试试自己写

2019年7月19日17:09:45 已经过了40mins了，然而自己现在还是在试探性地写题，所以可能会浪费很多时间..战略不容许，所以先看大佬的思路，确定自己的思路是否正确

结果2019年7月19日17:23:45 看了大佬的代码发现自己 先转10进制再转化的代码很长很臭...... 在大战略上面是失败的，那么就算你小战略上 使用位数组来处理也不会带来多大改善..
所以说还是 要从大战略先优化.. 小战略当然也要尽量优化..然后就是自己的get_value 函数写得过于复杂还写错了....  只减去了基本值但是没有加上他们自带的偏移量


饭后又看了50mins....太菜了，大概此题写题，想题，看题花了2小时，太菜了啊
 */

// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
// using namespace std;
// #define ll long long
// const int M = 1e5;
// char cs[M],cc[M],ct[M];
// int s[M],c[M],t[M];
// int a,b;
// int get_value(char a){
//     if('0'<=a&&a<='9') return a-'0';
//     else if('A'<=a&&a<='Z') return a-'A';
//     else return a-'a';
// }

// ll qpow(ll x, int n) {
//     ll res = 1;
//     while(n) {
//         if(n & 1) res = res * x % mod;
//         x = x * x % mod;
//         n >>= 1;
//     }
//     return res;
// }

// void add(ll x){
//     /* st为进位 */
//     int st = 0;
//     for(int i=0;x;i++){
//         a[i] += x%10 + st;

//     }
// }

// s2c(){
//     int n = cs.size();
//     int k = 0;
//     for(int i=n-1,i>=0;i--){
//        ll tmp = char[i] * qpow(a*1ll,k);
//        add(tmp);
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     int _;
//     cin>>_;
//     while(_--){
//         cin>>a>>b;
//         cin>>cs;
//         s2c();
//         solve();
//     }

//     return 0;
// }



/* 大佬代码和思路 */

#include <stdio.h>
#include <string.h>
const int maxn = 1000;
int  t[maxn], A[maxn];
char str1[maxn], str2[maxn];
int n, m;
void solve()
{
    int i, len, k;
    len = strlen(str1);
    /* 这里应该是i = len - 1 开始的 \
      48 是因为 -48 + 0
      55 because - 65 + 10
      61 because - 97 + 36

      然后这里i从个位(在len-1处)开始，t数组的最小下标存的个位的值，所以t数组是从个位开始的*/
    for(i=len-1; i>=0; --i) t[len-1-i] = str1[i] -(str1[i]<58 ? 48: str1[i]<97 ? 55: 61);
    // for(i=len; i>=0; --i) t[len-1-i] = str1[i] -(str1[i]<58 ? 48: str1[i]<97 ? 55: 61);
    for(k=0; len;) {
        for(i=len; i>=1; --i) {
            /* 从大下标，也就是大的数位开始 -- t[i]%m*n是
            大数位本位上面不能除尽的数值乘以自己相对下一位的权重n加到下一位上面去操作
            然后本位就保留除得尽得部分 */
            t[i-1] +=t[i]%m*n;
            t[i] /= m;
        }
        /* 每次把末尾不能除尽的部分用于A数组的值，然后就是t[0]/=m,相当于让A数组进位了，上升了一个m的权重(权重乘以了m) */
        A[k++] = t[0] % m;
        t[0] /=m;
        /*高位的数是否为0，为0则要减少len */
        while(len>0&&!t[len-1])  len--;
    }
    str2[k] =NULL;
    for(i=0; i<k; i++)
        str2[k-1-i] = A[i]+(A[i]<10 ? 48: A[i]<36 ? 55:61);
}

int main()
{
    int T;
//    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%s",&n, &m, str1);
        solve();
        printf("%d %s\n%d %s\n\n", n, str1, m, str2);
    }
    return 0;
}
