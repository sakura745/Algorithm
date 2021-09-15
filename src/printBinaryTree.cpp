#include<bits/stdc++.h>

using namespace std;

#define COUNT 8

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

void printBranch(TreeNode *root, int space)
{
    if (root == nullptr) return;
    //数字间的距离（只看横向）
    space += COUNT;

    printBranch(root->right, space);

    //inorderTraversal for the space
    cout << endl;
    for (int i = COUNT; i < space; i++) cout << " ";
    cout << root->val << endl;

    printBranch(root->left, space);

}
void printTreeNode(TreeNode *root)
{
    printBranch(root, 0);
}

TreeNode* InputBinaryTree(void){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);

//    root->left->left->left->left = new TreeNode(16);
//    root->left->left->left->right = new TreeNode(17);
//    root->left->left->right->left = new TreeNode(18);
//    root->left->left->right->right = new TreeNode(19);
//    root->left->right->left->left = new TreeNode(20);
//    root->left->right->left->right = new TreeNode(21);
//    root->left->right->right->left = new TreeNode(22);
//    root->left->right->right->right = new TreeNode(23);
//    root->right->left->left->left = new TreeNode(24);
//    root->right->left->left->right = new TreeNode(25);
//    root->right->left->right->left = new TreeNode(26);
//    root->right->left->right->right = new TreeNode(27);
//    root->right->right->left->left = new TreeNode(28);
//    root->right->right->left->right = new TreeNode(29);
//    root->right->right->right->left = new TreeNode(30);
//    root->right->right->right->right = new TreeNode(31);
    return root;
}

int main()
{
    TreeNode* root = InputBinaryTree();
    printTreeNode(root);
    return 0;
}

