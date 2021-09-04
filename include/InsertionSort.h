//
// Created by bas on 9/4/21.
//

#ifndef MAIN_INSERTIONSORT_H
#define MAIN_INSERTIONSORT_H

class Solution {
    void swap(int& a, int& b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void InsertionSort(vector<int> &nums){
        for(int i = 1; i < nums.size(); i++){
//            for(int j = i; j > 0 && j < nums.size(); j--)
//                if(nums[j - 1] > nums[j]) swap(nums[j - 1], nums[j]);
            for(int j = i; j > 0 && nums[j - 1] > nums[j]; j--)
                swap(nums[j - 1], nums[j]);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        InsertionSort(nums);
        return nums;
    }
};

#endif //MAIN_INSERTIONSORT_H
