//
// Created by bas on 9/30/21.
//

#ifndef ALGRITHOM_78SUBSETS_H
#define ALGRITHOM_78SUBSETS_H
//Method 1 ForceRecursive
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        process(0, tmp, nums, res);
        return res;
    }
private:
    //函数返回类型为 void，不用管理返回值的递归
    void process(int i, vector<int>& tmp, vector<int>&nums, vector<vector<int>>& res) {
        if (i == nums.size()) {//base case
            res.push_back(tmp);
            return;
        } else {
            tmp.push_back(nums[i]);//i从0开始
            process(i + 1, tmp, nums, res);
            tmp.pop_back();
            process(i + 1, tmp, nums, res);
        }
    }
};

//Method 2 BackTracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtracking(res, nums, tmp, 0);
        return res;
    }
private:
    void backtracking(vector<vector<int>>&res, vector<int>& nums, vector<int>& tmp, int i) {
        res.push_back(tmp);
        if (i == nums.size()) {
            return;
        }
        for (int j = i; j < nums.size(); j++) {//横向遍历
            tmp.push_back(nums[j]);
            backtracking(res, nums, tmp, j + 1);//深向递归
            tmp.pop_back();
        }
    }
};
#endif //ALGRITHOM_78SUBSETS_H
