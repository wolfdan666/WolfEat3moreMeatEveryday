// 2019年5月7日20:30:22 开始看题，有番茄钟，还剩20mins
// 完蛋,没什么思路,先想想最暴力的吧,就是先暴力枚举然后直接维护max,不过想想就知道不现实..
// 用优先排序，先最早到时限的，然后最快能做完的优先排序，然后再一次性求解？那example 1直接过不了
// 直接看大佬怎么写吧，2019年5月7日20:46:15
// 没想最终还是暴力枚举法，不过举得很有艺术，2019年5月7日21:28:23 感觉有点慢和凉，加油

/*
利用二进制位的方法来解题用过不少次，但真正意义上的状态压缩dp，这是第一道，有纪念意义，当然，一开始也没想出来，看了前人思路才恍然大悟。
先大致说说状态压缩，假设有三门作业a，b，c
那么，abc都做完即111，111可由101，110，011任意一个来得到。而101可以从100或者001来得到，这就是状态压缩dp的一个基本的状态转移。
之前自己一直奇怪二进制10串怎么能跟全排列扯上关系，相通上面那么思路，当然就迎刃而解。
---------------------
作者：shiyicode
原文：https://blog.csdn.net/to_be_better/article/details/50563344

果然又是这位仁兄
*/


#include<bits/stdc++.h>
using namespace std;

const int N = 16;
struct Node{
    char str[109];
    int want, need;
} node[N];

struct DP{
    int now, sum, next, pos;
}dp[1<<N]; // 2的N次方种排列

void put_ans(int x){
    if(dp[x].next != -1){
        put_ans(dp[x].next);
        printf("%s\n", node[dp[x].pos].str);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%s%d%d", node[i].str, &node[i].want, &node[i].need);
        dp[0].now = dp[0].sum = 0;
        dp[0].next = dp[0].pos = -1;
        int m = (1<<n)-1;
        for(int i=1; i<=m; i++){
            dp[i].sum = 0x3f3f3f3f;
            for(int j=0; j<n; j++){
                if((1<<j) & i){
                    int k = i - (1<<j);
                    int v = dp[k].now + node[j].need - node[j].want;
                    v = max(v, 0);
                    if(dp[i].sum >= dp[k].sum+v){
                        dp[i].sum = dp[k].sum + v;
                        dp[i].now = dp[k].now + node[j].need; // 这里保证了v为负值也是可以挽回来的
                        dp[i].next = k;   // 这里是回溯的next,本质上是前一个
                        dp[i].pos = j;
                    }
                }
            }
        }
        printf("%d\n", dp[m].sum);
        put_ans(m);
    }
    return 0;
}
