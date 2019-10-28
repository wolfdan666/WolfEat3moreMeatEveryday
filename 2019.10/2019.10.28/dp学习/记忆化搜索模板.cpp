int g[MAXN];
int f(传入数值) {
  if (g[规模] != 无效数值) return g[规模];
  if (终止条件) return 最小子问题解;
  g[规模] = f(缩小规模);
  return g[规模];
}
int main() {
  ... memset(g, 无效数值, sizeof(g));
  ...
}