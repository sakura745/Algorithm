//
// Created by bas on 9/3/21.
//

#ifndef MAIN_SELECTIONSORT_H
#define MAIN_SELECTIONSORT_H


class Solution {
    void swap(int& a, int& b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void selectsort(vector<int>& nums, int n){
        for (int i = 0; i < nums.size(); i++){
            int minIndex = i;
            for (int j = i + 1; j < nums.size(); j++)
                minIndex = nums[j] < nums[minIndex] ? j : minIndex;
            if(i != minIndex) swap(nums[i], nums[minIndex]);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        selectsort(nums, n);
        return nums;
    }
};


#endif //MAIN_SELECTIONSORT_H
