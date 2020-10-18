/*
模板题目:
https://oi-wiki.org/ds/sparse-table/#_2
*/

#include <bits/stdc++.h>
using namespace std;
const int logn = 21;
const int maxn = 2000001;
long long a[maxn], f[maxn][logn], Logn[maxn];
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
void pre() {
  Logn[1] = 0;
  Logn[2] = 1;
  for (int i = 3; i <= maxn; i++) {
    Logn[i] = Logn[i / 2] + 1;
  }
}
int main() {
  int n = read(), m = read();
  /*这一部分就是st表的rmq预处理 nlog(n)*/
  {
    for (int i = 1; i <= m; i++) f[i][0] = read();
    pre();
    for (int j = 1; j <= logn; j++)
      for (int i = 1; i + (1 << j) - 1 <= n; i++)
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  }
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    int s = Logn[y - x + 1];
    printf("%d\n", max(f[x][s], f[y - (1 << s) + 1][s]));
  }
  return 0;
}