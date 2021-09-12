//
// Created by bas on 9/9/21.
//

#ifndef MAIN_DELETENODE_H
#define MAIN_DELETENODE_H


class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *pre = head, *cur = head->next;//删除a位置节点时，需要将a前一个指向a后一个，所以令a前一个为pre
        if(val == head->val ) return head->next;//当a没有前一个节点时
        while(cur != NULL && cur->val != val){//没找到val之前且链表没结束
            pre = cur;
            cur = cur->next;
        }
        if(cur->val == val){//当找到val的时候
//        if(cur != NULL){    在while跳出的前提下，链表没结束，也就是找到了
            pre->next = cur->next;
        }
        return head;
    }
};

#endif //MAIN_DELETENODE_H
