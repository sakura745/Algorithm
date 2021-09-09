//
// Created by bas on 9/5/21.
//

#ifndef MAIN_MERGESUM_H
#define MAIN_MERGESUM_H

//在一个数组中，每个数左边比当前数小的累加起来，叫这个数组的小和。求一个数组的小和。
//逆思维的话：每个数的右侧有多少个比该数大的，就产生多少个该数的小和
class Soluation{
public:
    int merge(vector<int>& nums, int l, int m, int r){
        int p1 = l, p2 = m + 1;
        int res = 0;
        vector<int> tmp(r - l + 1);
        int i = 0;
        while(p1 <= m && p2 <= r) {
            res += nums[p1] < nums[p2] ? (r - p2 + 1) * nums[p1] : 0;//产生多少个该数的小和
            tmp[i++] = (nums[p1] < nums[p2] ? nums[p1++] : nums[p2++]);
        }

        while(p1 <= m) {
            tmp[i++] = nums[p1++];
        }
        while(p2 <= r) {
            tmp[i++] = nums[p2++];
        }

        for(int index = 0; index < tmp.size(); index++){
            nums[index + l] = tmp[index];
        }
        return res;
    }

    int MergeSum(vector<int>& nums, int l, int r){
        if(l == r) return 0;
        int m = l + ((r - l) >> 1);
        return  MergeSum(nums, l, m) +
                MergeSum(nums, m + 1, r) +
                merge(nums, l, m, r);
    }

};

#endif //MAIN_MERGESUM_H
