/*
2019年10月10日16:19:58 开始看题
2019年10月10日16:26:39 想不出来,还是看tutorial吧
2019年10月10日16:43:53 没太看懂tutorial,然后去看大佬们怎么写,发现好多超短代码! 竟然是反向思考就完事了

发现[tutorial](https://codeforces.com/blog/entry/69244)  中的法二还是比较好懂的,但是没有下面大佬的实现精简高效,

然后理解了大佬的写法和tutorial 2 之后,发现tutorial 1也很好理解...

原来这是个找规律题,大佬的写法简直精妙
*/

// By YellowJ, contest: Codeforces Round #581 (Div. 2), problem: (D2) Kirk and a Binary String (hard version), Accepted, #
#include<bits/stdc++.h>
using namespace std;
main(){
    string s; cin>>s;
    int cnt=0 , l=s.size();
    for(int i=l-1;i>=0;i--)if(s[i]=='0')cnt++;else if(s[i]=='1'){if(cnt)cnt--;else s[i]='0';}
    cout<<s;
}