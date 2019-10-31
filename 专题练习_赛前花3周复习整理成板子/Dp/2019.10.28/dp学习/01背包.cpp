// https://www.luogu.org/problemnew/show/P2871
#include <iostream>
const int maxn = 13010;
int n,W, w[maxn], v[maxn], f[maxn];
int main() {
  std::cin >> n >> W;
  for (int i = 1; i <= n; i++) std::cin >> w[i] >> v[i];
  // 所有的其他状态值,都对w[i]的选与不选进行一下评估判断
  for (int i = 1; i <= n; i++)
    for (int l = W; l >= w[i]; l--)
      if (f[l - w[i]] + v[i] > f[l]) f[l] = f[l - w[i]] + v[i];
  std::cout << f[W];
  return 0;
}