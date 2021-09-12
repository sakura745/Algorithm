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
    vector<int> preorderTraversal_NoRec(TreeNode* root){
        if(nullptr != root) {
            stack<TreeNode> stack;

        }
    }
public:
    vector<int> inorderTraversal_NoRec(TreeNode* root){
        vector<int> res;
        if(nullptr != root) {
            stack<TreeNode*> stack;
            while(!stack.empty() || root != nullptr){
                if(root != nullptr){
                    stack.push(root);
                    root = root->left;
                } else {
                    root = stack.top();
                    stack.pop();
                    res.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return res;
    }

public:
    vector<int> postorderTraversal_NoRec(TreeNode* head){
        if(nullptr != head) {
            stack<TreeNode> stack ;
        }
    }

};

int main(){
    TreeNode* cur = new TreeNode(1);
    cur->left = new TreeNode(2);
    cur->right = new TreeNode(3);
    cur->left->left = new TreeNode(4);
    cur->left->right = new TreeNode(5);
    cur->right->left = new TreeNode(6);
    cur->right->right = new TreeNode(7);

}
