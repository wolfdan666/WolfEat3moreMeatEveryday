#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define ll long long
const int M = 1e6+7;
int t,to[M];
map<int,vector<int>> a;
string s;
queue<int> q;
set<int> cunzai;
map<int,queue<int>> qq;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int k = 1;
    while(cin>>t && t){
        cout<<"Scenario #"<<k++<<endl;
        int n;
        for(int i=0;i<t;i++){
            cin>>n; int b;
            for(int j=0;j<n;j++){
                cin>>b;
                /* vector<> 用错了*/
                // a[i][j] = b;
                to[b] = i;
            }
        }
        while(cin>>s && s[0]!='S'){
            int tmp; cin>>tmp;
            if(s[0]=='E'){
                if(cunzai.find(to[tmp])!=cunzai.end()){
                    cunzai.insert(to[tmp]);
                    q.push(to[tmp]);
                }
                qq[to[tmp]].push(tmp);
            }
            else{
                cout<<qq[q.front()].front()<<endl;
                qq[q.front()].pop();
                if(qq[q.front()].empty())
                    q.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}