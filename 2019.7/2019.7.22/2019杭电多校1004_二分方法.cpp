#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const double eps = 1e-8;

int n;
int s[maxn], v[maxn], l[maxn];
double pos[maxn];

bool check(double x) {
    /*队友l_这里加上了s[0]的偏移量--> 其实用不用偏移量问题不大*/
    pos[n] = s[0]-s[n]+1.0*v[n]*x;
    /*再快也不能超过别人的车,所以min限制住*/
    for(int i = n-1; i >= 0; i--) pos[i] = min(pos[i+1]-l[i+1], s[0]-s[i]+1.0*v[i]*x);
    /*pos[0]此时是否过线*/
    return pos[0] >= double(s[0]+0.0);
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    while(~scanf("%d", &n)) {
        for(int i = 0; i <= n; i++) scanf("%d", &l[i]);
        for(int i = 0; i <= n; i++) scanf("%d", &s[i]);
        for(int i = 0; i <= n; i++) scanf("%d", &v[i]);
        double L = 0, R = s[0];
        while(R-L > eps) {
            double mid = (L+R)/2;
            if(check(mid)) R = mid;
            else L = mid;
        }
        printf("%.10f\n", L);
    }
    return 0;
}