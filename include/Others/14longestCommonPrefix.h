//
// Created by bas on 9/28/21.
//

#ifndef ALGRITHOM_14LONGESTCOMMONPREFIX_H
#define ALGRITHOM_14LONGESTCOMMONPREFIX_H

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return {};
        for(int i = 0; i < strs[0].size(); i++){
            auto c = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(i == strs[j].size() || c != strs[j][i])
                    return strs[0].substr(0, i);//substr(begin_pos, length)
            }
        }
        return strs[0];
    }
};

#endif //ALGRITHOM_14LONGESTCOMMONPREFIX_H
