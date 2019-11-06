/*
就用全排列的匹配啊

*/


#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 7;
char s[maxn];
int vis[10][30];
char a[] = "harbin";

void solve() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 6; i++) {
        scanf("%s", s);
        int st = strlen(s);
        for (int j = 0; j < st; j++) vis[i][s[j] - 'a'] = 1;
    }
    bool ff = false;
    sort(a, a + 6);
    do {
        bool flag = true;
        for (int i = 0; i < 6; i++)
            if (!vis[i][a[i] - 'a']) {
                flag = false;
                break;
            }
        if (flag) {
            ff = true;
            break;
        }
    } while (next_permutation(a, a + 6));
    if (ff) printf("Yes\n");
    else printf("No\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();

    return 0;
}