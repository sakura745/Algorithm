#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution{
public:
//    void swap(int& a, int& b){
//        a ^= b;
//        b ^= a;
//        a ^= b;
//    }

    void BubbleSort(vector<int> &nums){
        for(int i = 0; i < nums.size(); i++ ){
            for(int j = 1; j < nums.size() - i; j++)
                if(nums[j - 1] > nums[j]) swap(nums[j - 1], nums[j]);
        }
    }

};

vector<int> generateRandomArray(int maxSize, int maxValue){
    srand(time(0));
    vector<int> arr(maxSize);
    for(auto & i : arr){
        i =  rand() % maxValue + 1;
    }
    return arr;
}

void printVec(vector<int> &nums){
    for(auto &i : nums){
        cout << i << " ";
    }
    cout << endl;
}

int main(){

    int maxSize = 1000;
    int maxValue = 1000;

    vector<int> arr = generateRandomArray(maxSize, maxValue);
    vector<int> arr2 = arr;//deep copy
    Solution A;
    A.BubbleSort(arr);
    sort(arr2.begin(), arr2.end());

    assert(arr == arr2);
    cout << "Success!" << endl;

//    cout << "Output original array: \n";
//    printVec(arr);
//    vector<int> arr2 = arr;//deep copy
//    A.BubbleSort(arr);
//    cout << "Output BubbleSort array: \n";
//    printVec(arr);
//    sort(arr2.begin(), arr2.end());
//    cout << "Output STL array: \n";
//    printVec(arr2);


}