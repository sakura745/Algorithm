//
// Created by bas on 9/10/21.
//

#ifndef ALGRITHOM_COPYRANDOMLIST_H
#define ALGRITHOM_COPYRANDOMLIST_H
/**
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
**/

//法一：笔试 用hash map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(NULL == head) return head;
        Node * cur = head;
        unordered_map<Node*, Node*> map;
        //遍历到map中
        while(cur != NULL){
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        //遍历map value 的ptr
        cur = head;
        while(cur != NULL){
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        return map[head];
    }
};

//法二 面试 不用新建额外空间
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(NULL == head)return head;

        Node* cur = head;//为了遍历用
        //加入复制的节点
        while(cur != NULL){
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }

        cur= head;
        while(cur != NULL){
            if(cur->random != NULL){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head->next;
        Node * pre = head;//原来的链
        Node * res = head->next;//要的链
        while(cur->next != NULL){//cur终止（要得就是cur）
            pre->next = pre->next->next;//pre单成一链
            pre = pre->next;
            cur->next = cur->next->next;//cur单成一链
            cur = cur->next;
        }
        pre->next = NULL;//pre终止
        return res;
    }
};

#endif //ALGRITHOM_COPYRANDOMLIST_H
