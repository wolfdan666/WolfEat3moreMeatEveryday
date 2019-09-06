/*
2019年9月6日20:11:53 开始看题

2019年9月6日20:13:06 题意:
给你一个串,求出出现次数最多的长度为i(属于[1,|S|])的字串,输出它的出现次数

分解任务,先想清楚怎么求出一个字串的出现次数,
应该就是从叶子节点用fa回跳计算cnt[长度],然后不同回跳之间用max维护,
最终输出的时候一定是所有长度[1->|S|之间]都是必定出现过的,所以直接输出就行

叶子节点是转移到无法转移就是叶子节点吗？
2019年9月6日20:27:32 看大佬怎么写

大佬：ww140142
几天没更新，水一发后缀自动机的题解吧；

首先定义后缀自动机的的right集合大小，就是该结点代表的状态能拓展到的子串种类；

那么对于长度为x的子串的答案就是所有长度>=x的结点的right值的最大值；

right值是不能再构建自动机时增量维护的，所以只能在构建这个后缀自动机之后再O(n)搞一遍；

具体就是从反向后缀树的叶子开始，定义每个关键节点的right初始都为1，然后顺着求出所有节点的子树和就可以了；

然后再用right[x]更新f[len[x]]，扫一遍让f[i]=max(f[i],f[i+1])；

时间复杂度O(n)；

然而后缀自动机的构建依然是基本靠背的代码。。

而且大概后缀自动机顺便建出来的反向后缀树比那个识别后缀的本体要有用得多。。真是233
————————————————
原文链接：https://blog.csdn.net/ww140142/article/details/49914211

英雄所见略同

最终有点懵逼，然后又思索到了2019年9月6日21:39:13 才看懂了
[MashiroSky](https://www.cnblogs.com/MashiroSky/p/6287433.html)大佬的博文...
原来之前ccpc1003用的拓扑排序就是基数排序，怪不得当时这么熟悉但是又没有想起来

*/


#include<bits/stdc++.h>
using namespace std;
const int N=250010;
char s[N];
int r[N<<1],id[N<<1],b[N],F[N];
struct sam{
    // 注意N是题目给的n的两倍,因为节点数最多有2*n-1个
    int p,q,np,nq,cnt,last,a[N<<1][26],l[N<<1],f[N<<1];
    sam(){cnt=0;last=++cnt;}
    void init(){
        cnt=0;last=++cnt;
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        memset(f,0,sizeof(f));
    }
    void extend(int c){
        p=last;np=last=++cnt;l[np]=l[p]+1;
        while(!a[p][c]&&p)a[p][c]=np,p=f[p];
        if(!p)f[np]=1;
        else{
            q=a[p][c];
            if(l[p]+1==l[q])f[np]=q;
                else{
                    nq=++cnt;l[nq]=l[p]+1;
                    memcpy(a[nq],a[q],sizeof(a[q]));
                    f[nq]=f[q]; f[np]=f[q]=nq;
                    while(a[p][c]==q)a[p][c]=nq,p=f[p];
                }
        }
    }
    void solve(){
        init();
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<n;i++)extend(s[i]-'a');

        // 给主链的right值先+1.因为他们都是叶子节点(从构造算法就可以看出来,虽然这个性质我做了这个题才知道)
        // 源点就是1号节点
        for(int p=1,i=0;i<n;i++) p=a[p][s[i]-'a'],r[p]++;
        // 按照len[x]从小到大基数排序，相当于对SAM图进行拓扑排序(源点也是加入排序的)
        // 第一for先按照长度计数，然后第二for再对长度赋予排名，最后第三for让节点长度排名对应于节点
        // 同长度下，先出现的节点排名大(数值小)-->这个没有多大关系,因为同长度的必定不在同一条拓扑链上
        // 因为从源点出发的每一条链的长度都是递增的
        for(int i=1;i<=cnt;i++) b[l[i]]++;
        // 下面的for的i表示的是长度
        for(int i=1;i<=n;i++) b[i]+=b[i-1];
        for(int i=1;i<=cnt;i++) id[b[l[i]]--]=i;
        // 从后往前for,自底向上更新parent的right大小
        for(int i=cnt;i>=1;i--) r[f[id[i]]]+=r[id[i]];

        // 更新答案
        // 每个节点的endpos集合就是它自己代表的子串在串中出现的次数
        // 然后以这个子串为后缀的更长的串出现的位置通过拓扑排序累加上来了,
        // 存到了r[i]中表示这个节点代表的子串在整个串中所有出现的位置！<==>出现次数
        // 所以r[i]和F[len[i]]用max维护就行了
        for (int i=1;i<=cnt;i++) F[l[i]]=max(F[l[i]],r[i]);
        // 因为长度较短的串的F[i]值有可能是比F[i+1]小的，这样的话最优策略是取i+1长的串的后i长
        // 所以f[i] = max(F[i],F[i+1])
        for (int i=n;i>=1;i--) F[i]=max(F[i],F[i+1]);

        for (int i=1;i<=n;i++) printf("%d\n",F[i]);
    }
} sam;
int T;
int main(){
    sam.solve();
    return 0;
}