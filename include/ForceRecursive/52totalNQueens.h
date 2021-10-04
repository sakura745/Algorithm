//
// Created by bas on 9/27/21.
//

#ifndef ALGRITHOM_52TOTALNQUEENS_H
#define ALGRITHOM_52TOTALNQUEENS_H


class Solution {
public:
    int totalNQueens(int n) {
        int limit = (1 << n) - 1;
        return process(limit, 0, 0, 0);
    }
private:
    int process(int limit, int colLim, int lDigLim, int rDigLim){
        if(limit == colLim)
            return 1;
        int pos = limit & (~(colLim | lDigLim | rDigLim));
        int mostRightOne = 0;
        int res = 0;
        while(pos != 0){
            mostRightOne = pos & (~pos + 1);
            pos = pos - mostRightOne;
            res += process(limit, colLim | mostRightOne, (lDigLim | mostRightOne) << 1, (rDigLim | mostRightOne) >> 1);
        }
        return res;
    }
};

#endif //ALGRITHOM_52TOTALNQUEENS_H
