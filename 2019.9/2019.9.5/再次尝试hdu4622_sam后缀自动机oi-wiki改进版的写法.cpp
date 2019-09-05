/*
改成scanf和unordered_map还是会TLE！==>怎么回事

自建next hash函数才过的！看了unordered_map也慢的一批...

前缀里面新产生的后缀个数..
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
  // std::unordered_map<char, int> next;
  int next[26];
};
state st[MAXLEN * 2];
int sz, last;

void sam_init() {
  st[0].len = 0;
  st[0].link = -1;
  // if(!st[0].next.empty()) st[0].next.clear();
  memset(st[0].next,0,sizeof st[0].next);
  /*这个破板子，sz不清零.

  还有next没有清零啊啊啊啊,这个破板子,太坑了...*/
  sz = 0;
  sz++;
  last = 0;
  tp = 0;
}

int sam_extend(int c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  // if(!st[cur].next.empty()) st[cur].next.clear();
  memset(st[cur].next,0,sizeof st[cur].next);
  int p = last;
  // while (p != -1 && !st[p].next.count(c)) {
  while (p != -1 && !st[p].next[c]) {
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
      // st[clone].next = st[q].next;
      for(int i=0;i<26;i++) st[clone].next[i] = st[q].next[i];
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
    // ios::sync_with_stdio(false);cin.tie(0);
    // cin>>T;
    scanf("%d",&T);
    while(T--){
        // string s;
        char s[MAXLEN];
        int n;
        scanf("%s",s);
        scanf("%d",&n);
        // cin>>s>>n;
        // int len = s.length();
        int len = strlen(s);
        for(int i=0;i<len;i++){
            sam_init();
            for(int j=i;j<len;j++){
                ans[i][j] = sam_extend(s[j]-'a');
            }
        }
        // for(int i = 0;i<len;++i){for(int j = i;j<len;++j) cout<<ans[i][j]; cout<<endl;}
        while(n--){
            int l,r;
            // cin>>l>>r;
            scanf("%d%d",&l,&r);
            l--,r--;
            // cout<<ans[l][r]<<endl;
            printf("%d\n",ans[l][r] );
        }
    }

    return 0;
}