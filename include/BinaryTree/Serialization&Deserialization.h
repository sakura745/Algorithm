//
// Created by bas on 9/16/21.
//

#ifndef ALGRITHOM_SERIALIZATION_DESERIALIZATION_H
#define ALGRITHOM_SERIALIZATION_DESERIALIZATION_H

class Solution{
public:
    string serialByPre(TreeNode* root){
        if(root == nullptr) return "#_";
        string res = to_string(root->val) + "_";
        res += serialByPre(root->left);
        res += serialByPre(root->right);
        return res;
    }
};

class Solution{
public:
    TreeNode* deserialPreString(string str){
        string values = split(str, '_');
        queue<string> queue;
        for(int i = 0; i != values.size(); i++){
            queue.push(values);
        }
        return deserial(queue);
    }
private:
    string split(string str, char del){
        string res;
        stringstream ss(str);
        string s;
        while(getline(ss, s, del)){
            res += s;
        }
        return res;
    }

    TreeNode* deserial(queue<string> queue){
        string value = queue.front();
        queue.pop();
        if(value == "#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(value));
        root->left = deserial(queue);
        root->right = deserial(queue);
        return root;
    }
};

#endif //ALGRITHOM_SERIALIZATION_DESERIALIZATION_H
