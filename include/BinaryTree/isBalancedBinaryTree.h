//
// Created by bas on 9/15/21.
//

#ifndef ALGRITHOM_ISBALANCEDBINARYTREE_H
#define ALGRITHOM_ISBALANCEDBINARYTREE_H

//AVL是科学家的名字组合而成的，他们发明了BalancedBinaryTree
//DP
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return process(root).isBalan;
    }
private:
    //因为需要返回两个信息
    class Info{
    public:
        int height;
        bool isBalan;
        Info(int x, bool is):height(x), isBalan(is){};
    };

    Info process(TreeNode* root){
        if(root == NULL) return Info(0, true);//Base Case

        //将函数分别递归下去，
        Info l = process(root->left);
        Info r = process(root->right);

        int he = max(l.height, r. height) + 1;//通过递归的信息，算出返回值，
        bool isBal = l.isBalan && r.isBalan && abs(l.height - r.height) < 2;//通过递归的信息，算出返回值，

        return Info(he, isBal);
    }
};

#endif //ALGRITHOM_ISBALANCEDBINARYTREE_H
