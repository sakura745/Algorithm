//
// Created by bas on 9/28/21.
//

#ifndef ALGRITHOM_19REMOVENTHFROMEND_H
#define ALGRITHOM_19REMOVENTHFROMEND_H
//Method 1 :fast slow pointer
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        ListNode* dum = new ListNode(-1);//为了返回链表
        dum->next = slow;
        while(n--){
            fast = fast->next;
        }
        if(fast == nullptr) return dum->next->next;//n个节点倒数第n个，也就是删除第一个节点
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dum->next;
    }
};

#endif //ALGRITHOM_19REMOVENTHFROMEND_H
