/**
 * 2021年01月15日20:43:44 想了一下就是遍历并递归棋子
 * 
 * 记录vis[]
 * 
 * 几次递归就有几个剩余棋子 
 * 
 * 然后因为工作之后都主要写C,所以最近几期开始用C写
 * 
 * 但是没有看懂这个默认的c的api的第三个参数 int* stonesColSize是什么鬼
 * 直接看答案吧
 * 
 * 结果发现答案直接没有用到这个参数，我也是醉了
 */


#include <stdio.h>


// 作者：liu-xiang-3
// 链接：https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/solution/cyu-yan-bing-cha-ji-ha-xi-biao-by-liu-xi-c9ri/
inline int find(int *parent, int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

/* 和普通的并查集用法有区别, 之前是x,y直接联通   */
/* 然后判断存在有多少联通集                      */
/* 本题是x与y+10001联通, 判断find(x)是否被访问过 */
/* 如果没有访问过, 联通集加1                     */
    
int removeStones(int** stones, int stonesSize, int* stonesColSize){
    int *parent = (int*)malloc(sizeof(int) * 20002);
    int *hash   = (int*)malloc(sizeof(int) * 20002);
    int i, root1, root2;
    int cnt = 0;
    /* 并查集,hash表初始化 */
    for (i = 0; i < 20002; i++) {
        parent[i] = i;
        hash[i]   = -1;
    }

    /* 行或列相同, 就属于联通分量; 先将x,y区分 */
    for (i = 0; i < stonesSize; i++) {
        root1 = find(parent, stones[i][0]);
        root2 = find(parent, stones[i][1] + 10001);
        if (root1 != root2) {
            parent[root1] = root2;
        }
    }
    /* 寻找行的root节点, 如果没有被联通过, cnt++ */
    for (i = 0; i < stonesSize; i++) {
        root1 = find(parent, stones[i][0]);
        if (hash[root1] == -1) {
            cnt++;
            hash[root1] = root1;
        }
    }
    free(parent);
    free(hash);
    return stonesSize - cnt;
}
int main(){
    
    
    return 0;
}