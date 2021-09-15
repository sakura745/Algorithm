//
// Created by bas on 9/15/21.
//

#ifndef ALGRITHOM_MAXNODESINLEVEL_H
#define ALGRITHOM_MAXNODESINLEVEL_H

//Method 1 NoHashMap
int MaxWidthTraversal_NoHash(TreeNode* root){
    queue<TreeNode*> queue;
    queue.push(root);
    int MaxNodes = -1;//store node numbers in level
    TreeNode* curend = root, *nextend = nullptr;
    int curLevelNodes = 1;//current level exist node numbers
    while(!queue.empty()){
        root = queue.front();
        queue.pop();
        if(root->left){
            queue.push(root->left);
            nextend = root->left;
        }
        if(root->right){
            queue.push(root->right);
            nextend = root->right;
        }
        if(root == curend){//if pop's treenode is current level end
            curend = nextend;
            nextend = nullptr;
            MaxNodes = max(MaxNodes, curLevelNodes);
            curLevelNodes = 1;
        } else {
            curLevelNodes++;
        }
    }
    return MaxNodes;
}

//Method 2 Using HashMap
int MaxWidthTraversal(TreeNode* root){
    if(root == nullptr) return {};
    queue<TreeNode*> queue ;
    queue.push(root);
    unordered_map<TreeNode*, int> LevelMap;
    LevelMap.insert(make_pair(root, 1));
    int curLevel = 1;
    int curLevelNodes = 0;
    int MaxNodes = -1;//node numbers in one line
    while(!queue.empty()){
        TreeNode* cur = queue.front();
        queue.pop();
        int curNodeLevel = LevelMap[cur];
        if(curLevel == curNodeLevel){
            curLevelNodes++;
        } else {
            MaxNodes = max(MaxNodes, curLevelNodes);
            curLevel++;
            curLevelNodes = 1;
        }
        if(cur->left) {
            LevelMap.insert(make_pair(cur->left, curNodeLevel + 1));
            queue.push(cur->left);
        }
        if(cur->right) {
            LevelMap.insert(make_pair(cur->right, curNodeLevel + 1));
            queue.push(cur->right);
        }
    }
    return max(MaxNodes, curLevelNodes);
}

#endif //ALGRITHOM_MAXNODESINLEVEL_H
