//
// Created by bas on 9/4/21.
//

#ifndef MAIN_DUISHUQI_H
#define MAIN_DUISHUQI_H
class Solution{
public:
    vector<int> generateRandomArray(int maxSize, int maxValue){
        srand(time(0));
        vector<int> arr(maxSize);
        for(auto & i : arr){
            i =  rand() % maxValue + 1;
        }
        return arr;
    }
};
#endif //MAIN_DUISHUQI_H
