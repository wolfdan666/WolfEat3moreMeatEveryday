// 开始看题2019年4月25日20:07:04
// 十分明显的AC自动机的简单题，但是由于自己没写过，所以先借鉴

// 复习了一下trie和AC—automaton
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
//ac_automaton algorithm

const int MAXNODE = 550000;
const int SIGMA_SIZE = 26;

int fail[MAXNODE]; //失配数组
int last[MAXNODE]; //后缀链接
int ans;

//构造trie
int ch[MAXNODE][SIGMA_SIZE];
int val[MAXNODE];
int sz;
void init()
{
    ans = 0;
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
}

void insert(char *s)
{
    int u = 0;
    int len = strlen(s);

    for(int i = 0; i < len; ++i)
    {
        int c = s[i] - 'a';
        if(!ch[u][c])
        {
            memset(ch[sz], 0, sizeof(ch[sz]));
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    val[u]++;
}


//计算fail指针
void getFail()
{
    queue<int> q;
    fail[0] = 0;
    for(int c = 0; c < SIGMA_SIZE; c++)
    {
        int u = ch[0][c];
        if(u)
        {
            fail[u] = 0; q.push(u); last[u] = 0;
        }
    }
    while(!q.empty())
    {
        int r = q.front(); q.pop();
        for(int c = 0;c < 26;c++)
        {
            int u = ch[r][c];
            if(!u){ ch[r][c] = ch[fail[r]][c]; continue;}
            q.push(u);
            int v = fail[r];
            while(v && !ch[v][c]) v = fail[v];
            fail[u] = ch[v][c];
            last[u] = val[fail[u]] ? fail[u] : last[fail[u]];
        }
        //cout << last[r] <<endl;
    }
}

void solve(int j)
{
    //cout << j <<endl;
    if(!j) return;
    if(val[j])
    {
        ans += val[j];
        val[j] = 0;
    }
    solve(last[j]);
}
void find(char* T)
{
    int len = strlen(T),j = 0;
    getFail();
    for(int i = 0; i < len; i++)
    {
        j = ch[j][T[i] - 'a'];
        //cout << val[j] <<endl;
        if(val[j]) solve(j);
        else if(last[j]) solve(last[j]);
    }
}

int main()
{
    int t, n;
    char dic[100],str[1100000];
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d", &n);
        while(n--)
        {
            scanf("%s", dic);
            insert(dic);
        }
        scanf("%s", str);
        find(str);
        printf("%d\n", ans);
    }
    return 0;
}
