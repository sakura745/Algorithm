//
// Created by sakura on 25/09/2021.
//

#ifndef ALGORITHM_MANNCHAER_H
#define ALGORITHM_MANNCHAER_H

class Solution {
public:
    int longestPalindrome(string s) {
        string str = expandString(s);

        //R表示回文右边界再往右一个位置，为了方便计算，回文有效右边界为R-1
        int *pr = new int[str.size()], C = -1, R = -1, res = INT_MIN;
        for(int i = 0; i < str.size(); i++){//回文数组
            pr[i] = R > i ? min(pr[2 * C - i], R - i) : 1;//至少不用验的区域
            while(i + pr[i] < str.size() && i - pr[i] > -1){
                if(str[i + pr[i]] == str[i - pr[i]]) pr[i]++;//需要扩的会扩
                else break;//不需要扩的 会跳出
            }
            if(i + pr[i] > R){
                R = i + pr[i];
                C = i;
            }
            res = max(res, pr[i]);
        }
        return res - 1;//比如#1#2#1#为最后求的长度，2对应的pr为4：2#1#，4-1就为121的长度
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

    string reduceString(string s){
        string res(s.size() / 2, ' ');
        int index = 0, i = 0;
        while(i < res.size()){
            if((index & 1) == 0) index++;
            else res[i++] = s[index++];
        }
        return res;
    }
};
#endif //ALGORITHM_MANNCHAER_H
