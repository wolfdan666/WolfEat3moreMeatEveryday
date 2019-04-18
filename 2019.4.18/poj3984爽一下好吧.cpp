#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class queue
{
public:
    int x, y, pre;
}q[10000];

int map[5][5];
int visit[5][5];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void output(int front)
{
    if (q[front].pre != -1)
    {
        output(q[front].pre);  //递归到第一层，逐层输出
        printf("(%d, %d)\n", q[front].x, q[front].y);
    }
}

void bfs()
{
    int front, rear;
    q[front = rear = 0].x = 0;
    q[front].y = 0;
    q[rear++].pre = -1;
    visit[0][0] = true;

    while (front < rear)
    {
        for (int i = 0; i < 4; i++)
        {
            int x = q[front].x + dx[i];
            int y = q[front].y + dy[i];
            if (map[x][y] == 0 && !visit[x][y] && x >= 0 && x < 5 && y >= 0 && y < 5 )
            {
                visit[x][y] = true;
                q[rear].x = x;
                q[rear].y = y;
                q[rear++].pre = front;
            }
            if (x == 4 && y == 4) output(front);
        }
        front++;
    }
}

int main()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];

    printf("(0, 0)\n");
    bfs();
    printf("(4, 4)\n");
    return 0;
}