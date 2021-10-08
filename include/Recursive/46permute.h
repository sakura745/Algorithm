//
// Created by bas on 9/30/21.
//

#ifndef ALGRITHOM_46PERMUTE_H
#define ALGRITHOM_46PERMUTE_H

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        process(nums, 0, res);
        return res;
    }
private:
    void process(vector<int>&nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            process(nums, i + 1, res);
            swap(nums[i], nums[j]);//backtracking
        }
    }
};

#endif //ALGRITHOM_46PERMUTE_H
