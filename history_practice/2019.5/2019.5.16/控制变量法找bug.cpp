// 2019年5月16日20:23:15 看题
// 决定再次直接看题解
// 2019年5月16日20:42:33 发现这是kuangbin kmp+回文+ekmp的字符串题里面最难的一题，所以先手撸一次大佬的代码，第一次是cv的
// 并做些许改进
// 感觉电脑放在散热架上面，自己打字好累好累，所以纯写code,写文章,开比较少的应用的时候就把散热架给去掉
// 去掉之后突然打字变爽了好多，但是有一点点的不太适应... 而且电脑真的是哗哗哗地巨响...
// 2019年5月16日21:30:33 ,中途浪了30mins，但是还是无法解释你为什么这么慢，现在才写到getNext(),所以现在争取一个番茄钟必须写完，明天再写一遍

// 2019年5月16日22:43:17 自己检查了3遍，结果莫名奇妙就是不对...看来这题要9阴真经，5毒肯定搞不定
// 2019年5月16日23:47:13 真的窒息了，我晚上又检查了好久，但是还是错了，用vscode Debug看看吧
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
// typedef long long ll;
typedef long long LL;
const int MAXN = 2e6+5;
const int KIND = 26;

struct TrieNode{
    int num;   // 到当前节点的个数
    int cnt;   // 到当前节点的回文字串的个数
    TrieNode* nxt[26];
};

TrieNode node[MAXN]; // 避免动态申请时间消耗  空间换时间
TrieNode * root;
int bg[MAXN];   // 每个节点的开始位置
int ed[MAXN];   // 每个节点的结束位置
bool flag[2][MAXN]; // f[0][i]为true表示原串后面为回文串，flag[1][i] 表示反串
char S[MAXN];  // 存放原串
char T[MAXN];  // 存放反串
int nxt[MAXN]; // 存放next数组
int extend[MAXN]; // 用于判断是否为回文串
LL ans;
int tot;  // node数组的下标

void GetNext(char* T,int l,int r){
    int j = 0;
    while(l + j + 1<= r&& T[l+j]==T[l+j+1]) ++j;
    nxt[l+1] = j;
    int k = l + 1;
    for(int i = l+2;i<=r;++i){
        int p = nxt[k] + k -1;
        int L = nxt[l + i -k];
        if(L+i<p+1) nxt[i] = L;
        else{
            j = max(0,p-i+1);
            while(i+j<=r&&T[l+j]==T[i+j]) ++j;
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
void Insert(char S[], int l, int r){
    TrieNode* temp = root;
    for(int i = l; i <= r; i++){
        int ch = S[i] - 'a';

        temp->cnt += flag[0][i];  //2类 更新当前节点   "后面"    回文串的数目   不太理解的1或者重点2就先单行搞着

        if(temp->nxt[ch] == NULL) temp->nxt[ch] = &node[tot++];
        temp = temp->nxt[ch]; // 指针用指向，实体用点  .
    }
    ++temp->num;
    // temp->num++;
}

void Search(char S[],int l,int r){
    TrieNode* temp = root;
    for(int i=l;i<=r;i++){
        int ch = S[i] - 'a';
        temp = temp->nxt[ch];
        if(temp == NULL) break;
        if((i<r&&flag[1][i+1]) || i==r){
            ans += temp->num;  // 加自己后面是回文(flag[1][i+1]) ,别人是自己的前缀的结果
        }
    }
    if(temp) ans += temp->cnt;  // 加自己是别人的前缀  而别人后面是回文的结果  (在insert的时候就处理好了)
}

// int main(int argc, char const *argv[]){
int main(){
    int n;
    // while(~scanf("%d",&n)){
    while (scanf("%d", &n) != EOF){
        tot=0;
        ans = 0;
        memset(node,0,sizeof(node));
        memset(flag,0,sizeof(flag));
        root = &node[tot++];

        int l = 0;
        int L = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&l);
            // bg[i] = L;
            // ed[i] = L+l-1;
            scanf("%s",S+L);

            //生成反串
            for(int j = 0;j<l;j++)
                T[L+j] = S[L+l-1-j];

            bg[i] = L;
            ed[i] = L+l-1;


            ExtendKMP(S,T,bg[i],ed[i],0);
            ExtendKMP(T,S,bg[i],ed[i],1);
            Insert(S,bg[i],ed[i]);

            L += l;
        }
        for(int i = 0;i<n;i++)
            Search(T,bg[i],ed[i]);

        printf("%lld\n",ans);
    }
    return 0;
}




