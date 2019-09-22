/*
APIO2014|luogu3649 回文串

建出树来，类似后缀自动机统计出现次数即可
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 300010;
char str[N];

//变量名与上文基本相同，其中ptr为转移指针，数组大小应为字符集大小
class PA {
 // private:
  public:
  static const int N = 300010;
  struct Node {
    int len;int ndcnt;
    int ptr[26], fail;
    Node(int len = 0) : len(len), ndcnt(0), fail(0) { memset(ptr, 0, sizeof(ptr)); }
  } nd[N];

  int size, cnt;  // size为字符串长度，cnt为节点个数
  int cur;  //当前指针停留的位置，即最后插入字符所对应的节点
  char s[N];

  int getfail(int x)  //沿着fail指针找到第一个回文后缀
  {
    while (s[size - nd[x].len - 1] != s[size]) {
      x = nd[x].fail;
    }
    return x;
  }   

 // public:
  PA() : size(0), cnt(0), cur(0) {
    nd[cnt] = Node(0);
    nd[cnt].fail = 1;
    nd[++cnt] = Node(-1);
    nd[cnt].fail = 0;
    s[0] = '$';
  }

  void extend(char c) {
    s[++size] = c;
    int now = getfail(cur);  //找到插入的位置
    if (!nd[now].ptr[c - 'a'])  //若没有这个节点，则新建并求出它的fail指针
    {
      int tmp = ++cnt;
      nd[tmp] = Node(nd[now].len + 2);
      nd[tmp].fail = nd[getfail(nd[now].fail)].ptr[c - 'a'];
      nd[now].ptr[c - 'a'] = tmp;
    }
    cur = nd[now].ptr[c - 'a'];
    nd[cur].ndcnt++;
  }

  int qlen() { return nd[cur].len; }
} A;

int main(int argc, char const *argv[]){
  long long ans=0;
  scanf("%s",str+1);
  int len=strlen(str+1);
  for(int i=1;i<=len;i++) A.extend(str[i]);
  for(int i=A.cnt;i>=2;i--){
    A.nd[A.nd[i].fail].ndcnt += A.nd[i].ndcnt;
    ans = max(ans,(long long)A.nd[i].ndcnt*A.nd[i].len);
  }
  cout<<ans<<endl;
  return 0;
}
