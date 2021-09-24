//
// Created by bas on 9/24/21.
//

#ifndef ALGRITHOM_567CHECKINCLUSION_H
#define ALGRITHOM_567CHECKINCLUSION_H

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map1, map2;
        for(auto& c : s1) map1[c]++;
        int l = 0;
        for(int r = 0; r < s2.size();r++){
            map2[s2[r]]++;
            if(map1 == map2) return true;
            if(r - l + 1 == s1.size()){
                map2[s2[l]]--;
                if(map2[s2[l]] == 0)
                    map2.erase(s2[l]);
                l++;
            }
        }
        return false;
    }
};
#endif //ALGRITHOM_567CHECKINCLUSION_H
