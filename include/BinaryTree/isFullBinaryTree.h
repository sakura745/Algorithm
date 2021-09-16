//
// Created by bas on 9/15/21.
//

#ifndef ALGRITHOM_FULLBINARYTREE_H
#define ALGRITHOM_FULLBINARYTREE_H

class FBT{
public:
    int height;
    int nodes;
    FBT(int h, int n): height(h), nodes(n){}
};

FBT fullBinaryTree(TreeNode* root){
    if(root == nullptr) return FBT(0, 0);
    FBT l = fullBinaryTree(root->left);
    FBT r = fullBinaryTree(root->right);
    int height = max(l.height, r.height) + 1;
    int nodes = l.nodes + r.nodes + 1;
    return FBT(height, nodes);
};

bool isFull(TreeNode* root){
    if(root == nullptr) return true;
    FBT tmp = fullBinaryTree(root);
    return tmp.nodes == (1 << tmp.height) - 1;
}


#endif //ALGRITHOM_FULLBINARYTREE_H
