//
// Created by bas on 9/4/21.
//

#ifndef MAIN_MERGESORT_H
#define MAIN_MERGESORT_H

void merge(vector<int>&nums, int l, int m, int r){
    int i = 0;
    vector<int> tmp(r - l + 1);
    int p1 = l, p2 = m + 1;
    while(p1 <= m && p2 <= r) {//设置边界,看p1和p2哪个先消耗完
        tmp[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
    }

    //两者只能中其一
    while(p1 <= m) {
        tmp[i++] = nums[p1++];
    }
    while (p2 <= r) {
        tmp[i++] = nums[p2++];
    }


    for(int index = 0; index < tmp.size(); index++){//之所以不能用 nums = tmp;来替换，是因为递归
        nums[index + l] = tmp[index];
    }

}

void MergeSort(vector<int>&nums, int l, int r){
    if(l == r) return;//break recursive
    int m = l + ( ( r - l ) >> 1 );//r-((r-l)>>1)是不对的，改为r-((r-l+1)>>1); l+是靠近l取整，r-是靠近r取整
    MergeSort(nums, l, m);
    MergeSort(nums,m + 1, r);
    merge(nums, l, m, r);
}
#endif //MAIN_MERGESORT_H
