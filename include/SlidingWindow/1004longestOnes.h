//
// Created by bas on 9/24/21.
//

#ifndef ALGRITHOM_1004LONGESTONES_H
#define ALGRITHOM_1004LONGESTONES_H


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = INT_MIN, l = 0, sum = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(r - l + 1 - sum > k){
                sum -= nums[l++];
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

#endif //ALGRITHOM_1004LONGESTONES_H
