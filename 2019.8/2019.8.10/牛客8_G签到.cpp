#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

char str[maxn];
int stk[maxn], top;
int main() {
    scanf("%s", str);
    int len = strlen(str), ans = 0;
    for(int i = 0; i < len; i++) {
        if(top >= 2 && str[i] == stk[top] && str[i] == stk[top-1]) {
            ans++;
            top -= 2;
            continue;
        }
        stk[++top] = (int)str[i];
    }
    while(top >= 3 && stk[top] == stk[top-1] && stk[top-1] == stk[top-2]) {
        top -= 3;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}