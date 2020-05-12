/*
bfs最简单搜索
2020年5月11日22:46:26 开始写

2020年5月11日23:03:15 卡
#include <queue>
using namespace std;
这两句一小会...

2020年5月11日23:07:29
行列搞反就用int calc(struct weiqi *wq, int y, int x)解决

2020年5月11日23:08:04 MLE！？ 忘了pop...傻逼了
还忘了vis[][]

看来自己好久没写算法变傻了

2020年5月11日23:20:30
内存超限:您的程序使用了超过限制的内存
case通过率为68.75%
准备洗洗睡吧，明天再搞，今天没能量了...
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

enum color {
    NONE, WHITE, BLACK,         //棋子颜色，NONE表示未落子
};
struct weiqi {
    enum color board[19][19];   //棋盘上每个位置的落子
};

// int calc(struct weiqi *wq, int x, int y)
int calc(struct weiqi *wq, int y, int x)
{
    //TODO:
    int ans = 0;
    if(wq->board[x][y] == NONE) return ans;

    queue<pair<int,int>> q;
    int a[4] = {1,-1,0,0};
    int b[4] = {0,0,1,-1};
    bool vis[19][19];
    memset(vis,0,sizeof vis);

    q.push({x,y});
    enum color curC = wq->board[x][y];
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        vis[cur.first][cur.second] = true;
        ans++;
        for(int i=0;i<4;i++){
            if( !vis[cur.first+a[i]][cur.second+b[i]] &&
                (cur.second+b[i] >= 0 && cur.second+b[i] <19) &&
                (cur.first+a[i] >= 0 && cur.first+a[i] <19) &&
                curC == wq->board[cur.first+a[i]][cur.second+b[i]]){
                q.push({cur.first+a[i],cur.second+b[i]});
            }
        }
    }

    return ans;
}

int input(struct weiqi *wq, int *x, int *y)
{
    int row, col;
    int ret;
    char buf[80];

    for (row = 0; row < 19; ++row) {
        if (fgets(buf, sizeof(buf), stdin) == NULL)
            return -1;
        if (strlen(buf) < 19)
            return -1;
        for (col = 0; col < 19; ++col) {
            switch (buf[col]) {
            case '0':
                wq->board[row][col] = NONE;
                break;
            case '1':
                wq->board[row][col] = WHITE;
                break;
            case '2':
                wq->board[row][col] = BLACK;
                break;
            default:
                return -1;
            }
        }
    }
    ret = fscanf(stdin, "%d,%d\n", x, y);
    if (ret != 2)
        return -1;
    // 定向到error是为了测试用吧
    for (row = 0 ; row < 19; ++row) {
        for (col = 0; col < 19; ++col) {
            fprintf(stderr, "%d ", wq->board[row][col]);
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "x = %d, y = %d\n", *x, *y);
    return 0;
}

int main()
{
    struct weiqi wq;
    int x = 0, y = 0;
    int cnt;

    memset(&wq, 0, sizeof(wq));
    if (input(&wq, &x, &y) < 0) {
        fprintf(stderr, "error!\n");
        return 1;
    }
    cnt = calc(&wq, x, y);

    printf("%d\n", cnt);
    return 0;
}