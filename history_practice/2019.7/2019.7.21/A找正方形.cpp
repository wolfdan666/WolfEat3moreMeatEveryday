#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 300 + 5;

int n, m;
int mp[maxn][maxn], dp[maxn][maxn];
int stk[maxn];
vector<int> ans;

void solve(int* f) {
    int top = 0;
    //init
    stk[top] = 0;

    // f[m+1] = 0就可以不用下面的while操作
    for(int i = 1; i <= m; i++) {
        if(!top || stk[top] <= f[i]) stk[++top] = f[i];
        else {
            int cnt = 0;
            /*然后这里可以写宽度进行优化*/
            while(top && stk[top] > f[i]) {
                cnt++;
                if(cnt==stk[top]) ans.push_back(stk[top] * cnt);
                top--;
            }
            while(cnt--) stk[++top] = f[i];
            stk[++top] = f[i];
        }
    }
    int cnt = 1;
    while(top) {
        if(cnt==stk[top]) ans.push_back(stk[top] * cnt);
        top--;
        cnt++;
    }
}

int main() {
    char str[maxn];
    int T;
    cin>>T;
    while(T--){
        scanf("%d%d", &n, &m);
        /* init */
        ans.clear();

        for(int i = 1; i <= n; i++) {
            scanf("%s", str);
            for(int j = 0; j < m; j++)  mp[i][j+1] = str[j]=='.'?1:0;
        }
        memset(dp, 0, sizeof(dp));
        /*先对于每一列进行横向扫描---> (此时每一行的长度就相当于高度值)再纵向使用单调栈，对啊！*/
        /*但是这里每一行的跌列的层数可能会中断...所以还是有问题*/
        for(int j = 1; j <= m; j++) {
            for(int i = 1; i <= n; i++) {
                /*没有看清楚，原来队友叠加的是每一列的行深...但是中途会有断层怎么解决...先想想*/
                if(mp[i][j]) dp[i][j] = dp[i-1][j] + 1;
                // if(mp[i][j]) dp[i][j] = dp[i][j-1] + 1;
            }
        }
        // 所以每一行都用了一次solve来解决断层问题
        // for(int i = 1;i<=n;i++) {for(int j=1;j<=m;j++) cout<<dp[i][j]; cout<<endl;} cout<<endl;
        for(int i = 1; i <= n; i++) solve(dp[i]);
        sort(ans.begin(), ans.end());
        int sz = ans.size();
        if(sz <= 1) printf("0\n");
        else printf("%d\n", ans[sz-1]);
    }


    return 0;
}