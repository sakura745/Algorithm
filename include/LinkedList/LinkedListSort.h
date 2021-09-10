//
// Created by bas on 9/10/21.
//

#ifndef MAIN_LINKEDLISTSORT_H
#define MAIN_LINKEDLISTSORT_H
//法一：merge 笔试
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(nullptr == head || nullptr == head->next) return head;
        ListNode* slow = head, * fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        //将链表打断
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        ListNode* headl = sortList(head);
        ListNode* headr = sortList(tmp);
        return merge(headl, headr);
    }
private:
    ListNode* merge(ListNode* headl, ListNode* headr){
        //建立辅助Linked List
        ListNode * dum = new ListNode(-1);
        ListNode * ptr = dum;
        while(headl != nullptr && headr != nullptr){
            if(headl->val < headr->val){
                ptr->next = headl;
                headl = headl->next;
            } else {
                ptr->next = headr;
                headr = headr->next;
            }
            ptr = ptr->next;
        }

        //二选一
//        if(headl != nullptr) ptr->next = headl;
//        if(headr != nullptr) ptr->next = headr;
        ptr->next = headl != nullptr ? headl : headr;

        ptr = dum->next;
        delete dum;
        return ptr;
    }
};

//法二：QuickSort 面试

#endif //MAIN_LINKEDLISTSORT_H
