//
// Created by bas on 9/27/21.
//

#ifndef ALGRITHOM_5LONGESTPALINDROME_H
#define ALGRITHOM_5LONGESTPALINDROME_H

//因为返回的是字符串
class Solution {
public:
    string longestPalindrome(string& s) {
        string str = expandeString(s);
        int R = -1, C = -1, *pr = new int[str.size()];
        int res = INT_MIN, maxIndex = -1;
        for(int i = 0; i < str.size(); i++){
            pr[i] = R > i ? min(R - i, pr[2 * C - i]) : 1;
            while(i + pr[i] < str.size() && i - pr[i] > -1){
                if(str[i + pr[i]] == str[i - pr[i]])
                    pr[i]++;
                else
                    break;
            }
            if(i + pr[i] > R){
                R = i + pr[i];
                C = i;
            }

            if(res < pr[i]){
                res = pr[i];
                maxIndex = i;
            }
        }
        string re;
//        for(int i = maxIndex - pr[maxIndex] + 1; i < maxIndex + pr[maxIndex]; i++){//举一个具体的例子来计算起点终点
//            re += str[i];
//        }
        re = str.substr(maxIndex - pr[maxIndex] + 1, 2 * pr[maxIndex] - 1);
        return reduceString(re);
    }
private:
    string expandString(string s){
        string res(2 * s.size() + 1, ' ');
        int i = 0;
        for(int index = 0; index < res.size(); index++){
            res[index] = (index & 1) == 0 ? '#' : s[i++];
        }
        return res;
    }
    string reduceString(string s){
        string res(s.size() / 2, ' ');
        int index = 0, i = 0;
        while(index < res.size()){
            if( (i & 1) == 0 )
                i++;
            else
                res[index++] = s[i++];
        }
        return res;
    }
};

#endif //ALGRITHOM_5LONGESTPALINDROME_H
