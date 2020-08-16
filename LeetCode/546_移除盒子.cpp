// 2020年8月15日17:14:10 开始看题
// 1. 2020年8月15日17:16:17 感觉好像是每次都找最长连续的串
// 但是有反例 2 2 1 2 2 ，那种思路只能 9 ，然而 1 + 16 = 17
// 2. 暴力枚举肯定不行
// 3. 2020年8月15日17:19:36 去思考子状态
// 2020年8月15日17:48:29 中途有些事情，现在去看题解吧
// 2020年8月15日18:03:15 看完题解吃饭去

class Solution {
public:
    int dp[100][100][100];

    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof dp);
        return calculatePoints(boxes, 0, boxes.size() - 1, 0);
    }

    int calculatePoints(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] != 0) return dp[l][r][k];
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
};
