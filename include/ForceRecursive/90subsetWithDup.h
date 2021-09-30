//
// Created by bas on 9/30/21.
//

#ifndef ALGRITHOM_90SUBSETWITHDUP_H
#define ALGRITHOM_90SUBSETWITHDUP_H
//Method 1 BackTracking
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());//排序是为了将重复的放到一起
        backtracking(0, tmp, nums, res);
        return res;
    }
private:
    void backtracking(int i, vector<int>&tmp, vector<int>&nums, vector<vector<int>>&res) {
        res.push_back(tmp);
        if (i == nums.size()) {
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j - 1]) {//j>i而不是j>0
                continue;
            }
            tmp.push_back(nums[j]);
            backtracking(j + 1, tmp, nums, res);
            tmp.pop_back();
        }
    }
};


#endif //ALGRITHOM_90SUBSETWITHDUP_H
