#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 50;
int d[M][M];
int a[M],b[M];
int cnt1,cnt2;
ll ans;int N;

void dfs(int cur,ll val){
    /*当达到2*N+1的时候,正好已经插入了2*N个人了,所以开始比较*/
    if(cur>2*N){ ans = max(ans,val);return ;}
    if(cnt1<N){
        a[cnt1++]=cur;
        ll tmp = 0;
        /*每次加入了cnt1之后,就要把左边队伍新加人与对面队伍当下所有人产生的竞争值加入左边队伍*/
        for(int i=0;i<cnt2;i++) tmp+=d[cur][b[i]];
        dfs(cur+1,val+tmp);
        /*上面的遍历return之后要恢复现场,即之前产生的影响要消除掉,避免对后面的操作有影响*/
        cnt1--;
    }
    if(cnt2<N){
        b[cnt2++]=cur;
        ll tmp = 0;
        /*每次加入了cnt2之后,就要把右边队伍新加人与对面队伍当下所有人产生的竞争值加入右边队伍*/
        for(int i=0;i<cnt1;i++) tmp+=d[a[i]][cur];
        dfs(cur+1,val+tmp);
        cnt2--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=2*N;i++)
        for(int j=1;j<=2*N;j++)
            cin>>d[i][j];
    ans = 0;
    /*像一颗树一样遍历下去,然后到达叶子的时候进行比较出最大值再返回*/
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}