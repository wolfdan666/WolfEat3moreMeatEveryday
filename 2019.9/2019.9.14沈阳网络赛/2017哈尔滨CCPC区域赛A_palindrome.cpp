/*
2019年9月14日10:40:30 开始看题
2019年9月14日10:53:57 找到了O(n)判断字串是否为题中所说回文的方法，然后找到暴力解法O(n^2),要想办法怎么重复利用判断结果...
2019年9月14日11:00:04 看大佬怎么想吧


大佬jiachin_zhao:
很明显这里的回文串长度为奇数，所以用manacher处理时不需要添加间隔字符
所以这里的Len[i]表示的就是以i为中心的回文串向左右最远能延伸的长度

那么S[i]=S[2n−i]=S[2n+i−2](1≤i≤n)就等价于
找到一对(i,j),满足i−Len[i]+1<=j<i且j+Len[j]−1>=i
可以用主席树来维护，更简单的方法就是
将j+Len[j]−1按升序排列,然后对于j丢到树状数组里查询贡献就好了。
*/



#include<bits/stdc++.h>
#define P pair<int,int>
#define LL long long
using namespace std;

const int maxn = 5e5 + 10;
const int N = 1e6 + 10;
char s[N];
int Len[N];
int lowbit(int x){return x & (-x);}
int tr[N],R;
int getsum(int pos){
    int ans = 0;
    for(;pos;pos -= lowbit(pos)) ans += tr[pos];
    return ans;
}
void up(int pos){
    for(;pos <= R;pos += lowbit(pos)) tr[pos]++;
}
void Manacher(char *s){
    int len = strlen(s + 1);
    s[0] = '#';
    int mx = 0,center = 0;
    ///mx为当前计算回文串最右边字符的最大值
    ///center为取得mx最大值的中心
    for(int i = 1;i <= len;i++){
        if(mx > i) Len[i] = min(mx - i, Len[2 * center - i]);///考虑i关于center的对称的Len
        else Len[i] = 1;
        while(s[i - Len[i]] == s[i + Len[i]]) Len[i]++;
        if(Len[i] + i > mx) mx = Len[i] + i, center = i; ///更新最右
    }
}
struct node{
    int x,l;
    node(int x,int l):x(x),l(l){};
    node(){};
    bool operator<(const node &rhs)const{
        return l > rhs.l;
    }
}q[N];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
       scanf("%s",s + 1);
       Manacher(s);
       int len = strlen(s + 1);
       R = len;
       for(int i = 1;i <= R;i++) tr[i] = 0;
       for(int i = 1;i <= len;i++) q[i] = node(i, i + Len[i] - 1);
       sort(q + 1, q + len + 1);
       int l = 1;
       LL ans = 0;
       for(int i = len;i >= 1;i--){
            while(l <= len && q[l].l >= i) up(q[l++].x);
            ans += getsum(i - 1) - getsum(i - Len[i]);
       }
       printf("%lld\n",ans);
    }
    return 0;
}