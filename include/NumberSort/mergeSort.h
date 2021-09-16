//
// Created by bas on 9/4/21.
//

#ifndef MAIN_MERGESORT_H
#define MAIN_MERGESORT_H
class Solution {
private:
    void process(vector<int> &nums, int l, int m, int r) {
        //辅助数组及其指针
        vector<int> tmp(r - l + 1);
        int tmptr = 0;

        //左右指针
        int p1 = l, p2 = m + 1;

        //设置边界,看p1和p2哪个先消耗完
        while (p1 <= m && p2 <= r) tmp[tmptr++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];

        //两者只能中其一
        while (p1 <= m) tmp[tmptr++] = nums[p1++];
        while (p2 <= r) tmp[tmptr++] = nums[p2++];

        //之所以不能用 nums = tmp;来替换，是因为递归
        for (int index = 0; index < tmp.size(); index++) nums[index + l] = tmp[index];
    }

public:
    void mergeSort(vector<int> &nums, int l, int r) {
        //都可以if (l == r) return;//break recursive
        if(l < r) {
            int m = l + ((r - l) >> 1);//r-((r-l)>>1)是不对的，改为r-((r-l+1)>>1); l+是靠近l取整，r-是靠近r取整
            mergeSort(nums, l, m);
            mergeSort(nums, m + 1, r);
            process(nums, l, m, r);
        }
    }
};
#endif //MAIN_MERGESORT_H
