//
// Created by sakura on 25/09/2021.
//

#ifndef ALGORITHM_MANNCHAER_H
#define ALGORITHM_MANNCHAER_H

class Solution {
public:
    int longestPalindrome(string s) {
        string str = expandString(s);
        int pArray[str.size()], C = -1, R = -1, res = INT_MIN;
        for(int i = 0; i < str.size(); i++){
            pArray[i] = R > i ? min(pArray[2 * C - i], R - i) : 1;
            while(i + pArray[i] < str.size() && i - pArray[i] > -1){
                if(str[i + pArray[i]] == str[i - pArray[i]]) pArray[i]++;
                else break;
            }
            if(i + pArray[i] > R){
                R = i + pArray[i];
                C = i;
            }
            res = max(res, pArray[i]);
        }
        return res - 1;
    }
private:
    string expandString(string s){
        string res(2 * s.size() + 1, ' ');
        int index = 0;
        for(int i = 0; i < res.size(); i++){
            res[i] = (i & 1) == 0 ? '#' : s[index++];
        }
        return res;
    }
};
#endif //ALGORITHM_MANNCHAER_H
