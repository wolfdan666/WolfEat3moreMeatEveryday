#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

char str[maxn], s[27];
int main() {
    int kase = 0;
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s%s", str, s);
        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            str[i] = s[str[i]-'a'];
        }
        printf("Case #%d: ", ++kase);
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < len; i++) {
            if(str[i] == 'd') a++;
            else if(str[i] == 'w') b++;
            else c++;
        }
        if(c*4 >= len) {
            printf("Harmful\n");
            continue;
        }
        if(c*10 <= len) {
            printf("Recyclable\n");
            continue;
        }
        if(a >= 2*b) {
            printf("Dry\n");
            continue;
        }
        else printf("Wet\n");
    }
    return 0;
}