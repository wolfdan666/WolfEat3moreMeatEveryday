/*
直接观察形态模拟就行2019年8月17日19:50:49 OK
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

vector<int> G[10];
int d[10], cnt[5];
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        for(int i = 1; i <= 6; i++) G[i].clear();
        memset(d, 0, sizeof(d));
        for(int i = 0; i < 5; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            d[u]++; d[v]++;
        }
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= 6; i++) {
            cnt[d[i]]++;
        }
        if(cnt[1] == 2 && cnt[2] == 4) printf("n-hexane\n");
        else if(cnt[1] == 4 && cnt[3] == 2) printf("2,3-dimethylbutane\n");
        else if(cnt[1] == 4 && cnt[2] == 1 && cnt[4] == 1) printf("2,2-dimethylbutane\n");
        else {
            int id;
            for(id = 1; id <= 6; id++) {
                if(d[id] == 3) break;
            }
            int x = 0, y = 0;
            for(int i = 0; i < G[id].size(); i++) {
                int v = G[id][i];
                if(d[v] == 1) x++;
                else if(d[v] == 2) y++;
            }
            if(x == 2) printf("2-methylpentane\n");
            else printf("3-methylpentane\n");
        }
    }

    return 0;
}