//
// Created by bas on 9/4/21.
//

#ifndef MAIN_ODD_EVEN_H
#define MAIN_ODD_EVEN_H
class Solution{
public:
    //一组数字含有一个数字为奇数个，其他为偶数个。
    void  getNums(vector<int>&nums){
        int eor = 0;
        for(auto &i : nums){
            eor ^= i;
        }
        cout << eor ;
    }

    //一组数字含有两个数字为奇数个，其他为偶数个。
    void getNums2(vector<int>&nums){
        //eor = a^b,a!=b
        int eor = 0;
        for(auto &i : nums){
            eor ^= i;
        }
        int ehas = eor & (~eor + 1);//取出a，b不相等的最右边的1
        int eorp = 0;
        for(auto &i : nums){
            if(0 != (ehas & i)) //通过不相等的1来将a b分组
                eorp ^= i;
        }
        cout << eorp << " and " << ( eorp ^ eor );
    }
};
#endif //MAIN_ODD_EVEN_H
