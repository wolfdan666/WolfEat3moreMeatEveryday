/*
2019年10月27日14:22:17 再看题解
感觉题解的想法确实和我的差不多,但是我不会写...

2019年10月27日14:31:37 那就学习别人怎么写吧

学了,其实很简单,但是自己太菜不会写,所以自己去写一遍

2019年10月27日15:52:47 结果写了50mins,还是写不对,没事,再去尝试
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 250;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> segs(n);
    vector<int> cnt(N);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].first >> segs[i].second;
        ++cnt[segs[i].first];
        --cnt[segs[i].second + 1];
    }

    for (int i = 0; i + 1 < N; ++i) {
        cnt[i + 1] += cnt[i];
    }

    vector<int> ans(n);
    for (int i = 0; i < N; ++i) {
        while (cnt[i] > k) {
            int pos = -1;
            // 找到最右位置
            for (int p = 0; p < n; ++p) {
                if (!ans[p] && (segs[p].first <= i && i <= segs[p].second) && (pos == -1 || segs[p].second > segs[pos].second)) {
                    pos = p;
                }
            }
            assert(pos != -1);
            for (int j = segs[pos].first; j <= segs[pos].second; ++j) {
                --cnt[j];
            }
            ans[pos] = 1;
        }
    }

    cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    for (int i = 0; i < n; ++i) {
        if (ans[i]) cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}