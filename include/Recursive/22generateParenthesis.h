//
// Created by bas on 10/8/21.
//

#ifndef ALGRITHOM_22GENERATEPARENTHESIS_H
#define ALGRITHOM_22GENERATEPARENTHESIS_H


//通常来说，设置为0增加到n，需要有一个n的界限；但是如果从n开始减少到0，这个0可能属于是代码中天然的界限。
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        process(res, "", 0, n);
        return res;
    }
private:
    void process(vector<string>& res, const string& tmp, int r, int n) {//const限制符是为了满足 tmp + '('
        if (r == 0 && n == 0) {//base case
            res.push_back(tmp);
            return;
        }
        if (n) {
            process(res, tmp + '(', r + 1, n - 1);//用n来计算'('的个数，同时r来对应左括号的个数
        }
        if (r) {
            process(res, tmp + ')', r - 1, n);//用上一行得到的来控制')'的个数
        }
    }
};

#endif //ALGRITHOM_22GENERATEPARENTHESIS_H
