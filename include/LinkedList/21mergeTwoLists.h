//
// Created by bas on 9/29/21.
//

#ifndef ALGRITHOM_21MERGETWOLISTS_H
#define ALGRITHOM_21MERGETWOLISTS_H

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dum = new ListNode(-1),  *ptr = dum;

        //ListNode *ptr1 = l1, *ptr2 = l2;//不会改变了l1 l2,因此不需要新建ptr1 ptr2

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }

        ptr->next = l1 == nullptr ? l2 : l1;
        // if(ptr1 == nullptr)
        //     ptr->next = ptr2;
        // if(ptr2 == nullptr)
        //     ptr->next = ptr1;

        return dum->next;
    }
};

#endif //ALGRITHOM_21MERGETWOLISTS_H
