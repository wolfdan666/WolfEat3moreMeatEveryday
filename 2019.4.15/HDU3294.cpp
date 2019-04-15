// 2019年4月15日16:50:41开始看题
// Manacher + 简单的变化  所以2019年4月15日16:56:17 争取15mins写完
// 今天不知怎么回事，总是把2^16 = 65536 当成int 的最大值 正2.1e8,mdzz了

// 2019年4月15日17:51:24 第一发超时，所以先不对s进行转化处理，否则浪费了很多时间，最后再进行转化处理，odk

// 2019年4月15日17:55:09 觉得AC了，因为Manacher最优，然后转化也最优了，结果还是TLE了

// 莫名其妙，不会又是因为输入的问题吧？2019年4月15日18:00:58先吃饭去吧，然后去上公选，晚上再继续，push一下

#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int p[M];
string s,t;
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
    ios::sync_with_stdio(false);
    while(cin>>a>>s){
        for(int i=0,j=a-'a';i<26;i++,j=(j+1)%26){   // j记得保持在26里面
            b[j] = 'a' + i; // j = 1（b-'a'）的b对应的是'a' + 0 = 'a'
        }
        // int n = int(s.length());
        // for(int i=0;i<n;i++){
        //     s[i] = b[s[i]-'a'];
        // }
        // for(int i=0;i<n;i++) cout<<s[i]; cout<<endl;
        int begin = 0;
        int m = Manacher(s,begin);
        if(m <= 1) cout<<"No solution!"<<endl;
        // else cout<<begin<<' '<<begin + m - 1<<"\n";// <<s.substr(begin,begin + m )<<endl; // begin + m取不到
        else{
            cout<<begin<<' '<<begin + m - 1<<"\n";
            for(int i = begin; i < begin + m;i++){
                cout<<b[s[i]-'a'];
            }
            cout<<endl;
        }
    }
    return 0;
}
