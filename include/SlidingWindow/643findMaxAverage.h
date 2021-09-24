//
// Created by bas on 9/23/21.
//

#ifndef ALGRITHOM_FINDMAXAVERAGE_H
#define ALGRITHOM_FINDMAXAVERAGE_H

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -DBL_MAX, sum = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            if(r - l + 1 == k){
                res = max(res, sum / k);
                sum -= nums[l++];
            }
        }
        return res;
    }
};

#endif //ALGRITHOM_FINDMAXAVERAGE_H
