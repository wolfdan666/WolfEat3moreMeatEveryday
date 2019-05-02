class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>  ans;
        ans.insert(ans.end(),nums1.begin(), nums1.end());
        // ans.insert(ans.end(),nums1.begin(), nums1.end());
        ans.insert(ans.end(),nums2.begin(), nums2.end());
        int n = int(ans.size());
        sort(ans.begin(),ans.begin()+n);
        return n&1?ans[n/2]:(ans[n/2]+ans[n/2-1])/2.0;
    }
};

// 你可以假设 nums1 和 nums2 不会同时为空。。。。。 没有认真审题...

// 其实没有错，是自己沙雕用了复制粘贴！没改清楚出错了