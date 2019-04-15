// 2019年4月15日16:50:41开始看题
// Manacher + 简单的变化  所以2019年4月15日16:56:17 争取15mins写完
// 今天不知怎么回事，总是把2^16 = 65536 当成int 的最大值 正2.1e8,mdzz了

// 2019年4月15日17:51:24 第一发超时，所以先不对s进行转化处理，否则浪费了很多时间，最后再进行转化处理，odk

// 2019年4月15日17:55:09 觉得AC了，因为Manacher最优，然后转化也最优了，结果还是TLE了

// 莫名其妙，不会又是因为输入的问题吧？2019年4月15日18:00:58先吃饭去吧，然后去上公选，晚上再继续，push一下

// 2019年4月15日23:04:13 晚上又找为啥超时找了30mins，先做一个简单题爽一下(cf A题)

// 发现自己用Manacher，没有用两倍数组大小，mdzz，改了之后TLE就变成了WA了(因为自己用的转化，后面再TLE的时候改了一下，改回来就好)，不过好过了一点

// 2019年4月16日00:23:23发现好像自己太菜了，默写的Manacher 马拉车有问题，明天继续吧，睡了2019年4月16日00:24:05，晚安
#include<bits/stdc++.h>
using namespace std;
const int M = 4e5 + 10;
// const int M = 2e5 + 10;
int p[M];
// string s,t;
string t;
char s[M];
char a;
char b[26];

int Init(string ts){
    int n = int(ts.length());
    t.resize(n*2+2,'#');
    t[0] = '$';t[1] = '#';
    int j = 2;
    for(int i=0;i<n;i++){
        t[j++] = ts[i];
        j++;
    }
    return j;
}

int Manacher(string ts,int &begin){
    int len = Init(ts);
    int max_len = 1;// 这里是根据题目做的一些修改
    int mx=0,id=0;
    for(int i=1;i<len;i++){
        if(i<mx) p[i] = max(p[2*id - i],mx - i);
        else p[i] = 1;
        while(t[i-p[i]] == t[i+p[i]]) p[i]++;
        if(mx<i+p[i]){
            mx = i+p[i];
            id = i;
        }
        if(p[i]-1>max_len){
            max_len = p[i] - 1;
            // begin = i/2-1; // 刚刚好设计成2倍关系，真好   // 注意要变成下标
            begin =i - (p[i]-1);      // p[i]-1 是s的子回文串长，也是t的回文串的半径长
            begin = (begin+1)/2 - 1;      // 上面正好到达t的最左侧也就是#号的位置，所以加一除2，就是begin位置，-1 后就是它的下标
        }
    }
    return max_len;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);cin.tie(0) ;
    cout .tie(0) ;
    while(cin>>a>>s){
        for(int i=0,j=a-'a';i<26;i++,j=(j+1)%26){   // j记得保持在26里面
            b[j] = 'a' + i; // j = 1（b-'a'）的b对应的是'a' + 0 = 'a'
        }
        // int n = strlen(s);
        // for(int i=0;i<n;i++){
            // s[i] = b[s[i]-'a'];
        // }
        // for(int i=0;i<n;i++) cout<<s[i]; cout<<endl;
        int begin = 0;
        int m = Manacher(s,begin);
        if(m <= 1) cout<<"No solution!"<<endl;
        // else cout<<begin<<' '<<begin + m - 1<<"\n"<<s.substr(begin,begin + m )<<endl; // begin + m取不到
        else{
            cout<<begin<<' '<<begin + m - 1<<"\n";
            for(int i = begin; i < begin + m;i++){
                cout<<s[i];
            }
            cout<<endl;
            for(int i = begin; i < begin + m;i++){
                cout<<b[s[i]-'a'];
            }
            cout<<endl;
        }
    }
    return 0;
}



// 玄学，我找了好多人写的code，后面终于找到一个跟我相近的代码，但是我还是tle，他却过了
// #include <bits/stdc++.h>
// using namespace std ;
// typedef unsigned long long ull ;
// typedef long long ll ;
// const int Maxn = 4e5 + 10 ;
// const int INF = 0x3f3f3f3f ;
// const double PI = acos(-1.0) ;
// const ull seed = 133 ;

// char s[Maxn], ch ;
// int len ;

// void Manacher (){
//     string str ;
//     str = "$#" ;
//     for (int i = 0; i < len; i++){
//         str += s[i] ;
//         str += "#" ;
//     }
// //    cout << str << endl ;
//     len = str.size() ;
//     vector < int > ve (len, 0) ;
//     int Mx = 0, id = 0, maxLen = 0, index = 0 ;
//     for (int i = 0; i < len; i++){
//         ve[i] = Mx > i ? min(ve[2 * id - i], Mx - i) : 1 ;
//         while (str[i + ve[i]] == str[i - ve[i]]) ve[i]++;
//         if (Mx < i + ve[i]){
//             Mx = i + ve[i] ;
//             id = i ;
//         }
//         if (maxLen < ve[i]) {
//             maxLen = ve[i] ;
//             index = i ;
//         }
//     }
//     if (maxLen - 1 == 1) cout << "No solution!" << endl ;
// //    else {
// //        cout << (index - maxLen) / 2 << " " << (index - maxLen) / 2 + maxLen - 2 << endl ;
// ////        cout << str.substr((index - maxLen) / 2, maxLen - 1) << endl ;
// //        int cnt = 0 ;
// //        for (int i = (index - maxLen) / 2 ;i < len; i++){
// //            if (str[i] != '$' && str[i] != '#'){
// //                cnt++ ;
// //                cout << str[i] ;
// //            }
// //            if (cnt == maxLen - 1) break ;
// //        }
// //        cout << endl ;
// //    }
//     else {
//         cout << (index - maxLen) / 2 << " " << (index - maxLen) / 2 + maxLen - 2 << endl ;
//         for (int i = (index - maxLen) / 2; i < (index - maxLen) / 2 + maxLen - 1; i++){
//             cout << s[i] ;
//         }
//         cout << endl ;
//     }
// }

// int main (){
//     // ios_base::sync_with_stdio(false) ;
//     ios::sync_with_stdio(false) ; // 改了别人ac代码这里，还快了40ms,那我为啥会超时呢？先做下一题吧
//     cin.tie(0) ;
//     cout .tie(0) ;
//     while (cin >> ch >> s ){
//         len = strlen(s) ;
//         int sub = ch - 'a' ;
//         for (int i = 0; i < len; i++){
//             s[i] -= sub ;
//             if (s[i] < 'a') s[i] += ('z' - 'a' + 1) ;
//         }
// //        cout << s << endl ;
//         Manacher() ;
//     }
//     return 0 ;
// }