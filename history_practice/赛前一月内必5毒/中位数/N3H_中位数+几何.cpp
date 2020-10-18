/*
mdzz了, N = 2,然后vector变成了0,1   你N/2访问的是0
N = 4, N/2 = 2! 要-1！

2019年7月26日21:53:52 cin.cout超时...
2019年7月26日21:54:26 改成scanf也超时！---> vector这么慢的吗？
mdzz,晚上有点头晕了，忘了多组初始化point.clear();
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int oo = (1e9) - (1e6);
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int T,N;
typedef pair<int,int> P;
vector<P> point;
bool cmp(P a,P b){
    return a.first == b.first ? a.second<b.second : \
    a.first < b.first;
}

int main(){
    // ios::sync_with_stdio(false);cin.tie(0);
    scanf("%d",&T);
    while(T--){
        /*init*/
        point.clear();

        scanf("%d",&N);
        int a,b;
        for(int i=1;i<=N;i++){
            scanf("%d%d",&a,&b);
            point.push_back({a,b});
        }
        sort(point.begin(),point.end(),cmp);
        int x = point[N/2-1].first;
        int y = point[N/2-1].second;
        printf("%d %d %d %d\n", x-1,y+oo+1,x+1,y-oo);
    }

    return 0;
}
