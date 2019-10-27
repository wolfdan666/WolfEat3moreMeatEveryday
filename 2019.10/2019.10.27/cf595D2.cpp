/*
没有太看懂题解...

2019年10月27日18:44:49 整理好状态然后重新开始看题解,加油!
2019年10月27日19:53:01 看懂了,形象得说,这个左端点就是右端点的指路人!太巧妙了!

晚上认真看都又看了1小时,我好菜啊!没事,继续加油吧

其实这个大概思路可以想出来,但是自己不会实现...所以还是要多练

2019年10月27日19:59:13 决定明天再自己写一遍,今天暂时没有时间了
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 200200;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> segs(n);
    vector<int> cnt(N);
    vector<vector<int>> ev(N);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].first >> segs[i].second;
        ++cnt[segs[i].first];
        --cnt[segs[i].second + 1];
        /*
        append to the array evli the index i that says us that in the point li the i-th segment is opened.
        And add to the evri+1 the index −i that says us that in the point ri+1 the i-th segment is closed.
        Note that you need to add 1-indexed values i because +0 and −0 are the same thing actually.
        */
        ev[segs[i].first].push_back(i + 1);
        ev[segs[i].second + 1].push_back(-i - 1);
    }

    for (int i = 0; i + 1 < N; ++i) {
        cnt[i + 1] += cnt[i];
    }

    vector<int> ans(n), sub(N);
    set<pair<int, int>> curSegs;
    int curSub = 0;
    for (int i = 0; i < N; ++i) {
        // curSub是当前已经减少的数
        // 然后sub是右端点已经减少的数,到达这个点之后,再右边的点就是不再减少的数了,所以说sub为负值
        curSub += sub[i];
        for (auto it : ev[i]) {
            // if是左端点.else是右端点,it-1减一是因为之前加了1,得到i,-it-1也是得到i
            if (it > 0) {
                // 如果是左端点,找到就插入它的右端点
                curSegs.insert(make_pair(segs[it - 1].second, it - 1));
            } else {
                // 找到了就搽除
                auto iter = curSegs.find(make_pair(segs[-it - 1].second, -it - 1));
                if (iter != curSegs.end()) curSegs.erase(iter);
            }
        }
        while (cnt[i] - curSub > k) {
            // 不为空不报错
            assert(!curSegs.empty());
            int pos = curSegs.rbegin()->second;
            // 搽除最右边的!
            curSegs.erase(prev(curSegs.end()));
            ++curSub;
            --sub[segs[pos].second + 1];
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