// 2019年4月17日20:24:42 开始看题

// 晕死，看了几遍，还是不懂题目是要怎么插入theme section，看看大佬怎么说
// 大佬说:题意是在一个字符串中找出一个前缀一个后缀和一个中间的子串，互相不重叠并且三部分完全一样
// 暴力枚举长度N/3，然后KMP
// 2019年4月17日22:12:07 回去做自己咯

#include <bits/stdc++.h>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define FORD(i,s,t) for(int i=(s-1); i>=t; i--)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

const int MAX = 1000010;
char s[MAX];
int p[MAX];
bool hastail(int len, int n) {
    FOR(i, 0, len)
        if( s[i] != s[n-len+i] )
            return false;
    return true;
}

void kmp2(int m, char a[])
{
    p[1] = 0;
    int j = 0;
    for(int i = 2; i <= m; ++i)
    {
        while( (j > 0) && (a[i] != 0) && (a[j+1] != a[i]))
            j = p[j];
        if( (a[j+1] == a[i]) || (a[i] == 0)) ++j;
        p[i] = j;
    }
}

bool kmp1(int n,int m, char a[], char x[])
{
    int j = 0;
    for(int i = 1; i <= n; ++i)
    {
        while( (j > 0) && (x[i] != 0) && (a[j+1]!=0)  && (a[j+1] != x[i]))
            j = p[j];
        if( (x[i]==0) || (a[j+1] == 0) || (a[j+1] == x[i]) )
            ++j;
        if(j == m){
            return true;
            j = p[j];
        }
    }
    return false;
}

bool right(int len, int n) {
    kmp2(len, s-1);
    // cout<<"www"<<*s<<"DD"<<*(s-1)<<endl;   这里测试了一下大佬的代码，发现*s是首字母，*(s-1)是空，之所以没错，是因为她后面取的for(i<=m)，有个=顶住了
    return kmp1(n - 2*len, len, s-1, s+len-1);
}
int solve(int len) {
    int maxlen = len/3;
    for(int i=maxlen; i>=1; i--) {
        if( hastail(i, len) && right(i, len) ) {
            return i;
        }
    }
    return 0;
}
int main() {
    int ncases;

    scanf("%d", &ncases);
    while( ncases -- ) {
        // scanf("%s", &s);
        scanf("%s", s);
        int len = strlen(s);
        if( len < 3 ) {
            printf("0\n");
            continue;
        }
        int ans = solve(len);
        printf("%d\n", ans);
    }
    return 0;
}