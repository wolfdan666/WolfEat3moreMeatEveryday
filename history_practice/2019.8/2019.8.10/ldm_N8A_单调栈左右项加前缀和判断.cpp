#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 5;
#define mk make_pair

int mp[maxn][maxn], cnt[maxn][maxn];
int L[maxn][maxn], R[maxn][maxn];
int sum[maxn][maxn];
int stk[maxn];
char str[maxn];
vector<pair<pair<int, int>, pair<int, int>> > ans;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", str);
        for(int j = 1; j <= m; j++) {
            mp[i][j] = str[j-1]-'0';
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mp[i][j]) cnt[i][j] = cnt[i-1][j] + 1;
            else cnt[i][j] = 0;
            sum[i][j] = sum[i][j-1] + mp[i][j];
        }
        sum[i][m+1] = sum[i][m] + 1;
        cnt[i][m+1] = 0;
    }
    int top;
    for(int i = 1; i <= n; i++) {
        top = 0; stk[top] = 0;
        for(int j = 1; j <= m; j++) {
            /*记录左边下标*/
            while(top && cnt[i][stk[top]] >= cnt[i][j]) top--;
            L[i][j] = stk[top]+1;
            stk[++top] = j;
        }
        top = 0; stk[top] = m+1;
        for(int j = m; j >= 1; j--) {
            /*记录右边下标*/
            while(top && cnt[i][stk[top]] >= cnt[i][j]) top--;
            R[i][j] = stk[top]-1;
            stk[++top] = j;
        }
        for(int j = 1; j <= m; j++) {
            if(cnt[i][j] == 0) continue;
            int l = L[i][j], r = R[i][j], h = cnt[i][j];
            /*检测左右的下标没有和下面的地方重合*/
            if(i == n || sum[i+1][r]-sum[i+1][l-1] != r-l+1) {
                ans.push_back(mk(mk(i-h+1, l), mk(i, r)));
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    printf("%d\n", ans.size());

    return 0;
}