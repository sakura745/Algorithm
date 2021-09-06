//
// Created by bas on 9/6/21.
//

#ifndef MAIN_BUCKETSORT_H
#define MAIN_BUCKETSORT_H
#include <cmath>
#include <algorithm>

class Solution{
public:
    const int radix = 10;//基数为10

    //求最大位数
    int maxDigit(vector<int>& nums){
        int digit = 0;
        int Max = 0;
        for(auto &i : nums){
            Max = max(i, Max);
        }
        while(Max != 0){
            digit++;
            Max /= radix;
        }
        return digit;
    }

    //每一位的数
    int getDigit(int num, int digit){
        return  int(num / pow(radix, digit - 1)) % radix;
    }

    void BucketSort(vector<int>& nums){

        vector<int> tmp(nums.size());
        int digit = maxDigit(nums);

        //从个位开始循环
        int j = 0;
        for(int d = 1; d <= digit; d++){

            //设计桶
            vector<int> count(radix, 0);
            for(int i = 0; i < nums.size(); i++){
                j = getDigit(nums[i], d);
                count[j]++;//个数为j出现的次数
            }
            for(int i = 1; i < radix; i++){
                count[i] = count[i - 1] + count[i];
            }

            //入桶
            for(int i = nums.size() - 1; i >= 0; i--){
                j = getDigit(nums[i], d);//位置
                tmp[count[j] - 1] = nums[i];
                count[j]--;
            }

            //出桶
            for(int i = 0; i < nums.size(); i++){
                nums[i] = tmp[i];
            }

        }
    }
};
#endif //MAIN_BUCKETSORT_H
