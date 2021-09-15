//
// Created by bas on 9/15/21.
//

#ifndef ALGRITHOM_ISCOMPLETEBINARYTREE_H
#define ALGRITHOM_ISCOMPLETEBINARYTREE_H

//非完全二叉树有两种，子节点不全在：
//1）l == nullptr && r != nullptr
//2） 不是1）的情况下即（l!= nullptr && r == nullptr）时，之后只要后面的节点为非叶节点，则不满足完全二叉树

bool isCBT(TreeNode* root){
    queue<TreeNode*> queue;
    queue.push(root);

    //是个开关，开了就接着判断 && 之后的
    bool leaf = false;//leaf = true 表示不是叶节点，该节点后某个子节点为非完全二叉树

    while(!queue.empty()){
        root = queue.front();
        queue.pop();
        TreeNode* l = root->left, * r = root->right;
        if((l == nullptr && r != nullptr)//1）

           //2)
           //先leaf = false直接跳过子节点判断，因为leaf = false表明之前没有叶节点
           //leaf = true时才判断leaf之后的节点是否为叶节点，如果之后的节点不是叶节点则不满足完全二叉树
           || (leaf
               &&
               (l != nullptr || r != nullptr)
           ))
            return false;
        if(l != nullptr) queue.push(l);
        if(r != nullptr) queue.push(r);
        if(l == nullptr || r == nullptr) leaf = true; //当出现叶节点之后，打开开关
    }
    return true;
}

#endif //ALGRITHOM_ISCOMPLETEBINARYTREE_H
