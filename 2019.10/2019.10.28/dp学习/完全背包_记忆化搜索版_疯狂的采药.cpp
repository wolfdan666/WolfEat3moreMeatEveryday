/*
普通采药是0,1背包,所以记忆化搜索也是01背包问题


魔改解决01背包问题----> 然后tle了???---抄错板子了...

改了,MLE...开大了点

开小也卡MLE,因为这题直接dp可以用滚动数组...
*/

#include<bits/stdc++.h>
using namespace std;
// 魔改解决01背包问题
const int N = 3403;
const int M = 12881;

int n, t;
int tcost[N], mget[N];
int mem[N][M];
int dfs(int pos, int tleft) {
  if (mem[pos][tleft] != -1) return mem[pos][tleft];
  if (pos == n + 1) return mem[pos][tleft] = 0;
  int dfs1, dfs2 = -2;
  dfs1 = dfs(pos + 1, tleft);
  if (tleft >= tcost[pos]) dfs2 = dfs(pos + 1, tleft - tcost[pos]) + mget[pos];
  return mem[pos][tleft] = max(dfs1, dfs2);
}
int main() {
  memset(mem, -1, sizeof(mem));
  // cin >> t >> n;
  cin >> n >> t;
  for (int i = 1; i <= n; i++) cin >> tcost[i] >> mget[i];
  cout << dfs(1, t) << endl;
  return 0;
}