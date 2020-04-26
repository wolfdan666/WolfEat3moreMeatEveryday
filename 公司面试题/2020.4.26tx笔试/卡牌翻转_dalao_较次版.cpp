// 作者：Boomboy
// 链接：https://www.nowcoder.com/discuss/417907?type=post&order=time&pos=&page=1&channel=
// 来源：牛客网


/*
这个人的方法有点激进，激进地认为所有的都有解...所以还是冒泡排序的思路好一点

*/

#include <iostream>
#include <vector>
using namespace std;
int Min_Ope(vector<int>& va, vector<int>& vb, int n) {
    int ret = 0;
    while (true) {
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (va[i] > va[i + 1]) {
                swap(va[i], va[i + 1]);
                swap(vb[i], vb[i + 1]);
                swap(va[i], vb[i]);
                swap(va[i + 1], vb[i + 1]);
                ret++;
                flag = true;
            }
            if (i == n - 2) break;
        }
        if (flag == false) break;
    }
    return ret;
}
int main() {
    int n;
    while (cin >> n) {
        vector<int> va(n);
        vector<int> vb(n);
        for (int i = 0; i < n; i++) cin >> va[i];
        for (int i = 0; i < n; i++) cin >> vb[i];
        cout << Min_Ope(va, vb, n) << endl;
    }
    return 0;
}