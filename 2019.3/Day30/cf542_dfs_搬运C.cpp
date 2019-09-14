// why always submit failed?
#include <bits/stdc++.h>
using namespace std;

int n, r, c, r1, c1, used[52][52];
char g[51][51];
vector<pair<int,int> > v[3];

void DFS(int x, int y, int id){
    v[id].push_back({x, y});
    used[x][y] = id;
    for(int i : {-1, 0, 1}){
        for(int j : {-1, 0, 1}){
            if(abs(i)!=abs(j) && g[x+i][y+j]=='0' && used[x+i][y+j] != id){
                DFS(x+i, y+j, id);
            }
        }
    }
}

int main(){
    cin >> n >> r >> c >> r1 >> c1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> g[i][j];
        }
    }

    DFS(r, c, 1);
    DFS(r1, c1, 2);

    int ans = 1e9;

    for(auto X : v[1]){
        for(auto Y : v[2]){
            ans = min(ans, (X.first-Y.first)*(X.first-Y.first)+(X.second-Y.second)*(X.second-Y.second));
        }
    }

    cout << ans << endl;
    return 0;
}