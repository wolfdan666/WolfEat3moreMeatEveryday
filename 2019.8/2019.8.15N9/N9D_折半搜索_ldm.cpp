#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6;

struct node {
    ll v;
    int id;
    bool operator < (const node& r) const { return v < r.v; }
}b[maxn];
ll arr[40];
ll a[maxn], c[maxn];
int main() {
    int n; ll sum;
    scanf("%d%lld", &n, &sum);
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    int x = n/2, y = n-x;
    int up1 = (1<<x), up2 = (1<<y);
    /*全0到全1串的遍历，然后之后是对每个串的逐位遍历，记录此串的和值*/
    for(int i = 0; i < up1; i++) {
        for(int j = 0; j < x; j++) {
            if(i & (1<<j)) a[i] += arr[j];
        }
    }
    for(int i = 0; i < up2; i++) {
        b[i].id = i; b[i].v = 0;
        for(int j = 0; j < y; j++) {
            if(i & (1<<j)) b[i].v += arr[x+j];
        }
    }
    /*让B[i]数组有序，然后使用lower_bound去搜索*/
    sort(b, b+up2);
    for(int i = 0; i < up2; i++) c[i] = b[i].v;
    /*这里复杂度是2^18*log(2^18) = 4.7*10^6左右*/
    for(int i = 0; i < up1; i++) {
        int p = lower_bound(c, c+up2, sum-a[i])-c;
        if(c[p]+a[i] == sum) {
            for(int j = 0; j < x; j++) {
                if(i & (1<<j)) printf("1");
                else printf("0");
            }
            int id = b[p].id;
            for(int j = 0; j < y; j++) {
                if(id & (1<<j)) printf("1");
                else printf("0");
            }
            break;
        }
    }

    return 0;
}