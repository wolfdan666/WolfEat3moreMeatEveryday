/*
这里的重中之重是如何将有填充的线转化为无填充的先--->每个线都先*=2？ 这样1->2.2->4,正好隔着一个，试试

 */

#include<bits/stdc++.h>
using namespace std;
const int M = 1e4+7;
queue<int> q;
int xx[M], yy[M];
int mat[M][M];
bool vis[M][M];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int T;char tp;
struct Rect {
  int x1, x2, y1, y2;
} rect[M];

struct Line {
  int y, x1, x2;
  int ud;
  bool operator<(const Line &l) const {
    return y < l.y;
  }
} line[M];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>T;
  while(T--){
    int w,h,n;
    cin>>w>>h>>n;
    for (int i = 0; i < n; ++i) {
      cin>>rect[i].x1>>rect[i].y1>>tp;
      if(tp=='U'){ rect[i].x2=rect[i].x1; rect[i].y2=h;}
      else if(tp=='D'){rect[i].x2=rect[i].x1; rect[i].y2=0;}
      else if(tp=='L'){rect[i].x2=0;rect[i].y2=rect[i].y1;}
      else {rect[i].x2=w;rect[i].y2=rect[i].y1;}
      xx[i << 1] = 2*rect[i].x1;
      xx[i << 1 | 1] = 2*rect[i].x2;
      yy[i << 1] = 2*rect[i].y1;
      yy[i << 1 | 1] = 2*rect[i].y2;
    }

    w*=2;h*=2;

    xx[n << 1] = 0;
    xx[n << 1 | 1] = w;
    yy[n << 1] = 0;
    yy[n << 1 | 1] = h;

    // 离散化

    int cnt = n + 3*n + 2;
    int cntx, cnty;
    sort(xx, xx + cnt);
    sort(yy, yy + cnt);
    cntx = unique(xx, xx + cnt) - xx;
    cnty = unique(yy, yy + cnt) - yy;

    for (int i = 0; i < n; ++i) {
      int x1, y1, x2, y2;
      x1 = lower_bound(xx, xx + cntx, rect[i].x1) - xx;
      x2 = lower_bound(xx, xx + cntx, rect[i].x2) - xx;
      y1 = lower_bound(yy, yy + cnty, rect[i].y1) - yy;
      y2 = lower_bound(yy, yy + cnty, rect[i].y2) - yy;

      line[i << 1].y = y1;
      line[i << 1].ud = 1;
      line[i << 1].x1 = x1;
      line[i << 1].x2 = x2;
      line[i << 1 | 1].y = y2;
      line[i << 1 | 1].ud = -1;
      line[i << 1 | 1].x1 = x1;
      line[i << 1 | 1].x2 = x2;
    }
    sort(line, line + n + n);

    // 扫描线

    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < n + n; ++i) {
      int y = line[i].y;
      for (int j = line[i].x1; j < line[i].x2; ++j) {
        mat[y][j] += line[i].ud;
      }
    }
    for (int i = 1; i < cnty - 1; ++i) {
      for (int j = 0; j < cntx - 1; ++j) {
        mat[i][j] += mat[i - 1][j];
      }
    }

  //    for (int i = 0; i < cnty - 1; ++i) {
  //      for (int j = 0; j < cntx - 1; ++j) {
  //        printf("%d ", mat[i][j]);
  //      }
  //      printf("\n");
  //    }

    // BFS

    long long ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < cnty - 1; ++i) {
      for (int j = 0; j < cntx - 1; ++j) {
        if (mat[i][j] || vis[i][j]) continue;
        ++ans;
        q.push(i * cnt + j);
        while (!q.empty()) {
          int x, y;
          x = q.front() / cnt;
          y = q.front() % cnt;
          q.pop();
          int nx, ny;
          for (int k = 0; k < 4; ++k) {
            nx = x + dx[k];
            ny = y + dy[k];
            if (nx >= 0 && nx < cnty - 1 && ny >= 0 && ny < cntx - 1 && !vis[nx][ny] && !mat[nx][ny]) {
              vis[nx][ny] = 1;
              q.push(nx * cnt + ny);
            }
          }
        }
      }
    }

    cout<<ans<<endl;
  }

  return 0;
}