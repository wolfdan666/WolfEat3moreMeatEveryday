/*2019年7月20日15:12:42  看看队友的代码为什么wa了
2019年7月20日15:22:33 看了队友的思路，感觉是对的O(n^2+n)-->O(n^2)
2019年7月20日16:01:11 又一次帮队友debug成功AC,开心 --> 牛客一二场因为自己太菜想题想不出...只能尽力发挥点作用，就是认真debug..

第一场也是debug的单调栈的题目


想想直接暴力枚举的复杂度
- 从最大矩形 -> 缩行or缩列 2种选择,每种选择遍历一下...必然超时.. ---> O(m*n*2^min(n,m))
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;

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
                ans.push_back(stk[top] * cnt);
                top--;
            }
            while(cnt--) stk[++top] = f[i];
            stk[++top] = f[i];
        }
    }
    int cnt = 1;
    while(top) {
        ans.push_back(stk[top] * cnt);
        top--;
        cnt++;
    }
}

int main() {
    char str[maxn];
    while(~scanf("%d%d", &n, &m)) {
        /* init */
        ans.clear();

        for(int i = 1; i <= n; i++) {
            scanf("%s", str);
            for(int j = 0; j < m; j++) mp[i][j+1] = str[j]-'0';
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
        else printf("%d\n", ans[sz-2]);
    }

    return 0;
}