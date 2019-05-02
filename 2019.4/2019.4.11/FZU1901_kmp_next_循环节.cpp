// 开始看题2019年4月11日23:00:57
// 读懂题意是滑块周期重复，然后可能用到循环节，而且总长必定是答案
// 感觉答案就是循环节的个数+1(如果全由循环节组成，那就不加1)，但是现在2019年4月11日23:17:21时间不够了， 所以也借鉴一下别人

/*
果然英雄所见略同，大佬和我想的一样，其实我是菜鸡
大佬思路:
求出该字符串的所有循环节。

求出字符串的next数组。可知len-next[len]就是字符串的最小循环节，然后next数组回退，len-next[next[len]]就是第二小循环节……

然后发现fzu好像不支持bits/stdc++  因为用bits就CE compile error
2019年4月11日23:28:18 回家
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long LL;
const double eps = 1e-6;
const int INF = 2e9;
const LL LNF = 9e18;
const int MOD = 1e9+7;
const int MAXN = 1e6+10;

char x[MAXN];
int Next[MAXN];

void get_next(char x[], int m)
{
    int i, j;
    j = Next[0] = -1;
    i = 0;
    while(i<m)
    {
        while(j!=-1 && x[i]!=x[j]) j = Next[j];
        Next[++i] = ++j;
    }
}

int ans[MAXN];
int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", x);
        int len = strlen(x);
        get_next(x, len);

        int cnt = 0;
        for(int k = Next[len]; k!=-1; k = Next[k])
            ans[++cnt] = len-k;

        printf("Case #%d: %d\n", ++kase, cnt);
        for(int i = 1; i<=cnt; i++)
        {
            printf("%d", ans[i]);
            if(i!=cnt) printf(" ");
        }
        printf("\n");
    }
}