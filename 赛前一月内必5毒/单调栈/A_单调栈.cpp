#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;
struct node { int id; int val; };
int a[maxn], b[maxn];
int l1[maxn], l2[maxn];
node s[maxn];
int n;

/* L是输出端，然后s是辅助数组,c是源数组 */
void solve(int* c, int* L) {
    int top = 0;
    s[0] = node{0, 0};
    for(int i = 1; i <= n; i++) {
        /*找到向左走第一个比它小的数 */
        while(top && s[top].val >= c[i]) top--;
        L[i] = s[top].id;
        s[++top] = node{i, c[i]};
    }
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        solve(a, l1); solve(b, l2);
        int ans = n;
        for(int i = 1; i <= n; i++) {
            if(l1[i] != l2[i]) {
                ans = i-1;
                // ans = n-1;
                break;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}