//
// Created by bas on 9/16/21.
//

#ifndef ALGRITHOM_SERIALIZATION_DESERIALIZATION_H
#define ALGRITHOM_SERIALIZATION_DESERIALIZATION_H

class Solution{
public:
    string serialByPre(TreeNode* root){
        if(root == nullptr) return "#_";
        string res = root->val + "_";
        res += serialByPre(root->left);
        res += serialByPre(root->right);
        return res;
    }
};

class Solution{
public:
    TreeNode* deserialByPre(string preStr){

    }
private:
    vector<string>
};

#endif //ALGRITHOM_SERIALIZATION_DESERIALIZATION_H
