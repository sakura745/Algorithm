//
// Created by bas on 9/22/21.
//

#ifndef ALGRITHOM_SUMTWONUMBERS_H
#define ALGRITHOM_SUMTWONUMBERS_H

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dum = new ListNode(-1);
        ListNode *ptr = dum;
        int carry = 0, newVal = 0;
        while(l1 != nullptr || l2 != nullptr || carry > 0){
            newVal = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            carry = newVal / 10;
            newVal %= 10;
            ptr->next = new ListNode(newVal);//将链表连上
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
            ptr = ptr->next;
        }
        return dum->next;
    }
};

#endif //ALGRITHOM_SUMTWONUMBERS_H
