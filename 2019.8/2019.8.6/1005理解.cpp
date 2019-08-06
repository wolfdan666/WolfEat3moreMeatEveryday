#include <cstdio>
#include <algorithm>
const int SIZE = 50;
int n, k;
int d[SIZE], u[SIZE];
// ????????????????????????????????
bool dfs(int id, int low, int hi)
{
    if (id == n)
    {
        k--;
        if (!k)
        {
            for (int i = 0; i < n; i++)
            {
                if (i)
                    printf(" ");
                printf("%d", d[i] - low + 1);
            }
            puts("");
            return 1;
        }
        return 0;
    }
    for (int i = hi - n + 1; i <= low + n - 1; i++)
    {
        if (u[i])
            continue;
        u[i] = 1;
        d[id] = i;
        if (dfs(id + 1, std::min(low, i), std::max(hi, i)))
        {
            u[i] = 0;
            return 1;
        }
        u[i] = 0;
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        d[0] = n;
        u[n] = 1;
        dfs(1, n, n);
        u[n] = 0;
    }
    return 0;
}