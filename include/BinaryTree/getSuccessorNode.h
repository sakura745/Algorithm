//
// Created by bas on 9/16/21.
//

#ifndef ALGRITHOM_GETSUCCESSORNODE_H
#define ALGRITHOM_GETSUCCESSORNODE_H

//Method 1
//TreeNode has a parent pointer  which means can point to parent nodes
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(): val(0), left(nullptr), right(nullptr), parent(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr), parent(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *parent): val(x), left(left), right(right), parent(parent){}
};
class Solution{
public:
    TreeNode* getSuccessorNode(TreeNode* root){
        if(root == nullptr) return root;
        if(root->left != nullptr){//有右树时
            return getLeftMost(root);
        } else {//无右子树
            TreeNode* parent = root->parent;
            while(parent != nullptr && parent->left != root){//当前节点是其父节点右子节点
                root = parent;
                parent = root->parent;
            }
            return parent;//parent == nullptr is mean no succeessor， return nullptr 或者 parent->left == root, return parent
        }
    }
private:
    TreeNode* getLeftMost(TreeNode* root){
        if(root == nullptr) return root;
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
};

#endif //ALGRITHOM_GETSUCCESSORNODE_H
