// 作者：卖报人
// 链接：https://www.nowcoder.com/discuss/389640?type=post&order=time&pos=&page=1
// 来源：牛客网
/*
作者：卖报人
链接：https://www.nowcoder.com/discuss/389640?type=post&order=time&pos=&page=1
来源：牛客网

第二题：一个地图n*m，包含1个起点，1个终点，其他点包括可达点和不可达点。
每一次可以：上下左右移动，或使用1点能量从（i,j)移动到（n-1-i, m-1-j)，最多可以使用5点能量。
考试时用了本地编译器所以记了代码，补了点注释，供讨论：

*/
/*
AC 代码
空间复杂度O(m*n*6), 时间复杂度O(m*n*6)
考试时写的比较草率，没有好好做函数化，简单加点注释供讨论
简单来说思路是类似于广度优先搜索的，但也写成了偏dp的样子……
dp[i][j][k]：对于位置i,j，用了k次飞行器时，达到这个位置最小需要的步数
用队列来进行访问：
1. 首先把起点坐标放入队列
2. 每一次访问队头元素，观察其1步可以到达的（上、下、左、右、中心对称位）的坐标：
   如果该坐标当前记录的某一种飞行器使用次数k下的值>当前值+1，则更新该值，把这一坐标加入队列
   （注意，上、下、左、右是同k值比较，中心对称位需要使用一次飞行器，所以是k+1和K比较）
3. 队列清空，更新完成
给出终点目前记录的步数，即为结果
*/

/*
可能的优化：
因为队列入队时，肯定越到后面步数需要越多，所以其实第一次访问到终点坐标就可以跳出了，
不过已经AC了就不想改了……
*/

#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

//定义坐标点
struct pos{
    int x;
    int y;
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char> > M;
    vector<char> vtmp;
    queue<pos> q1;
    pos ps, pe, ptmp;
    char ctmp;
    int dp[n][m][6];
    bool flag;
    int i,j, k;

    //先把每个位置设置一个大值
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            for(k = 0; k < 6; k++) {
                dp[i][j][k] = n*m+1;
            }
        }
    }

    //输入 && 记录起点、终点
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin>>ctmp;
            vtmp.push_back(ctmp);
            if(ctmp == 'S') {
                ps.x = i;
                ps.y = j;
                q1.push(ps);
                for(k = 0; k < 6; k++) {
                    dp[i][j][k] = 0;
                }
            }
            else if(ctmp == 'E') {
                pe.x = i;
                pe.y = j;
            }
        }
        M.push_back(vtmp);
        vtmp.clear();
    }

    //类似广度优先遍历的走完地图
    while(!q1.empty()) {
        ptmp = q1.front();

        //上下左右走，相同k更新
        if(ptmp.x > 0 && M[ptmp.x - 1][ptmp.y] != '#') {
            flag = 0;
            for(k = 0; k < 6; k++) {
                if(dp[ptmp.x-1][ptmp.y][k] > dp[ptmp.x][ptmp.y][k] + 1) {
                    dp[ptmp.x-1][ptmp.y][k] = dp[ptmp.x][ptmp.y][k] + 1;
                    flag = 1;
                }
            }
            if(flag == 1) {
                ps.x = ptmp.x-1;
                ps.y = ptmp.y;
                q1.push(ps);
            }
        }

        if(ptmp.y > 0 && M[ptmp.x][ptmp.y - 1] != '#') {
            flag = 0;
            for(k = 0; k < 6; k++) {
                if(dp[ptmp.x][ptmp.y-1][k] > dp[ptmp.x][ptmp.y][k] + 1) {
                    dp[ptmp.x][ptmp.y-1][k] = dp[ptmp.x][ptmp.y][k] + 1;
                    flag = 1;
                }
            }
            if(flag == 1) {
                ps.x = ptmp.x;
                ps.y = ptmp.y-1;
                q1.push(ps);
            }
        }

        if(ptmp.x < n-1 && M[ptmp.x + 1][ptmp.y] != '#') {
            flag = 0;
            for(k = 0; k < 6; k++) {
                if(dp[ptmp.x+1][ptmp.y][k] > dp[ptmp.x][ptmp.y][k] + 1) {
                    dp[ptmp.x+1][ptmp.y][k] = dp[ptmp.x][ptmp.y][k] + 1;
                    flag = 1;
                }
            }
            if(flag == 1) {
                ps.x = ptmp.x+1;
                ps.y = ptmp.y;
                q1.push(ps);
            }
        }

        if(ptmp.y < m-1 && M[ptmp.x][ptmp.y +1] != '#') {
            flag = 0;
            for(k = 0; k < 6; k++) {
                if(dp[ptmp.x][ptmp.y+1][k] > dp[ptmp.x][ptmp.y][k] + 1) {
                    dp[ptmp.x][ptmp.y+1][k] = dp[ptmp.x][ptmp.y][k] + 1;
                    flag = 1;
                }
            }
            if(flag == 1) {
                ps.x = ptmp.x;
                ps.y = ptmp.y+1;
                q1.push(ps);
            }
        }

        //中心对称走，k->k+1更新
        if(M[n - 1 - ptmp.x][m - 1 - ptmp.y] != '#') {
            flag = 0;
            for(k = 0; k < 5; k++) {
                if(dp[n - 1 - ptmp.x][m - 1 - ptmp.y][k+1] > dp[ptmp.x][ptmp.y][k] + 1) {
                    dp[n - 1 - ptmp.x][m - 1 - ptmp.y][k+1] = dp[ptmp.x][ptmp.y][k] + 1;
                    flag = 1;
                }
            }
            if(flag == 1) {
                ps.x = n - 1 - ptmp.x;
                ps.y = m - 1 - ptmp.y;
                q1.push(ps);
            }
        }
        q1.pop();
    }


    if(dp[pe.x][pe.y][5] == n*m+1) {
        cout<<-1<<endl;
    }
    else {
        cout<<dp[pe.x][pe.y][5]<<endl;
    }

    return 0;
}