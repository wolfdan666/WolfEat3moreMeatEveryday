// 2019年4月24日17:03:54开始看题
// 2019年4月24日17:10:41 感觉是考纯的数据结构...可是我还不会...
// 2019年4月24日17:32:52 懂了这题的思路，能看懂，但不一定会写，所以还是多多练习吧
// 今天做了大概3h40mins了，明天go on
// 交的时候，发现这题tle了！

// 莫名其妙...网上搜的代码全tle，所以我觉得是2014年的题目的判题机出问题了，所以不管了，吃饭去

/*
题目大意：给定一些结构体，结构体有value值和key值，Q次询问，输出每个key值对应的value值。

解题思路：思路很简单，写个类词法的递归函数，
每次将key值映射成一个hash值，用map映射每个key的value起始终止位置，预处理完了查询就很简单了。
*/

#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;

const int maxn = 2000000;
const ll x = 123;

int N, Q, mv;
char op[maxn], s[maxn];
map<ll, pii> G;

inline int idx(char ch) {
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 10;
    else if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 36;
    else if (ch == '.')
        return 62;
    return 63;
}

void solve (ll u) {
    ll tmp = u;

    while (s[mv] != '}') {
        mv++;
        if (s[mv] == '}')
            return;
        u = tmp;

        while (s[mv] != ':')
            u = u * x + idx(s[mv++]);

        int l = ++mv;

        if (s[mv] == '{')
            solve(u * x + 62LL);// 62对应于那个点   .
        else
            while (s[mv+1] != ',' && s[mv+1] != '}') mv++;

        G[u] = make_pair(l, mv);
        mv++;
    }
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", s);

        mv = 0;
        G.clear();
        solve(0);

        scanf("%d", &Q);
        for (int i = 1; i <= Q; i++) {
            scanf("%s", op);

            ll ret = 0;
            int len = strlen(op);

            for (int i = 0; i < len; i++)
                ret = ret * x + idx(op[i]);

            if (G.count(ret)) {
                pii u = G[ret];
                for (int i = u.first; i <= u.second; i++)
                    printf("%c", s[i]);
                printf("\n");
            } else
                printf("Error!\n");
        }
    }
    return 0;
}