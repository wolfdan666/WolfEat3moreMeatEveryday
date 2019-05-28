#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxarea = 0,l = 0, r = int(height.size()) - 1;
        while (l < r) {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};

int main(int argc, char const* argv[])
{
    Solution solve;
    vector<int> a={1,8,6,2,5,4,8,3,7};
    cout << solve.maxArea(a)<< endl;
    return 0;
}