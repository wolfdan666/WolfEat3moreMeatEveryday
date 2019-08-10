/*
这里应该不是单调栈...
00111
00111
00111
如果枚举每一行的话，会得到按ans=3,其实ans=1!

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 5;

int mp[maxn][maxn], cnt[maxn][maxn];
int L[maxn][maxn], R[maxn][maxn];
int LL[maxn][maxn], RR[maxn][maxn];
struct node { int id, v; } stk[maxn];
char str[maxn];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", str);
        for(int j = 1; j <= m; j++) {
            mp[i][j] = str[j-1]-'0';
            //scanf("%d", &mp[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mp[i][j]) cnt[i][j] = cnt[i-1][j] + 1;
            else cnt[i][j] = 0;
        }
    }
    int top;
    for(int i = 1; i <= n; i++) {
        top = 0; stk[0] = node{0, -1};
        LL[i][0] = 0; RR[i][m+1] = m+1;
        for(int j = 1; j <= m; j++) {
            while(top && stk[top].v >= cnt[i][j]) top--;
            L[i][j] = stk[top].id;
            stk[++top] = node{j, cnt[i][j]};
            if(i == n || mp[i+1][j] == 0) LL[i][j] = j;
            else LL[i][j] = LL[i][j-1];
        }
        top = 0; stk[0] = node{n+1, -1};
        for(int j = m; j >= 1; j--) {
            while(top && stk[top].v >= cnt[i][j]) top--;
            R[i][j] = stk[top].id;
            stk[++top] = node{j, cnt[i][j]};
            if(i == n || mp[i+1][j] == 0) RR[i][j] = j;
            else RR[i][j] = RR[i][j+1];
        }
    }
    int ans = 0, flag;
    for(int i = 1; i <= n; i++) {
        flag = 0;
        for(int j = 1; j <= m; j++) {
            //printf("%d %d %d %d %d %d %d\n", i, j, cnt[i][j], LL[i][j], RR[i][j], L[i][j], R[i][j]);
            if(cnt[i][j] != cnt[i][j-1]) flag = 1;
            if((cnt[i][j] == cnt[i][j-1] && flag) || cnt[i][j] == 0) continue;
            if(LL[i][j] > L[i][j] || RR[i][j] < R[i][j]) ans++;
            else flag = 0;
        }
    }

    printf("%d\n", ans);

    return 0;
}