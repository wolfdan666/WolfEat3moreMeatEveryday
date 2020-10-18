// https://www.luogu.org/problem/P1616

#include <iostream>
const int maxn = 1e5+10;
int n, W, w[maxn], v[maxn], f[maxn];
int main() {
  std::cin >> W >> n;
  for (int i = 1; i <= n; i++) std::cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
    // 每种状态都看看对之前状态的是否有更优解,很想图论里的最短路问题,其实就是二维的贪心(因为这里有两个变量,所以很像)
    for (int l = w[i]; l <= W; l++)
      if (f[l - w[i]] + v[i] > f[l]) f[l] = f[l - w[i]] + v[i];
  std::cout << f[W];
  return 0;
}