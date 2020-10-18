#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

int main() {
    int T; scanf("%d", &T);
    int x1, x2, y1, y2, x3, x4, y3, y4;
    while(T--) {
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        if(x1 == x3 && x2 == x4 && y1 == y3 && y2 == y4) printf("2\n");
        else {
            if(x1 > x3) {
                swap(x1, x3); swap(x2, x4); swap(y1, y3); swap(y2, y4);
            }
            int ans;
            if(x3 < x2 && (y3 < y2 && y4 > y1)) {
                if(x4 > x2) {
                    if(y3 < y1 && y2 < y4) {
                        if(x1 == x3) ans = 3;
                        else ans = 4;
                    }
                    else if((y3 == y1 && y2 < y4) || (y3 < y1 && y2 == y4)) {
                        if(x1 == x3) ans = 3;
                        else ans = 4;
                    }
                    else if((y3 == y1 && y4 < y2) || (y3 > y1 && y2 == y4)) {
                        ans = 4;
                    }
                    else if((y1 < y3 && y3 < y2 && y2 < y4) || (y3 < y1 && y1 < y4 && y4 < y2)) {
                        ans = 4;
                    }
                    else if(y3 == y1 && y2 == y4) {
                        if(x1 == x3) ans = 3;
                        else ans = 4;
                    }
                    else if(y1 < y3 && y4 < y2) {
                        if(x1 == x3) ans = 5;
                        else ans = 4;
                    }
                }
                else if(x4 == x2) {
                    if(y3 < y1 && y2 < y4) {
                        if(x1 == x3) ans = 4;
                        else ans = 5;
                    }
                    else if((y3 == y1 && y2 < y4) || (y3 < y1 && y2 == y4)) {
                        if(x1 == x3) ans = 3;
                        else ans = 4;
                    }
                    else if((y3 == y1 && y4 < y2) || (y3 > y1 && y2 == y4)) {
                        ans = 3;
                    }
                    else if((y1 < y3 && y3 < y2 && y2 < y4) || (y3 < y1 && y1 < y4 && y4 < y2)) {
                        ans = 4;
                    }
                    else if(y3 == y1 && y2 == y4) {
                        if(x1 == x3) ans = 2;
                        else ans = 3;
                    }
                    else if(y1 < y3 && y4 < y2) {
                        if(x1 == x3) ans = 4;
                        else ans = 3;
                    }
                }
                else {
                    if(y3 < y1 && y2 < y4) {
                        if(x1 == x3) ans = 5;
                        else ans = 6;
                    }
                    else if((y3 == y1 && y2 < y4) || (y3 < y1 && y2 == y4)) {
                        if(x1 == x3) ans = 4;
                        else ans = 5;
                    }
                    else if((y3 == y1 && y4 < y2) || (y3 > y1 && y2 == y4)) {
                        ans = 3;
                    }
                    else if((y1 < y3 && y3 < y2 && y2 < y4) || (y3 < y1 && y1 < y4 && y4 < y2)) {
                        ans = 4;
                    }
                    else if(y3 == y1 && y2 == y4) {
                        if(x1 == x3) ans = 3;
                        else ans = 4;
                    }
                    else if(y1 < y3 && y4 < y2) {
                        ans = 3;
                    }
                }
                printf("%d\n", ans);
            }
            else printf("3\n");
        }
    }

    return 0;
}