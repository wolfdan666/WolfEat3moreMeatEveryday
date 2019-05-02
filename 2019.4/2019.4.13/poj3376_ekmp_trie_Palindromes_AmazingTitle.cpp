// 2019年4月13日09:56:04开始看题
// 思路很简单，就是直接模拟，然后看Manacher返回的最长回文字串长是不是总串长2019年4月13日10:06:52 开始写
// 2019年4月13日10:36:43 写完了，可是莫名其妙不能输入全部数据...没找出bug，先看大佬的  发现大佬们又是用的ekmp
// 然后发现自己智障用什么Manacher，全串的话不如直接翻转，然后直接比较==== or 直接前后比较
// 还是不能输入全部数据，改一下scanf输入试试(开启输入同步)
// 2019年4月13日12:13:43debug完，发现poj不让用bits/stdc++.h，改头文件再交
// 嗯，果然，这样暴力的，不出意外地tle了，还是要用ekmp,2019年4月13日12:17:02(2个小时20mins 还没写完今天第一题，GG)
// 2019年4月13日16:07:53 再来搞此题，看大佬怎么写吧，4点30pm尽量搞完 有难度，再加点时间...

// 2019年4月13日17:19:18 经历各种看不懂的绝望后，在此刻先把Insert那里看懂了
// 一题更比6题自闭，我佛了，间断发呆好久，加油啊！2019年4月13日17:41:42
// 2019年4月13日17:59:30 总算能看懂search，先去吃饭，回来go on 看懂最奇怪的反串的getNext

// 2019年4月13日19:45:13 终于粗略地理解了整体，暑假的时候每周都要整理一下此题
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define x first
#define y second

vector<pair<int,string> > p;
// vector<int> r;

// int Init(string s,string &t){// 其实自己没有记住，参照2019.4.11号的Manacher学习的板子写的，比赛的时候把所有学习的TXT打印
//     int len = int(s.length());
//     t.resize(2*(len+1),'#');
//     t[0]='#';
//     int j=2;
//     for(int i=0;i<len;i++){
//         t[j]=s[i]; j+=2;
//     }
//     t[j]='\0';
//     cout<<2*(len+1)<<"&"<<j<<endl;
//     return j;
// }

// int Manacher(string s){
//     string t;
//     int len = Init(s,t);
//     int max_len = -1;
//     int id=0,mx=0;
//     for(int i=1;i<len;i++){
//         if(i<mx) r[i] = min(r[2*id-i],mx-i);
//         else r[i]=1;
//         while(t[i-r[i]]==t[i+r[i]]) {
//             r[i++];
//         }
//         if(mx<i+r[i]){
//             id=i;
//             mx=i+r[i];
//         }
//         max_len = max(max_len,r[i]-1);
//     }
//     return max_len;
// }

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int tem;string ts;
    for(int i=0;i<n;i++){
        cin>>tem>>ts;
        p.push_back({tem,ts});
        // cout<<"what's wrong!?"<<p[i].x<<p[i].y<<endl;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string s = p[i].y + p[j].y;
            int len = p[i].x+p[j].x;
            // if(Manacher(s)==p[i].x+p[j].x) ans++;
            bool f=1;
            for(int i=0;i<=len/2;i++){
                if(s[i]!=s[len-1-i]) f=0;
            }
            if(f) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/

/*
大佬思路:https://www.cnblogs.com/ykzou/p/4487740.html
题意：给你n个字符串m1、m2、m3...mn 求S = mimj（1=<i,j<=n）是回文串的数量

思路：我们考虑第i个字符串和第j个字符串能构成组合回文串要满足的条件：

1、i的长度小于j，那么i一定是j的反串的前缀，且j的反串剩下的后缀是回文串

2、i的长度等于j，那么i等于j的反串

3、i的长度大于j，那么j的反串一定是i的前缀，且i串剩下的后缀是回文串

我们可以将这n个字符串插入trie，每个节点要维护两个值：value1. 到当前节点的字符串个数；value2. 当前节点后面的回文子串个数

我们用每个字符串的反串去trie上查找，要构成回文串有以下情况：

1、 此反串是其他串的前缀，那么组合回文串的数量就要加上value2(可能是多分枝)   对应上面的3.

2、此反串的前缀是某些字符串，且反串剩下的后缀是回文串，那么组合回文串的数量要加上value1 (前缀树在相应节点的那个字符串的个数)   对应上面的1.

3、2的特例：此反串的前缀是某些字符串，且反串剩下的后缀为空，同样要加上value1，这种情况可以和2一起处理

关键：

1、判断字符串的哪些后缀是回文串（用于更新value2），以及对应反串的哪些后缀是回文串（当面临第二种情况时，可直接判断后缀否为回文串）

2、如何更新value1和value2（借助1的结果）
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 2000005;
const int KIND = 26;

struct TrieNode
{
    int num;    // 到当前节点的字符串个数
    int cnt;    // 当前节点后面回文子串个数
    TrieNode* nxt[26];
};

TrieNode node[MAXN];      // 避免动态申请空间的时间消耗
TrieNode* root;           // trie树的根节点
int bg[MAXN];             // bg[i]第i+1个字符串开始的位置
int ed[MAXN];             // ed[i]第i+1个字符串结束的位置
bool flag[2][MAXN];       // flag[0][i]为true表示原串后面为回文串   flag[1][i]表示反串
char S[MAXN];             // 存放原串
char T[MAXN];             // 存放反串
int nxt[MAXN];            // 存放next数组
int extend[MAXN];         // 用于判断是否为回文子串
LL ans;                   // 保存结果
int tot;                  // node数组的下标

void GetNext(char* T, int lhs, int rhs)
{
    int j = 0;
    while (lhs + j + 1 <= rhs && T[lhs + j] == T[lhs + j + 1]) ++j;
    nxt[lhs + 1] = j;   // 和常规的next数组的生成方式不一样   这是和enext,感觉和extend[]生成方式一样
    int k = lhs + 1;
    for (int i = lhs + 2; i <= rhs; ++i)
    {
        int p = nxt[k] + k - 1;  // 右边
        int L = nxt[lhs + i - k];  // L为原始的nxt长度，L+i表示左边   >> 理解这里了以后  就可以很好的理解  后面的循环了
    // 注意此nxt生成和extend(ekmp)生成类似(匹配值的大数字在左边)，普通nxt和kmp生成类似(有失配的物理意义，很好理解)(匹配值的大数字在右边)
// 现在才发现ekmp中的getNext与 kmp中的getFail不同 都怪自己前几天都没有好好学习ekmp
        if (L + i < p + 1) nxt[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j <= rhs && T[lhs + j] == T[i + j]) ++j;
            nxt[i] = j;
            k = i;
        }
    }
}

void ExtendKMP(char* S, char* T, int lhs, int rhs, bool sign)
{
    GetNext(T, lhs, rhs);
    int j = 0;
    while (j + lhs <= rhs && S[j + lhs] == T[j + lhs]) ++j;
    extend[lhs] = j;
    int k = lhs;
    for (int i = lhs + 1; i <= rhs; ++i)
    {
        int p = extend[k] + k - 1;
        int L = nxt[lhs + i - k];
        if (L + i < p + 1) extend[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j <= rhs && S[i + j] == T[lhs + j]) ++j;
            extend[i] = j;
            k = i;
        }
    }
    for (int i = lhs; i <= rhs; ++i)
    {
        if (extend[i] == rhs - i + 1)
            flag[sign][i] = true;
    }
}

void Insert(char S[], int lhs, int rhs)
{
    TrieNode* temp = root;
    for (int i = lhs; i <= rhs; ++i)
    {
        int ch = S[i] - 'a';
        temp->cnt += flag[0][i];    // 更新当前节点后面回文子串的数目
        if (temp->nxt[ch] == NULL) temp->nxt[ch] = &node[tot++];
        temp = temp->nxt[ch];
    }
    ++temp->num; // 更新到当前节点的字符串数目   // 这是这个节点专属的num,也就是相同字符串
}

void Search(char S[], int lhs, int rhs)
{
    TrieNode* temp = root;
    for (int i = lhs; i <= rhs; ++i)
    {
        int ch = S[i] - 'a';
        temp = temp->nxt[ch];
        if (temp == NULL) break;// 不匹配而退出
        if ((i < rhs && flag[1][i + 1]) || i == rhs) //i == rhs此反串的前缀是某些字符串，且反串剩下的后缀为空，同样要加上value1，这种情况可以和2一起处理
            ans += temp->num;        //2处理此反串的前缀是某些字符串，且反串剩下的后缀是回文串，那么组合回文串的数量要加上value1,这个要不断演进加
    }
    if (temp) ans += temp->cnt;//此反串是其他串的前缀，那么组合回文串的数量就要加上value2
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // 初始化
        tot = 0;
        ans = 0;
        memset(node, 0, sizeof(node));
        memset(flag, 0, sizeof(flag));
        root = &node[tot++];

        int l = 0;
        int L = 0;
        for (int i = 0; i < n; ++i)
        {
            // 输入一组数据
            scanf("%d", &l);
            scanf("%s", S + L);

            // 生成反串
            for (int j = 0; j < l; ++j)
                T[L + j] = S[L + l - 1 - j];

            bg[i] = L;
            ed[i] = L + l - 1;


            ExtendKMP(S, T , bg[i], ed[i], 0);// 判断原串S的后缀是否是回文串(和前面定义一致了)，因ekmp的extend[]是S中前多少个和T[]前多少个匹配
            ExtendKMP(T, S , bg[i], ed[i], 1);// 同理，判断T的后缀是否是回文串
            Insert(S, bg[i], ed[i]);

            L += l;
        }

        for (int i = 0; i < n; ++i)
            Search(T, bg[i], ed[i]);

        printf("%lld\n", ans);
    }
    return 0;
}