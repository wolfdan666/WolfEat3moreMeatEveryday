// 一个橙名大佬的code
// 这种题目一般有套路，没学过，所以看别人code

// 自己看了好久好久才看懂，其实就是有技巧的暴力模拟求解，考虑去除2人后的维护最大值

#include <cstdio>
int c[5010], s[5010], l[5010], r[5010];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &l[i], &r[i]);
        --l[i];   // 是为了后面的前缀和
        for (int j = l[i]; j < r[i]; j++) {
            c[j]++;    // 第j块被涂到的次数(留意l[i])
        }
    }
    int ans = 0;
    for (int i = 0; i < q; i++) {
        for (int j = l[i]; j < r[i]; j++) {  // 先去掉某一个人
            c[j]--;
        }
        int t = 0;
        for (int j = 0; j < n; j++) {
            s[j+1] = s[j] + (c[j] == 1); // s[]数组是去掉一个人后不能在再去掉的地方的   前缀和
            t += c[j] > 0;  // t是记录去掉一个人后的总的被粉刷的量值
        }
        for (int j = 0; j < q; j++) {   // 这里是去掉当前的一个人后，考虑再去掉一个人后能得到的最优解k   然后再与总的最优解比较
            if (i == j) continue;
            int k = t - s[r[j]] + s[l[j]];  // 去掉当前人后，总粉刷量-考虑再去除人的核心贡献量(没了他就会少值)=少了他还剩多少
            if (ans < k) ans = k;
        }
        for (int j = l[i]; j < r[i]; j++) {
            c[j]++;
        }
    }
    printf("%d\n", ans);
    return 0;
}