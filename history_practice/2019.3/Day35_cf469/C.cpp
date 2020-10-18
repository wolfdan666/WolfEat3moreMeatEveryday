// 2019年3月19日22:13:44 开始读题
// 心境波动较大，所以明天再写吧

// 2019年3月20日19:48:01//  2019年3月20日20:30:44 输出还是没看懂，所以看下大佬怎么写吧

// 结果发现自己确实还是理解有问题，自己的英文阅读水平真是菜，这几天有点忙，所以暂时先不做D题吧
#include<bits/stdc++.h>
using namespace std;

char a[200005];
vector<int>V[200005];
int main() {
    scanf("%s",a);
    int len=strlen(a),cur=0,k=0;
    for(int i=0; i<len; i++) {
        if(a[i]=='0')V[cur++].push_back(1+i);
        else {
            if(cur==0) {
                cout<<-1<<endl;
                return 0;
            }
            V[--cur].push_back(1+i);
        }
        k=max(k,cur);
    }
    if(cur!=k) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<cur<<endl;
    for(int i=0; i<cur; i++) {
        cout<<V[i].size();
        for(int j=0; j<(int)V[i].size(); j++)cout<<' '<<V[i][j];
        cout<<endl;
    }
    return 0;
}