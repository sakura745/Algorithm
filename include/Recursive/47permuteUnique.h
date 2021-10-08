//
// Created by bas on 9/30/21.
//

#ifndef ALGRITHOM_47PERMUTEUNIQUE_H
#define ALGRITHOM_47PERMUTEUNIQUE_H

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        process(nums, 0, res);
        return res;
    }
private:
    void process(vector<int>&nums, int i, vector<vector<int>>&res) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }
        bool isValid[20] = {false};//自定义一个检验是否重复的数组 20:因为题目所给的数组值的范围为-10~10
        for (int j = i; j < nums.size(); j++) {
            if (!isValid[nums[j] + 10]) {//因为题目所给的数组值的范围为-10~10
                isValid[nums[j] + 10] = true;
                swap(nums[i], nums[j]);
                process(nums, i + 1, res);
                swap(nums[i], nums[j]);
            }
        }
    }
};
#endif //ALGRITHOM_47PERMUTEUNIQUE_H
