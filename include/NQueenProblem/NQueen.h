//
// Created by bas on 9/27/21.
//

#ifndef ALGRITHOM_NQUEEN_H
#define ALGRITHOM_NQUEEN_H

//Recursive
class Solution {
public:
    int totalNQueens(int n) {
        int *record = new int[n];
        return process(0, record, n);
    }
private:
    int process(int i, int* record, int n) {
        if (i == n) return 1;
        int res = 0;//一定要初始化为0
        for (int j = 0; j < n; j++) {//第i行第j列
            if (isValid(i, j, record)) {
                record[i] = j;
                res += process(i + 1, record, n);
            }
        }
        return res;
    }
    bool isValid(int i, int j, int* record) {
        for (int k = 0; k < i; k++) {//第k行与第i行
            if (j == record[k] || abs(record[k] - j) == abs(i - k)) {
                return false;
            }
        }
        return true;
    }
};


//Using Bits
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
            int res = 0;//一定要初始化为0
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
