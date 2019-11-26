/*
棋盘
2019年11月13日21:56:49 直接看别人的分析

Author: zhaoyichen
问题分析
棋盘很小(8*8)，且玩家只能在合法的位置落子，因此推测游戏的状态数可能不多，
于是尝试直接dfs枚举所有可能的情况。

代码实现
为了方便使用了全局变量，不过并不推荐这么做……

代码里出现的函数：

- find：从当前位置和方向出发，查找第一个颜色等于clr的棋子
- set：从当前位置和方向出发，把前cnt个棋子的颜色置为clr

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,n;
int ans;

// find一个方向上的夹了多少个异色棋子
int find(int board[][8], int i, int j, int di, int dj, int clr, int rev) {
    i += di;
    j += dj;
    int cnt = 1;
    while(0 <= i && i < 8 && 0 <= j && j < 8) {
        // 同色返回cnt
        if(board[i][j] == clr) {
            return cnt;
        }
        // 不是异色不是同色,则为未落子返回0
        else if(board[i][j] != rev) {
            return 0;
        }
        i += di;
        j += dj;
        cnt++;
    }
    return 0;
}
void set(int board[][8], int i, int j, int di, int dj, int cnt, int clr) {
    for(int x = 0; x < cnt; x++) {
        board[i][j] = clr;
        i += di;
        j += dj;
    }
}
void dfs(int cnt_step, int board[][8]) {
    if(cnt_step == n) {
        int cur = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == 2) {
                    cur++;
                }
            }
        }
        ans = max(ans, cur);
    }
    else {
        // 注意id从0到2N-2(共2N-1次),所以n(2N-1减一时不进入else)
        // cnt_step为偶数的时候,就是白子先下,所以白子的同色值为2-0=2,黑子则为3-2=1
        // cnt_step为奇数就是黑子下，同色为2-1=1，白子异色为3-1=2
        int clr = 2 - (cnt_step % 2);
        int rev = 3 - clr;
        int nxt_board[8][8];
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == 0) {
                    bool flag = false;
                    for(int di = -1; di <= 1; di++) {
                        for(int dj = -1; dj <= 1; dj++) {
                            if(di == 0 && dj == 0) {
                                continue;
                            }
                            int cnt = find(board, i, j, di, dj, clr, rev);
                            if(cnt > 1) {
                                if(!flag) {
                                    memcpy(nxt_board, board, sizeof(int) * 64);
                                    flag = true;
                                }
                                set(nxt_board, i, j, di, dj, cnt, clr);
                            }
                        }
                    }
                    // 已经下过了一个棋子,则可以进入下一个状态的dfs
                    if(flag) {
                        dfs(cnt_step + 1, nxt_board);
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    // 总共两者要走2n-1次
    n = 2 * N - 1;
    int board[8][8];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    ans = 0;
    dfs(0, board);
    printf("%d\n", ans);

    return 0;
}

/*
1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 1 2 0 0 0
0 0 0 2 1 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

ans = 4
*/