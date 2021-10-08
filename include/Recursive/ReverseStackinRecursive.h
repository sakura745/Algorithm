//
// Created by bas on 10/3/21.
//

#ifndef ALGRITHOM_REVERSESTACKINRECURSIVE_H
#define ALGRITHOM_REVERSESTACKINRECURSIVE_H

class Solution {
public:
    void reverse(stack<int>& stk) {
        if (stk.empty()) {
            return;
        }
        int i = popBottomElementInStack(stk);
        reverse(stk);
        stk.push(i);
    }
private:
    int popBottomElementInStack(stack<int>&stk) {
        int res = stk.top();
        stk.pop();
        if (stk.empty()) {
            return res;
        } else {
            int last = popBottomElementInStack(stk);
            stk.push(res);
            return last;
        }
    }
};
#endif //ALGRITHOM_REVERSESTACKINRECURSIVE_H
