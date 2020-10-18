// 2019年7月7日19:52:50 开始补题
/*
看完题目发现这题  好像是  在<算法竞赛进阶指南>里面有讲过类似题... 没找到
2019年7月7日20:01:46 GG 去看题解
尴尬，发现确实只要瞎暴力就行！... mdzz
 */

#include <iostream>
using namespace std;

int main(){
    int a[105], n, i, cnt, sum;
    while (cin >> n) {
        cnt = 0;
        sum = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            sum = sum + a[i];
        }
        sum = sum / n;
        for (i = 0; i < n; i++) {
            if (a[i] > sum) {
                a[i + 1] = a[i + 1] + (a[i] - sum);
                cnt++;
            } else {
                if (a[i] < sum) {
                    a[i + 1] = a[i + 1] - (sum - a[i]);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}