//
// Created by bas on 9/23/21.
//

#ifndef ALGRITHOM_FINDMAXAVERAGE_H
#define ALGRITHOM_FINDMAXAVERAGE_H

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, res = -DBL_MAX;
        int l = 0;//左窗口
        for(int r = 0; r < nums.size(); r++){//右窗口移动
            sum += nums[r];
            if(r - l + 1 == k) res = max(sum / k, res);
            if(r >= k - 1) sum -= nums[l++];//左窗口移动
        }
        return res;
    }
};

#endif //ALGRITHOM_FINDMAXAVERAGE_H
