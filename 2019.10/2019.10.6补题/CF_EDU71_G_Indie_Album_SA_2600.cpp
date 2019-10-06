/*
2019年10月06日15:52:43 开始看题? no.先休息一下,吃个水果,补充能量
2019年10月06日16:06:33 休息了15mins,开始看题

2019年10月06日16:17:42 有点分心...focus on!

2019年10月06日16:26:17 感觉是构建多个后缀自动机,然后id值要进行映射管理,然后就可以从某个节点开始拓扑跳fa后缀树来计数了

2019年10月06日16:31:58 感觉操作有点复杂,自己写可能要写一天多,然后这样训练太低效,不利于短期冲金牌,所以看tutorial吧

多个串还是用AC自动机比较好一点...看得有点懵了,所以先去复习一下AC自动机--->冲冲冲,向着目标进发!(有点累了就听歌放松一下)
2019年10月06日17:15:18 大概看懂了tutorial了...它就是证明了可以用AC自动机做这题...具体的方法讲得少,所以直接看代码吧

感觉直接看代码也会花很久的时间,所以再辅助一点大佬的blog

自闭30mins后的自己 ---> 2019年10月06日21:02:31 不要再自闭了,静下心来,一个个地慢慢看,加油!
2019年10月06日21:24:16 不行,有点看不懂,难受,明天复习一下AC自动机再看吧
*/

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
const int AL = 26;
const int N = 400 * 1000 + 13;

struct node{
    int nxt[AL];
    node(){
        memset(nxt, -1, sizeof(nxt));
    }
    int& operator [](int x){
        return nxt[x];
    }
};

struct node_at{
    int nxt[AL];
    int p;
    char pch;
    int link;
    int go[AL];
    node_at(){
        memset(nxt, -1, sizeof(nxt));
        memset(go, -1, sizeof(go));
        link = p = -1;
    }
    int& operator [](int x){
        return nxt[x];
    }
};

int cntnm;
node trienm[N];

int cntqr;
node_at trieqr[N];

int add_string(string s){
    int v = 0;
    for (auto it : s){
        int c = it - 'a';
        if (trieqr[v][c] == -1){
            trieqr[cntqr] = node_at();
            trieqr[cntqr].p = v;
            trieqr[cntqr].pch = c;
            trieqr[v][c] = cntqr;
            ++cntqr;
        }
        v = trieqr[v][c];
    }
    return v;
}

int go(int v, int c);
 
int get_link(int v){
    if (trieqr[v].link == -1){
        if (v == 0 || trieqr[v].p == 0)
            trieqr[v].link = 0;
        else
            trieqr[v].link = go(get_link(trieqr[v].p), trieqr[v].pch);
    }
    return trieqr[v].link;
}
 
int go(int v, int c) {
    if (trieqr[v].go[c] == -1){
        if (trieqr[v][c] != -1)
            trieqr[v].go[c] = trieqr[v][c];
        else
            trieqr[v].go[c] = (v == 0 ? 0 : go(get_link(v), c));
    }
    return trieqr[v].go[c];
}

int add_letter(int v, int c){
    if (trienm[v][c] == -1){
        trienm[cntnm] = node();
        trienm[v][c] = cntnm;
        ++cntnm;
    }
    return trienm[v][c];
}

vector<int> g[N];
int tin[N], tout[N], T;

void dfs_init(int v){
    tin[v] = T++;
    for (auto u : g[v])
        dfs_init(u);
    tout[v] = T;
}

int f[N];

void upd(int v, int val){
    for (int i = tin[v]; i < N; i |= i + 1)
        f[i] += val;
}

int get(int x){
    int sum = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        sum += f[i];
    return sum;
}

int sum(int v){
    return get(tout[v] - 1) - get(tin[v] - 1);
}

int n, m;
int nm[N], qr[N];
vector<int> nms[N];
vector<int> reqs[N];
int ans[N];

void dfs(int v, int cur){
    upd(cur, 1);
    for (auto it : nms[v])
        for (auto q : reqs[it])
            ans[q] = sum(qr[q]);
    forn(i, AL) if (trienm[v][i] != -1)
        dfs(trienm[v][i], go(cur, i));
    upd(cur, -1);
}

int main(){
	// 根节点是0,好像这是query中的所有的string建的自动机
    cntqr = 0;
    trieqr[cntqr++] = node_at();
    
    // 输入串的字典树
    cntnm = 0;
    trienm[cntnm++] = node();
    
    char buf[N];
    scanf("%d", &n);
    forn(i, n){
        int t;
        scanf("%d", &t);
        if (t == 1){
            scanf("%s", buf);
            // 构建字典树
            nm[i] = add_letter(0, buf[0] - 'a');
        }
        else{
            int j;
            scanf("%d%s", &j, buf);
            --j;
            // 在j后面加字母
            nm[i] = add_letter(nm[j], buf[0] - 'a');
        }
        // 把各个节点对应的题目中的值记录下来
        nms[nm[i]].push_back(i);
    }
    
    scanf("%d", &m);
    forn(i, m){
        int j;
        scanf("%d%s", &j, buf);
        --j;
        // 记录这个节点对应哪一次询问
        reqs[j].push_back(i);
        // 给模式串构建字典树
        qr[i] = add_string(buf);
    }
    
    // 询问串中的节点个数cntqr
    for (int v = 1; v < cntqr; ++v)
        g[get_link(v)].push_back(v);
    
    T = 0;
    dfs_init(0);
    dfs(0, 0);
    
    forn(i, m)
        printf("%d\n", ans[i]);
}