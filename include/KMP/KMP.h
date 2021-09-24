//
// Created by bas on 9/24/21.
//

#ifndef ALGRITHOM_KMP_H
#define ALGRITHOM_KMP_H

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size(), n = needle.size();
        if(n == 0) return 0;
        if(h < n) return -1;
        int i = 0, j = 0;
        int *next = nextVector(needle);
        //j跳出while表示已经配出相同的了，才会导致j++到出界
        //不是因为j跳出的while，说明没有找到
        while(i < h && j < n){
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }
            //next[j] == -1
            else if(j == 0) i++;
            else  j = next[j];
        }
        return j == n ? i - j : -1;//i越界了；j越界了表示没有找到，返回-1
    }
private:
    int* nextVector(string s){
        int res[s.size()];
        res[0] = -1;
        if(s.size() == 1) return res;
        res[1] = 0;
        int i = 2, j = 0;//哪个位置的字符和i-1的字符比较
        while(i < s.size()){
            if(s[i - 1] == s[j])res[i++] = ++j;
                //cn往前跳
            else if (j > 0){j = res[j];
            else res[i++] = 0;
        }
        return res;
    }
};

#endif //ALGRITHOM_KMP_H
