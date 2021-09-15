//
// Created by bas on 9/15/21.
//

#ifndef ALGRITHOM_ISBINARYSEARCHTREE_H
#define ALGRITHOM_ISBINARYSEARCHTREE_H
//Method 1 :Recursion
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(!isValidBST(root->left)){
            return false;
        }
        if(root->val <= preValue){
            return false;
        }
        preValue = root->val;
        return isValidBST(root->right);
    }
private:
    long preValue = LONG_MIN;
};

//Method 2 No recursion
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        stack<TreeNode*> stack;
        while(!stack.empty() || root != nullptr){
            while(root != nullptr){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(root->val <= preValue){
                return false;
            }
            preValue = root->val;
            root = root->right;
        }
        return true;
    }
private:
    long preValue = LONG_MIN;
};

#endif //ALGRITHOM_ISBINARYSEARCHTREE_H
