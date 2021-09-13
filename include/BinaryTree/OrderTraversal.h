//
// Created by bas on 9/13/21.
//

#ifndef ALGRITHOM_ORDERTRAVERSAL_H
#define ALGRITHOM_ORDERTRAVERSAL_H
class Solution{
    //法一： recursive
public:
    vector<int> preorderTraversal_R(TreeNode* root){
        vector<int> res;
        preorder(root, res);
        return res;
    }
private:
    void preorder(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
/****************************************************/
public:
    vector<int> inorderTraversal_R(TreeNode* root){
        vector<int> res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
/****************************************************/
public:

    vector<int> postorderTraversal_R(TreeNode* root){
        vector<int> res;
        postorder(root, res);
        return res;
    }
private:
    void postorder(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
/****************************************************/
/****************************************************/

//法二： Iterator
public:
    vector<int> preorderTraversal_I(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            root = stack.top();
            stack.pop();
            res.push_back(root->val);
            if(root->right != nullptr) stack.push(root->right);
            if(root->left != nullptr) stack.push(root->left);
        }
        return res;
    }
/****************************************************/
public:
    vector<int> inorderTraversal_I(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> stack;
        while(root != nullptr || !stack.empty()){
            //左
            while(root != nullptr){//只要有左子树，就入栈
                stack.push(root);
                root = root->left;
            }
            //头
            //出栈
            root = stack.top();
            stack.pop();
            res.push_back(root->val);
            //右
            //右子树循环上述
            root = root->right;
        }
        return res;
    }
/****************************************************/
public:
    vector<int> postorderTraversal_I(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> stack1, stack2;
        stack1.push(root);
        TreeNode* cur;
        while(!stack1.empty()){
            cur = stack1.top();
            stack1.pop();
            stack2.push(cur);
            if(cur->left) stack1.push(cur->left);
            if(cur->right) stack1.push(cur->right);
        }
        while(!stack2.empty()){
            cur = stack2.top();
            stack2.pop();
            res.push_back(cur->val);
        }
        return res;
    }
};

#endif //ALGRITHOM_ORDERTRAVERSAL_H
