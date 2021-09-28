//
// Created by bas on 9/28/21.
//

#ifndef ALGRITHOM_15THREESUM_H
#define ALGRITHOM_15THREESUM_H

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        //nums[i] >=0 不可能有解 i为最小的指针
        for(int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++){

            //i > 0 && nums[i] == nums[i - 1]不等价于nums[i + 1] == nums[i]
            //因为通过i的来遍历的，而不是i+1
            if(i > 0 && nums[i] == nums[i - 1]) continue;//去重
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] > 0)
                    r--;
                else if(nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else{
                    res.push_back({nums[i], nums[l++], nums[r--]});
                    while(l < r && nums[l] == nums[l - 1]) l++;//去重
                    while(l < r && nums[r] == nums[r + 1]) r--;//去重
                }
            }
        }
        return res;
    }
};

#endif //ALGRITHOM_15THREESUM_H
