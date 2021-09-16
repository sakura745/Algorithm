//
// Created by bas on 9/16/21.
//

#ifndef ALGRITHOM_LOWERCOMMONANCESTOR_H
#define ALGRITHOM_LOWERCOMMONANCESTOR_H
//Method 1 HashMap HashSet
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> fatherMap;//任何节点的父节点的map
        fatherMap.insert(make_pair(root, root));//root的父节点是root
        process(root, fatherMap);//带着map向上回溯
        unordered_set<TreeNode*> setp;
        TreeNode* cur = p;
        while(cur != fatherMap[cur]){//只有头结点会等于自己的父
            setp.insert(p);
            cur = fatherMap[cur];
        }
        setp.insert(root);
        TreeNode* cur2 = q;
        while(cur2 != fatherMap[cur2]){
            setp.insert(q);
            cur2 = fatherMap[cur2];
            if(cur2 = setp[cur1])
        }

    }
private:
    void process(TreeNode* root, unordered_map<TreeNode*, TreeNode*> fatherMap){
        if(root == NULL) return;
        fatherMap.insert(make_pair(root->left, root));
        fatherMap.insert(make_pair(root->right, root));
        process(root->left, fatherMap);
        process(root->right, fatherMap);
    }
};


//Method 2:
//Recusive: execute recusive except base case，until leaf node. Return information about leaf node info,
//recall to root.
//1)p is q lca or q is p lca
//2) except 1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == q || root == p) return root;//base case
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL) return root;//if left = q, right = p,return root

        //if left = null and right = null，return null;if left = q ,right = null ,return left;
        //if left = null ,right = q ,return right;
        return left != NULL ? left : right;

        //if left = null ,right = q ,return right, return q;
        //if(root == NULL || root == q || root == p) return root;

    }
};
#endif //ALGRITHOM_LOWERCOMMONANCESTOR_H
