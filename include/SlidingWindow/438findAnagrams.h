//
// Created by bas on 9/24/21.
//

#ifndef ALGRITHOM_438FINDANAGRAMS_H
#define ALGRITHOM_438FINDANAGRAMS_H

//题目所述为与p相同的字符串，p就涉及到字符串中出现字母的个数，因此不能用hashset。
//Hash_map
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mapP, mapS;
        for(auto& i : p)//导入p的map
            mapP[i]++;
        int l = 0;
        vector<int> res;
        for(int r = 0; r < s.size(); r++){
            mapS[s[r]]++;
            if(mapP == mapS) res.push_back(l);

            //表示没满足上一个相等
            if(r - l + 1 == p.size()){//>= 也可以，但是不会执行 >,因为一直在修改窗口范围为<= 区间
                mapS[s[l]]--;
                if(mapS[s[l]] == 0)//确保哈希表没有当前元素之后，要删除
                    mapS.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};

#endif //ALGRITHOM_438FINDANAGRAMS_H
