// 2019年6月11日12:34:22 开始看题
// 2019年6月11日12:47:06 13mins才看完(中途浪了)
// 直接看大佬思路，因为自己暂时还不清楚

// 自己不会用bit求逆序数,暂时不想看这个,树状数组也暂时不会,所以先用归并排序先


/*
某状态的奇偶性定义为逆序对(不包括0的)总数的奇偶性。 此题目终态为偶数
首先，0的左右移动不改变奇偶性；然后是0的上下移动，如下：
————-------0***********
***********x————-------
x是任意数，现在要把x移上去，那么***********中，假设有a个大于x，b个小于x，那么移动之后逆序数就会加上一个b-a，x所能影响的也就是这些，除此之外，其他都不变。
接着，如果列数为偶数，那么***********的个数就是奇数，b,a奇偶性互异，b-a为奇数，所以移动一次后，原序列的逆序数的奇偶性变了。考虑到最后0会移动到最后一行，所以奇偶性会改变n-i次(i为0的行数)，只需判断最后是否是偶数即可。
反之，如果列数为奇数，那么***********的个数就是偶数，b,a奇偶性相同，b-a为偶数，所以移动一次后，原序列的逆序数的奇偶性没变。因为无论怎么移，奇偶性都不变，所以说一开始初态的奇偶性就必须与末态一致
所以得出如下结论:
n为奇数，0上下移动不改变奇偶性，故逆序数为偶的YES ----(因为最终逆序数也是偶数 0 )
n为偶数，0上下移动逆序数变化为±1，此时还要考虑0的竖直距离，逆序数%2 == 距离%2 时YES(就是逆序数为奇,那么改变次数也必须为奇,使得最终逆序数也是偶数 0 (逆序数为偶同理))
---------------------
作者：v5zsq
原文：https://blog.csdn.net/V5ZSQ/article/details/46843981
*/


// 方法一:bit求逆序数
// #include <stdio.h>
// #include <string.h>
// #define maxn 1000001
// int m, n, a[maxn], b[maxn], k;

// void add(int i){
//     while (i <= k) {
//         b[i]++;
//         i += i & -i;
//     }
// }

// int sum(int i){
//     int res = 0;
//     while (i > 0) {
//         res += b[i];
//         i -= i & -i;
//     }
//     return res;
// }

// int solve(){
//     int res = 0;
//     for (int i = 0; i < k; i++) {
//         add(a[i]);
//         res += i + 1 - sum(a[i]);
//     }
//     return res;
// }

// int main(){
//     while (scanf("%d%d", &m, &n), m) {
//         memset(b, 0, sizeof(b)); //初始化
//         int d, step;
//         k = 0;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++) {
//                 scanf("%d", &d);
//                 if (d == 0) //逆序数要考虑0的竖直位置
//                     step = (m-1) - i;
//                 else
//                     a[k++] = d;
//             }
//         int ans = solve(); //BIT求逆序对数
//         if (n & 1) //n为奇数时不需要考虑0的竖直位置
//             step = 0;
//         printf(step % 2 == ans % 2 ? "YES\n" : "NO\n");
//     }
//     return 0;
// }


// 方法二:归并求逆序数
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 1000001
int m, n, a[maxn], b[maxn], ans, k;

void Merge(int l, int mid, int r){
    int i = l, j = mid + 1;
    for(int k=l;k<=r;k++){
        if(j>r || (i <= mid && a[i] <= a[j])) b[k]=a[i++];
        else b[k]=a[j++],ans += mid - i + 1;//因为左右区间都是有序的，因此a[i]>a[j]说明a[i]~a[mid]都大于a[j]
    }
    for(int k=l;k<=r;k++) a[k]=b[k];
    return;
}

void Merge_sort(int l, int r){
    if (l < r) {
        int mid = (l + r) / 2;
        Merge_sort(l, mid);
        Merge_sort(mid + 1, r);
        Merge(l, mid, r);
    }
    return;
}

int main(){
    while (scanf("%d%d", &m, &n), m) {
        int d, step;
        k = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                scanf("%d", &d);
                if (d == 0) //逆序数要考虑0的竖直位置
                    step = m - i;
                else
                    a[++k] = d;
                    // a[k++] = d;  // 这里一开错了，导致逆序数算错了
            }

        ans = 0;
        Merge_sort(1,k); //BIT求逆序对数
        // cout<<"ans:"<<ans<<endl;
        if (n & 1) //n为奇数时不需要考虑0的竖直位置
            step = 0;
        printf(step % 2 == ans % 2 ? "YES\n" : "NO\n");
    }
    return 0;
}


// 方法三:树状数组求逆序数