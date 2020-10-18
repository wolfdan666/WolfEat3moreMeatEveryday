// 2019年3月17日20:44:39 开始看题
// 2019年3月17日20:52:11 开始2分搜索
// 昨天打月赛，暴露了兔派刷题的弊端，就是自己实操的时候会慢
// 2019年3月17日22:57:51 绝了，EDU60自己没有细致地去分析，而是不断地套式子，浪费时间（以后不准！！！），回去再想，现在脑子有点乱
//  狂肝两个多小时，GG
// #include<bits/stdc++.h>
// using namespace std;
// const int inf = 0x3f3f3f3f;
// string s;
// int a,b,c,d;

// int left(int m,int n,bool &flag){
//     int source = abs(a-c) + abs(b-d);
//     // int aftern = 0;
//     int ta=a,tb=b,tc=c,td=d;
//     // int dis = source;
//     int day = m < n? m : n;
//     for(int i=0;i<day;i++){
// //         if(s[i]=='U'){
// //             int tdis = abs(ta-tc) + abs(tb+1-td);
// //             if(tdis>dis) {
// //                 day++;continue;
// //             }
// //             else{
// //                 tb++;
// //                 if(abs(tb-td)>0){
// //                     tb++; // 这里不能盲目决策，这又回到了最初问题的源头，到底可不可以像这样决策，其实应该要考虑后面的走向的，所以当时没想清楚就写，真是浪费时间！
// // // 不过自己细细一想，发现很简单，就是在跟风走了n天后，然后再根据n天后的进度抉择自己n天的走向就完美了，如果
// // // m<n 就更简单了，直接让它先跟风m天，如果可以就可
// //                 }
// //             }
// //         }
//         if(s[i]=='U') tb++;
//         else if(s[i]=='D') tb--;
//         else if(s[i]=='L') ta--;
//         else if(s[i]=='R') ta++;
//     }
//     // int afterDay = abs(ta-tc) + abs(tb+1-td); // 用vscode debug发现自己刚刚复制多加了个1
//     int afterDay = abs(ta-tc) + abs(tb-td);
//     if(flag && m >= n && afterDay-day == source) flag=0; // n天穷举完了，发现没有靠近(不存在远离)，所以重复n更加不会靠近，m<n之所以能达到，是因为前面m值很大都能到，所以m<n的时候必定到达
//     return m - afterDay;
// }

// int main(int argc, char const *argv[]){
//     ios::sync_with_stdio(false);
//     cin>>a>>b>>c>>d;
//     int n;
//     cin>>n;
//     cin>>s;
//     int l=1,r=inf;
//     int m = (l + r) / 2;
//     int f=0;bool flag=1;
//     while((r-l)>1) {// f>0是剩余
//         f=left(m,n,flag);
//         if(f>0){
//             r = m;
//             m = (l + r) / 2;
//         }
//         else{
//             l = m;
//             m = (l+r)/2;
//         }
//     }
//     if(flag) cout<<r<<endl;
//     else puts("-1");
//     return 0;
// }



// 2019年3月18日20:03:27发现大佬们写的都一样，看来是自己没有接触过的地方，所以还是兔派一波
// 结果中途去搞安卓去了，然后现在2019年3月18日22:11:12 回来继续肝
// #include<bits/stdc++.h>
// using namespace std;
// long long n,a,b,c,d,ans = 1e18;
// string s;
// int main(){
//     cin>>a>>b>>c>>d>>n>>s;
//     long long i = 0,j = 1e18,rep = 64;
//     while(rep--)
//     {
//         long long m = (i+j)/2;
//         long long x = a,y = b;
//         for(int i=0;i<n;i++){
//             long long p = m/n + (long long)(i<m%n);
//             if(s[i]=='U') y+=p;
//             else if(s[i]=='D')y-=p;
//             else if(s[i]=='L')x-=p;
//             else x+=p;
//         }
//         if(abs(c-x)+abs(d-y)<=m) j=m;
//         else i = m;
//     }
//     if(j==(long long)1e18)
//         cout<<-1<<endl;
//     else
//         cout<<j<<endl;  // 右边一定是对的，确实符合我所理解的
//     return 0;
// }

// 大佬的code不如tutorial清晰，我自己的做法是没有考虑清楚mid%n那一块，自己的处理比较粗糙，所以就wa了
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int N = 100009;

pair<int, int> st, fi;
int n;
string s;

string mv = "UDLR";
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

pair<int, int> d[N];

int main(){
    cin >> st.x >> st.y >> fi.x >> fi.y;
    cin >> n >> s;

    for(int i = 0; i < n; ++i){
        int id = -1;
        for(int j = 0; j < 4; ++j)
            if(mv[j] == s[i])
                id = j;
        assert(id != -1);
        d[i + 1] = make_pair(d[i].x + dx[id], d[i].y + dy[id]);
    }

    long long l = 0, r = 1e18;
    while(r - l > 1){
        long long mid = (l + r) / 2;
        long long cnt = mid / n, rem = mid % n;
        long long x = st.x + d[rem].x + cnt *  1LL * d[n].x;
        long long y = st.y + d[rem].y + cnt *  1LL * d[n].y;
        long long dist = abs(x - fi.x) + abs(y - fi.y);
        if(dist <= mid)
            r = mid;
        else
            l = mid;
    }

    if(r > 5e17) r = -1;
    cout << r << endl;

    return 0;
}