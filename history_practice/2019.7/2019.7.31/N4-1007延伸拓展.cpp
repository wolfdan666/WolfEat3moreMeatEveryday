/*
先用结论判断是否有解呀！不然没解跑这个会死循环，燃烧你的CPU的话我不背锅哦
 */

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//limit全部的曼哈顿距离之和
int map[4][4], map2[16], limit;
int flag, length;
//各个数字应在位置(i,j)对照表,比如0在位置(3,3)
int goal[16][2] = {{3,3},{0,0},{0,1},{0,2},
                   {0,3},{1,0},{1,1},{1,2},
                   {1,3},{2,0},{2,1},{2,2},
                   {2,3},{3,0},{3,1},{3,2}};

int nx[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };


//估价函数,曼哈顿距离,小于等于实际总步数
int hv(int a[][4]){
    int cost = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int w = map[i][j];
            // 不算0
            if (w != 0)
                cost += abs(i - goal[w][0]) + abs(j - goal[w][1]);
        }
    }
    return cost;
}

/* x,y起始坐标，len是已经走过的长度,pre_move是上次走的方向 */
void dfs(int x, int y, int len, int pre_move){
    if (flag) return;
    int dv = hv(map);
    if (len == limit) {
        //成功 退出
        if (dv == 0){
            flag = 1;
            length = len;
            return;
        } else
            //超过预设长度 回退
            return;
    }

    for (int i = 0; i < 4; i++) {
        //不和上一次移动方向相反,对第二步以后而言
        if (i + pre_move == 3 && len > 0) continue;
        int tx = x + nx[i][0];
        int ty = y + nx[i][1];
        if (tx >= 0 && tx < 4 && ty >= 0 && ty < 4) {
            swap(map[x][y], map[tx][ty]);
            int p = hv(map);
            if (p + len <= limit && flag == 0) {
                dfs(tx, ty, len + 1, i);
                if (flag)
                    return;
            }
            /* 递归回来后恢复现场 */
            swap(map[x][y], map[tx][ty]);
        }
    }
}

int main(){
    int t; cin>>t;
    while (t--) {
        int x1, y1;
        //map2一维 map二维
        for (int i = 0; i < 16; i++){
            scanf("%d", &map2[i]);
            if (map2[i] == 0) {
                x1 = i/4; y1 = i%4;
                map[x1][y1] = 0;
            } else {
                map[i/4][i%4] = map2[i];
            }
        }

        /* 曼哈顿长度要递减的 */
        limit = hv(map);
        flag = 0;
        length = 0;
        //要求120步之内到达,其实如果可以的话最多80多步就可以走完
        while (flag == 0 && length <= 90){
            //得到的是最小步数
            dfs(x1, y1, 0, 0);
            /* 加大初始额曼哈顿距离的限制，让递归的行走能不曼哈顿距离递减得多试探几步 */
            if (flag == 0) limit++;
        }
        // if (flag)
        //     printf("%d\n", length);
        if(flag) cout<<"Yse"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}