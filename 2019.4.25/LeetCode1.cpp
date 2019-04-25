// leetcode第一发  两数之和  感觉这个环境有点不熟悉

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> res;
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++) {
            mymap[nums[i]] = i;
        }

        int temp = 0, i = 0, j = 0;
        for (; i < nums.size(); i++) {
            temp = target - nums[i];
            unordered_map<int, int>::const_iterator got = mymap.find(temp);
            if (got == mymap.end()) { // not found
                continue;
            }
            else{
                j = got->second;
                if (j == i){ continue; }
                else{ break; }
            }
        }

        if (i < j) {
            res.push_back(i);
            res.push_back(j);
        }
        else {
            res.push_back(j);
            res.push_back(i);
        }
        return res;
    }
};