/*
看大佬的代码，发现真的扩展kmp，自己都忘了...太傻逼了自己，我不配说自己是acmer

z[i]是s和 从i开始的s的后缀的最大公共前缀长度

2020年5月26日17:52:06 理解完了
*/

#include<bits/stdc++.h>
using namespace std;
string str[11];
int dp[1 << 11][11];
int tmp[11][11];

vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int main() {
  int T; cin >> T;
  while(T--) {
    int n, l; cin >> n >> l;
    for(int i = 0; i < n; i++) {
      cin >> str[i];
    }
    // 预处理tmp[i][j]数组-str[j]的前缀 和 str[i]后缀的共同长度---str[i]`+`str[j]
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        tmp[i][j] = 0;
        string nw = str[j] + "$" + str[i];
        vector<int> z = z_function(nw);
        const int sz = nw.size();
        for(int k = int(str[j].size()) + 1; k < sz; k++) {
          if(sz - k == z[k]) {
            tmp[i][j] = z[k];
            break;
          }
        }
      }
    }
    // 置为最大值
    for(int i = 0; i < (1 << n); i++) {
      for(int j = 0; j < n; j++) {
        dp[i][j] = 0x3f3f3f3f;
      }
    }
    // dp初始值---dp[哪几个串][以i串开头]
    for(int i = 0; i < n; i++) {
      dp[1 << i][i] = str[i].size();
    }
    // 状压dp
    for(int i = 0; i < (1 << n); i++) {
      const int cur = __builtin_popcount(i);
      if(cur == 1) continue;
      for(int j = 0; j < n; j++) {
        if((i >> j) & 1) {
          for(int k = 0; k < n; k++) {
            // 在 k 串后面拼接 j 串
            dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + int(str[j].size()) - tmp[k][j]);
          }
        }
      }
    }
    int mn = INT_MAX;
    for(int i = 0; i < n; i++) {
      mn = min(mn, dp[(1 << n) - 1][i]);
    }
    cout << mn << '\n';
  }
}