// 2019年4月2日20:15:23 开始看题
// 1-n的无环树，root 的 parent 是 -1
// 给pi 和 ci(1表示尊敬parents吗)
// 用pi串起来tree，然后遍历查找  不尊上，且下无尊  的最小节点
// GG,2019年4月2日21:19:00，写了一个小时，发现自己的dfs还是没有考虑清楚，看tutorial吧,没考虑尊重父亲的子孙也可能不尊重父亲
// 而且可以直接用一个数组存ans，sort一下就行，自己真他妈智障了，看了别人写得超级简洁，自己就更加哭了，我太菜了！绝了
// 2019年4月2日21:42:12  今天90mins，先这样，明天再加油搞extend kmp吧，然后每天必须保证90mins以上，然后暑假天天魔鬼训练
// 然后也把lu的dfs看了一下
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;

struct P{
    int p;
    bool c;
    vector<int> s;
} a[N];

int dfs(int r,int ans){// 终止条件是没有找到满足的，找到满足的就记下最小值，可以一次性完成吗？不尊重父母，应该也不会尊敬爷爷奶奶，所以不能一次完成
    if(!a[r].c) return 0; // 尊敬父亲// 没有孩子a[r].s.empty()||(看样例1发现不考虑这个)
    else{// 已经是有孩子以及不尊重父亲了
        int siz = (int)a[r].s.size();
        int f=1;
        for(int i=0;i<siz;i++){
            int t=a[a[r].s[i]];
            if(!t.c) f=0;
            else{// 不尊父的要继续dfs
                int k = dfs(t);
                if(!k)
                    ans=min(ans,k);
            }
        }
        if(f){

        }
    }

}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n;int root;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].p>>a[i].c;
        a[a[i].p].s.push_back(i);// 所以小的总是先放入
        if(~a[i].p) root=i;
    }
    int ans=0x3f3f3f3f;
    if(dfs(root,ans)){
        cout<<ans;
        while(dfs(root,ans)) {
            cout<<' '<<ans;
        }
        cout<<endl;
    }
    else puts("-1");
    return 0;
}


#include<bits/stdc++.h>
#define N 200100
using namespace std;
int n,can[N],P;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)can[i]=1;
    for(int i=1;i<=n;++i){
        int p,c;scanf("%d %d",&p,&c);
        if(c==0){// 尊敬父母，父母就不能删,他也不能删
            if(p>=0)can[p]=0;can[i]=0;
        }
    }
    for(int i=1;i<=n;++i)if(can[i])printf("%d ",i),P=1;
    if(!P) printf("-1");
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

int p[maxn], e[maxn];
int ans[maxn], cnt;
vector<int> G[maxn];

void dfs(int u) {
    int flag = 1;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(e[v] == 0) flag = 0;
        dfs(v);
    }
    if(flag && e[u]) ans[cnt++] = u;
}

int main() {
    int n, root;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i], &e[i]);
        if(p[i] == -1) root = i;
        if(p[i] != -1) G[p[i]].push_back(i);
    }
    dfs(root);
    if(cnt == 0) printf("-1\n");
    else {
        sort(ans, ans+cnt);
        for(int i = 0; i < cnt; i++)
            printf("%d ", ans[i]);
        puts("");
    }

    return 0;
}