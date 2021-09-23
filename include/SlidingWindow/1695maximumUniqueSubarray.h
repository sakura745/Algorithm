//
// Created by bas on 9/23/21.
//

#ifndef ALGRITHOM_1695MAXIMUMUNIQUESUBARRAY_H
#define ALGRITHOM_1695MAXIMUMUNIQUESUBARRAY_H

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        unordered_set<int> set;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(set.find(nums[r]) != set.end()){
                set.erase(nums[l]);
                sum -= nums[l++];
            }
            res = max(res, sum);
            set.insert(nums[r]);
        }
        return res;
    }
};

#endif //ALGRITHOM_1695MAXIMUMUNIQUESUBARRAY_H
