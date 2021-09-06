//
// Created by bas on 9/6/21.
//

#ifndef MAIN_HEAPSORT_H
#define MAIN_HEAPSORT_H
class Solution {
public:
    void HeapSort(vector<int> &nums) {

        for (int i = 0; i < nums.size(); i++) {
            HeapInsert(nums, i);
        }

//等价HeapInsert
//        for(int e = nums.size() - 1; e >= 0; e--){
//            Heapify(nums, e, nums.size());
//        }

        int heapSize = nums.size();
        swap(nums[0], nums[--heapSize]);

        while (heapSize != 0) {
            Heapify(nums, 0, heapSize);
            swap(nums[0], nums[--heapSize]);
        }
    }

    void HeapInsert(vector<int> &nums, int index) {
        //(index - 1)>>1，如果是index - 1 >= 0可以，小于零带符号则不能位移
        while (nums[index] > nums[(index - 1) / 2]) {
            swap(nums[index], nums[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void Heapify(vector<int> &nums, int index, int heapSize) {
        //heapify是向下操作的，所以写出向下的子节点
        int left = 2 * index + 1;

        while (left < heapSize) {//越界与否

            //xiugai daxiao
            //比较index的两个子节点的大小
            // && 的优先级比 ?: 优先级高
            //a&&b 如果a为true则再判断b，如果a为false则a&&b为false。
            //对于 ?: 来说，如果?前为false，则直接执行:后面的
            //因此nums为先判断是否有右子节点，如果有再比较大小。
            //比较符号不能修改为<。是因为右子节点的判断相对应
            int larger = left + 1 < heapSize && nums[left + 1] > nums[left] ? left + 1 : left;

            //比较节点和子节点
            larger = nums[index] > nums[larger] ? index : larger;

            if (index == larger) {
                break;
            }
            swap(nums[index], nums[larger]);

            index = larger;
            left = 2 * index + 1;
        }
    }

};
#endif //MAIN_HEAPSORT_H
