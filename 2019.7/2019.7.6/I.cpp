// 剪刀石头布，谁输谁吃屎
/*
这个题目有点牛逼哦    好玩

发现数电课程设计真值表什么的竟然和程序设计思路中的打表是一脉相承的！
*/
#include<bits/stdc++.h>
using namespace std;
int T;
string A,B,x1,x2,ans;
map<string,int> s2n={{"shitou",1},{"jiandao",2},{"bu",3}};
map<pair<int,int>,int> check={ {{1,1},0},{{1,2},1},{{1,3},-1}, {{2,1},-1},{{2,2},0},{{2,3},1}, {{3,1},1},{{3,2},-1},{{3,3},0} };

int main(){
    cin>>T;
    while (T--){
        cin>>A>>x1>>B>>x2;
        int y1 = s2n[x1],y2 = s2n[x2];
        int t = check[{ y1, y2 }];
        if (t == 1) cout << B << " chishi." << endl;
        else if(t == -1) cout<< A <<" chishi."<<endl;
        else cout << "yi qi chi shi."<<endl;
    }
    return 0;
}