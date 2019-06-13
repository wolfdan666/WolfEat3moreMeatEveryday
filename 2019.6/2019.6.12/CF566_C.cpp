// emmm,看大佬怎么写吧,我的思路和官方的差不多,但是不太会实现
#include <bits/stdc++.h>
using namespace std;

set<char> vow={'a','e','i','o','u'};

int main() {
    //freopen("input","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    map<int,map<char,vector<int>>> cc;
    vector<string> word(n);
    for(int i=0;i<n;++i) {
        string s;
        cin>>s;
        word[i]=s;
        int cnt=0;char last=0;
        for(int i=0;i<s.length();++i)
            if(vow.count(s[i])) {
                cnt++;
                last=s[i];
            }
        cc[cnt][last].push_back(i);// map可以这样用！我惊了！2019年6月12日11:59:30 先吃饭去吧
    }
    vector<pair<int,int>> c1,c2;

    for(auto &p : cc) { // 总的map流动
        vector<int> rem;
        for(auto &q : p.second) { //  这里是  元音字母长度 对应的map
            auto &v=q.second;  // 这里是char对应的  id 数组(可以通过这个找到word[id])
            for(size_t i=0;i+1<v.size();i+=2)
                c2.push_back({v[i],v[i+1]});  // 拿走两个
            if(v.size()%2==1)
                rem.push_back(v.back());  // 是否剩余一个  以及  所有没有配上对的剩下的word值
        }
        for(size_t i=0;i+1<rem.size();i+=2)
            c1.push_back({rem[i],rem[i+1]});
    }
    while(c1.size()<c2.size()) {  // c2 是优势兵种，可以补给c1
        c1.push_back(c2.back());  // 充分体现了vector在末尾的特性
        c2.pop_back();
    }
    int tot=min(c1.size(),c2.size());
    cout<<tot<<'\n';
    for(int i=0;i<tot;++i)
        cout<<word[c1[i].first]<<' '<<word[c2[i].first]<<'\n'
            <<word[c1[i].second]<<' '<<word[c2[i].second]<<'\n';
    return 0;
}