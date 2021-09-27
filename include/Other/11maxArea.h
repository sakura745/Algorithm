//
// Created by bas on 9/27/21.
//

#ifndef ALGRITHOM_11MAXAREA_H
#define ALGRITHOM_11MAXAREA_H

//双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, res = INT_MIN;
        while(l < r){
            //可以换为三元操作符是因为
            //            int tmp = min(height[l], height[r]) * (r - l);
            //            res = max(res, tmp);
            //            if(height[l] < height[r]) l++;
            //            else r--;
            //15行取最小值和if语句相同，且if下的执行条件可以放入到height[l]中去

            res = height[l] < height[r] ?
                  max(res, (r - l) * height[l++]) :
                  //注意r--的使用，如果是height[r--] * (r - l)则会出错，因为r--会作用到r上
                  //要注意r--放到最后使用
                  max(res, (r - l) * height[r--]);
        }
        return res;
    }
};

#endif //ALGRITHOM_11MAXAREA_H
