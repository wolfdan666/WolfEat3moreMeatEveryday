/*
为什么不要用这个板子？

2019年9月4日22:15:02 的 HDU4622来告诉你

发现oi-wiki的板子不仅  sz没有清零，连next都没有清零，导致我debug 2小时(好吧,是我太菜)
然后还因为使用的map,直接tle了...所以再也不想用这个板子了

去oi-wiki提交意见去了

1. **建议sam_init将sz清理，并且在init和cur构建的时候清空map！**（菜鸡debug一题两小时）
2. **建议不要使用map**(菜鸡debug完又TLE了)
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int MAXLEN = 2010;
int T,ans[MAXLEN][MAXLEN],tp;
struct state {
  int len, link;
  std::map<char, int> next;
};
state st[MAXLEN * 2];
int sz, last;

void sam_init() {
  st[0].len = 0;
  st[0].link = -1;
  if(!st[0].next.empty()) st[0].next.clear();
  /*这个破板子，sz不清零.

  还有next没有清零啊啊啊啊,这个破板子,太坑了...*/
  sz = 0;
  sz++;
  last = 0;
  tp = 0;
}

int sam_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  if(!st[cur].next.empty()) st[cur].next.clear();
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
  tp += st[cur].len - st[st[cur].link].len;
  return tp;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        string s;int n;
        cin>>s>>n;
        int len = s.length();
        for(int i=0;i<len;i++){
            sam_init();
            for(int j=i;j<len;j++){
                ans[i][j] = sam_extend(s[j]);
            }
        }
        // for(int i = 0;i<len;++i){for(int j = i;j<len;++j) cout<<ans[i][j]; cout<<endl;}
        while(n--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<ans[l][r]<<endl;
        }
    }

    return 0;
}