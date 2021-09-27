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
        int *next = nextArray(needle);
        while(i < h && j < n){

            //一直保持i的位置不变，调节j的位置，通过i和j同时相加，确保i和j 的对齐，
            // 一直到j= 0再移动i
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }
            //next[j] == -1
            else if(j == 0) i++;
            else  j = next[j];
        }

        //j跳出while表示已经配出相同的了，才会导致j++到出界
        //不是因为j跳出的while，说明没有找到
        return j == n ? i - j : -1;//i越界了；j越界了表示没有找到，返回-1
    }
private:
    int* nextArray(string s){
        int *res = new int[s.size()];
        res[0] = -1;//认为规定，可以跳出j = res[j]
        if(s.size() == 1) return res;
        res[1] = 0;
        int i = 2, j = 0;//j位置的字符和i-1的字符比较来确定i的值
        while(i < s.size()){

            //其中有i的位置都要i++；用i更新数列
            if(s[i - 1] == s[j]) res[i++] = ++j;
            //j = 0表示j指针到头了，res[i] = 0
            else if (j == 0) res[i++] = 0;
            //j往前跳
            else j = res[j];
        }
        return res;
    }
};

#endif //ALGRITHOM_KMP_H
