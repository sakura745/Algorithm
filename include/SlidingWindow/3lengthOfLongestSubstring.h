//
// Created by bas on 9/23/21.
//

#ifndef ALGRITHOM_LENGTHOFLONGESTSUBSTRING_H
#define ALGRITHOM_LENGTHOFLONGESTSUBSTRING_H

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, res = INT_MIN;//l窗口左边界
        unordered_set<char> set;
        for(int r = 0; r < s.size(); r++){//窗口右边界
            while(set.find(s[r]) != set.end())//如果找得到 左边界就移动且更新substring
                set.erase(s[l++]);
            res = max(res, r - l + 1);
            set.insert(s[r]);//没有找到,更新substring
        }
        return res;
    }
};
#endif //ALGRITHOM_LENGTHOFLONGESTSUBSTRING_H
