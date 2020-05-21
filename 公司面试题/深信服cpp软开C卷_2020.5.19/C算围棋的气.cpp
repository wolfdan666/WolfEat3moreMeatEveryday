/*
2020年5月19日22:06:06 开始看题

2020年5月20日13:48:36 随便写了一下AC了
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[4] = {1,-1,0,0};
int b[4] = {0,0,1,-1};
bool vis[19][19];


enum color {
    NONE, WHITE, BLACK,         //棋子颜色，NONE表示未落子
};
struct weiqi {
    enum color board[19][19];   //棋盘上每个位置的落子
};

void dfs(struct weiqi *wq,int x,int y,enum color f,int &ans){
    if( !(x>=0 && x<19 && y>=0 && y<19) ) return;
    if(vis[x][y]) return;

    vis[x][y] = true;
    if(wq->board[x][y] == f) {
        for(int i=0;i<4;i++){
           dfs(wq,x+a[i],y+b[i],f,ans);
        }
    }
    else if(wq->board[x][y] == NONE){
        ans++;
        for(int i=0;i<4;i++){
           dfs(wq,x+a[i],y+b[i],f,ans);
        }
    }
    else return;

    // cout<< " ( " << x << " , " << y << " ) " <<endl;
    // for(int i=0;i<4;i++){
    //     dfs(wq,x+a[i],y+b[i],f,ans);
    // }
}

int calc(struct weiqi *wq, int x, int y)
{
    //TODO:
    swap(x,y);
    int ans = 0;
    enum color curC = wq->board[x][y];
    if(curC == NONE) return -1;


    memset(vis,0,sizeof vis);

    dfs(wq,x,y,curC,ans);

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