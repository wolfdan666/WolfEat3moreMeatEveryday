/*
二分是O(nlog(n))
队友还有个O(n)的算法
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

int n;
char str[maxn];

bool check(int m) {
    int a = 0, b = 0;
    for(int i = 0; i < m; i++) {
        if(str[i] == '0') a++;
        else b++;
    }
    if(a == b) return true;
    for(int j = m; j < n; j++) {
        if(str[j-m] == '0') a--;
        else b--;
        if(str[j] == '0') a++;
        else b++;
        if(a == b) return true;
    }
    return false;
}

int main() {
    int ans1, ans2;
    scanf("%d%s", &n, str);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '0') a++;
        else b++;
    }
    ans2 = 2*min(a, b);
    int L = 0, R = n;
    while(L <= R) {
        int h = (L+R) >> 1;
        int m = h&1 ? h-1:h;
        if(check(m)) {
            ans1 = m;
            L = m+2;
        } else R = m-2;
    }
    printf("%d %d\n", ans1, ans2);

    return 0;
}


/*
ldm O(n) 算法--->和标程一样
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 5;

int n;
char str[maxn];
int sum[maxn], pos[maxn];


int main() {
    int ans1, ans2;
    scanf("%d%s", &n, str+1);
    int a = 0, b = 0;
    for(int i = 1; i <= n; i++) {
        if(str[i] == '0') a++;
        else b++;
    }
    ans2 = 2*min(a, b);
    int bs = 200000;
    sum[0] = bs;
    for(int i = 1; i <= n; i++) {
        if(str[i] == '0') sum[i] = sum[i-1] + 1;
        else sum[i] = sum[i-1] - 1;
    }
    for(int i = n; i >= 1; i--) {
        if(!pos[sum[i]]) pos[sum[i]] = i;
    }
    ans1 = 0;
    for(int i = 0; i <= n; i++) {
        ans1 = max(ans1, pos[sum[i]]-i);
    }

    printf("%d %d\n", ans1, ans2);

    return 0;
}