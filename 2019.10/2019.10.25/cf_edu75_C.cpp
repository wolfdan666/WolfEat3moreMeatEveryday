/*
2019年10月25日16:22:33 开始看C
中途犯困一会儿,但是想到自己的实现梦想时候的快乐,又一次精力充沛,冲啊

2019年10月25日16:39:39 发现只有奇偶之间可以交换,所以直接记录前一个奇偶就行

2019年10月25日16:44:22 想不出,兔派,看大佬的

2019年10月25日17:00:51 感受到了震惊,红名大佬告诉我原来并不要什么自己造轮子
直接利用现有的merge函数,而且还是非常规地使用先sort的,而是直接使用merge的本质!cool!
template <class InputIterator1, class InputIterator2, class OutputIterator>
  OutputIterator merge (InputIterator1 first1, InputIterator1 last1,
                        InputIterator2 first2, InputIterator2 last2,
                        OutputIterator result)
{
  while (true) {
    if (first1==last1) return std::copy(first2,last2,result);
    if (first2==last2) return std::copy(first1,last1,result);
    *result++ = (*first2<*first1)? *first2++ : *first1++;
  }
}

*/
// By Aria, contest: Educational Codeforces Round 75 (Rated for Div. 2), problem: (C) Minimize The Integer, Accepted, #, hack it!
#include <bits/stdc++.h>
using namespace std;
string a;
void solve(){
    string a;
    cin>>a;
    string b, c;
    for(char &x: a) if(x%2) b+=x; else c+=x;
    merge(b.begin(), b.end(), c.begin(), c.end(), a.begin());
    cout<<a<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}