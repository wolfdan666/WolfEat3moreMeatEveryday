// 2019年6月10日22:53:24 开始看题目
// 冒泡排序--->用归并排序求出a的逆序数即可
// 有点尴尬归并排序和快排忘了怎么写了,马上复习一下
// 2019年6月10日23:15:55 AC 很慢！先回去洗澡吧

#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int const MAX = 500005;
int a[MAX], b[MAX], n;
ll ans;

void Merge(int l, int mid, int r){
    int i = l, j = mid + 1;
    // for(int k=1;k<=r;k++){
    for(int k=l;k<=r;k++){
        if(j>r || (i <= mid && a[i] <= a[j])) b[k]=a[i++];
        else b[k]=a[j++],ans += mid - i + 1;//因为左右区间都是有序的，因此a[i]>a[j]说明a[i]~a[mid]都大于a[j]
    }
    for(int k=l;k<=r;k++) a[k]=b[k];
    // for(int k=1;k<=r;k++) a[k]=b[k];
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
    while (scanf("%d", &n) != EOF && n) {
        ans = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        Merge_sort(1, n);
        printf("%lld\n", ans);
    }
}