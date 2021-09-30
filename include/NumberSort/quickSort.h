//
// Created by bas on 9/5/21.
//

#ifndef MAIN_QUICKSORT_H
#define MAIN_QUICKSORT_H
class Solution{
public:
    void quickSort(vector<int>&nums, int l, int r){
        if(l < r) {//递归。因为是用partition分出的边界，要保证l r 的大小关系。
            srand(time(0));
            swap(nums[l + rand() % (r - l + 1)], nums[r]);
            vector<int> a = partition(nums, l, r);
            quickSort(nums, l, a[0] - 1);
            quickSort(nums, a[1] + 1, r);
        }
    }

private:
    vector<int> partition(vector<int>&nums, int l, int r){
        int less = l - 1, more = r;
        while (l < more) {//用l 和 more 双指针表示i指针的位置
            if(nums[l] < nums[r])
                swap(nums[++less], nums[l++]);

            //else if 不能去掉else。因为 else if是在if的基础上的，是递进关系 不是并列
            else if (nums[l] > nums[r])
                swap(nums[l], nums[--more]);
            else
                l++;
        }

        //当l = more时，由于more的取值是从r开始，而非r+1，因此最后要交换一下
        //l指针指向r
        //将r放入数组中
        swap(nums[l], nums[r]);

        //返回值相等的区间
        vector<int> tmp {less + 1, more};
        return  tmp;
    }

};
#endif //MAIN_QUICKSORT_H
