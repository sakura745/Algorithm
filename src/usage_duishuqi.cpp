#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

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
    void swap(int& a, int& b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void BubbleSort(vector<int> &nums){
        for(int i = 0; i < nums.size(); i++ ){
            for(int j = 1; j < nums.size() - i; j++)
                if(nums[j - 1] > nums[j]) swap(nums[j - 1], nums[j]);
        }
    }

    void readVec(vector<int> &nums){
        for(auto &i : nums){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){

    int maxSize = 20;
    int maxValue = 20;
    Solution A;
    vector<int> arr = A.generateRandomArray(maxSize, maxValue);
    cout << "Output original array: \n";
    A.readVec(arr);
    vector<int> arr2 = arr;//deep copy
    A.BubbleSort(arr);
    cout << "Output BubbleSort array: \n";
    A.readVec(arr);
    sort(arr2.begin(), arr2.end());
    cout << "Output STL array: \n";
    A.readVec(arr2);
}