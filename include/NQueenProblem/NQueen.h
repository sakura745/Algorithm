//
// Created by bas on 9/27/21.
//

#ifndef ALGRITHOM_NQUEEN_H
#define ALGRITHOM_NQUEEN_H

class Solution{
public:
    int num(int n){
        if(n < 1 || n > 32){
            return 0;
        }
        int limit = n == 32 ? -1 : (1 << n) - 1;//保证n位以内都为1
        return process(limit, 0, 0, 0);
    }
private:
        //返回找到多少种
        int process(int limit, int colLim, int lDigLim, int rDigLim){
            if(colLim == limit)//base case 找到一种
                return 1;
            int pos = limit & (~(colLim | lDigLim | rDigLim));//保证n位以外都为0
            int mostRightOne = 0;
            int res = 0;
            while(pos != 0){
                mostRightOne = pos & (~pos + 1);//可以在mostRightOne位置上试皇后
                pos = pos - mostRightOne;//试过一个，删掉一个
                res += process(limit,
                               colLim | mostRightOne,//
                               (lDigLim | mostRightOne) << 1,
                               (rDigLim | mostRightOne) >> 1);
        }
        return res;
    }
};

#endif //ALGRITHOM_NQUEEN_H
