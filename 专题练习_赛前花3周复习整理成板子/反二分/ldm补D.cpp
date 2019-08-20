#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;

int n, k, a[maxn];
multiset<int> st;
multiset<int>::iterator it;

bool check(int mid) {
    for(int i = 0; i < k; i++) {
        int v = mid;
        while(v) {
            if(st.size() == 0) return true;
            it = st.upper_bound(v);
            if(it == st.begin()) break;
            it--;
            v -= *it;
            st.erase(it);
        }
    }
    return st.size() == 0;
}

int main() {
    int T; scanf("%d", &T);
    int kase = 0;
    while(T--) {
        scanf("%d%d", &n, &k);
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for(int i = sum/k; ; i++) {
            st.clear();
            for(int j = 1; j <= n; j++) st.insert(a[j]);
            if(check(i)) {
                printf("Case #%d: %d\n", ++kase, i);
                break;
            }
        }
    }

    return 0;
}