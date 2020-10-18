/*
第一次wa：(小测)  --- > 实际上wa在 单点  *
. . .
. * .
* * *
第二次wa：(终测我猜)
. * . *
* * * *(这个点不算中心，但却污染了"十"字)
. * . *
要小心:(这下面那个被污染的点周围也是两点，所以还要判断是否是在一条直线)--->实际上终测试wa在这种
. * . .
* * * *(这个点不算中心，但却污染了"十"字)
. * . *
// 然后自己又交了一次，又wa了，还比以前早wa，因为没有考虑仅有一个中心的时候必须要是四方心才行！
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
char a[505][505];
int w,h,visited[505][505];
int center = 0,fullcenter = 0;
int p[4] = {0,1,0,-1};// 下左上右
int q[4] = {1,0,-1,0};
// head

void dfs(int m,int n){
    if(visited[m][n]) return;
    visited[m][n] = 1; // 都是要先判断没到过再标记的 --- 好久没写这类dfs有点生疏
    // bool f = 1;
    int cnt = 0;
    int dir[4] = {0,0,0,0};
    for(int i=0;i<4;i++){
        if(m+p[i]>=1 && m+p[i]<=w && n+q[i]>=1 && n+q[i]<=h){
            // if(a[m+p[i]][n+q[i]] != '*') f=0;// wa..f=0的情况漏了！万一“十”在边上,那么也会不能center++！所以换一种判断
            if(a[m+p[i]][n+q[i]] != '*') continue;
            // else cnt++,dfs(m+p[i],n+q[i]);
            else cnt++,dir[i]++,dfs(m+p[i],n+q[i]);
        }
    }
    // if(f) center++;
    // if(cnt==4) center++;
    if(cnt==4) fullcenter++;
    if(cnt>2) center++;
    if(cnt==2){
        int temp=dir[1]+dir[3];
        if(temp==0||temp==2) ;// 在上下或者左右一条线上
        else center++;
    }
    return ;
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
//    #ifdef LOCAL
//  freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
//  #endif
    //scanf("%d",&a);
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    while(1){
    int tt = clock();
//测试的时候请对重复使用的数组或者变量清零！！
//    k=0;
//    memset(a,0,sizeof(a));
//  以及后文中该特判return的地方要及时return！
#endif
    cin>>w>>h;

    // cout<<w<<h;
    // int cnt=0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            cin>>a[i][j]; // char类型！你定义的int类型，导致出现了莫名其妙的错误！
            // cnt++;
        }
    }
    // cout<<"cnt:"<<cnt<<endl;

    int f = 0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(a[i][j]=='*'){
                if(visited[i][j]) continue;
                else if(f){  // 发现了第二块大陆，就是其他地方不为空
                    cout<<"NO"<<endl;return 0;
                }
                else{
                    f=1;  // 标记发现第一块大陆
                    dfs(i,j);
                }
            }
        }
    }
    if(center==1 && fullcenter==1) cout<<"YES"<<endl;
    else return cout<<"NO"<<endl,0;
#ifdef LOCAL
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
    }
#endif
    return 0;
}