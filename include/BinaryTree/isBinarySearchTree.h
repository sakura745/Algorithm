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


//Method 3 Dynamic Programming
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return bBST(root).isBST;
    }
private:

    class BST{
    public:
        bool isBST;
        int Min;
        int Max;
        BST(bool is, int mi, int ma):isBST(is), Min(mi), Max(ma){};
    };

    BST bBST(TreeNode* root){
        if(root == nullptr) return BST(true, 0, 0);

        BST l = bBST(root->left);
        BST r = bBST(root->right);

        int Min = root->val;
        int Max = root->val;
        if(l != n){
            Min = min(Min, l.Min);
            Max = max(Max, l.Max);
        }
        if(r != BST(true, 0, 0)){
            Min = min(Min, r.Min);
            Max = max(Max, r.Max);
        }
        // bool i = true;
        // if(l != nullptr && (!l.isBST || l.max >= x->val))
        //     isBST = false;
        // if(r != nullptr && (!r.isBST || r.min <= x->val))
        //     isBST = false;
        bool i = false;
        if(
                (l != BST(true, 0, 0) ? (l.isBST && l.Max < x->val) : true)
                &&
                (r != BST(true, 0, 0) ? (r.isBST && r.min > x->val) : true)
                )
            i = true;



        return BST(i, Min, Max);
    }
};
#endif //ALGRITHOM_ISBINARYSEARCHTREE_H
