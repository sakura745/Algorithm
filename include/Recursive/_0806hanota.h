//
// Created by bas on 9/30/21.
//

#ifndef ALGRITHOM__0806HANOTA_H
#define ALGRITHOM__0806HANOTA_H

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        process(A.size(), A, C, B);//A为from C为to B为tmp
    }
private:
    void process(int i, vector<int>& from, vector<int>& to, vector<int>& tmp) {
        if (i == 1) {
            to.push_back(from.back());
            from.pop_back();
            return;
        } else {
            process(i - 1, from, tmp, to);
            to.push_back(from.back());
            from.pop_back();
            process(i - 1, tmp, to, from);
        }
    }
};

#endif //ALGRITHOM__0806HANOTA_H
