//
// Created by bas on 9/23/21.
//

#ifndef ALGRITHOM_209MINSUBARRAYLEN_H
#define ALGRITHOM_209MINSUBARRAYLEN_H

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, sum = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum >= target){
                res = min(res, r - l + 1);//有小的就捕捉
                sum -= nums[l++];//因为求的是最小的长度，因此移动r没意义，移动l
            }
        }
        if(res == INT_MAX) return 0;
        return res;
    }
};

#endif //ALGRITHOM_209MINSUBARRAYLEN_H
