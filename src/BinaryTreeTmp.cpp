//
// Created by bas on 9/12/21.
//
//
// Created by bas on 9/12/21.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace  std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class Solution{
public:
    vector<int> preorderTraversal_NoRec(TreeNode* head){
        if(nullptr != head) {
            stack<TreeNode> stack;

        }
    }
public:
    vector<int> inorderTraversal_NoRec(TreeNode* head){
        if(nullptr != head) {
            stack<TreeNode*> stack;
            while(!stack.empty() || head != nullptr){
                if(head != nullptr){
                    stack.push(head);
                    head = head->left;
                } else {
                    head = stack.top();
                    stack.pop();

                    head = head->right;
                }
            }
        }
    }

public:
    vector<int> postorderTraversal_NoRec(TreeNode* head){
        if(nullptr != head) {
            stack<TreeNode> stack ;
        }
    }

};

int main(){

}
