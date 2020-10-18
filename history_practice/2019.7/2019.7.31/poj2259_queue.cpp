/*
2019年8月1日10:02:28 竟然RE了！
看看别人怎么写
发现是因为自己的set->cunzai忘了清除掉弹出的队头了
poj 2259
Status Accepted
Time 250ms
Memory 1328kB
Length 1538
Lang G++
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define ll long long
const int M = 1e6+7;
/*to是队员对应的组号的hash*/
int t,to[M];
/*每组多少人一个类似链状数组的东西*/
map<int,vector<int> > a;
string s;
/*队伍队列以及队伍是否存在的set维护*/
queue<int> q;
set<int> cunzai;
/*队伍队列对应的每个小组的队列*/
map<int,queue<int> > qq;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int k = 1;
    while(cin>>t && t){
        /* init */
        a.clear();qq.clear();cunzai.clear();
        while(!q.empty()) q.pop();
        /* solve */
        cout<<"Scenario #"<<k++<<endl;
        int n;
        for(int i=0;i<t;i++){
            cin>>n; int b;
            for(int j=0;j<n;j++){
                cin>>b;
                /* vector<> 用错了*/
                // a[i][j] = b;
                a[i].push_back(b);
                to[b] = i;
            }
        }
        while(cin>>s && s[0]!='S'){
            if(s[0]=='E'){
                int tmp; cin>>tmp;
                if(cunzai.find(to[tmp])==cunzai.end()){
                    cunzai.insert(to[tmp]);
                    q.push(to[tmp]);
                }
                qq[to[tmp]].push(tmp);
            }
            else{
                cout<<qq[q.front()].front()<<endl;
                qq[q.front()].pop();
                if(qq[q.front()].empty()){
                    cunzai.erase(q.front());
                    q.pop();
                }
            }
        }
        cout<<endl;
    }
    return 0;
}