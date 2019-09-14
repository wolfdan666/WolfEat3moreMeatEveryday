// 2019年3月5日20:27:45 开始专注做

// 2019年3月5日22:10:44 用vscode探讨了别人的答案许久，总算明白了，GG
#include<bits/stdc++.h>
using namespace std;
int a[1024], b[1024];
bool ok[1024];

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    int tp = 0;
    set<int> p;
    int q = 0, m = 0;
    for (int t = 0; p.size() || tp < n; t++)
    {
        while (int(p.size()) < k && tp < n)
            p.insert(tp++);
        for (auto it = p.begin(); it != p.end();)
        {
            int x = *it;
            if (++b[x] == a[x])// 维护最小的先出去
                p.erase(it++), m++;
            else
                it++;
            ok[x] |= b[x] == q;
        }
        q = 100. * m / n + 0.5;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += ok[i];
    cout << ans << endl;
    return 0;
}