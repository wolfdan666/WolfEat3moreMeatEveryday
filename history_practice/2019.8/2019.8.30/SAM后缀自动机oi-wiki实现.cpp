/**
 *　　　　　　　 ┏┓　 ┏┓+ +
 *　　　　　　　┏┛┻━━━┛┻┓ + +
 *　　　　　　　┃　　　 ┃ 　
 *　　　　　　　┃　　　━┃ ++ + + +
 *　　　　　　 ████━████┃+
 *　　　　　　　┃　　　 ┃ +
 *　　　　　　　┃　┻　　┃
 *　　　　　　　┃　　　 ┃ + +
 *　　　　　　　┗━┓　 ┏━┛
 *　　　　　　　　┃　 ┃　　　　　　　　　　　
 *　　　　　　　　┃　 ┃ + + + +
 *　　　　　　　　┃　 ┃　　　　Code is far away from bug with the animal protecting　　　　　　　
 *　　　　　　　　┃　 ┃ + 　　　　神兽保佑,代码无bug　　
 *　　　　　　　　┃　 ┃
 *　　　　　　　　┃　 ┃　　+　　　　　　　　　
 *　　　　　　　　┃　 ┗━━━┓ + +
 *　　　　　　　　┃  　　 ┣┓
 *　　　　　　　　┃  　　 ┏┛
 *　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
 *　　　　　　　　 ┃┫┫ ┃┫┫
 *　　　　　　　　 ┗┻┛ ┗┻┛+ + + +
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;

struct state {
  int len, link;
  std::map<char, int> next;
};
const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;

void sam_init() {
/*sz在重复使用的时候可要小心...*/
  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
}

void sam_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && !st[p].next.count(c)) {
    st[p].next[c] = cur;
    p = st[p].link;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      while (p != -1 && st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);


    return 0;
}