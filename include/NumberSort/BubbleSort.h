//
// Created by bas on 9/4/21.
//

#ifndef MAIN_BUBBLESORT_H
#define MAIN_BUBBLESORT_H


class Solution {
    void swap(int& a, int& b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void BubbleSort(vector<int>& nums, int n){
        for (int i = 0; i < nums.size(); i++){
            // int r = i;
            for(int j = 1; j < nums.size() - i; j++){
                if(nums[j - 1] > nums[j]) swap(nums[j - 1], nums[j]);
            }
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        BubbleSort(nums, n);
        return nums;
    }
};
#endif //MAIN_BUBBLESORT_H
